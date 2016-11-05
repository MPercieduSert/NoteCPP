/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef TYPENIVEAU_H
#define TYPENIVEAU_H

#include "AttributEntity.h"
#include "EntityNom.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité TypeNiveau.
 */
class TypeNiveau : public NomEntity
{
    ATTRIBUT_ENTITY_INT_SUP(AnBac,anBac,-18)
public:
    //! Positions des attributs.
    enum Position {Id = NomEntity::Id,
                   Nom = NomEntity::Nom,
                   AnBac = NomEntity::NbrAtt,
                   NbrAtt};

    using NomEntity::NomEntity;
    BASE_ENTITY(TypeNiveau,InfoEntity::TypeNiveauId)

    //! Constructeur à partir des valeurs attributs.
    TypeNiveau(int an, const QString & nom, int id = 0)
        : NomEntity(nom, id),
          m_anBac(an)
    {}

    MEMBRE_ATT_1(TypeNiveau,NomEntity,AnBac,anBac)
};

#endif // TYPENIVEAU_H
