/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef ANNEE_H
#define ANNEE_H

#include "AttributEntity.h"
#include "Entity.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Annee.
 */
class Annee : public Entity
{
    ATTRIBUT_ENTITY_INT_SUP(An,an,1)

public:
    //! Positions des attributs.
    enum Position {Id = Entity::Id,
                   An = Entity::NbrAtt,
                   NbrAtt};

    using Entity::Entity;
    BASE_ENTITY(Annee,InfoEntity::AnneeId)

    //! Constructeur à partir des valeurs attributs.
    Annee(int an, int id)
        : Entity(id), m_an(an) {}

    //! Renvoie la chaine de caractère "annee-annee+1".
    QString affiche() const;

    //! Oprérateur d'ordre strictement croissant sur an.
    bool operator < (const Annee & annee) const
        {return an() < annee.an();}

    MEMBRE_ATT_1(Annee,Entity,An,an)
};

#endif // ANNEE_H
