#ifndef TABLESVIEWER_H
#define TABLESVIEWER_H

#include <QMainWindow>
#include <QStringList>
#include <QtSql>

namespace Ui {
    class TablesViewer;
}

class TablesViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit TablesViewer(QWidget *parent = 0);
    void initialize();
    ~TablesViewer();

public slots:
    void show();

private slots:
    void currentIndexChangedSlot(const QString text);
    void addRowInTableSlot();

private:
    Ui::TablesViewer *ui;
    QSqlTableModel *tableModel;
    QStringList getAllTablesInDB();


};

#endif // TABLESVIEWER_H
