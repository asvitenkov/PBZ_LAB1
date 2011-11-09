#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tablesviewer.h"
#include <QMainWindow>
#include "queryeditordialog.h"
#include "schemabrowser.h"
#include "dataviewer.h"
#include "amounofmuscompofgroup.h"
#include "listofallgroupalbums.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QueryEditorDialog *queryDialog;
    DataViewer *dataViewer;
    QSqlTableModel *model;
    SchemaBrowser *schemaBrowser;
    void createWindow();
    void createActions();


private slots:
    void queryExec();
    void testSlot();
    void treeItemActivated(QTreeWidgetItem * item, int column);
    void createQuery();
    void createAmountOfMusCompOfGroup();
    void createListOfAllGroupAlbums();
    void createTopSalesAlbum();
};

#endif // MAINWINDOW_H
