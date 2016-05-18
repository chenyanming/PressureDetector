#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T14:55:46
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PressureDetector
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    console.cpp

HEADERS  += mainwindow.h \
    console.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
