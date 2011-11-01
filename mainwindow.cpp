#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QtGui>
#include "dataviewer.h"
#include "sqlmodels.h"


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
    createWindow();
//    TablesViewer *tv = new TablesViewer();
//    tv->initialize();
//    tv->show();

//    queryDialog = new QueryEditorDialog();
//    connect(queryDialog,SIGNAL(accepted()),this,SLOT(queryExec()));
//    queryDialog->exec();





//    connect(schemaBrowser->tableTree, SIGNAL(itemActivated(QTreeWidgetItem *, int)),
//            this, SLOT(testSlot()));




//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("mus_group");
//    model->select();
//    model->setEditStrategy(QSqlTableModel::OnFieldChange);
//    QTableView *table = new QTableView();
//    table->show();
//    table->setModel(model);



//    dataViewer = new DataViewer();
//    dataViewer->setEnabled(true);
//    dataViewer->show();
    //dataViewer->setTableModel(new QSqlQueryModel(), false);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::queryExec(){
    qDebug()<<queryDialog->statement();
}


void MainWindow::testSlot(){
    qDebug()<<"run";
}



void MainWindow::treeItemActivated(QTreeWidgetItem * item, int /*column*/)
{

    qDebug()<<"run";
        if(!item)
                return;

        if (item->type() == TableTree::TableType || item->type() == TableTree::ViewType
                || item->type() == TableTree::SystemType)
        {
                dataViewer->freeResources();
                if (item->type() == TableTree::ViewType || item->type() == TableTree::SystemType)
                {
                    SqlQueryModel * model = new SqlQueryModel();
                    model->setQuery(QString("select * from \"%1\".\"%2\"").arg(item->text(1)).arg(item->text(0)));
                    dataViewer->setTableModel(model, false);
                }
                else
                {
                        SqlTableModel * model = new SqlTableModel();
                        //model->setSchema(item->text(1));
                        model->setTable(item->text(0));
                        model->select();
                        model->setEditStrategy(SqlTableModel::OnManualSubmit);
                        dataViewer->setTableModel(model, true);
                }
        }
}



void MainWindow::createWindow(){
    schemaBrowser = new SchemaBrowser(0,Qt::Widget);
    schemaBrowser->tableTree->buildTree();
    schemaBrowser->buildPragmasTree();
    schemaBrowser->show();
    schemaBrowser->setMinimumWidth(200);


    connect(schemaBrowser->tableTree, SIGNAL(itemActivated(QTreeWidgetItem *, int)),
            this, SLOT(treeItemActivated(QTreeWidgetItem *, int)));


    dataViewer = new DataViewer();
    dataViewer->setEnabled(true);
    dataViewer->show();
    //dataViewer->setTableModel(new QSqlQueryModel(), false);

    //ui->pushButton->hide();
    ui->myLayout->addWidget(schemaBrowser);
    ui->myLayout->addWidget(dataViewer);

}
