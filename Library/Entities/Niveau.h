/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */
#ifndef NIVEAU_H
#define NIVEAU_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Niveau.
 */
class Niveau : public EntityAttributsID<Attributs<RelationAttribut,NcNomAttribut>,InfoEntity::NiveauId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,Niveau>::Position,
                   Id1 = PositionEnum<Id1Attribut,Niveau>::Position,
                   Id2 = PositionEnum<Id2Attribut,Niveau>::Position,
                   Nc = PositionEnum<NcAttribut,Niveau>::Position,
                   Nom = PositionEnum<NomAttribut,Niveau>::Position,
                   NbrAtt,
                   IdTp = Id1,
                   IdTpEtab = Id2};

    using EAID = EntityAttributsID<Attributs<RelationAttribut,NcNomAttribut>,InfoEntity::NiveauId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(Niveau)
    ALIAS_CLE(Tp,1)
    ALIAS_CLE(TpEtab,2)

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Niveau(const QString & nom, int id = 0)
        : EAID(id)
        {setNom(nom);}

    //! Constructeur à partir des valeurs attributs.
    Niveau(int idTp, int idTpEtab, const QString & nc, const QString & nom, int id = 0)
        : Niveau(nom,id)
    {
        setNc(nc);
        setIdTp(idTp);
        setIdTpEtab(idTpEtab);
    }
};

#endif // NIVEAU_H
