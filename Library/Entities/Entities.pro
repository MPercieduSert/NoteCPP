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
    Arbres.h \
    Attribut.h \
    AttributEntity.h \
    AttributEntityAlias.h \
    AttributEntityMacroAlias.h \
#    Bareme.h \
    Classe.h \
    ClasseEleve.h \
#    Coefficient.h \
    Commentaire.h \
#    Controle.h \
    Donnee.h \
    Eleve.h \
    Entity.h \
    EntityDivers.h \
    EntityNom.h \
    EntityRelation.h \
    Etablissement.h \
#    Exercice.h \
    Groupe.h \
    InfoEntity.h \
    ListEntities.h \
    Niveau.h \
#    Note.h \
#    NumControle.h \
#    Point.h \
    Relation.h \
    Relations.h \
    Source.h \
#    TypeControle.h \
#    TypeGroupe.h \
    TypeNiveau.h

SOURCES += \
    Annee.cpp \
    Attribut.cpp \
#    Bareme.cpp \
    Classe.cpp \
    ClasseEleve.cpp \
#    Coefficient.cpp \
    Commentaire.cpp \
#    Controle.cpp \
    Donnee.cpp \
    Eleve.cpp \
    Etablissement.cpp \
    Entity.cpp \
#    Exercice.cpp \
    Groupe.cpp \
    ListEntities.cpp \
    Niveau.cpp \
#    Note.cpp \
#    NumControle.cpp \
#    Point.cpp \
    Source.cpp \
#    TypeControle.cpp \
#    TypeGroupe.cpp \
    TypeNiveau.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
