/*Auteur: PERCIE DU SERT Maxime
 *Date: 24/03/2016
 */
#ifndef ARBRES
#define ARBRES

#include "Arbre.h"
#include "EntityNom.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Commentaire.
 */
typedef TexteOnlyEntity<CaracteristiqueEntity::CommentaireId> Commentaire;

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Etablissement.
 */
typedef NcNomTypeOnlyEntity<CaracteristiqueEntity::EtablissementId> Etablissement;

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Source.
 */
typedef NomTypeOnlyEntity<CaracteristiqueEntity::SourceId> Source;

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité TypeNiveau.
 */
typedef NomTypeOnlyEntity<CaracteristiqueEntity::TypeNiveauId> TypeNiveau;
#endif // ARBRES

