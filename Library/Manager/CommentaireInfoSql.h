/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/03/2016
 */
#ifndef COMMENTAIREINFOSQL
#define COMMENTAIREINFOSQL

#include "InfoSql.h"

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité Commentaire.
 */
struct CommentaireInfoSql : TexteInfoSql
{
    static constexpr char Table[] {"cm"};
};

#endif // COMMENTAIREINFOSQL

