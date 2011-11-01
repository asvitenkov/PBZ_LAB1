#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tablesviewer.h"
#include <QMainWindow>
#include "queryeditordialog.h"
#include "schemabrowser.h"
#include "dataviewer.h"


//typedef struct
//{
//        int cid;
//        QString name;
//        QString type;
//        bool notnull;
//        QString defval;
//        bool pk;
//        QString comment;
//}
//DatabaseTableField;
//typedef QList<DatabaseTableField> FieldList;

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


private slots:
    void queryExec();
    void testSlot();
    void treeItemActivated(QTreeWidgetItem * item, int column);
};

#endif // MAINWINDOW_H
