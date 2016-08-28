#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T14:55:46
#
#-------------------------------------------------

QT       += core gui serialport printsupport
CONFIG   += qwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PressureDetector
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    console.cpp \
    samplingthread.cpp \
    curvedata.cpp \
    plot.cpp \
    log.cpp \
    data.cpp


HEADERS  += mainwindow.h \
    console.h \
    curvedata.h \
    samplingthread.h \
    plot.h \
    log.h \
    data.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
