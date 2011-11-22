#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QtGui>
#include "dataviewer.h"
#include "sqlmodels.h"
#include "addalbumform.h"
#include "tablesviewer.h"
#include "addgroupform.h"

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
    dataViewer = NULL;
    queryDialog = NULL;
    schemaBrowser = NULL;



    createWindow();

}

MainWindow::~MainWindow()
{
    delete ui;
    QSqlDatabase::database("MusShopDB.db").close();
}


void MainWindow::queryExec(){
    if(queryDialog==NULL) return;
    qDebug()<<queryDialog->statement();
    SqlQueryModel *model = new SqlQueryModel();
    model->setQuery(queryDialog->statement());
    dataViewer->setTableModel(model,false);
    dataViewer->setStatusText(queryDialog->statement());

}


void MainWindow::testSlot(){
    qDebug()<<"run";
}



void MainWindow::treeItemActivated(QTreeWidgetItem * item, int /*column*/)
{

    qDebug()<<"run";
    if(!item)
        return;
    qDebug()<<item->type();

    if (item->type() == TableTree::TableType || item->type() == TableTree::ViewType
            || item->type() == TableTree::SystemType)
    {

        dataViewer->freeResources();

        if (item->type() == TableTree::ViewType || item->type() == TableTree::SystemType)
        {
            qDebug()<<"create sqlquery";
            SqlQueryModel * model = new SqlQueryModel();
            model->setQuery(QString("select * from \"%1\".\"%2\"").arg(item->text(1)).arg(item->text(0)));
            dataViewer->setTableModel(model, true);
        }
        else
        {
            qDebug()<<"create Table";
            SqlTableModel * model = new SqlTableModel();
            model->setTable(item->text(0));
            model->select();
            model->setEditStrategy(SqlTableModel::OnManualSubmit);
            dataViewer->setTableModel(model, true);
        }
    }
    if(item->type() == TableTree::TriggerType){
        //qDebug();
        QSqlQuery query;
        QString str = QString("Select sqlite_master.sql FROM sqlite_master WHERE type = 'trigger' AND name = '%1'").arg(item->text(0));
        qDebug()<<str;
        if(!query.exec(str)){
            qDebug()<<query.lastError();
            return;
        }
        if(!query.next()) return;
        dataViewer->freeResources();
        qDebug()<<query.value(query.record().indexOf("sql")).toString();
        dataViewer->setStatusText(query.value(query.record().indexOf("sql")).toString());
        qDebug()<<query.lastError();
    }
}



void MainWindow::createWindow(){
    schemaBrowser = new SchemaBrowser(0,Qt::Widget);
    schemaBrowser->tableTree->buildTree();
    schemaBrowser->buildPragmasTree();
    schemaBrowser->setMinimumWidth(200);
    schemaBrowser->setMaximumWidth(300);


    connect(schemaBrowser->tableTree, SIGNAL(itemActivated(QTreeWidgetItem *, int)),
            this, SLOT(treeItemActivated(QTreeWidgetItem *, int)));


    dataViewer = new DataViewer();
    dataViewer->setEnabled(true);

    ui->myLayout->addWidget(schemaBrowser);
    ui->myLayout->addWidget(dataViewer);
    schemaBrowser->show();
    dataViewer->show();


    createActions();

}



void MainWindow::createActions(){
    connect(ui->exitAction,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->createQueryAction,SIGNAL(triggered()),this,SLOT(createQuery()));
    connect(ui->amountOfCompositionAction,SIGNAL(triggered()),this,SLOT(createAmountOfMusCompOfGroup()));
    connect(ui->listOfAllGroupAlbumsAction,SIGNAL(triggered()),this,SLOT(createListOfAllGroupAlbums()));
    connect(ui->topSalesAction,SIGNAL(triggered()),this,SLOT(createTopSalesAlbum()));
    connect(ui->addAlbumAction,SIGNAL(triggered()),this,SLOT(addAlbum()));
    connect(ui->AddGroupaction,SIGNAL(triggered()),this,SLOT(addGroup()));

}



void MainWindow::createQuery(){
    qDebug()<<"MainWindow::createQuery()";
    if(queryDialog != NULL) queryDialog->deleteLater();
    queryDialog = new QueryEditorDialog();
    connect(queryDialog,SIGNAL(accepted()),this,SLOT(queryExec()));
    queryDialog->exec();


}


void MainWindow::createAmountOfMusCompOfGroup(){
    AmounOfMusCompOfGroup *t = new AmounOfMusCompOfGroup();
    t->setParent(this,Qt::Window);
    t->show();

}


void MainWindow::createListOfAllGroupAlbums(){
    ListOfAllGroupAlbums *t = new ListOfAllGroupAlbums();
    t->setParent(this,Qt::Window);
    t->show();

}


void MainWindow::createTopSalesAlbum(){
    //QString str = "SELECT album_title FROM album WHERE id_album = (SELECT id_album FROM statistics_of_sales WHERE sold_for_this_year=(SELECT MAX(sold_for_this_year) FROM statistics_of_sales))";
    QString str =
            "SELECT ALBUM.album_title, STATISTICS_OF_SALES.sold_for_this_year "
            "FROM  STATISTICS_OF_SALES "
            "INNER JOIN ALBUM "
            "ON STATISTICS_OF_SALES.id_album = ALBUM.id_album "
            "LIMIT 3 ";
    SqlQueryModel * model = new SqlQueryModel(this);
    model->setQuery(str);
    model->setHeaderData(0,Qt::Horizontal,QVariant(QString::fromLocal8Bit("Название альбома")));
    model->setHeaderData(1,Qt::Horizontal,QVariant(QString::fromLocal8Bit("Продано за этот год")));
    dataViewer->setTableModel(model,false);
    dataViewer->setStatusText(str);
}



void MainWindow::addAlbum(){
    AddAlbumForm *t = new AddAlbumForm();
    t->setWindowFlags(Qt::Dialog);
    t->show();

}


void MainWindow::addGroup(){
    AddGroupForm *t = new AddGroupForm(0);
    t->setParent(this,Qt::Window);
    t->show();
}
