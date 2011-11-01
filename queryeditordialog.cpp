/*
For general Sqliteman copyright and licensing information please refer
to the COPYING file provided with the program. Following this notice may exist
a copyright and/or license notice that predates the release of Sqliteman
for which a new license (GPL+exception) is in place.
*/
#include <QScrollBar>
#include <QComboBox>
#include <QLineEdit>
#include <QDebug>
#

#include "queryeditordialog.h"



FieldList tableFieldsThis(const QString & table)
{
        FieldList fields;
        QString sql(QString("PRAGMA TABLE_INFO(\"%1\");").arg(table));
        QSqlQuery query(sql);
        if (query.lastError().isValid())
        {
                //exception(tr("Error while getting the fileds of %1: %2.").arg(table).arg(query.lastError().text()));
            qDebug()<<"ERROR FieldList tableFields(const QString & table)";
                return fields;
        }

        while (query.next())
        {
                DatabaseTableField field;
                field.cid = query.value(0).toInt();
                field.name = query.value(1).toString();
                field.type = query.value(2).toString();
                if (field.type.isNull() || field.type.isEmpty())
                        field.type = "NULL";
                field.notnull = query.value(3).toBool();
                field.defval = query.value(4).toString();
                field.pk = query.value(5).toBool();
                field.comment = "";
                fields.append(field);
        }

        return fields;
}





QStringList getAllTablesInDB(){
    QStringList listTables;
    //listTables.push_back("------------------");
    QSqlQuery query;
    QString strQuery="SELECT NAME FROM sqlite_master where type = 'table'";
    if(!query.exec(strQuery)){
        qDebug() << "Unable to execute query - exiting";
        qDebug()<<query.lastError();
        return listTables;
    }
    while(query.next()){
        QSqlRecord rec = query.record();
        QString tableName = query.value(rec.indexOf("name")).toString();
        if(tableName.indexOf("sqlite")==-1)
            listTables.push_back(tableName);
    }
    return listTables;
}


TermEditor::TermEditor(const FieldList & fieldList, QWidget * parent)
	: QWidget(parent)
{
	fields = new QComboBox();
	for(int i = 0; i < fieldList.size(); i++)
		fields->addItem(fieldList[i].name);

	relations = new QComboBox();
	relations->addItems(QStringList() << tr("Contains") << tr("Doesn't contain") << tr("Equals") << tr("Not equals")
					<< tr("Bigger than") << tr("Smaller than"));

	value = new QLineEdit();

	QHBoxLayout * layout = new QHBoxLayout();
	layout->addWidget(fields);
	layout->addWidget(relations);
	layout->addWidget(value);

	setLayout(layout);
}

QString TermEditor::selectedField()
{
	return fields->currentText();
}
int TermEditor::selectedRelation()
{
	return relations->currentIndex();
}
QString TermEditor::selectedValue()
{
	return value->text();
}


QueryStringModel::QueryStringModel(QObject * parent)
	: QStringListModel(parent)
{
}

