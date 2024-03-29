/********************************************************************************
** Form generated from reading UI file 'schemabrowser.ui'
**
** Created: Tue 1. Nov 18:45:02 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEMABROWSER_H
#define UI_SCHEMABROWSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>
#include "tabletree.h"

QT_BEGIN_NAMESPACE

class Ui_SchemaBrowser
{
public:
    QGridLayout *gridLayout;
    QTabWidget *schemaTabWidget;
    QWidget *schemaTab;
    QGridLayout *gridLayout1;
    TableTree *tableTree;
    QWidget *pragmaTab;
    QGridLayout *gridLayout2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout3;
    QLineEdit *pragmaName;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *pragmaValue;
    QPushButton *setPragmaButton;
    QTableWidget *pragmaTable;
    QWidget *extensionTab;
    QGridLayout *gridLayout4;
    QTableView *extensionTableView;

    void setupUi(QWidget *SchemaBrowser)
    {
        if (SchemaBrowser->objectName().isEmpty())
            SchemaBrowser->setObjectName(QString::fromUtf8("SchemaBrowser"));
        SchemaBrowser->resize(271, 721);
        gridLayout = new QGridLayout(SchemaBrowser);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        schemaTabWidget = new QTabWidget(SchemaBrowser);
        schemaTabWidget->setObjectName(QString::fromUtf8("schemaTabWidget"));
        schemaTab = new QWidget();
        schemaTab->setObjectName(QString::fromUtf8("schemaTab"));
        gridLayout1 = new QGridLayout(schemaTab);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        tableTree = new TableTree(schemaTab);
        tableTree->setObjectName(QString::fromUtf8("tableTree"));

        gridLayout1->addWidget(tableTree, 0, 0, 1, 1);

        schemaTabWidget->addTab(schemaTab, QString());
        pragmaTab = new QWidget();
        pragmaTab->setObjectName(QString::fromUtf8("pragmaTab"));
        gridLayout2 = new QGridLayout(pragmaTab);
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        groupBox = new QGroupBox(pragmaTab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout3 = new QGridLayout(groupBox);
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        pragmaName = new QLineEdit(groupBox);
        pragmaName->setObjectName(QString::fromUtf8("pragmaName"));
        pragmaName->setReadOnly(true);

        gridLayout3->addWidget(pragmaName, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout3->addWidget(label_4, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout3->addWidget(label_2, 0, 0, 1, 1);

        pragmaValue = new QLineEdit(groupBox);
        pragmaValue->setObjectName(QString::fromUtf8("pragmaValue"));
        pragmaValue->setReadOnly(true);

        gridLayout3->addWidget(pragmaValue, 3, 0, 1, 1);

        setPragmaButton = new QPushButton(groupBox);
        setPragmaButton->setObjectName(QString::fromUtf8("setPragmaButton"));

        gridLayout3->addWidget(setPragmaButton, 4, 0, 1, 1);


        gridLayout2->addWidget(groupBox, 1, 0, 1, 1);

        pragmaTable = new QTableWidget(pragmaTab);
        if (pragmaTable->columnCount() < 2)
            pragmaTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        pragmaTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        pragmaTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        pragmaTable->setObjectName(QString::fromUtf8("pragmaTable"));
        pragmaTable->setAlternatingRowColors(true);
        pragmaTable->setSelectionMode(QAbstractItemView::SingleSelection);
        pragmaTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        pragmaTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout2->addWidget(pragmaTable, 0, 0, 1, 1);

        schemaTabWidget->addTab(pragmaTab, QString());
        extensionTab = new QWidget();
        extensionTab->setObjectName(QString::fromUtf8("extensionTab"));
        gridLayout4 = new QGridLayout(extensionTab);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        extensionTableView = new QTableView(extensionTab);
        extensionTableView->setObjectName(QString::fromUtf8("extensionTableView"));
        extensionTableView->setAlternatingRowColors(true);
        extensionTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout4->addWidget(extensionTableView, 0, 0, 1, 1);

        //schemaTabWidget->addTab(extensionTab, QString());

        gridLayout->addWidget(schemaTabWidget, 0, 0, 1, 1);


        retranslateUi(SchemaBrowser);

        schemaTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SchemaBrowser);
    } // setupUi

    void retranslateUi(QWidget *SchemaBrowser)
    {
        SchemaBrowser->setWindowTitle(QApplication::translate("SchemaBrowser", "Form", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = tableTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("SchemaBrowser", "Database", 0, QApplication::UnicodeUTF8));
        schemaTabWidget->setTabText(schemaTabWidget->indexOf(schemaTab), QApplication::translate("SchemaBrowser", "Sche&ma", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SchemaBrowser", "Detail", 0, QApplication::UnicodeUTF8));
        pragmaName->setText(QString());
        label_4->setText(QApplication::translate("SchemaBrowser", "Value:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SchemaBrowser", "Pragma:", 0, QApplication::UnicodeUTF8));
        pragmaValue->setText(QString());
        setPragmaButton->setText(QApplication::translate("SchemaBrowser", "Change &Value...", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = pragmaTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SchemaBrowser", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = pragmaTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SchemaBrowser", "Value", 0, QApplication::UnicodeUTF8));
        schemaTabWidget->setTabText(schemaTabWidget->indexOf(pragmaTab), QApplication::translate("SchemaBrowser", "&Pragmas", 0, QApplication::UnicodeUTF8));
        schemaTabWidget->setTabText(schemaTabWidget->indexOf(extensionTab), QApplication::translate("SchemaBrowser", "E&xtensions", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SchemaBrowser: public Ui_SchemaBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEMABROWSER_H
