#-------------------------------------------------
#
# Project created by QtCreator 2015-10-11T12:58:53
#
#-------------------------------------------------

TARGET = Widget
TEMPLATE = lib
CONFIG += staticlib

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    SpinBoxAnnee.cpp \
    SpinBoxNumClasse.cpp

HEADERS += \
    SpinBoxAnnee.h \
    SpinBoxNumClasse.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
