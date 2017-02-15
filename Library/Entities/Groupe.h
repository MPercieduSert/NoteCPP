/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */
#ifndef GROUPE_H
#define GROUPE_H

#include "AttributEntity.h"
#include "EntityRelation.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Groupe.
 */
class Groupe : public RelationExactOneNotNullEntity
{
    ATTRIBUT_ENTITY_INT_SUP(Alpha,alpha,0)
    ATTRIBUT_ENTITY_STR_NOT_EMPTY(Nom,nom)
    ATTRIBUT_ENTITY_INT_SUP(Type,type,0)
public:
    //! Positions des attributs.
    enum Position {Id = RelationExactOneNotNullEntity::Id,
                   IdAn = RelationExactOneNotNullEntity::Id1,
                   IdCl = RelationExactOneNotNullEntity::Id2,
                   Alpha = RelationExactOneNotNullEntity::NbrAtt,
                   Nom,
                   Type,
                   NbrAtt};

    enum grPour {GrAnnee = 0,
                 GrClasse = 1};

    BASE_ENTITY(Groupe,InfoEntity::GroupeId)
    RELATION_ALIAS_2_CLE(An,Cl)

    //! Constructeur par defaut.
    Groupe(int id = 0)
        :RelationExactOneNotNullEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    Groupe(int idAn, int idCl, int alpha, const QString & nom, int type, int id = 0)
        : RelationExactOneNotNullEntity(idAn,idCl,id),
          m_alpha(alpha),
          m_nom(nom),
          m_type(type)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Groupe(int cle, const QString & nom, grPour pr)
        : m_nom(nom)
    {
        if(pr == GrClasse)
            {setIdCl(cle);}
        else
            {setIdAn(cle);}
    }

    MEMBRE_ATT_3(Groupe,RelationExactOneNotNullEntity,Alpha,alpha,Nom,nom,Type,type)
};

#endif // GROUPE_H
