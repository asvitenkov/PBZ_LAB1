/********************************************************************************
** Form generated from reading UI file 'queryeditordialog.ui'
**
** Created: Mon 14. Nov 22:48:51 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYEDITORDIALOG_H
#define UI_QUERYEDITORDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueryEditorDialog
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *tableList;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QListView *columnView;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *addAllButton;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *removeAllButton;
    QSpacerItem *verticalSpacer;
    QListView *selectView;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QRadioButton *andButton;
    QRadioButton *orButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *moreButton;
    QPushButton *lessButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QueryEditorDialog)
    {
        if (QueryEditorDialog->objectName().isEmpty())
            QueryEditorDialog->setObjectName(QString::fromUtf8("QueryEditorDialog"));
        QueryEditorDialog->resize(388, 398);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/db_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        QueryEditorDialog->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(QueryEditorDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(QueryEditorDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        tableList = new QComboBox(QueryEditorDialog);
        tableList->setObjectName(QString::fromUtf8("tableList"));

        horizontalLayout->addWidget(tableList);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        tabWidget = new QTabWidget(QueryEditorDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        columnView = new QListView(tab);
        columnView->setObjectName(QString::fromUtf8("columnView"));
        columnView->setSelectionMode(QAbstractItemView::MultiSelection);

        gridLayout->addWidget(columnView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        addAllButton = new QPushButton(tab);
        addAllButton->setObjectName(QString::fromUtf8("addAllButton"));

        verticalLayout->addWidget(addAllButton);

        addButton = new QPushButton(tab);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout->addWidget(addButton);

        removeButton = new QPushButton(tab);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        verticalLayout->addWidget(removeButton);

        removeAllButton = new QPushButton(tab);
        removeAllButton->setObjectName(QString::fromUtf8("removeAllButton"));

        verticalLayout->addWidget(removeAllButton);

        verticalSpacer = new QSpacerItem(20, 27, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        selectView = new QListView(tab);
        selectView->setObjectName(QString::fromUtf8("selectView"));
        selectView->setSelectionMode(QAbstractItemView::MultiSelection);

        gridLayout->addWidget(selectView, 0, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        andButton = new QRadioButton(tab_2);
        andButton->setObjectName(QString::fromUtf8("andButton"));
        andButton->setChecked(true);

        gridLayout_3->addWidget(andButton, 0, 0, 1, 1);

        orButton = new QRadioButton(tab_2);
        orButton->setObjectName(QString::fromUtf8("orButton"));

        gridLayout_3->addWidget(orButton, 1, 0, 1, 1);

        scrollArea = new QScrollArea(tab_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 344, 200));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(284, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        moreButton = new QPushButton(tab_2);
        moreButton->setObjectName(QString::fromUtf8("moreButton"));

        horizontalLayout_2->addWidget(moreButton);

        lessButton = new QPushButton(tab_2);
        lessButton->setObjectName(QString::fromUtf8("lessButton"));
        lessButton->setEnabled(false);

        horizontalLayout_2->addWidget(lessButton);


        gridLayout_3->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(QueryEditorDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(QueryEditorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QueryEditorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QueryEditorDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QueryEditorDialog);
    } // setupUi

    void retranslateUi(QDialog *QueryEditorDialog)
    {
        QueryEditorDialog->setWindowTitle(QApplication::translate("QueryEditorDialog", "Build Query", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QueryEditorDialog", "Table to Query:", 0, QApplication::UnicodeUTF8));
        addAllButton->setText(QApplication::translate("QueryEditorDialog", ">>", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("QueryEditorDialog", ">", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("QueryEditorDialog", "<", 0, QApplication::UnicodeUTF8));
        removeAllButton->setText(QApplication::translate("QueryEditorDialog", "<<", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("QueryEditorDialog", "Fields", 0, QApplication::UnicodeUTF8));
        andButton->setText(QApplication::translate("QueryEditorDialog", "Match all of the following terms", 0, QApplication::UnicodeUTF8));
        orButton->setText(QApplication::translate("QueryEditorDialog", "Match any of the following terms", 0, QApplication::UnicodeUTF8));
        moreButton->setText(QApplication::translate("QueryEditorDialog", "More", 0, QApplication::UnicodeUTF8));
        lessButton->setText(QApplication::translate("QueryEditorDialog", "Less", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("QueryEditorDialog", "Terms", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QueryEditorDialog: public Ui_QueryEditorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYEDITORDIALOG_H
