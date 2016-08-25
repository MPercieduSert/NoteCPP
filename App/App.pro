#-------------------------------------------------
#
# Project created by QtCreator 2015-08-29T12:00:45
#
#-------------------------------------------------



TEMPLATE = app
TARGET = App
CONFIG += staticlib
CONFIG += c++11
QT  += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    ../Library/Delegate/ListeEleveDelegate.cpp \
    ../Library/Dialog/NewAnneeDialog.cpp \
    ../Library/Dialog/NewClasseDialog.cpp \
    ../Library/Dialog/NewEtablissementDialog.cpp \
    ../Library/Dialog/SelectAnneeDialog.cpp \
    ../Library/Div/AbstractBdd.cpp \
    ../Library/Div/AbstractManagers.cpp \
    ../Library/Div/Bdd.cpp \
    ../Library/Div/Config.cpp \
    ../Library/Div/FileInterface.cpp \
    ../Library/Div/Tree.cpp \
    ../Library/Div/TreeItem.cpp \
    ../Library/Div/Managers.cpp \
    ../Library/Entities/Annee.cpp \
    ../Library/Entities/Arbre.cpp \
    ../Library/Entities/Attribut.cpp \
    ../Library/Entities/AttributEntity.cpp \
#    ../Library/Entities/Bareme.cpp \
    ../Library/Entities/Classe.cpp \
    ../Library/Entities/ClasseEleve.cpp \
#    ../Library/Entities/Coefficient.cpp \
#    ../Library/Entities/Commentaire.cpp \
#    ../Library/Entities/Controle.cpp \
    ../Library/Entities/Donnee.cpp \
    ../Library/Entities/Eleve.cpp \
#    ../Library/Entities/Etablissement.cpp \
    ../Library/Entities/Entity.cpp \
    ../Library/Entities/EntityDivers.cpp \
    ../Library/Entities/EntityNom.cpp \
    ../Library/Entities/EntityOfDefaultType.cpp \
    ../Library/Entities/EntityRelation.cpp \
#    ../Library/Entities/Exercice.cpp \
    ../Library/Entities/Groupe.cpp \
    ../Library/Entities/InfoEntity.cpp \
    ../Library/Entities/InfoEntityBase.cpp \
    ../Library/Entities/ListEntities.cpp \
    ../Library/Entities/Niveau.cpp \
#    ../Library/Entities/Note.cpp \
#    ../Library/Entities/NumControle.cpp \
#    ../Library/Entities/Point.cpp \
#    ../Library/Entities/Source.cpp \
#    ../Library/Entities/TypeControle.cpp \
#    ../Library/Entities/TypeGroupe.cpp \
    ../Library/Entities/TypeEtablissement.cpp \
    ../Library/Entities/TypeNiveau.cpp \
    ../Library/Entities/VectorEntities.cpp \
    ../Library/Entities/VersionBdd.cpp \
    ../Library/Fen/Fen.cpp \
#    ../Library/Fen/FenExo.cpp \
    ../Library/Fen/FenFoundFile.cpp \
#    ../Library/Fen/FenMenu.cpp \
#    ../Library/Fen/FenNote.cpp \
    ../Library/Fen/FenPrincipale.cpp \
    ../Library/Fen/TabAbstractClasse.cpp \
    ../Library/Fen/TabAbstractModule.cpp \
    ../Library/Fen/TabAbstractTableau.cpp \
    ../Library/Fen/TabClasse.cpp \
    ../Library/Fen/TabListeEleve.cpp \
#    ../Library/Fen/TabListeGroupe.cpp \
    ../Library/Fen/TabMenu.cpp \
    ../Library/Fen/TabModule.cpp \
    ../Library/Manager/AbstractLinkSql.cpp \
    ../Library/Manager/AbstractUniqueSql.cpp \
    ../Library/Manager/ArbreManager.cpp \
    ../Library/Manager/InfoBdd.cpp \
    ../Library/Manager/InfoBddBase.cpp \
    ../Library/Manager/LinkSql.cpp \
    ../Library/Manager/LinkSqlBase.cpp \
    ../Library/Manager/Manager.cpp \
    ../Library/Manager/ManagerOf.cpp \
    ../Library/Manager/ManagerSql.cpp \
    ../Library/Manager/ReqSql.cpp \
    ../Library/Manager/UniqueSql.cpp \
    ../Library/Manager/UniqueSqlBase.cpp \
    ../Library/Manager/VersionBddManager.cpp \
    ../Library/Model/ListeEleveModel.cpp \
    ../Library/Model/MAbstractTableModel.cpp \
    ../Library/Widget/SelectInListBox.cpp \
    ../Library/Widget/SpinBoxAnnee.cpp \
    ../Library/Widget/SpinBoxNumClasse.cpp \
    ../Library/Xml/XmlDoc.cpp \
    ../Library/Xml/XmlElement.cpp \
    ../Library/Xml/XmlReader.cpp \
    ../Library/Xml/XmlWriter.cpp

