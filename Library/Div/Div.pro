TEMPLATE = lib
TARGET = Div
CONFIG += staticlib
CONFIG += c++11
QT  += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Xml/release/ -lXml
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Xml/debug/ -lXml
else:unix: LIBS += -L$$OUT_PWD/../Xml/ -lXml

INCLUDEPATH += $$PWD/../Xml
DEPENDPATH += $$PWD/../Xml

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Xml/release/libXml.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Xml/debug/libXml.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Xml/release/Xml.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Xml/debug/Xml.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Xml/libXml.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Manager/release/ -lManager
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Manager/debug/ -lManager
else:unix: LIBS += -L$$OUT_PWD/../Manager/ -lManager

INCLUDEPATH += $$PWD/../Manager
DEPENDPATH += $$PWD/../Manager

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Manager/release/libManager.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Manager/debug/libManager.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Manager/release/Manager.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Manager/debug/Manager.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Manager/libManager.a

HEADERS += \
    AbstractBdd.h \
    AbstractManagers.h \
    Bdd.h \
    Config.h \
    FileInterface.h \
    Macro.h \
    Managers.h \
    Tree.h \
    TreeItem.h

SOURCES += \
    AbstractBdd.cpp \
    AbstractManagers.cpp \
    Bdd.cpp \
    Config.cpp \
    FileInterface.cpp \
    Managers.cpp \
    Tree.cpp \
    TreeItem.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}


