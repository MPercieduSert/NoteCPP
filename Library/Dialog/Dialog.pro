#-------------------------------------------------
#
# Project created by QtCreator 2015-10-11T12:53:00
#
#-------------------------------------------------

TARGET = Dialog
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11
QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Widget/release/ -lWidget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Widget/debug/ -lWidget
else:unix: LIBS += -L$$OUT_PWD/../Widget/ -lWidget

INCLUDEPATH += $$PWD/../Widget
DEPENDPATH += $$PWD/../Widget

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Widget/release/libWidget.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Widget/debug/libWidget.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Widget/release/Widget.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Widget/debug/Widget.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Widget/libWidget.a

SOURCES += \
    NewAnneeDialog.cpp \
    NewClasseDialog.cpp \
    NewControleDialog.cpp \
    NewEtablissementDialog.cpp \
    SelectAnneeDialog.cpp \
    SelectDonneeDialog.cpp \
    NewTypeControleDialog.cpp \
    ControleGraphDialog.cpp \
    NewMotCleDialog.cpp


HEADERS += \ 
    NewAnneeDialog.h \
    NewClasseDialog.h \
    NewControleDialog.h \
    NewEtablissementDialog.h \
    SelectAnneeDialog.h \
    SelectDonneeDialog.h \
    NewTypeControleDialog.h \
    ControleGraphDialog.h \
    NewMotCleDialog.h


unix {
    target.path = /usr/lib
    INSTALLS += target
}
