#-------------------------------------------------
#
# Project created by QtCreator 2015-08-29T12:00:45
#
#-------------------------------------------------



TEMPLATE = app
TARGET = App

QT  += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    ../Library/Delegate/Delegate.cpp \
    ../Library/Delegate/ListeEleveDelegate.cpp \
    ../Library/Dialog/NewAnneeDialog.cpp \
    ../Library/Dialog/NewClasseDialog.cpp \
    ../Library/Dialog/SelectAnneeDialog.cpp \
    ../Library/Div/Bdd.cpp \
    ../Library/Div/Config.cpp \
    ../Library/Div/FileInterface.cpp \
    ../Library/Div/Tree.cpp \
    ../Library/Div/TreeItem.cpp \
#    ../Library/Entities/Annee.cpp \
#    ../Library/Entities/Appreciation.cpp \
#    ../Library/Entities/Attribut.cpp \
#    ../Library/Entities/Attribut_bareme.cpp \
#    ../Library/Entities/Attribut_exercice.cpp \
#    ../Library/Entities/Bareme.cpp \
#    ../Library/Entities/Classe.cpp \
#    ../Library/Entities/Coefficient.cpp \
#    ../Library/Entities/Commentaire.cpp \
#    ../Library/Entities/Controle.cpp \
#    ../Library/Entities/Controle_exercice.cpp \
#    ../Library/Entities/Eleve.cpp \
#    ../Library/Entities/Eleve_groupe.cpp \
    ../Library/Entities/Entity.cpp \
#    ../Library/Entities/EntityAnnee.cpp \
#    ../Library/Entities/Exercice.cpp \
#    ../Library/Entities/Groupe.cpp \
#    ../Library/Entities/ListEntities.cpp \
#    ../Library/Entities/Niveau.cpp \
#    ../Library/Entities/Note.cpp \
#    ../Library/Entities/NumControle.cpp \
#    ../Library/Entities/Point.cpp \
#    ../Library/Entities/Source.cpp \
#    ../Library/Entities/TypeControle.cpp \
#    ../Library/Entities/TypeGroupe.cpp \
#    ../Library/Entities/TypeNiveau.cpp \
    ../Library/Fen/Fen.cpp \
    ../Library/Fen/FenExo.cpp \
    ../Library/Fen/FenFoundFile.cpp \
    ../Library/Fen/FenMenu.cpp \
    ../Library/Fen/FenNote.cpp \
    ../Library/Fen/FenPrincipale.cpp \
    ../Library/Fen/TabAbstractModule.cpp \
    ../Library/Fen/TabAbstractClasse.cpp \
    ../Library/Fen/TabAbstractTableau.cpp \
    ../Library/Fen/TabClasse.cpp \
    ../Library/Fen/TabListeEleve.cpp \
    ../Library/Fen/TabListeGroupe.cpp \
    ../Library/Fen/TabMenu.cpp \
    ../Library/Fen/TabModule.cpp \
#    ../Library/Manager/AnneeManager.cpp \
#    ../Library/Manager/AppreciationManager.cpp \
#    ../Library/Manager/Attribut_baremeManager.cpp \
#    ../Library/Manager/Attribut_exerciceManager.cpp \
#    ../Library/Manager/AttributManager.cpp \
#    ../Library/Manager/BaremeManager.cpp \
#    ../Library/Manager/ClasseManager.cpp \
#    ../Library/Manager/CoefficientManager.cpp \
#    ../Library/Manager/CommentaireManager.cpp \
#    ../Library/Manager/Controle_exerciceManager.cpp \
#    ../Library/Manager/ControleManager.cpp \
#    ../Library/Manager/Eleve_groupeManager.cpp \
#    ../Library/Manager/EleveManager.cpp \
#    ../Library/Manager/ExerciceManager.cpp \
#    ../Library/Manager/GroupeManager.cpp \
    ../Library/Manager/Manager.cpp \
#    ../Library/Manager/ManagerAnnee.cpp \
    ../Library/Manager/ManagerSql.cpp \
#    ../Library/Manager/NiveauManager.cpp \
#    ../Library/Manager/NoteManager.cpp \
#    ../Library/Manager/NumControleManager.cpp \
#    ../Library/Manager/PointManager.cpp \
#    ../Library/Manager/SourceManager.cpp \
#    ../Library/Manager/TypeControleManager.cpp \
#    ../Library/Manager/TypeGroupeManager.cpp \
#    ../Library/Manager/TypeNiveauManager.cpp \
    ../Library/Model/ListeEleveModel.cpp \
    ../Library/Model/MAbstractTableModel.cpp \
    ../Library/Widget/SpinBoxAnnee.cpp \
    ../Library/Widget/SpinBoxNumClasse.cpp \
    ../Library/Xml/XmlDoc.cpp \
    ../Library/Xml/XmlElement.cpp \
    ../Library/Xml/XmlReader.cpp \
    ../Library/Xml/XmlWriter.cpp