HEADERS += \
    ../Library/Delegate/ListeEleveDelegate.h \
    ../Library/Dialog/NewAnneeDialog.h \
    ../Library/Dialog/NewClasseDialog.h \
    ../Library/Dialog/NewEtablissementDialog.h \
    ../Library/Dialog/SelectAnneeDialog.h \
    ../Library/Div/AbstractBdd.h \
    ../Library/Div/AbstractManagers.h \
    ../Library/Div/Bdd.h \
    ../Library/Div/Config.h \
    ../Library/Div/FileInterface.h \
    ../Library/Div/Macro.h \
    ../Library/Div/Managers.h \
    ../Library/Div/Tree.h \
    ../Library/Div/TreeItem.h \  
    ../Library/Entities/Annee.h \
    ../Library/Entities/Arbre.h \
    ../Library/Entities/Attribut.h \
    ../Library/Entities/AttributEntity.h \
#    ../Library/Entities/Bareme.h \
    ../Library/Entities/Classe.h \
    ../Library/Entities/ClasseEleve.h \
#    ../Library/Entities/Coefficient.h \
#    ../Library/Entities/Commentaire.h \
#    ../Library/Entities/Controle.h \
    ../Library/Entities/Donnee.h \
    ../Library/Entities/Eleve.h \
#    ../Library/Entities/Etablissement.h \
    ../Library/Entities/Entity.h \
    ../Library/Entities/EntityDivers.h \
    ../Library/Entities/EntityNom.h \
    ../Library/Entities/EntityOfDefaultType.h \
    ../Library/Entities/EntityRelation.h \
#    ../Library/Entities/Exercice.h \
    ../Library/Entities/Groupe.h \
    ../Library/Entities/InfoEntity.h \
    ../Library/Entities/InfoEntityBase.h \
    ../Library/Entities/ListEntities.h \
    ../Library/Entities/Niveau.h \
#    ../Library/Entities/Note.h \
#    ../Library/Entities/NumControle.h \
#    ../Library/Entities/Point.h \
#    ../Library/Entities/Source.h \
#    ../Library/Entities/TypeControle.h \
#    ../Library/Entities/TypeGroupe.h \
    ../Library/Entities/TypeEtablissement.h \
    ../Library/Entities/TypeNiveau.h \
    ../Library/Entities/VectorEntities.h \
    ../Library/Entities/VersionBdd.h \
    ../Library/Fen/Fen.h \
#    ../Library/Fen/FenExo.h \
    ../Library/Fen/FenFoundFile.h \
#    ../Library/Fen/FenMenu.h \
#    ../Library/Fen/FenNote.h \
    ../Library/Fen/FenPrincipale.h \
    ../Library/Fen/TabAbstractClasse.h \
    ../Library/Fen/TabAbstractModule.h \
    ../Library/Fen/TabAbstractTableau.h \
    ../Library/Fen/TabClasse.h \
    ../Library/Fen/TabListeEleve.h \
#    ../Library/Fen/TabListeGroupe.h \
    ../Library/Fen/TabMenu.h \
    ../Library/Fen/TabModule.h \
    ../Library/Manager/AbstractLinkSql.h \
    ../Library/Manager/AbstractUniqueSql.h \
    ../Library/Manager/ArbreManager.h \
    ../Library/Manager/InfoBdd.h \
    ../Library/Manager/InfoBddBase.h \
    ../Library/Manager/LinkSql.h \
    ../Library/Manager/LinkSqlBase.h \
    ../Library/Manager/Manager.h \
    ../Library/Manager/ManagerOf.h \
    ../Library/Manager/ManagerSql.h \
    ../Library/Manager/ReqSql.h \
    ../Library/Manager/UniqueSql.h \
    ../Library/Manager/UniqueSqlBase.h \
    ../Library/Manager/VersionBddManager.h \
    ../Library/Model/ListeEleveModel.h \
    ../Library/Model/MAbstractTableModel.h \
    ../Library/Widget/SelectInListBox.h \
    ../Library/Widget/SpinBoxAnnee.h \
    ../Library/Widget/SpinBoxNumClasse.h \
    ../Library/Xml/XmlDoc.h \
    ../Library/Xml/XmlElement.h \
    ../Library/Xml/XmlReader.h \
    ../Library/Xml/XmlWriter.h
