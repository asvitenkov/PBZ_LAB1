#-------------------------------------------------
#
# Project created by QtCreator 2011-10-30T20:24:40
#
#-------------------------------------------------

QT       += core gui\
            sql

TARGET = PBZ_LAB1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tablesviewer.cpp \
    queryeditordialog.cpp \
    schemabrowser.cpp \
    extensionmodel.cpp \
    utils.cpp \
    tabletree.cpp \
    dataviewer.cpp \
    sqlmodels.cpp \
    blobpreviewwidget.cpp \
    sqlitemview.cpp \
    preferences.cpp \
    amounofmuscompofgroup.cpp

HEADERS  += mainwindow.h \
    tablesviewer.h \
    queryeditordialog.h \
    schemabrowser.h \
    extensionmodel.h \
    tabletree.h \
    utils.h \
    sqlmodels.h \
    blobpreviewwidget.h \
    sqlitemview.h \
    dataviewer.h \
    preferences.h \
    ui_dataviewer.h \
    QDwmWindow.hh \
    MinGWFix.hh \
    ui_mainwindow.h \
    amounofmuscompofgroup.h


FORMS    += mainwindow.ui \
    tablesviewer.ui \
    queryeditordialog.ui \
    schemabrowser.ui \
    dataviewer.ui \
    blobpreviewwidget.ui \
    sqlitemview.ui \
    amounofmuscompofgroup.ui

RESOURCES += \
    icons/icons.qrc \
    ts/ts.qrc





  DEFINES += _QDWM_MINGW
















































































