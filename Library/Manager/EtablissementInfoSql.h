/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/03/2016
 */
#ifndef ETABLISSEMENTINFOSQL
#define ETABLISSEMENTINFOSQL

#include "InfoSql.h"

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité Commentaire.
 */
struct EtablissementInfoSql : NcNomTypeInfoSql
{
    static constexpr char Table[] {"etab"};
};

#endif // ETABLISSEMENTINFOSQL

