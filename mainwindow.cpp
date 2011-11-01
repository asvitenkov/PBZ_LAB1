#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QtGui>


static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MusShopDB.db");

    db.setUserName("root");
    if (!db.open()) {
        qDebug() << "Cannot open database:" << db.lastError();
        return false;
    }
    return true;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (!createConnection()) {
        exit(-1);
    }
    TablesViewer *tv = new TablesViewer();
    tv->initialize();
    tv->show();

    queryDialog = new QueryEditorDialog();
    connect(queryDialog,SIGNAL(accepted()),this,SLOT(queryExec()));
    queryDialog->exec();

    SchemaBrowser *schemaBrowser = new SchemaBrowser(0,Qt::Widget);
    schemaBrowser->tableTree->buildTree();
    schemaBrowser->buildPragmasTree();
    schemaBrowser->show();



//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("mus_group");
//    model->select();
//    model->setEditStrategy(QSqlTableModel::OnFieldChange);
//    QTableView *table = new QTableView();
//    table->show();
//    table->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::queryExec(){
    qDebug()<<queryDialog->statement();
}
