/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/03/2016
 */
#ifndef COMMENTAIREMANAGER_H
#define COMMENTAIREMANAGER_H

#include "LinkSqlDivers.h"
#include "LinkSqlUnique.h"
#include "ManagerSql.h"
#include "CommentaireInfoSql.h"
#include "../Entities/Commentaire.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité Commentaire de programation et sa représentation en base de donnée.
 */
typedef TexteLinkSqlUnique<TexteOnlyLinkSql<Commentaire,CommentaireInfoSql> > CommentaireLinkSql;

/*! \ingroup groupeManager
 * \brief Manager de l'entité Commentaire.
 */
class CommentaireManager : public ManagerSql<CommentaireLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    CommentaireManager(QSqlQuery & req)
        : ManagerSql(req)
    {}
};

#endif // COMMENTAIREMANAGER_H
