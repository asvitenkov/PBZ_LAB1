/*
For general Sqliteman copyright and licensing information please refer
to the COPYING file provided with the program. Following this notice may exist
a copyright and/or license notice that predates the release of Sqliteman
for which a new license (GPL+exception) is in place.
*/

#include <QColor>
#include <QSqlField>

#include "sqlmodels.h"
//#include "database.h"
//#include "preferences.h"
#include "utils.h"
#include <QtSql>


typedef struct
{
        int cid;
        QString name;
        QString type;
        bool notnull;
        QString defval;
        bool pk;
        QString comment;
}
DatabaseTableField;

/*! \brief List of the attached databases ("schemas").
Mapping name/filename */
typedef QMap<QString,QString> DbAttach;

//! \brief Table columns list.
typedef QList<DatabaseTableField> FieldList;

//! \brief A map with "object name"/"its parent" - schema
typedef QMap<QString,QString> DbObjects;

typedef QList<DatabaseTableField> FieldList;



FieldList tableFieldsSQLModel(const QString & table)
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


DbObjects getObjectsSQLModel(const QString type, const QString schema)
{
        DbObjects objs;

        QString sql;
        if (type.isNull())
                sql = QString("SELECT lower(name), lower(tbl_name) FROM \"%1\".sqlite_master;").arg(schema);
        else
                sql = QString("SELECT lower(name), lower(tbl_name) FROM \"%1\".sqlite_master WHERE type = '%2' and name not like 'sqlite_%';").arg(schema).arg(type);

        QSqlQuery query(sql);
        while(query.next())
                objs.insertMulti(query.value(1).toString(), query.value(0).toString());

        if(query.lastError().isValid())
                //exception(tr("Error while the list of %1: %2.").arg(type).arg(query.lastError().text()));

        return objs;
}


DbObjects getSysObjects(const QString & schema)
{
        DbObjects objs;

        QSqlQuery query(QString("SELECT lower(name), lower(tbl_name) FROM \"%1\".sqlite_master WHERE type = 'table' and name like 'sqlite_%';").arg(schema));

        objs.insert("sqlite_master", "");
        while(query.next())
                objs.insertMulti(query.value(1).toString(), query.value(0).toString());

        if(query.lastError().isValid());
                //exception(tr("Error while the list of the system catalogue: %2.").arg(query.lastError().text()));

        return objs;
}



QStringList getSysIndexesSQLModel(const QString & table, const QString & schema)
{
        QStringList orig = getObjectsSQLModel("index", schema).values(table);
        // really all indexes
        QStringList sysIx;
        QSqlQuery query(QString("PRAGMA \"%1\".index_list(\"%2\");").arg(schema).arg(table));

        QString curr;
        while(query.next())
        {
                curr = query.value(1).toString();
                if (!orig.contains(curr))
                        sysIx.append(curr);
        }

        if(query.lastError().isValid());
                //exception(tr("Error while the list of the system catalogue: %2.").arg(query.lastError().text()));

        return sysIx;
}


SqlTableModel::SqlTableModel(QObject * parent, QSqlDatabase db)
	: QSqlTableModel(parent, db),
	m_pending(false),
	m_schema("")
{
	m_deleteCache.clear();
//	Preferences * prefs = Preferences::instance();
//	m_useNull = prefs->nullHighlight();
//	m_nullColor = prefs->nullHighlightColor();
//	m_nullText = prefs->nullHighlightText();
//	m_useBlob = prefs->blobHighlight();
//	m_blobColor = prefs->blobHighlightColor();
//	m_blobText = prefs->blobHighlightText();
//	m_cropColumns = prefs->cropColumns();

	connect(this, SIGNAL(primeInsert(int, QSqlRecord &)),
			this, SLOT(doPrimeInsert(int, QSqlRecord &)));
}

