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
    ATTRIBUT_ENTITY_INT_SUP(Sur,sur,0)
public:
    //! Positions des attributs.
    enum Position {Id = Entity::Id,
                   IdDonnee = Entity::NbrAtt,
                   Card,
                   Sur,
                   NbrAtt};

    using Entity::Entity;
    BASE_ENTITY(DonneeCard,InfoEntity::DonneeCardId)

    //! Constructeur à partir des valeurs attributs.
    DonneeCard(int idDonnee, int card, int sur, int id = 0)
        : Entity(id), m_idDonnee(idDonnee), m_card(card), m_sur(sur)
        {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    DonneeCard(int idDonnee, int sur)
        : m_idDonnee(idDonnee), m_sur(sur)
        {}

    MEMBRE_ATT_3(DonneeCard,Entity,IdDonnee,idDonnee,Card,card,Sur,sur)
};

#endif // DONNEECARD_H
