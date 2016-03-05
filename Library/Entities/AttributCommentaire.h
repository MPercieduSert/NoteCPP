/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/03/2016
 */

#ifndef ATTRIBUTCOMMENTAIRE_H
#define ATTRIBUTCOMMENTAIRE_H

#include "RelEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée AttributCommentaire.
 */

class AttributCommentaire : public RelEntity
{
public:
    REL_SIMPLE(At,Cm,AttributCommentaire)
};

#endif // ATTRIBUTCOMMENTAIRE_H
