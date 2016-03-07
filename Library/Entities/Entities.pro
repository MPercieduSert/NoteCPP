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
    ArbreEntity.h \
    Attribut.h \
    Bareme.h \
    Classe.h \
    Commentaire.h \
    Coefficient.h \
    Controle.h \
    Donnee.h \
    Eleve.h \
#    Eleve_groupe.h \
    Entity.h \
    Exercice.h \
    Groupe.h \
    ListEntities.h \
#    Note.h \
#    NumControle.h \
    Niveau.h \
#    Point.h \
    Source.h \
    RelSimple.h \
#    TypeControle.h \
#    TypeGroupe.h \
    TypeNiveau.h \
    RelDate.h \
    Etablissement.h \
    ClasseEleve.h \
    RelNum.h \
    RelDateVal.h


SOURCES += \
    Annee.cpp \
    ArbreEntity.cpp \
    Attribut.cpp \
    Bareme.cpp \
    Classe.cpp \
    Commentaire.cpp \
    Coefficient.cpp \
    Controle.cpp \
    Donnee.cpp \
    Eleve.cpp \
#    Eleve_groupe.cpp \
    Entity.cpp \
    Exercice.cpp \
    Groupe.cpp \
    ListEntities.cpp \
#    Note.cpp \
#    NumControle.cpp \
    Niveau.cpp \
#    Point.cpp \
    Source.cpp \
    RelSimple.cpp \
#    TypeControle.cpp \
#    TypeGroupe.cpp \
    TypeNiveau.cpp \
    RelDate.cpp \
    Etablissement.cpp \
    ClasseEleve.cpp \
    RelNum.cpp \
    RelDateVal.cpp



unix {
    target.path = /usr/lib
    INSTALLS += target
}
