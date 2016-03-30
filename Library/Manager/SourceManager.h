/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/03/2016
 */
#ifndef SOURCEMANAGER_H
#define SOURCEMANAGER_H

#include "LinkSqlNom.h"
#include "LinkSqlUnique.h"
#include "ManagerSql.h"
#include "SourceInfoSql.h"
#include "../Entities/Source.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité Commentaire de programation et sa représentation en base de donnée.
 */
typedef NomLinkSqlUnique<NomTypeOnlyLinkSql<Source,SourceInfoSql> > SourceLinkSql;

/*! \ingroup groupeManager
 * \brief Manager de l'entité Source.
 */
class SourceManager : public ManagerSql<SourceLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    SourceManager(QSqlQuery & req)
        : ManagerSql(req)
    {}
};

#endif // SOURCEMANAGER_H
