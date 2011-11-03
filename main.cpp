#include <QtGui/QApplication>
#include <QTranslator>
#include "mainwindow.h"

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    QTranslator translator;
    translator.load(":/ts/sqliteman_ru");
    a.installTranslator(&translator);

    QApplication::setStyle("plastique");
    QApplication::setPalette(QApplication::style()->standardPalette());

    MainWindow w;
    w.show();


    return a.exec();
}
