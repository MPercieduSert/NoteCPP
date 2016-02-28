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
#    Appreciation.h \
#    Attribut.h \
#    Attribut_bareme.h \
#    Attribut_exercice.h \
#    Bareme.h \
#    Classe.h \
#    Commentaire.h \
#    Coefficient.h \
#    Controle.h \
#    Controle_exercice.h \
#    Eleve.h \
#    Eleve_groupe.h \
    Entity.h \
#    EntityAnnee.h \
    Exercice.h \
#    Groupe.h \
#    Note.h \
#    NumControle.h \
#    Niveau.h \
#    Point.h \
#    TypeControle.h \
#    TypeGroupe.h \
#    TypeNiveau.h \
#    ListEntities.h \
#    Source.h
    ArbreEntity.h

SOURCES += \
    Annee.cpp \
#    Appreciation.cpp \
#    Attribut.cpp \
#    Attribut_bareme.cpp \
#    Attribut_exercice.cpp \
#    Bareme.cpp \
#    Classe.cpp \
#    Commentaire.cpp \
#    Coefficient.cpp \
#    Controle.cpp \
#    Controle_exercice.cpp \
#    Eleve.cpp \
#    Eleve_groupe.cpp \
    Entity.cpp \
#    EntityAnnee.cpp \
    Exercice.cpp \
#    Groupe.cpp \
#    Note.cpp \
#    NumControle.cpp \
#    Niveau.cpp \
#    Point.cpp \
#    TypeControle.cpp \
#    TypeGroupe.cpp \
#    TypeNiveau.cpp \
#    ListEntities.cpp \
#    Source.cpp
    ArbreEntity.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
