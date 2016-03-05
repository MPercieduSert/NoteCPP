/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/03/2016
 */

#ifndef ATTRIBUTBAREME_H
#define ATTRIBUTBAREME_H

#include "RelEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée AttributBareme.
 */

class AttributBareme : public RelEntity
{
public:
    REL_SIMPLE(At,Br,AttributBareme)
};

#endif // ATTRIBUTBAREME_H
