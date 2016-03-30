/*Auteur: PERCIE DU SERT Maxime
 *Date: 06/03/2016
 */
#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H

#include "EntityNom.h"
#include "InfoEntity.h"

/*! \ingroup groupeInfoEntity
 * \brief Information sur l'entité Etablissement.
 */
struct EtablissementInfo
{
    static const int ID = InfoEntity::EtablissementId;
    static constexpr char Name[] {"Etablissement"};
    ATTRIBUT_3(Nc,Nom,Type)
};

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Etablissement.
 */
typedef NcNomTypeOnlyEntity<EtablissementInfo> Etablissement;

#endif // ETABLISSEMENT_H
