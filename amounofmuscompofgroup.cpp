#include "amounofmuscompofgroup.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>

AmounOfMusCompOfGroup::AmounOfMusCompOfGroup(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    tableModel = NULL;
    tableModel = new QSqlTableModel(this);
    connect(ui.groupList,SIGNAL(currentIndexChanged(QString)),this,SLOT(currentIndexChangedSlot(QString)));
    ui.groupList->addItems(getAllMusGroupInDB());
}

void AmounOfMusCompOfGroup::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui.retranslateUi(this);
        break;
    default:
        break;
    }
}



void AmounOfMusCompOfGroup::currentIndexChangedSlot(QString aText){
    tableModel->clear();
    ui.tableView->clearSpans();


    QSqlQuery query;
    // получаем айдишник группы для начала
    QString str="SELECT id_mus_group FROM \"main\".\"MUS_GROUP\" WHERE title ='%1';";
    str=str.arg(aText);
    if(!query.exec(str)){
        qDebug()<<query.lastError();
        return;
    }
    int id=-1;
    if(query.size()==1 || query.size()==-1){
        query.next();
        QSqlRecord rec = query.record();
        id = query.value(rec.indexOf("id_mus_group")).toInt();
    }
    else{
        // такого не должно быть
        qDebug()<<"error size of group != 1";
        qDebug()<<query.size();
        return;
    }
    str = "SELECT id_mus_composition FROM \"main\".\"executor_of_mus_com\" WHERE isGroupComp = '1' AND id_mus_group = '%1';";
    str=str.arg(QString::number(id));
    qDebug()<<tableModel->record();
    if(!query.exec(str)){
        qDebug()<<query.lastError();
        return;
    }
    //tableModel->clear();

    while(query.next()){
        if(!tableModel->setRecord(0,query.record()))
            qDebug()<<"NO ADD";
    }
    tableModel->select();
//    qDebug()<<query.size();
//    tableModel->setTable(QString("executor_of_mus_com"));
//    tableModel->setFilter(QString("id_mus_group = '%1'").arg(QString::number(id)));
//    tableModel->select();
//    QSqlQueryModel *model = new QSqlQueryModel();
//    model->setQuery(QString("SELECT id_mus_composition FROM executor_of_mus_com WHERE isGroupComp = '1' AND id_mus_group = '%1';").arg(QString::number(id)));
//    //ui.tableView->setModel(tableModel);
    ui.tableView->setModel(tableModel);
}

QStringList AmounOfMusCompOfGroup::getAllMusGroupInDB(){
    qDebug()<<"AmounOfMusCompOfGroup::getAllMusGroupInDB()";
    QStringList listTables;
    QSqlQuery query;
    QString strQuery="SELECT title FROM mus_group";
    if(!query.exec(strQuery)){
        qDebug() << "Unable to execute query - exiting";
        qDebug()<<query.lastError();
        return listTables;
    }
    while(query.next()){
        QSqlRecord rec = query.record();
        QString tableName = query.value(rec.indexOf("title")).toString();
        listTables.push_back(tableName);
    }
    return listTables;
}
