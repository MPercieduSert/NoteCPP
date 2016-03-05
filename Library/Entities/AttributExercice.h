/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/03/2016
 */

#ifndef ATTRIBUTEXERCICE_H
#define ATTRIBUTEXERCICE_H

#include "RelEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée AttributExercice.
 */

class AttributExercice : public RelEntity
{
public:
    REL_SIMPLE(At,Ex,AttributExercice)
};

#endif // ATTRIBUTEXERCICE_H
