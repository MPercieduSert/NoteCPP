/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */
#ifndef SOURCE_H
#define SOURCE_H

#include "AttributEntityAlias.h"
#include "EntityNom.h"
#include "InfoEntity.h"

/*! \ingroup groupeInfoEntity
 * \brief Information sur l'entité Source.
 */
struct SourceInfo
{
    static const int ID = InfoEntity::SourceId;
    static constexpr char Name[] {"Source"};
    ATTRIBUT_2(Nom,Type)
};

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Source.
 */
typedef NomTypeOnlyEntity<SourceInfo> Source;

#endif // SOURCE_H
