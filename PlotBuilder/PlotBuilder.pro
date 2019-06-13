#-------------------------------------------------
#
# Project created by QtCreator 2019-06-10T19:20:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlotBuilder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    keypress.cpp \
    realtimeplot.cpp

HEADERS  += mainwindow.h \
    keypress.h \
    realtimeplot.h

FORMS    += mainwindow.ui
