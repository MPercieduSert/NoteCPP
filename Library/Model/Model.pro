#-------------------------------------------------
#
# Project created by QtCreator 2015-11-13T18:30:56
#
#-------------------------------------------------

QT       +=core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Model
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Div/release/ -lDiv
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Div/debug/ -lDiv
else:unix: LIBS += -L$$OUT_PWD/../Div/ -lDiv

INCLUDEPATH += $$PWD/../Div
DEPENDPATH += $$PWD/../Div

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Div/release/libDiv.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Div/debug/libDiv.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Div/release/Div.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Div/debug/Div.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Div/libDiv.a


SOURCES += \
    ListeEleveModel.cpp \
    MAbstractTableModel.cpp \
    MAbstractTreeModel.cpp \
    TreeModelReadTemp.cpp \
    TreeModelTemp.cpp

HEADERS += \
    ListeEleveModel.h \
    MAbstractTableModel.h \
    MAbstractTreeModel.h \
    TreeModelReadTemp.h \
    TreeModelTemp.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
