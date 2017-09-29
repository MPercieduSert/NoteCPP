#-------------------------------------------------
#
# Project created by QtCreator 2015-10-11T12:58:53
#
#-------------------------------------------------

TARGET = Widget
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11
QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    BarPlotter.cpp \
    EditTreeWidget.cpp \
    HeaderView.cpp \
    Histogramme.cpp \
    MotCleWidget.cpp \
    Plotter.cpp \
    ReadTreeWidget.cpp \
    SelectInListBox.cpp \
    SpinBoxAnnee.cpp \
    SpinBoxDecimale.cpp \
    SpinBoxNote.cpp \
    SpinBoxNumExclu.cpp

HEADERS += \
    BarPlotter.h \
    EditTreeWidget.h \
    HeaderView.h \
    Histogramme.h \
    MotCleWidget.h \
    Plotter.h \
    ReadTreeWidget.h \
    SelectInListBox.h \
    SpinBoxAnnee.h \
    SpinBoxDecimale.h \
    SpinBoxNote.h \
    SpinBoxNumExclu.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
