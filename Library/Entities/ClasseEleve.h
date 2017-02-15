/*Auteur: PERCIE DU SERT Maxime
 *Date: 07/03/2016
 */
#ifndef CLASSEELEVE_H
#define CLASSEELEVE_H

#include "AttributEntity.h"
#include "EntityRelation.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité ClasseEleve.
 */

class ClasseEleve : public RelationEntity
{
    ATTRIBUT_ENTITY_DATE_NULL(Entree,entree)
    ATTRIBUT_ENTITY_DATE_NULL(Sortie,sortie)
public:
    //! Positions des attributs.
    enum Position {Id = RelationEntity::Id,
                   IdCl = RelationEntity::Id1,
                   IdEl = RelationEntity::Id2,
                   Entree = RelationEntity::NbrAtt,
                   Sortie,
                   NbrAtt};

    using RelationEntity::RelationEntity;
    BASE_ENTITY(ClasseEleve,InfoEntity::ClasseEleveId)
    RELATION_ALIAS_2_CLE(Cl,El)

    //! Constructeur à partir des valeurs attributs.
    ClasseEleve(int idCl, int idEl, const QDate & entree, const QDate & sortie, int id = 0)
        : RelationEntity(idCl, idEl, id),
          m_entree(entree),
          m_sortie(sortie)
    {}

    MEMBRE_ATT_2(ClasseEleve,RelationEntity,Entree,entree,Sortie,sortie)
};

#endif // CLASSEELEVE_H
