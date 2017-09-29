#-------------------------------------------------
#
# Project created by QtCreator 2015-09-18T07:58:47
#
#-------------------------------------------------

QT       += gui
QT      += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = Manager
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Entities/release/ -lEntities
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Entities/debug/ -lEntities
else:unix: LIBS += -L$$OUT_PWD/../Entities/ -lEntities

INCLUDEPATH += $$PWD/../Entities
DEPENDPATH += $$PWD/../Entities

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Entities/release/libEntities.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Entities/debug/libEntities.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Entities/release/Entities.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Entities/debug/Entities.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Entities/libEntities.a

HEADERS += \
    AbstractGestionAutorisation.h \
    AbstractLinkSql.h \
    AbstractManager.h \
    AbstractUniqueSql.h \
    GestionAutorisationCible.h \
    InfoBdd.h \
    InfoBddBase.h \
    ManagerArbre.h \
    ManagerOf.h \
    ManagerOfArbre.h \
    ManagerOfArbreModifControle.h \
    ManagerOfArbreSimple.h \
    ManagerOfArbreSimpleModifControle.h \
    ManagerOfModifControle.h \
    ManagerOfModifControlePermission.h \
    ManagerOfPermission.h \
    ManagerSql.h \
    ReqSql.h \
    UniqueSql.h \
    UniqueSqlBase.h \
    VersionBddManager.h

SOURCES += \
    AbstractGestionAutorisation.cpp \
    AbstractLinkSql.cpp \
    AbstractManager.cpp \
    AbstractUniqueSql.cpp \
    GestionAutorisationCible.cpp \
    InfoBdd.cpp \
    InfoBddBase.cpp \
    ManagerArbre.cpp \
    ManagerOf.cpp \
    ManagerOfArbre.cpp \
    ManagerOfArbreModifControle.cpp \
    ManagerOfArbreSimple.cpp \
    ManagerOfArbreSimpleModifControle.cpp \
    ManagerOfModifControle.cpp \
    ManagerOfModifControlePermission.cpp \
    ManagerOfPermission.cpp \
    ManagerSql.cpp \
    ReqSql.cpp \
    UniqueSql.cpp \
    UniqueSqlBase.cpp \
    VersionBddManager.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
