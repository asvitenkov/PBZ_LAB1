#include "tablesviewer.h"
#include "ui_tablesviewer.h"


TablesViewer::TablesViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TablesViewer)
{
    ui->setupUi(this);
    tableModel = NULL;
    //initialize();
}


void TablesViewer::initialize(){

    connect(ui->tablesList,SIGNAL(currentIndexChanged(QString)),this,SLOT(currentIndexChangedSlot(QString)));
    connect(ui->buttonAddRowInTable,SIGNAL(clicked()),this,SLOT(addRowInTableSlot()));
    if(!tableModel){
        tableModel = new QSqlTableModel(this);
        tableModel->setEditStrategy(QSqlTableModel::OnFieldChange);
        ui->tableView->setModel(tableModel);
    }

}

TablesViewer::~TablesViewer()
{
    delete ui;
}



QStringList TablesViewer::getAllTablesInDB(){
    QStringList listTables;
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


void TablesViewer::show(){
    ui->tablesList->clear();
    ui->tablesList->addItems(getAllTablesInDB());
    QWidget::show();

}


void TablesViewer::currentIndexChangedSlot(const QString text){
    if(text!="------------------"){
        tableModel->setTable(text);
        tableModel->select();
    }
    else{
        tableModel->clear();
        ui->tableView->clearSpans();
        ui->tableView->setModel(tableModel);
        //ui->tableView->model()->removeColumns(TablesViewer)
        //ui->tableView->model()->removeRows(ui->tableView-)


        //ui->tableView->setModel(tableModel);
    }
}



void TablesViewer::addRowInTableSlot(){
    int row = tableModel->rowCount();
    tableModel->insertRow(row);
}