QVariant SqlTableModel::data(const QModelIndex & item, int role) const
{
	QString curr(QSqlTableModel::data(item, Qt::DisplayRole).toString());
	// numbers
	if (role == Qt::TextAlignmentRole)
	{
		bool ok;
		curr.toDouble(&ok);
		if (ok)
			return QVariant(Qt::AlignRight | Qt::AlignTop);
		return QVariant(Qt::AlignTop);
	}

	if (role == Qt::BackgroundColorRole)
    {
    	// mark rows prepared for a deletion in this trasnaction
        if (m_deleteCache.contains(item.row()))
            return QVariant(Qt::red);
        for (int i = 0; i < columnCount(); ++i)
        {
            if (isDirty(index(item.row(), i)))
                return QVariant(Qt::cyan);
        }
    }

	// nulls
	if (m_useNull && curr.isNull())
	{
		if (role == Qt::BackgroundColorRole)
			return QVariant(m_nullColor);
		if (role == Qt::ToolTipRole)
			return QVariant(tr("NULL value"));
		if (role == Qt::DisplayRole)
			return QVariant(m_nullText);
	}
	// BLOBs
	// any others handling with blobs - e.g. converting to images etc.
	// are followed with serious perfromance issues.
	// Users can see it through edit dialog.
	if (/*f.type.toUpper() == "BLOB" || */
		m_useBlob /*&&
		   record().field(item.column()).type() == QVariant::ByteArray*/
		   && QSqlTableModel::data(item, Qt::DisplayRole).type() == QVariant::ByteArray)
	{
		if (role == Qt::BackgroundColorRole)
			return QVariant(m_blobColor);
		if (role == Qt::ToolTipRole)
			return QVariant(tr("BLOB value"));
		if (role == Qt::DisplayRole)
			return QVariant(m_blobText);
		if (role == Qt::EditRole)
// 			return Database::hex(QSqlTableModel::data(item, Qt::DisplayRole).toByteArray());
			return QSqlTableModel::data(item, Qt::DisplayRole);
	}

	// advanced tooltips
	if (role == Qt::ToolTipRole)
		return QVariant("<qt>" + curr + "</qt>");

	if (role == Qt::DisplayRole && m_cropColumns)
		return QVariant(curr.length() > 20 ? curr.left(20)+"..." : curr);

	return QSqlTableModel::data(item, role);
}

bool SqlTableModel::setData ( const QModelIndex & ix, const QVariant & value, int role)
{
    if (! ix.isValid())
        return false;

	if (role == Qt::EditRole)
		m_pending = true;

    int r = ix.row();
	emit dataChanged( index(r, 0), index(r, columnCount()-1) );

	return QSqlTableModel::setData(ix, value, role);
}

QVariant SqlTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal)
	{
		switch (role)
		{
			case (Qt::DecorationRole):
				switch (m_header[section])
				{
					case (SqlTableModel::PK):
						return Utils::getIcon("key.png");
						break;
					case (SqlTableModel::Auto):
						return Utils::getIcon("index.png");
						break;
					case (SqlTableModel::Default):
						return Utils::getIcon("column.png");
						break;
					default:
						return 0;
				}
				break;
			case (Qt::ToolTipRole):
				switch (m_header[section])
				{
					case (SqlTableModel::PK):
						return tr("Primary Key");
						break;
					case (SqlTableModel::Auto):
						return tr("Autoincrement");
						break;
					case (SqlTableModel::Default):
						return tr("Has default value");
						break;
					default:
						return "";
				}
				break;
		}
	}
	return QSqlTableModel::headerData(section, orientation, role);
}

void SqlTableModel::doPrimeInsert(int row, QSqlRecord & record)
{
        FieldList fl = tableFieldsSQLModel(tableName());
	bool ok;
	QString defval;
	// guess what type is the default value.
	foreach (DatabaseTableField column, fl)
	{
		if (column.defval.isNull())
			continue;
		defval = column.defval;
		defval.toInt(&ok);
		if (!ok)
		{
			defval.toDouble(&ok);
			if (!ok)
			{
				if (defval.left(1) == "'" || defval.left(1) == "\"")
					defval = defval.mid(1, defval.length()-2);
			}
		}
		record.setValue(column.name, QVariant(defval));
	}
}

bool SqlTableModel::insertRows ( int row, int count, const QModelIndex & parent)
{
	m_pending = true;
	return QSqlTableModel::insertRows(row, count, parent);
}