HEADERS += \
    ../Library/Delegate/Delegate.h \
    ../Library/Delegate/ListeEleveDelegate.h \
    ../Library/Dialog/NewAnneeDialog.h \
    ../Library/Dialog/NewClasseDialog.h \
    ../Library/Dialog/SelectAnneeDialog.h \
    ../Library/Div/Bdd.h \
    ../Library/Div/Config.h \
    ../Library/Div/FileInterface.h \
    ../Library/Div/Tree.h \
    ../Library/Div/TreeItem.h \
#    ../Library/Entities/Annee.h \
#    ../Library/Entities/Appreciation.h \
#    ../Library/Entities/Attribut.h \
#    ../Library/Entities/Attribut_bareme.h \
#    ../Library/Entities/Attribut_exercice.h \
#    ../Library/Entities/Bareme.h \
#    ../Library/Entities/Classe.h \
#    ../Library/Entities/Coefficient.h \
#    ../Library/Entities/Commentaire.h \
#    ../Library/Entities/Controle.h \
#    ../Library/Entities/Controle_exercice.h \
#    ../Library/Entities/Eleve.h \
#    ../Library/Entities/Eleve_groupe.h \
    ../Library/Entities/Entity.h \
#    ../Library/Entities/EntityAnnee.h \
#    ../Library/Entities/Exercice.h \
#    ../Library/Entities/Groupe.h \
#    ../Library/Entities/ListEntities.h \
#    ../Library/Entities/Niveau.h \
#    ../Library/Entities/Note.h \
#    ../Library/Entities/NumControle.h \
#    ../Library/Entities/Point.h \
#    ../Library/Entities/Source.h \
#    ../Library/Entities/TypeControle.h \
#    ../Library/Entities/TypeGroupe.h \
#    ../Library/Entities/TypeNiveau.h \
    ../Library/Fen/Fen.h \
    ../Library/Fen/FenExo.h \
    ../Library/Fen/FenFoundFile.h \
    ../Library/Fen/FenMenu.h \
    ../Library/Fen/FenNote.h \
    ../Library/Fen/FenPrincipale.h \
    ../Library/Fen/TabAbstractModule.h \
    ../Library/Fen/TabAbstractClasse.h \
    ../Library/Fen/TabAbstractTableau.h \
    ../Library/Fen/TabClasse.h \
    ../Library/Fen/TabListeEleve.h \
    ../Library/Fen/TabListeGroupe.h \
    ../Library/Fen/TabMenu.h \
    ../Library/Fen/TabModule.h \
#    ../Library/Manager/AnneeManager.h \
#    ../Library/Manager/AppreciationManager.h \
#    ../Library/Manager/Attribut_baremeManager.h \
#    ../Library/Manager/Attribut_exerciceManager.h \
#    ../Library/Manager/AttributManager.h \
#    ../Library/Manager/BaremeManager.h \
#    ../Library/Manager/ClasseManager.h \
#    ../Library/Manager/CoefficientManager.h \
#    ../Library/Manager/CommentaireManager.h \
#    ../Library/Manager/Controle_exerciceManager.h \
#    ../Library/Manager/ControleManager.h \
#    ../Library/Manager/Eleve_groupeManager.h \
#    ../Library/Manager/EleveManager.h \
#    ../Library/Manager/ExerciceManager.h \
#    ../Library/Manager/GroupeManager.h \
    ../Library/Manager/Manager.h \
#    ../Library/Manager/ManagerAnnee.h \
    ../Library/Manager/ManagerSql.h \
#    ../Library/Manager/NiveauManager.h \
#    ../Library/Manager/NoteManager.h \
#    ../Library/Manager/NumControleManager.h \
#    ../Library/Manager/PointManager.h \
#    ../Library/Manager/SourceManager.h \
#    ../Library/Manager/TypeControleManager.h \
#    ../Library/Manager/TypeGroupeManager.h \
#    ../Library/Manager/TypeNiveauManager.h \
    ../Library/Model/ListeEleveModel.h \
    ../Library/Model/MAbstractTableModel.h \
    ../Library/Widget/SpinBoxAnnee.h \
    ../Library/Widget/SpinBoxNumClasse.h \
    ../Library/Xml/XmlDoc.h \
    ../Library/Xml/XmlElement.h \
    ../Library/Xml/XmlReader.h \
    ../Library/Xml/XmlWriter.h



