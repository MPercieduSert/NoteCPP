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


#HEADERS += \
#    ../Entities/Annee.h \
#    ../Entities/Appreciation.h \
#    ../Entities/Attribut.h \
#    ../Entities/Attribut_bareme.h \
#    ../Entities/Attribut_exercice.h \
#    ../Entities/Bareme.h \
#    ../Entities/Classe.h \
#    ../Entities/Commentaire.h \
#    ../Entities/Coefficient.h \
#    ../Entities/Controle.h \
#    ../Entities/Controle_exercice.h \
#    ../Entities/Eleve.h \
#    ../Entities/Eleve_groupe.h \
#    ../Entities/Entity.h \
#    ../Entities/EntityAnnee.h \
#    ../Entities/Exercice.h \
#    ../Entities/Groupe.h \
#    ../Entities/ListEntities.h \
#    ../Entities/Note.h \
#    ../Entities/NumControle.h \
#    ../Entities/Niveau.h \
#    ../Entities/Point.h \
#    ../Entities/Source.h \
#    ../Entities/TypeControle.h \
#    ../Entities/TypeGroupe.h \
#    ../Entities/TypeNiveau.h \



#SOURCES += \
#    ../Entities/Annee.cpp \
#    ../Entities/Appreciation.cpp \
#    ../Entities/Attribut.cpp \
#    ../Entities/Attribut_bareme.cpp \
#    ../Entities/Attribut_exercice.cpp \
#    ../Entities/Bareme.cpp \
#    ../Entities/Classe.cpp \
#    ../Entities/Commentaire.cpp \
#    ../Entities/Coefficient.cpp \
#    ../Entities/Controle.cpp \
#    ../Entities/Controle_exercice.cpp \
#    ../Entities/Eleve.cpp \
#    ../Entities/Eleve_groupe.cpp \
#    ../Entities/Entity.cpp \
#    ../Entities/EntityAnnee.cpp \
#    ../Entities/Exercice.cpp \
#    ../Entities/Groupe.cpp \
#    ../Entities/ListEntities.cpp \
#    ../Entities/Note.cpp \
#    ../Entities/NumControle.cpp \
#    ../Entities/Niveau.cpp \
#    ../Entities/Point.cpp \
#    ../Entities/Source.cpp \
#    ../Entities/TypeControle.cpp \
#    ../Entities/TypeGroupe.cpp \
#    ../Entities/TypeNiveau.cpp \



HEADERS += \
#    AppreciationManager.h \
#    AttributManager.h \
#    Attribut_baremeManager.h \
#    Attribut_exerciceManager.h \
#    BaremeManager.h \
#    ClasseManager.h \
#    CoefficientManager.h \
#    CommentaireManager.h \
#    ControleManager.h \
#    Controle_exerciceManager.h \
#    EleveManager.h \
#    Eleve_groupeManager.h \
#    ExerciceManager.h \
#    GroupeManager.h \
#    NiveauManager.h \
#    NoteManager.h \
#    NumControleManager.h \
    Manager.h \
    ManagerSql.h \
    LinkSql.h \
    ArbreLinkSql.h \
    AnneeLinkSql.h
#    ManagerAnnee.h \
#    PointManager.h \
#    SourceManager.h \
#    TypeControleManager.h \
#    TypeGroupeManager.h \
#    TypeNiveauManager.h \



SOURCES += \
#    AppreciationManager.cpp \
#    AttributManager.cpp \
#    Attribut_baremeManager.cpp \
#    Attribut_exerciceManager.cpp \
#    BaremeManager.cpp \
#    ClasseManager.cpp \
#    CoefficientManager.cpp \
#    CommentaireManager.cpp \
#    ControleManager.cpp \
#    Controle_exerciceManager.cpp \
#    EleveManager.cpp \
#    Eleve_groupeManager.cpp \
#    ExerciceManager.cpp \
#    GroupeManager.cpp \
#    NiveauManager.cpp \
#    NoteManager.cpp \
#    NumControleManager.cpp \
    Manager.cpp \
    ManagerSql.cpp \
    AnneeLinkBdd.cpp \
    LinkSql.cpp \
    ArbreLinkSql.cpp
#    ManagerAnnee.cpp \
#    PointManager.cpp \
#    SourceManager.cpp \
#    TypeControleManager.cpp \
#    TypeGroupeManager.cpp \
#    TypeNiveauManager.cpp \


unix {
    target.path = /usr/lib
    INSTALLS += target
}
