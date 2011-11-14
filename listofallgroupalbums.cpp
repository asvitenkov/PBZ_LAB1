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
    QString str="SELECT id_mus_group FROM MUS_GROUP WHERE title ='%1';";
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
    str = "SELECT album_title FROM album WHERE isGroupAlbum = '1' AND id_mus_group = '%1';";
    str=str.arg(QString::number(id));
    if(!query.exec(str)){
        qDebug()<<query.lastError();
        return;
    }
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery(str);
    ui.tableView->setModel(model);
    ui.totalAmount->setText(QString::number(model->rowCount()));
    model->setHeaderData(0,Qt::Horizontal,QVariant(QString::fromLocal8Bit("Название")));
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
