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
    AttributMultiple.h \
    AttributSimple.h \
    Classe.h \
    ClasseEleve.h \
    Controle.h \
    DonneeCard.h \
    Donnee.h \
    Eleve.h \
    Entity.h \
    EntityCible.h \
    EntityComplexe.h \
    EntityDivers.h \
    EntityOfDefaultType.h \
    EntityRelation.h \
    Groupe.h \
    InfoEntity.h \
    InfoEntityBase.h \
    MotCle.h \
    Niveau.h \
    TypeControle.h \
    TypeEtablissement.h \
    TypeNiveau.h \
    VersionBdd.h






SOURCES += \
    Annee.cpp \
    Arbre.cpp \
    AttributMultiple.cpp \
    AttributSimple.cpp \
    Classe.cpp \
    ClasseEleve.cpp \
    Controle.cpp \
    Donnee.cpp \
    DonneeCard.cpp \
    Eleve.cpp \
    Entity.cpp \
    EntityCible.cpp \
    EntityComplexe.cpp \
    EntityDivers.cpp \
    EntityOfDefaultType.cpp \
    EntityRelation.cpp \
    Groupe.cpp \
    InfoEntity.cpp \
    InfoEntityBase.cpp \
    MotCle.cpp \
    Niveau.cpp \
    TypeControle.cpp \
    TypeEtablissement.cpp \
    TypeNiveau.cpp \
    VersionBdd.cpp





unix {
    target.path = /usr/lib
    INSTALLS += target
}
