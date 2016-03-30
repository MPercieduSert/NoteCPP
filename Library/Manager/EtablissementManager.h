/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/03/2016
 */
#ifndef ETABLISSEMENTMANAGER_H
#define ETABLISSEMENTMANAGER_H

#include "LinkSqlNom.h"
#include "LinkSqlUnique.h"
#include "ManagerSql.h"
#include "EtablissementInfoSql.h"
#include "../Entities/Etablissement.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité Commentaire de programation et sa représentation en base de donnée.
 */
typedef NomLinkSqlUnique<NcNomTypeOnlyLinkSql<Etablissement,EtablissementInfoSql> > EtablissementLinkSql;

/*! \ingroup groupeManager
 * \brief Manager de l'entité Etablissement.
 */
class EtablissementManager : public ManagerSql<EtablissementLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    EtablissementManager(QSqlQuery & req)
        : ManagerSql(req)
    {}
};

#endif // ETABLISSEMENTMANAGER_H
