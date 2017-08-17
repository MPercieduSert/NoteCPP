/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef ANNEE_H
#define ANNEE_H

#include "AttributSimple.h"
#include "Entity.h"
#include "InfoEntity.h"

SINGLE_ATTRIBUT(AnAttribut,AttributIntSup,AttributIntSup<1>,An,an,int)

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Annee.
 */
class Annee : public EntityAttributsID<AnAttribut,InfoEntity::AnneeId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,Annee>::Position,
                   An = PositionEnum<AnAttribut,Annee>::Position,
                   NbrAtt};

    using EAID = EntityAttributsID<AnAttribut,InfoEntity::AnneeId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(Annee)

    //! Constructeur à partir des valeurs attributs.
    Annee(int an, int id)
        : EAID(id)
        {setAn(an);}

    //! Renvoie la chaine de caractère "annee-annee+1".
    QString affiche() const;

    //! Oprérateur d'ordre strictement croissant sur an.
    bool operator < (const Annee & annee) const
        {return an() < annee.an();}
};

#endif // ANNEE_H
