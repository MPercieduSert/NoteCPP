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
    ../Library/Delegate/ListeElevesDelegate.cpp \
    ../Library/Delegate/ListeNoteDelegate.cpp \
    ../Library/Dialog/ControleGraphDialog.cpp \
    ../Library/Dialog/NewAnneeDialog.cpp \
    ../Library/Dialog/NewClasseDialog.cpp \
    ../Library/Dialog/NewControleDialog.cpp \
    ../Library/Dialog/NewEtablissementDialog.cpp \
    ../Library/Dialog/NewTypeControleDialog.cpp \
    ../Library/Dialog/SelectAnneeDialog.cpp \
    ../Library/Dialog/SelectDonneeDialog.cpp \
    ../Library/Div/AbstractBdd.cpp \
    ../Library/Div/AbstractManagers.cpp \
    ../Library/Div/Bdd.cpp \
    ../Library/Div/Config.cpp \
    ../Library/Div/FileInterface.cpp \
    ../Library/Div/ListPtr.cpp \
    ../Library/Div/Managers.cpp \
    ../Library/Div/Noyau.cpp \
    ../Library/Div/Tree.cpp \
    ../Library/Div/TreeItem.cpp \
    ../Library/Div/vectorPtr.cpp \
    ../Library/Entities/Annee.cpp \
    ../Library/Entities/Arbre.cpp \
    ../Library/Entities/AttributMultiple.cpp \
    ../Library/Entities/AttributSimple.cpp \
#    ../Library/Entities/Bareme.cpp \
    ../Library/Entities/Classe.cpp \
    ../Library/Entities/ClasseEleve.cpp \
    ../Library/Entities/Controle.cpp \
    ../Library/Entities/Donnee.cpp \
    ../Library/Entities/DonneeCard.cpp \
    ../Library/Entities/Eleve.cpp \
    ../Library/Entities/Entity.cpp \
    ../Library/Entities/EntityCible.cpp \
    ../Library/Entities/EntityComplexe.cpp \
    ../Library/Entities/EntityDivers.cpp \
    ../Library/Entities/EntityOfDefaultType.cpp \
    ../Library/Entities/EntityRelation.cpp \
    ../Library/Entities/Forme.cpp \
    ../Library/Entities/Groupe.cpp \
    ../Library/Entities/InfoEntity.cpp \
    ../Library/Entities/InfoEntityBase.cpp \
    ../Library/Entities/MotCle.cpp \
    ../Library/Entities/Niveau.cpp \
#    ../Library/Entities/Point.cpp \
    ../Library/Entities/TypeControle.cpp \
    ../Library/Entities/TypeCours.cpp \
    ../Library/Entities/TypeEtablissement.cpp \
    ../Library/Entities/TypeNiveau.cpp \
    ../Library/Entities/Utilisation.cpp \
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
    ../Library/Fen/TabCours.cpp \
    ../Library/Fen/TabListeEleve.cpp \
    ../Library/Fen/TabListeNote.cpp \
#    ../Library/Fen/TabListeGroupe.cpp \
    ../Library/Fen/TabMenu.cpp \
    ../Library/Fen/TabModule.cpp \
    ../Library/Fen/TabMotCle.cpp \
    ../Library/Manager/AbstractGestionAutorisation.cpp \
    ../Library/Manager/AbstractLinkSql.cpp \
    ../Library/Manager/AbstractManager.cpp \
    ../Library/Manager/AbstractUniqueSql.cpp \
    ../Library/Manager/GestionAutorisationCible.cpp \
    ../Library/Manager/InfoBdd.cpp \
    ../Library/Manager/InfoBddBase.cpp \
    ../Library/Manager/ManagerArbre.cpp \
    ../Library/Manager/ManagerOf.cpp \
    ../Library/Manager/ManagerOfArbre.cpp \
    ../Library/Manager/ManagerOfArbreModifControle.cpp \
    ../Library/Manager/ManagerOfArbreSimple.cpp \
    ../Library/Manager/ManagerOfArbreSimpleModifControle.cpp \
    ../Library/Manager/ManagerOfModifControle.cpp \
    ../Library/Manager/ManagerSql.cpp \
    ../Library/Manager/ReqSql.cpp \
    ../Library/Manager/UniqueSql.cpp \
    ../Library/Manager/UniqueSqlBase.cpp \
    ../Library/Manager/VersionBddManager.cpp \
    ../Library/Model/ListeEleveModel.cpp \
    ../Library/Model/ListeElevesModel.cpp \
    ../Library/Model/ListeNoteModel.cpp \
    ../Library/Model/MAbstractTableModel.cpp \
    ../Library/Model/MAbstractTreeModel.cpp \
    ../Library/Model/TreeModelReadTemp.cpp \
    ../Library/Model/TreeModelTemp.cpp \
    ../Library/Widget/BarPlotter.cpp \
    ../Library/Widget/HeaderView.cpp \
    ../Library/Widget/Histogramme.cpp \
    ../Library/Widget/Plotter.cpp \
    ../Library/Widget/ReadTreeWidget.cpp \
    ../Library/Widget/SelectInListBox.cpp \
    ../Library/Widget/SpinBoxAnnee.cpp \
    ../Library/Widget/SpinBoxDecimale.cpp \
    ../Library/Widget/SpinBoxNote.cpp \
    ../Library/Widget/SpinBoxNumExclu.cpp \
    ../Library/Xml/XmlDoc.cpp \
    ../Library/Xml/XmlElement.cpp \
    ../Library/Xml/XmlReader.cpp \
    ../Library/Xml/XmlWriter.cpp

