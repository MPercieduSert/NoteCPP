/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/05/2016
 */
#ifndef TYPEETABLISSEMENT_H
#define TYPEETABLISSEMENT_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntity.h"

SINGLE_ATTRIBUT(MaxAttribut,AttributIntInf,AttributIntInf<15>,Max,max,int)
SINGLE_ATTRIBUT(MinAttribut,AttributIntSup,AttributIntSup<-18>,Min,min,int)

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité TypeEtablissement.
 */
class TypeEtablissement : public EntityAttributsID<Attributs<MaxAttribut,MinAttribut,NomAttribut>,InfoEntity::TypeEtablissementId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,TypeEtablissement>::Position,
                   Max = PositionEnum<MaxAttribut,TypeEtablissement>::Position,
                   Min = PositionEnum<MinAttribut,TypeEtablissement>::Position,
                   Nom = PositionEnum<NomAttribut,TypeEtablissement>::Position,
                   NbrAtt};

    using EAID = EntityAttributsID<Attributs<MaxAttribut,MinAttribut,NomAttribut>,InfoEntity::TypeEtablissementId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(TypeEtablissement)

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    TypeEtablissement(const QString & nom, int id = 0)
        : EAID(id)
        {setNom(nom);}

    //! Constructeur à partir des valeurs attributs.
    TypeEtablissement(int max, int min, const QString &nom, int id = 0)
        : TypeEtablissement(nom, id)
    {
        setMax(max);
        setMin(min);
    }
};

#endif // TYPEETABLISSEMENT_H
