/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/10/2016
 */
#ifndef DONNEECARD_H
#define DONNEECARD_H

#include "AttributEntity.h"
#include "Entity.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité DonneeCard.
 */
class DonneeCard : public Entity
{
    ATTRIBUT_ENTITY_ID(Donnee)
    ATTRIBUT_ENTITY_INT_SUP(Card,card,-1)
    ATTRIBUT_ENTITY_BOOL(Exact,exact)
    ATTRIBUT_ENTITY_INT_SUP(Cible,cible,0)

public:
    //! Positions des attributs.
    enum Position {Id = Entity::Id,
                   IdDonnee = Entity::NbrAtt,
                   Card,
                   Exact,
                   Cible,
                   NbrAtt};

    //! Cardinal.
    enum cardinal {Infini = -1};

    using Entity::Entity;
    BASE_ENTITY(DonneeCard,InfoEntity::DonneeCardId)

    //! Constructeur à partir des valeurs attributs.
    DonneeCard(int idDonnee, int card, bool exact,int cible, int id = 0)
        : Entity(id), m_idDonnee(idDonnee), m_card(card), m_exact(exact), m_cible(cible)
        {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    DonneeCard(int idDonnee, int cible)
        : m_idDonnee(idDonnee), m_cible(cible)
        {}

    MEMBRE_ATT_4(DonneeCard,Entity,IdDonnee,idDonnee,Card,card,Exact,exact,Cible,cible)
};

#endif // DONNEECARD_H
