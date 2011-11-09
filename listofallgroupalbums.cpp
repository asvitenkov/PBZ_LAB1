#include "listofallgroupalbums.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QFont>


ListOfAllGroupAlbums::ListOfAllGroupAlbums(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.groupList,SIGNAL(currentIndexChanged(QString)),this,SLOT(currentIndexChangedSlot(QString)));
    ui.groupList->addItems(getAllMusGroupInDB());
}

void ListOfAllGroupAlbums::changeEvent(QEvent *e)
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



void ListOfAllGroupAlbums::currentIndexChangedSlot(QString aText){
    QSqlQuery query;
    // получаем айдишник группы для начала
    QString str="SELECT id_mus_group FROM \"main\".\"MUS_GROUP\" WHERE title ='%1';";
    str=str.arg(aText);
    if(!query.exec(str)){
        qDebug()<<query.lastError();
        return;
    }
    int id=-1;
    if(query.next()){
        id = query.value(query.record().indexOf("id_mus_group")).toInt();
    }
    else{
        // ошибка базы, есть айдишник группы а группы то самой нет
        qDebug()<<"error size of group != -1";
        qDebug()<<query.size();
        return;
    }
    str = "SELECT album_title FROM \"main\".\"album\" WHERE isGroupAlbum = '1' AND id_mus_group = '%1';";
    str=str.arg(QString::number(id));
    if(!query.exec(str)){
        qDebug()<<query.lastError();
        return;
    }
    int size = 0;
    ui.tableWidget->setRowCount(0);
    ui.tableWidget->setColumnWidth(0,200);
    while(query.next()){
        size++;
        ui.tableWidget->setRowCount(size);
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(query.value(query.record().indexOf("album_title")).toString());
        ui.tableWidget->setItem(ui.tableWidget->rowCount()-1,0,item);
    }
    ui.totalAmount->setText(QString::number(size));
}



QStringList ListOfAllGroupAlbums::getAllMusGroupInDB(){
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