bool SqlTableModel::removeRows ( int row, int count, const QModelIndex & parent)
{
	m_pending = true;
	// this is a workaround to allow mark heading as deletion
	// (as it's propably a bug in Qt QSqlTableModel ManualSubmit handling
	bool ret = QSqlTableModel::removeRows(row, count, parent);
	emit dataChanged( index(row, 0), index(row+count-1, columnCount()-1) );
	emit headerDataChanged(Qt::Vertical, row, row+count-1);
	for (int i = 0; i < count; ++i)
		m_deleteCache.append(row+i);

	return ret;
}

void SqlTableModel::setTable(const QString &tableName)
{
	m_header.clear();
        QStringList indexes = getSysIndexesSQLModel(tableName, m_schema);
        FieldList columns = tableFieldsSQLModel(tableName);

	foreach (DatabaseTableField c, columns)
	{
		// it's a little bit cryptic - docs are inconsistent here.
		// Maybe it's enough to have INTEGER PRIMARY KEY to autoincrement
		// as it's done in Qt4 driver and in various SWs,
		// but maybe there is something with AUTOINCREMENT too. Dunno.
		if (c.pk)
		{
			m_header[c.cid] = (c.type == "INTEGER") ? SqlTableModel::Auto : SqlTableModel::PK;
			continue;
		}
		// show has default icon
		if (!c.defval.isEmpty())
		{
			m_header[c.cid] = SqlTableModel::Default;
			continue;
		}
		m_header[c.cid] = SqlTableModel::None;
	}

	QSqlTableModel::setTable(tableName);
}

void SqlTableModel::setPendingTransaction(bool pending)
{
	m_pending = pending;

	// TODO: examine the better way to get only shown/changed lines.
	// If there is one...
	if (!pending)
	{
		for (int i = 0; i < m_deleteCache.size(); ++i)
			emit headerDataChanged(Qt::Vertical, m_deleteCache[i], m_deleteCache[i]);
	}
	m_deleteCache.clear();
}




SqlQueryModel::SqlQueryModel( QObject * parent)
	: QSqlQueryModel(parent)
{
//	Preferences * prefs = Preferences::instance();
//	m_useNull = prefs->nullHighlight();
//	m_nullColor = prefs->nullHighlightColor();
//	m_nullText = prefs->nullHighlightText();
//	m_useBlob = prefs->blobHighlight();
//	m_blobColor = prefs->blobHighlightColor();
//	m_blobText = prefs->blobHighlightText();
//	m_cropColumns = prefs->cropColumns();
}

QVariant SqlQueryModel::data(const QModelIndex & item, int role) const
{
	QString curr(QSqlQueryModel::data(item, Qt::DisplayRole).toString());

	// numbers
	if (role == Qt::TextAlignmentRole)
	{
		bool ok;
		curr.toDouble(&ok);
		if (ok)
			return QVariant(Qt::AlignRight | Qt::AlignTop);
		return QVariant(Qt::AlignTop);
	}

	if (m_useNull && curr.isNull())
	{
		if (role == Qt::BackgroundColorRole)
			return QVariant(m_nullColor);
		if (role == Qt::ToolTipRole)
			return QVariant(tr("NULL value"));
		if (role == Qt::DisplayRole)
			return QVariant(m_nullText);
	}

	if (/*f.type.toUpper() == "BLOB" || */
		m_useBlob /*&&
		   record().field(item.column()).type() == QVariant::ByteArray*/
		   && QSqlQueryModel::data(item, Qt::DisplayRole).type() == QVariant::ByteArray)
	{
		if (role == Qt::BackgroundColorRole)
			return QVariant(m_blobColor);
		if (role == Qt::ToolTipRole)
			return QVariant(tr("BLOB value"));
		if (role == Qt::DisplayRole)
			return QVariant(m_blobText);
	}

	// advanced tooltips
	if (role == Qt::ToolTipRole)
		return QVariant("<qt>" + curr + "</qt>");

	if (role == Qt::DisplayRole && m_cropColumns)
		return QVariant(curr.length() > 20 ? curr.left(20)+"..." : curr);

	return QSqlQueryModel::data(item, role);
}

void SqlQueryModel::setQuery ( const QSqlQuery & query )
{
	QSqlQueryModel::setQuery(query);
	info = record();
}

void SqlQueryModel::setQuery ( const QString & query, const QSqlDatabase & db)
{
	QSqlQueryModel::setQuery(query, db);
	info = record();
}
