#-------------------------------------------------
#
# Project created by QtCreator 2015-10-11T12:58:53
#
#-------------------------------------------------

TARGET = Widget
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    Plotter.cpp \
    ReadTreeWidget.cpp \
    SelectInListBox.cpp \
    SpinBoxAnnee.cpp \
    SpinBoxDecimale.cpp \
    SpinBoxNumExclu.cpp \
    HeaderView.cpp \
    SpinBoxNote.cpp \
    BarPlotter.cpp \
    Histogramme.cpp \
    EditTreeWidget.cpp


HEADERS += \
    Plotter.h \
    ReadTreeWidget.h \
    SelectInListBox.h \
    SpinBoxAnnee.h \
    SpinBoxDecimale.h \
    SpinBoxNumExclu.h \
    HeaderView.h \
    SpinBoxNote.h \
    BarPlotter.h \
    Histogramme.h \
    EditTreeWidget.h



unix {
    target.path = /usr/lib
    INSTALLS += target
}
