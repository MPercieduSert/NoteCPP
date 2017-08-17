/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/10/2016
 */
#ifndef DONNEECARD_H
#define DONNEECARD_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntity.h"



/*! \ingroup groupeEntity
 * \brief Représentation de l'entité DonneeCard.
 */
class DonneeCard : public EntityAttributsID<Attributs<Id1Attribut,CardAttribut,ExactAttribut,CibleAttribut>,InfoEntity::DonneeCardId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,DonneeCard>::Position,
                   Id1 = PositionEnum<Id1Attribut,DonneeCard>::Position,
                   Card = PositionEnum<CardAttribut,DonneeCard>::Position,
                   Exact = PositionEnum<ExactAttribut,DonneeCard>::Position,
                   Cible = PositionEnum<CibleAttribut,DonneeCard>::Position,
                   NbrAtt,
                   IdDn = Id1,};

    //! Cardinal.
    enum cardinal {Infini = -1};

    using EAID = EntityAttributsID<Attributs<Id1Attribut,CardAttribut,ExactAttribut,CibleAttribut>,InfoEntity::DonneeCardId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(DonneeCard)
    ALIAS_CLE(Dn,1)

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    DonneeCard(int idDn, int cible, int id = 0)
        : EAID(id)
    {
        setIdDn(idDn);
        setCible(cible);
    }

    //! Constructeur à partir des valeurs attributs.
    DonneeCard(int idDn, int card, bool exact,int cible, int id = 0)
        : DonneeCard(idDn, cible, id)
    {
        setCard(card);
        setExact(exact);
    }
};

#endif // DONNEECARD_H
