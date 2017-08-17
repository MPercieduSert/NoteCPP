/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef TYPENIVEAU_H
#define TYPENIVEAU_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntity.h"

SINGLE_ATTRIBUT(AnBacAttribut,AttributIntSup,AttributIntSup<-18>,AnBac,anBac,int)

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité TypeNiveau.
 */
class TypeNiveau : public EntityAttributsID<Attributs<AnBacAttribut,NomAttribut>,InfoEntity::TypeNiveauId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,TypeNiveau>::Position,
                   AnBac = PositionEnum<AnBacAttribut,TypeNiveau>::Position,
                   Nom = PositionEnum<NomAttribut,TypeNiveau>::Position,
                   NbrAtt};

    using EAID = EntityAttributsID<Attributs<AnBacAttribut,NomAttribut>,InfoEntity::TypeNiveauId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(TypeNiveau)

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    TypeNiveau(const QString & nom, int id = 0)
        : EAID(id)
        {setNom(nom);}

    //! Constructeur à partir des valeurs attributs.
    TypeNiveau(int an, const QString & nom, int id = 0)
        : TypeNiveau(nom, id)
        {setAnBac(an);}
};

#endif // TYPENIVEAU_H
