/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */
#ifndef COMMENTAIRE_H
#define COMMENTAIRE_H

#include "EntityDivers.h"
#include "InfoEntity.h"

/*! \ingroup groupeInfoEntity
 * \brief Information sur l'entité Commentaire.
 */
struct CommentaireInfo
{
    static const int ID = InfoEntity::CommentaireId;
    static constexpr char Name[] {"Commentaire"};
    ATTRIBUT_1(Texte)
};

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Commentaire.
 */
typedef TexteOnlyEntity<CommentaireInfo> Commentaire;

#endif // COMMENTAIRE_H
