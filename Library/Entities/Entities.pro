#-------------------------------------------------
#
# Project created by QtCreator 2015-09-07T22:00:47
#
#-------------------------------------------------

QT       += core

TARGET = Entities
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11
HEADERS += \
    Annee.h \
    Arbre.h \
    Attribut.h \
    AttributEntity.h \
    AttributEntityAlias.h \
    AttributEntityMacroAlias.h \
    Classe.h \
    ClasseEleve.h \
    Donnee.h \
    Eleve.h \
    Entity.h \
    EntityDivers.h \
    EntityNom.h \
    EntityRelation.h \
    Groupe.h \
    InfoEntity.h \
    ListEntities.h \
    Niveau.h \
    Relations.h


unix {
    target.path = /usr/lib
    INSTALLS += target
}

SOURCES += \
    Annee.cpp \
    Arbre.cpp \
    Attribut.cpp \
    AttributEntity.cpp \
    AttributEntityAlias.cpp \
    AttributEntityMacroAlias.cpp \
    Classe.cpp \
    ClasseEleve.cpp \
    Donnee.cpp \
    Eleve.cpp \
    Entity.cpp \
    EntityDivers.cpp \
    EntityNom.cpp \
    EntityRelation.cpp \
    Groupe.cpp \
    InfoEntity.cpp \
    ListEntities.cpp \
    Niveau.cpp \
    Relations.cpp
