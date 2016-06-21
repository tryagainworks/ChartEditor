#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T12:17:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChartEditor
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    clspdf.cpp \
    myqgraphicsrectitem.cpp \
    myqgraphicsellipseitem.cpp \
    mygraphicsitem.cpp \
    myqgraphicslineitem.cpp \
    mygraphicsitem1.cpp \
    clsglobalvariables.cpp \
    clswritesettings.cpp \
    clsloadsettings.cpp \
    dlgpreview.cpp \
    clsglobal.cpp

HEADERS  += mainwindow.h \
    clspdf.h \
    myqgraphicsrectitem.h \
    myqgraphicsellipseitem.h \
    mygraphicsitem.h \
    myqgraphicslineitem.h \
    clsglobalvariables.h \
    clswritesettings.h \
    clsloadsettings.h \
    dlgpreview.h \
    clsglobal.h

FORMS    += mainwindow.ui \
    dlgpreview.ui

CONFIG += c++11

RESOURCES += \
    resource.qrc
