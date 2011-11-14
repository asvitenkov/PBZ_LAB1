#include "amounofmuscompofgroup.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QFont>

AmounOfMusCompOfGroup::AmounOfMusCompOfGroup(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);
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
    QSqlQuery query;
    // получаем айдишник группы для начала
    QString str="SELECT id_mus_group FROM main.MUS_GROUP WHERE title ='%1';";
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

    str =
            "SELECT MUSICAL_COMPOSITION.title, ALBUM.album_title "
            "FROM "
            "EXECUTOR_OF_MUS_COM "
            "INNER JOIN MUSICAL_COMPOSITION "
            "ON EXECUTOR_OF_MUS_COM.id_mus_composition = MUSICAL_COMPOSITION.id_mus_composition "
            "INNER JOIN ALBUM_COMPOSITION "
            "ON ALBUM_COMPOSITION.id_mus_composition = MUSICAL_COMPOSITION.id_mus_composition "
            "INNER JOIN ALBUM "
            "ON ALBUM_COMPOSITION.id_album = ALBUM.id_album "
            "INNER JOIN MUS_GROUP "
            "ON EXECUTOR_OF_MUS_COM.id_mus_group = MUS_GROUP.id_mus_group AND ALBUM.id_mus_group = MUS_GROUP.id_mus_group "
            "WHERE "
            "EXECUTOR_OF_MUS_COM.isGroupComp = 1 "
            "AND EXECUTOR_OF_MUS_COM.id_mus_group = %1 "
            "ORDER BY ALBUM.album_title ";

    str = str.arg(id);

    if(!query.exec(str)){
        qDebug()<<query.lastError();
        return;
    }
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery(str);
    model->setHeaderData(0,Qt::Horizontal,QVariant(QString::fromLocal8Bit("Название")));
    model->setHeaderData(0,Qt::Horizontal,QVariant(QString::fromLocal8Bit("Альбом")));
    ui.tableView->setModel(model);
    ui.totalAmount->setText(QString::number(model->rowCount()));

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




