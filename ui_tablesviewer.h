/********************************************************************************
** Form generated from reading UI file 'tablesviewer.ui'
**
** Created: Mon 31. Oct 13:49:08 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLESVIEWER_H
#define UI_TABLESVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TablesViewer
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QComboBox *tablesList;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_3;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_4;
    QPushButton *buttonAddRowInTable;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TablesViewer)
    {
        if (TablesViewer->objectName().isEmpty())
            TablesViewer->setObjectName(QString::fromUtf8("TablesViewer"));
        TablesViewer->resize(588, 415);
        centralwidget = new QWidget(TablesViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tablesList = new QComboBox(centralwidget);
        tablesList->setObjectName(QString::fromUtf8("tablesList"));

        verticalLayout_3->addWidget(tablesList);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_3->addWidget(tableView, 0, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        buttonAddRowInTable = new QPushButton(centralwidget);
        buttonAddRowInTable->setObjectName(QString::fromUtf8("buttonAddRowInTable"));

        verticalLayout_4->addWidget(buttonAddRowInTable);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        TablesViewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TablesViewer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 588, 22));
        TablesViewer->setMenuBar(menubar);
        statusbar = new QStatusBar(TablesViewer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TablesViewer->setStatusBar(statusbar);

        retranslateUi(TablesViewer);

        QMetaObject::connectSlotsByName(TablesViewer);
    } // setupUi

    void retranslateUi(QMainWindow *TablesViewer)
    {
        TablesViewer->setWindowTitle(QApplication::translate("TablesViewer", "MainWindow", 0, QApplication::UnicodeUTF8));
        buttonAddRowInTable->setText(QApplication::translate("TablesViewer", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214\n"
"\321\201\321\202\321\200\320\276\320\272\321\203", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TablesViewer: public Ui_TablesViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLESVIEWER_H
