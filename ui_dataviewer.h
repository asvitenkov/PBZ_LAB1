/********************************************************************************
** Form generated from reading UI file 'dataviewer.ui'
**
** Created: Wed 2. Nov 00:03:17 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAVIEWER_H
#define UI_DATAVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "blobpreviewwidget.h"
//#include "sqleditorwidget.h"
#include "sqlitemview.h"

QT_BEGIN_NAMESPACE

class Ui_DataViewer
{
public:
    QAction *actionNew_Row;
    QAction *actionRemove_Row;
    QAction *actionTruncate_Table;
    QAction *actionExport_Data;
    QAction *actionCommit;
    QAction *actionRollback;
    QAction *actionRipOut;
    QAction *actionClose;
    QAction *actionBLOB_Preview;
    QAction *action_Goto_Line;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QSplitter *splitterBlob;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout1;
    QTableView *tableView;
    QWidget *tab_2;
    QGridLayout *gridLayout2;
    SqlItemView *itemView;
    QLabel *label;
    QWidget *tab_3;
    QGridLayout *gridLayout3;
    //SqlEditorWidget *scriptEdit;
    QGroupBox *blobPreviewBox;
    QGridLayout *gridLayout4;
    BlobPreviewWidget *blobPreview;
    QTextEdit *statusText;
    QToolBar *mainToolBar;
    QToolBar *exportToolBar;
    QToolBar *snapshotToolBar;

    void setupUi(QMainWindow *DataViewer)
    {
        if (DataViewer->objectName().isEmpty())
            DataViewer->setObjectName(QString::fromUtf8("DataViewer"));
        DataViewer->resize(976, 607);
        DataViewer->setMinimumSize(QSize(0, 100));
        actionNew_Row = new QAction(DataViewer);
        actionNew_Row->setObjectName(QString::fromUtf8("actionNew_Row"));
        actionRemove_Row = new QAction(DataViewer);
        actionRemove_Row->setObjectName(QString::fromUtf8("actionRemove_Row"));
        actionTruncate_Table = new QAction(DataViewer);
        actionTruncate_Table->setObjectName(QString::fromUtf8("actionTruncate_Table"));
        actionExport_Data = new QAction(DataViewer);
        actionExport_Data->setObjectName(QString::fromUtf8("actionExport_Data"));
        actionCommit = new QAction(DataViewer);
        actionCommit->setObjectName(QString::fromUtf8("actionCommit"));
        actionRollback = new QAction(DataViewer);
        actionRollback->setObjectName(QString::fromUtf8("actionRollback"));
        actionRipOut = new QAction(DataViewer);
        actionRipOut->setObjectName(QString::fromUtf8("actionRipOut"));
        actionClose = new QAction(DataViewer);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionClose->setVisible(false);
        actionBLOB_Preview = new QAction(DataViewer);
        actionBLOB_Preview->setObjectName(QString::fromUtf8("actionBLOB_Preview"));
        actionBLOB_Preview->setCheckable(true);
        action_Goto_Line = new QAction(DataViewer);
        action_Goto_Line->setObjectName(QString::fromUtf8("action_Goto_Line"));
        centralwidget = new QWidget(DataViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        splitter->setChildrenCollapsible(false);
        splitterBlob = new QSplitter(splitter);
        splitterBlob->setObjectName(QString::fromUtf8("splitterBlob"));
        splitterBlob->setOrientation(Qt::Horizontal);
        splitterBlob->setChildrenCollapsible(false);
        tabWidget = new QTabWidget(splitterBlob);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout1 = new QGridLayout(tab);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(0, 100));
        tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::ContiguousSelection);
        tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout1->addWidget(tableView, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout2 = new QGridLayout(tab_2);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        itemView = new SqlItemView(tab_2);
        itemView->setObjectName(QString::fromUtf8("itemView"));

        gridLayout2->addWidget(itemView, 1, 0, 1, 1);

        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout2->addWidget(label, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        //tab_3 = new QWidget();
        //tab_3->setObjectName(QString::fromUtf8("tab_3"));
        //gridLayout3 = new QGridLayout(tab_3);
        //gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
//        scriptEdit = new SqlEditorWidget(tab_3);
//        scriptEdit->setObjectName(QString::fromUtf8("scriptEdit"));
//        scriptEdit->setReadOnly(false);

//        gridLayout3->addWidget(scriptEdit, 0, 0, 1, 1);

        //tabWidget->addTab(tab_3, QString());
        splitterBlob->addWidget(tabWidget);
        blobPreviewBox = new QGroupBox(splitterBlob);
        blobPreviewBox->setObjectName(QString::fromUtf8("blobPreviewBox"));
        gridLayout4 = new QGridLayout(blobPreviewBox);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        blobPreview = new BlobPreviewWidget(blobPreviewBox);
        blobPreview->setObjectName(QString::fromUtf8("blobPreview"));

        gridLayout4->addWidget(blobPreview, 0, 0, 1, 1);

        splitterBlob->addWidget(blobPreviewBox);
        splitter->addWidget(splitterBlob);
        statusText = new QTextEdit(splitter);
        statusText->setObjectName(QString::fromUtf8("statusText"));
        statusText->setMinimumSize(QSize(0, 30));
        statusText->setReadOnly(true);
        splitter->addWidget(statusText);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        DataViewer->setCentralWidget(centralwidget);
        mainToolBar = new QToolBar(DataViewer);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setOrientation(Qt::Horizontal);
        DataViewer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        exportToolBar = new QToolBar(DataViewer);
        exportToolBar->setObjectName(QString::fromUtf8("exportToolBar"));
        exportToolBar->setOrientation(Qt::Horizontal);
        DataViewer->addToolBar(Qt::TopToolBarArea, exportToolBar);
        snapshotToolBar = new QToolBar(DataViewer);
        snapshotToolBar->setObjectName(QString::fromUtf8("snapshotToolBar"));
        snapshotToolBar->setOrientation(Qt::Horizontal);
        DataViewer->addToolBar(Qt::TopToolBarArea, snapshotToolBar);


        mainToolBar->addAction(actionNew_Row);
        mainToolBar->addAction(actionRemove_Row);
        mainToolBar->addAction(actionTruncate_Table);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCommit);
        mainToolBar->addAction(actionRollback);
        exportToolBar->addAction(actionBLOB_Preview);
        exportToolBar->addAction(actionExport_Data);
        exportToolBar->addAction(action_Goto_Line);
        exportToolBar->addAction(actionClose);
        snapshotToolBar->addAction(actionRipOut);

        snapshotToolBar->hide();
        exportToolBar->hide();

        retranslateUi(DataViewer);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DataViewer);
    } // setupUi

    void retranslateUi(QMainWindow *DataViewer)
    {
        DataViewer->setWindowTitle(QApplication::translate("DataViewer", "Data Viewer", 0, QApplication::UnicodeUTF8));
        actionNew_Row->setText(QApplication::translate("DataViewer", "New Row", 0, QApplication::UnicodeUTF8));
        actionRemove_Row->setText(QApplication::translate("DataViewer", "Remove Row", 0, QApplication::UnicodeUTF8));
        actionTruncate_Table->setText(QApplication::translate("DataViewer", "Truncate Table", 0, QApplication::UnicodeUTF8));
        actionExport_Data->setText(QApplication::translate("DataViewer", "Export Data", 0, QApplication::UnicodeUTF8));
        actionCommit->setText(QApplication::translate("DataViewer", "Commit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCommit->setToolTip(QApplication::translate("DataViewer", "Commit the current transaction in the result table", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRollback->setText(QApplication::translate("DataViewer", "Rollback", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRollback->setToolTip(QApplication::translate("DataViewer", "Rollback the current transaction in the result table", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRipOut->setText(QApplication::translate("DataViewer", "Table Snapshot", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("DataViewer", "Close", 0, QApplication::UnicodeUTF8));
        actionBLOB_Preview->setText(QApplication::translate("DataViewer", "BLOB Preview", 0, QApplication::UnicodeUTF8));
        action_Goto_Line->setText(QApplication::translate("DataViewer", "&Goto Record...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Goto_Line->setToolTip(QApplication::translate("DataViewer", "Go to line number", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DataViewer", "Full View", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DataViewer", "Item View is read only now.", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DataViewer", "Item View", 0, QApplication::UnicodeUTF8));
        //tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("DataViewer", "Script Output", 0, QApplication::UnicodeUTF8));
        blobPreviewBox->setTitle(QApplication::translate("DataViewer", "BLOB Preview", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("DataViewer", "DML Tools", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        mainToolBar->setToolTip(QApplication::translate("DataViewer", "Open a new standalone window with current results", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        exportToolBar->setWindowTitle(QApplication::translate("DataViewer", "Data Tools", 0, QApplication::UnicodeUTF8));
        snapshotToolBar->setWindowTitle(QApplication::translate("DataViewer", "Misc. Tools", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DataViewer: public Ui_DataViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAVIEWER_H
