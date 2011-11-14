/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 14. Nov 22:47:23 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *exitAction;
    QAction *createQueryAction;
    QAction *amountOfCompositionAction;
    QAction *listOfAllGroupAlbumsAction;
    QAction *topSalesAction;
    QAction *addAlbumAction;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *myLayout;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/database_mw.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        createQueryAction = new QAction(MainWindow);
        createQueryAction->setObjectName(QString::fromUtf8("createQueryAction"));
        amountOfCompositionAction = new QAction(MainWindow);
        amountOfCompositionAction->setObjectName(QString::fromUtf8("amountOfCompositionAction"));
        listOfAllGroupAlbumsAction = new QAction(MainWindow);
        listOfAllGroupAlbumsAction->setObjectName(QString::fromUtf8("listOfAllGroupAlbumsAction"));
        topSalesAction = new QAction(MainWindow);
        topSalesAction->setObjectName(QString::fromUtf8("topSalesAction"));
        addAlbumAction = new QAction(MainWindow);
        addAlbumAction->setObjectName(QString::fromUtf8("addAlbumAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("#centralWidget{\n"
"background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(104, 146, 255, 39), stop:1 rgba(158, 185, 255, 21))\n"
"}\n"
"\n"
"\n"
""));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        myLayout = new QHBoxLayout();
        myLayout->setSpacing(6);
        myLayout->setObjectName(QString::fromUtf8("myLayout"));

        gridLayout->addLayout(myLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(exitAction);
        menu_2->addAction(createQueryAction);
        menu_2->addAction(addAlbumAction);
        menu_3->addAction(amountOfCompositionAction);
        menu_3->addAction(listOfAllGroupAlbumsAction);
        menu_3->addAction(topSalesAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\234\321\203\320\267\321\213\320\272\320\260\320\273\321\214\320\275\321\213\320\271 \320\274\320\260\320\263\320\260\320\267\320\270\320\275", 0, QApplication::UnicodeUTF8));
        exitAction->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        exitAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        createQueryAction->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\267\320\260\320\277\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        amountOfCompositionAction->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\321\200\320\276\320\270\320\267\320\262\320\265\320\264\320\265\320\275\320\270\320\271 \320\263\321\200\321\203\320\277\320\277\321\213", 0, QApplication::UnicodeUTF8));
        listOfAllGroupAlbumsAction->setText(QApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\264\320\270\321\201\320\272\320\276\320\262 \320\263\321\200\321\203\320\277\320\277\321\213", 0, QApplication::UnicodeUTF8));
        topSalesAction->setText(QApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\273\320\270\320\264\320\265\321\200\320\276\320\262 \320\277\321\200\320\276\320\264\320\260\320\266 \321\202\320\265\320\272\321\203\321\211\320\265\320\263\320\276 \320\263\320\276\320\264\320\260", 0, QApplication::UnicodeUTF8));
        addAlbumAction->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\260\320\273\321\214\320\261\320\276\320\274", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\200\320\276\321\201\321\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
