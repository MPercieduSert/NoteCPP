/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/05/2016
 */
#ifndef TYPEETABLISSEMENT_H
#define TYPEETABLISSEMENT_H

#include "AttributEntity.h"
#include "EntityNom.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité TypeEtablissement.
 */
class TypeEtablissement : public NomEntity
{
    ATTRIBUT_ENTITY_INT_INF(Max,max,15)
    ATTRIBUT_ENTITY_INT_SUP(Min,min,-18)
public:
    using NomEntity::NomEntity;
    BASE_ENTITY(TypeEtablissement,InfoEntity::TypeEtablissementId)

    //! Constructeur à partir des valeurs attributs.
    TypeEtablissement(int max, int min, const QString &nom, int id = 0)
        : NomEntity(nom, id),
          m_max(max),
          m_min(min)
    {}

    MEMBRE_ATT_2(TypeEtablissement,NomEntity,Max,max,Min,min)
};

#endif // TYPEETABLISSEMENT_H
