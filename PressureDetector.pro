#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T14:55:46
#
#-------------------------------------------------

QT       += core gui serialport
CONFIG   += qwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PressureDetector
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    console.cpp \
    samplingthread.cpp \
    signaldata.cpp \
    plot.cpp \
    curvedata.cpp

HEADERS  += mainwindow.h \
    console.h \
    samplingthread.h \
    signaldata.h \
    plot.h \
    curvedata.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
