#-------------------------------------------------
#
# Project created by QtCreator 2016-09-07T18:02:58
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QThreadTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    worker.cpp

HEADERS  += mainwindow.h \
    worker.h

FORMS    += mainwindow.ui
