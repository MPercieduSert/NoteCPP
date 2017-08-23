/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */
#ifndef GROUPE_H
#define GROUPE_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Groupe.
 */
class Groupe : public EntityAttributsID<Attributs<RelationExactOneNotNullAttribut,AlphaAttribut,NomTypeAttribut>,InfoEntity::GroupeId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,Groupe>::Position,
                   Id1 = PositionEnum<Id1NullAttribut,Groupe>::Position,
                   Id2 = PositionEnum<Id2NullAttribut,Groupe>::Position,
                   Alpha = PositionEnum<AlphaAttribut,Groupe>::Position,
                   Nom = PositionEnum<NomAttribut,Groupe>::Position,
                   Type = PositionEnum<TypeAttribut,Groupe>::Position,
                   NbrAtt,
                   IdAn = Id1,
                   IdCl = Id2};

    enum grPour {GrAnnee = 0,
                 GrClasse = 1};

    using EAID = EntityAttributsID<Attributs<RelationExactOneNotNullAttribut,AlphaAttribut,NomTypeAttribut>,InfoEntity::GroupeId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(Groupe)
    ALIAS_CLE(An,1)
    ALIAS_CLE(Cl,2)

    //! Constructeur à partir des valeurs attributs.
    Groupe(int idAn, int idCl, int alpha, const QString & nom, int type, int id = 0)
        : EAID(id)
    {
        setIdAn(idAn);
        setIdCl(idCl);
        setAlpha(alpha);
        setNom(nom);
        setType(type);
    }

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Groupe(int cle, const QString & nom, grPour pr)
    {
        setNom(nom);
        if(pr == GrClasse)
            {setIdCl(cle);}
        else
            {setIdAn(cle);}
    }
};

#endif // GROUPE_H