HEADERS += \
    ../Library/Delegate/ListeElevesDelegate.h \
    ../Library/Delegate/ListeNoteDelegate.h \
    ../Library/Dialog/ControleGraphDialog.h \
    ../Library/Dialog/NewAnneeDialog.h \
    ../Library/Dialog/NewClasseDialog.h \
    ../Library/Dialog/NewControleDialog.h \
    ../Library/Dialog/NewEtablissementDialog.h \
    ../Library/Dialog/NewTypeControleDialog.h \
    ../Library/Dialog/SelectAnneeDialog.h \
    ../Library/Dialog/SelectDonneeDialog.h \
    ../Library/Div/AbstractBdd.h \
    ../Library/Div/AbstractManagers.h \
    ../Library/Div/Bdd.h \
    ../Library/Div/Config.h \
    ../Library/Div/FileInterface.h \
    ../Library/Div/ListPtr.h \
    ../Library/Div/Macro.h \
    ../Library/Div/Managers.h \
    ../Library/Div/Noyau.h \
    ../Library/Div/Tree.h \
    ../Library/Div/TreeItem.h \
    ../Library\Div\VectorPtr.h \
    ../Library/Entities/Annee.h \
    ../Library/Entities/Arbre.h \
    ../Library/Entities/AttributMultiple.h \
    ../Library/Entities/AttributSimple.h \
#    ../Library/Entities/Bareme.h \
    ../Library/Entities/Classe.h \
    ../Library/Entities/ClasseEleve.h \
    ../Library/Entities/Controle.h \
    ../Library/Entities/Donnee.h \
    ../Library/Entities/DonneeCard.h \
    ../Library/Entities/Eleve.h \
    ../Library/Entities/Entity.h \
    ../Library/Entities/EntityCible.h \
    ../Library/Entities/EntityComplexe.h \
    ../Library/Entities/EntityDivers.h \
    ../Library/Entities/EntityOfDefaultType.h \
    ../Library/Entities/EntityRelation.h \
    ../Library/Entities/Forme.h \
    ../Library/Entities/Groupe.h \
    ../Library/Entities/InfoEntity.h \
    ../Library/Entities/InfoEntityBase.h \
    ../Library/Entities/MotCle.h \
    ../Library/Entities/Niveau.h \
#    ../Library/Entities/Point.h \
    ../Library/Entities/TypeControle.h \
    ../Library/Entities/TypeCours.h \
    ../Library/Entities/TypeEtablissement.h \
    ../Library/Entities/TypeNiveau.h \
    ../Library/Entities/Utilisation.h \
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
    ../Library/Fen/TabCours.h \
    ../Library/Fen/TabListeEleve.h \
    ../Library/Fen/TabListeNote.h \
#    ../Library/Fen/TabListeGroupe.h \
    ../Library/Fen/TabMenu.h \
    ../Library/Fen/TabModule.h \
    ../Library/Fen/TabMotCle.h \
    ../Library/Manager/AbstractGestionAutorisation.h \
    ../Library/Manager/AbstractLinkSql.h \
    ../Library/Manager/AbstractManager.h \
    ../Library/Manager/AbstractUniqueSql.h \
    ../Library/Manager/GestionAutorisationCible.h \
    ../Library/Manager/InfoBdd.h \
    ../Library/Manager/InfoBddBase.h \
    ../Library/Manager/ManagerArbre.h \
    ../Library/Manager/ManagerOf.h \
    ../Library/Manager/ManagerOfArbre.h \
    ../Library/Manager/ManagerOfArbreModifControle.h \
    ../Library/Manager/ManagerOfArbreSimple.h \
    ../Library/Manager/ManagerOfArbreSimpleModifControle.h \
    ../Library/Manager/ManagerOfModifControle.h \
    ../Library/Manager/ManagerSql.h \
    ../Library/Manager/ReqSql.h \
    ../Library/Manager/UniqueSql.h \
    ../Library/Manager/UniqueSqlBase.h \
    ../Library/Manager/VersionBddManager.h \
    ../Library/Model/ListeEleveModel.h \
    ../Library/Model/ListeElevesModel.h \
    ../Library/Model/ListeNoteModel.h \
    ../Library/Model/MAbstractTableModel.h \
    ../Library/Model/MAbstractTreeModel.h \
    ../Library/Model/TreeModelReadTemp.h \
    ../Library/Model/TreeModelTemp.h \
    ../Library/Widget/BarPlotter.h \
    ../Library/Widget/HeaderView.h \
    ../Library/Widget/Histogramme.h \
    ../Library/Widget/Plotter.h \
    ../Library/Widget/ReadTreeWidget.h \
    ../Library/Widget/SelectInListBox.h \
    ../Library/Widget/SpinBoxAnnee.h \
    ../Library/Widget/SpinBoxDecimale.h \
    ../Library/Widget/SpinBoxNote.h \
    ../Library/Widget/SpinBoxNumExclu.h \
    ../Library/Xml/XmlDoc.h \
    ../Library/Xml/XmlElement.h \
    ../Library/Xml/XmlReader.h \
    ../Library/Xml/XmlWriter.h
