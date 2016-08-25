#-------------------------------------------------
#
# Project created by QtCreator 2015-09-07T22:00:47
#
#-------------------------------------------------

QT       += core

TARGET = Entities
QT       += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11
HEADERS += \
    Annee.h \
    Arbre.h \
    Attribut.h \
    AttributEntity.h \
    Classe.h \
    ClasseEleve.h \
    Donnee.h \
    Eleve.h \
    Entity.h \
    EntityDivers.h \
    EntityNom.h \
    EntityOfDefaultType.h \
    EntityRelation.h \
    Groupe.h \
    InfoEntity.h \
    InfoEntityBase.h \
    ListEntities.h \
    Niveau.h \
    TypeEtablissement.h \
    TypeNiveau.h \
    VectorEntities.h \
    VersionBdd.h

SOURCES += \
    Annee.cpp \
    Arbre.cpp \
    Attribut.cpp \
    AttributEntity.cpp \
    Classe.cpp \
    ClasseEleve.cpp \
    Donnee.cpp \
    Eleve.cpp \
    Entity.cpp \
    EntityDivers.cpp \
    EntityNom.cpp \
    EntityOfDefaultType.cpp \
    EntityRelation.cpp \
    Groupe.cpp \
    InfoEntity.cpp \
    InfoEntityBase.cpp \
    ListEntities.cpp \
    Niveau.cpp \
    TypeEtablissement.cpp \
    TypeNiveau.cpp \
    VectorEntities.cpp \
    VersionBdd.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
