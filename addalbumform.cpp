#include "addalbumform.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QFont>


QStringList getAllMusGroupInDB(){
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


AddAlbumForm::AddAlbumForm(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    ui.dateEdit->setDate(QDate::currentDate());
    ui.group->insertItems(0,getAllMusGroupInDB());
    connect(ui.addButton,SIGNAL(clicked()),this,SLOT(addAlbum()));
}

void AddAlbumForm::changeEvent(QEvent *e)
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


void AddAlbumForm::addAlbum(){
    qDebug()<<"AddAlbumForm::addAlbum()";
    QString str =
            "INSERT INTO album (release_date,musical_label,album_title,isGroupAlbum,id_mus_group,id_musician) "
            "VALUES ('%1','%2','%3','1','%4','') ";
    QString str2 = QString("SELECT MUS_GROUP.id_mus_group FROM  MUS_GROUP WHERE MUS_GROUP.title = '%1'").arg(ui.group->currentText());
    QSqlQuery query;
    if(!query.exec(str2)){
        qDebug()<<query.lastError();
        return;
    }
    query.next();
    str = str.arg(ui.dateEdit->date().toString("yyyy-MM-dd"),ui.lable->text(),ui.title->text(),query.value(query.record().indexOf("id_mus_group")).toString());
    if(!query.exec(str)){
        qDebug()<<query.lastError();
        return;
    }
    ui.lable->clear();
    ui.title->clear();

}
