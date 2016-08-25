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
typedef TexteOnlyEntity<InfoEntity::CommentaireId> Commentaire;

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Etablissement.
 */
typedef NcNomTypeOnlyEntity<InfoEntity::EtablissementId> Etablissement;

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Source.
 */
typedef NomTypeOnlyEntity<InfoEntity::SourceId> Source;

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité TypeNiveau.
 */
typedef NomTypeOnlyEntity<InfoEntity::TypeNiveauId> TypeNiveau;
#endif // ARBRES

