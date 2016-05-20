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
    AbstractLinkSql.h \
    AbstractUniqueSql.h \
    ArbreManager.h \
    AttributsLinkSql.h \
    AttributsMacroLinkSql.h \
    BaseInfoSql.h \
    InfoSql.h \
    LinkSql.h \
    LinkSqlArbre.h \
    LinkSqlDivers.h \
    LinkSqlNom.h \
    LinkSqlRelation.h \
    Manager.h \
    ManagerOf.h \
    ManagerSql.h \
    ReqSql.h \
    UniqueSql.h

SOURCES += \
    AbstractLinkSql.cpp \
    AbstractUniqueSql.cpp \
    ArbreManager.cpp \
    AttributsLinkSql.cpp \
    AttributsMacroLinkSql.cpp \
    BaseInfoSql.cpp \
    InfoSql.cpp \
    LinkSql.cpp \
    LinkSqlArbre.cpp \
    LinkSqlDivers.cpp \
    LinkSqlNom.cpp \
    LinkSqlRelation.cpp \
    Manager.cpp \
    ManagerOf.cpp \
    ManagerSql.cpp \
    ReqSql.cpp \
    UniqueSql.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
