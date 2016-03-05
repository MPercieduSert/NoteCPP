/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/03/2016
 */

#ifndef ATTRIBUTCOURS_H
#define ATTRIBUTCOURS_H

#include "RelEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée AttributCours.
 */

class AttributCours : public RelEntity
{
public:
    REL_SIMPLE(At,Crs,AttributCours)
};

#endif // ATTRIBUTCOURS_H
