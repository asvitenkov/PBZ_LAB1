#include "addgroupform.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

AddGroupForm::AddGroupForm(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.addButton,SIGNAL(clicked()),this,SLOT(AddGroup()));
}

void AddGroupForm::changeEvent(QEvent *e)
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


void AddGroupForm::AddGroup(){
    if(ui.title->text().isEmpty()) return;
    if(ui.title->text().isNull())return;
    QString str =
            "INSERT INTO mus_group (title,type) "
            "VALUES ('%1','%2') ";
    str = str.arg(ui.title->text()).arg(ui.type->text());
    QSqlQuery query;
    if(!query.exec(str)){
        qDebug()<<query.lastError();
        return;
    }
    ui.type->clear();
    ui.title->clear();
}
