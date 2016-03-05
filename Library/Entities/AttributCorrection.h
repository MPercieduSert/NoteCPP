/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/03/2016
 */

#ifndef ATTRIBUTCORRECTION_H
#define ATTRIBUTCORRECTION_H

#include "RelEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée AttributCorrection.
 */

class AttributCorrection : public RelEntity
{
public:
    REL_SIMPLE(At,Crr,AttributCorrection)
};

#endif // ATTRIBUTCORRECTION_H
