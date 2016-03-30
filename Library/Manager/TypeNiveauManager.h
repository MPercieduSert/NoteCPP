/*Auteur: PERCIE DU SERT Maxime
 *Date: 03/03/2016
 */

#ifndef TYPENIVEAUMANAGER_H
#define TYPENIVEAUMANAGER_H

#include "LinkSqlNom.h"
#include "LinkSqlUnique.h"
#include "ManagerSql.h"
#include "TypeNiveauInfoSql.h"
#include "../Entities/TypeNiveau.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité Commentaire de programation et sa représentation en base de donnée.
 */
typedef NomLinkSqlUnique<NomTypeOnlyLinkSql<TypeNiveau,TypeNiveauInfoSql> > TypeNiveauLinkSql;

/*! \ingroup groupeManager
 * \brief Manager de l'entité TypeNiveau.
 */
class TypeNiveauManager : public ManagerSql<TypeNiveauLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    TypeNiveauManager(QSqlQuery & req)
        : ManagerSql(req)
    {}
};

#endif // TYPENIVEAUMANAGER_H