Qt::ItemFlags QueryStringModel::flags (const QModelIndex & index) const
{
	return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

void QueryStringModel::clear()
{
	setStringList(QStringList());
}

void QueryStringModel::append(const QString & value)
{
	QStringList l(stringList());
	l.append(value);
	setStringList(l);
}


QueryEditorDialog::QueryEditorDialog(QWidget * parent): QDialog(parent)
{
	setupUi(this);

	m_schema = "main"; // FIXME: real schema

	columnModel = new QueryStringModel(this);
	selectModel = new QueryStringModel(this);
	columnView->setModel(columnModel);
	selectView->setModel(selectModel);

	// a litle bit of black magic to get Term scrolling right
	QWidget * w = new QWidget();
	termsLayout = new QVBoxLayout(w);
	w->setLayout(termsLayout);
	scrollArea->setWidget(w);
	
	connect(tableList, SIGNAL(activated(const QString &)),
			this, SLOT(tableSelected(const QString &)));
	connect(moreButton, SIGNAL(clicked()), this, SLOT(moreTerms()));
	connect(lessButton, SIGNAL(clicked()), this, SLOT(lessTerms()));
	//
	connect(addAllButton, SIGNAL(clicked()), this, SLOT(addAllSelect()));
	connect(addButton, SIGNAL(clicked()), this, SLOT(addSelect()));
	connect(removeAllButton, SIGNAL(clicked()), this, SLOT(removeAllSelect()));
	connect(removeButton, SIGNAL(clicked()), this, SLOT(removeSelect()));

        QStringList tables=getAllTablesInDB();
        tableList->addItems(tables);
	
        //If a database has at least one table. auto select it
        if(tables.size() > 0)
                tableSelected(tables[0]);
}

QueryEditorDialog::~QueryEditorDialog()
{
}

QString QueryEditorDialog::statement()
{
	QString logicWord;
	QString sql = "SELECT ";

	// columns
	if (selectModel->rowCount() == 0)
		sql += "* ";
	else
	{
		foreach (QString s, selectModel->stringList())
			sql += s + ", ";
		sql = sql.remove(sql.size() - 2, 2); 	// cut the extra ", "
	}

	// Add table name
	sql += (" FROM \"" + m_schema + "\".\"" + tableList->currentText() + "\"");

	// Optionaly add terms
	if(termsLayout->count() > 0)
	{
		// But first determine what is the chosen logic word (And/Or)
		(andButton->isChecked()) ? logicWord = "AND" : logicWord = "OR";

		sql += " WHERE ";

		for(int i = 0; i < termsLayout->count(); i++)
		{
			QWidget * widget = termsLayout->itemAt(i)->widget();

			if(!widget)
				continue;

			TermEditor * term = qobject_cast<TermEditor *>(widget);
			if(term)
			{
				sql += term->selectedField();

				switch(term->selectedRelation())
				{
					case 0:		// Contains
						sql += (" LIKE '%" + term->selectedValue() + "%'");
						break;

					case 1: 	// Doesn't contain
						sql += (" NOT LIKE '%" + term->selectedValue() + "%'");
						break;

					case 2:		// Equals
						sql += (" = '" + term->selectedValue() + "'");
						break;

					case 3:		// Not equals
						sql += (" <> '" + term->selectedValue() + "'");
						break;

					case 4:		// Bigger than
						sql += (" > '" + term->selectedValue() + "'");
						break;

					case 5:		// Smaller than
						sql += (" < '" + term->selectedValue() + "'");
						break;
				}
			}
			sql += (" " + logicWord + " ");
		}
		sql = sql.remove(sql.size() - (logicWord.size() + 2), logicWord.size() + 2); // cut the extra " AND " or " OR "
	}
	sql += ";";

	return sql;
}

void QueryEditorDialog::tableSelected(const QString & table)

{
    //qDebug()<<"QueryEditorDialog::tableSelected";

    curTable = table;
    QStringList cols;

    QString strQuery="PRAGMA table_info (%1)";
    strQuery = strQuery.arg(table);
    QSqlQuery query;

    if(!query.exec(strQuery)){
        qDebug()<<"ERROR";
        return;
    }

    while(query.next()){

        QSqlRecord rec = query.record();
        cols<<query.value(rec.indexOf("name")).toString();
    }

    columnModel->setStringList(cols);
    selectModel->clear();

    // clear terms
    while (termsLayout->count() != 0)
            lessTerms();


}

void QueryEditorDialog::addAllSelect()
{
	selectModel->setStringList(columnModel->stringList());
	columnModel->clear();
}

void QueryEditorDialog::addSelect()
{
	QItemSelectionModel *selections = columnView->selectionModel();
	if (!selections->hasSelection())
		return;
	QStringList list(columnModel->stringList());
	QString val;
	foreach (QModelIndex i, selections->selectedIndexes())
	{
		val = columnModel->data(i, Qt::DisplayRole).toString();
		selectModel->append(val);
		list.removeAll(val);
	}
	columnModel->setStringList(list);
}

void QueryEditorDialog::removeAllSelect()
{
	tableSelected(curTable);
	selectModel->clear();
}

void QueryEditorDialog::removeSelect()
{
	QItemSelectionModel *selections = selectView->selectionModel();
	if (!selections->hasSelection())
		return;
	QStringList list(selectModel->stringList());
	QString val;
	foreach (QModelIndex i, selections->selectedIndexes())
	{
		val = selectModel->data(i, Qt::DisplayRole).toString();
		columnModel->append(val);
		list.removeAll(val);
	}
	selectModel->setStringList(list);
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(selectModel->rowCount()!=0);
}

void QueryEditorDialog::moreTerms()
{

    TermEditor * term = new TermEditor(tableFieldsThis(curTable));
    termsLayout->addWidget(term);
    lessButton->setEnabled(true);
    scrollArea->widget()->resize(scrollArea->widget()->sizeHint());
    qApp->processEvents();
    scrollArea->verticalScrollBar()->setValue(scrollArea->verticalScrollBar()->maximum());
}

void QueryEditorDialog::lessTerms()
{
	QLayoutItem * child = termsLayout->takeAt(termsLayout->count() - 1);
	if(child)
	{
		delete child->widget();
		delete child;
	}
	
	if(termsLayout->count() == 0)
		lessButton->setEnabled(false);
}
