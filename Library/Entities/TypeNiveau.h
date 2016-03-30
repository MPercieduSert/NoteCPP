/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/02/2016
 */

#ifndef TYPE_NIVEAU_H
#define TYPE_NIVEAU_H

#include "EntityNom.h"
#include "InfoEntity.h"

/*! \ingroup groupeInfoEntity
 * \brief Information sur l'entité TypeNiveau.
 */
struct TypeNiveauInfo
{
    static const int ID = InfoEntity::TypeNiveauId;
    static constexpr char Name[] {"TypeNiveau"};
    ATTRIBUT_2(Nom,Type)
};

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité TypeNiveau.
 */
typedef NomTypeOnlyEntity<TypeNiveauInfo> TypeNiveau;

#endif // TYPE_NIVEAU_H
