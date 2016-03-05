/*Auteur: PERCIE DU SERT Maxime
 *Date: 03/03/2016
 */

#ifndef TYPENIVEAUMANAGER_H
#define TYPENIVEAUMANAGER_H

#include "ManagerSql.h"
#include "TypeNiveauLinkSql.h"


/*! \ingroup groupeManager
 * \brief Manager de l'entitée TypeNiveau.
 */

class TypeNiveauManager : public ManagerSql<TypeNiveauLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    TypeNiveauManager(QSqlQuery & req);

    //! creer la table et insert les entrées par defaut.
    void creer();
};

#endif // TYPENIVEAUMANAGER_H
