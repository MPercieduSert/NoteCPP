/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/09/2017
 */
#ifndef TABGESTIONBDD_H
#define TABGESTIONBDD_H

#include <QListWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSplitter>
#include <QStackedWidget>
#include <QTableView>
#include "FenPrincipale.h"
#include "TabAbstractModule.h"

//! \ingroup groupeFen
//! Défini les nom et nomBdd des entitée.
#define DECL_TABLE_ENTITY_NOM(ENTITY,NOM) m_tables[InfoEntity::ENTITY##Id].nom = NOM; \
    m_tables[InfoEntity::ENTITY##Id].nomBdd = InfoBdd<ENTITY>::table(); \
    nomAttributsBdd = InfoBdd<ENTITY>::attribut(); \
    for(int i = 0; i != ENTITY::NbrAtt; ++i) m_tables[InfoEntity::ENTITY##Id].nomAttributs \
.append(ENTITY::nomAttribut(i).append("(").append(nomAttributsBdd.value(i)).append(")"));

#define DECL_TABLE_ENTITY(ENTITY) DECL_TABLE_ENTITY_NOM(ENTITY,ENTITY::Name())
#define DECL_TABLE_ENTITY_NAME(ENTITY) DECL_TABLE_ENTITY_NOM(ENTITY,#ENTITY)
/*! \ingroup groupeFen
 * \brief Onglet de gestion de la base de donnée.
 */
class TabGestionBdd : public TabAbstractModule
{
    Q_OBJECT
protected:
    enum {ArbreCoursId = InfoEntity::NbrEntity,
          ArbreDonneeId,
          ArbreExerciceId,
          ArbreMotCleId,
          NbrTable
    };
    //! Structure contenant les donnée et variable associé à chaque table.
    struct table{
        QStringList nomAttributs;  //!< Liste des noms des attributs.
        QSqlTableModel * model;   //!< Model.
        QString nom;        //!< Nom de la table.
        QString nomBdd;     //!< Nom de la table dans la base de donnée.
        QTableView * view;       //!< Vue.
    };

    using Tables = std::array<table,NbrTable>;
    Tables m_tables; //!< Ensemble des liens avec les tables.

    QListWidget * m_listName;   //!< Liste des noms des entitées
    QSplitter * m_splitter;     //!< Splitter entre la liste des noms des entités et les tables
    QStackedWidget * m_stack;   //!< Staked widget.

    //QHBoxLayout * m_secondLayout;   //!< Calque secondaire.

public:
    //! Constructeur.
    explicit TabGestionBdd(QSqlDatabase & bdd, int index, TabModule *parent = 0);
};

#endif // TABGESTIONBDD_H
