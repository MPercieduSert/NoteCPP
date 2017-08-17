/*Auteur: PERCIE DU SERT Maxime
 *Date: 16/05/2016
 */
#ifndef ABSTRACTMANAGERS_H
#define ABSTRACTMANAGERS_H

#include <QMessageBox>
#include <QSqlQuery>
#include <stdexcept>

#include "../Entities/InfoEntity.h"
#include "../Manager/ManagerOf.h"
#include "../Manager/VersionBddManager.h"

namespace bdd {
    //! Version de création de la base de données.
    enum creationBdd{
        initiale
    };

    //! Demande autorisation de modification
    enum DemandeAutorisationModificationBdd{
        Oui = 1,
        Non = 0
    };
}


/*! \ingroup groupeFile
 * \brief Macro permettant de spécifier le membre get.
 */
#define DEF_GET_MANAGER(ENTITY) template<> inline ManagerOf<ENTITY> & Managers::get<ENTITY>() {return m_ ## ENTITY ## Manager;}

/*! \ingroup groupeFile
 * \brief Macro permettant de spécifier le membre get.
 */
#define MANAGER_TAB(ENTITY) m_managers[ENTITY::ID]=&m_ ## ENTITY ## Manager;

/*! \ingroup groupeFile
 *  \brief Classe mère de la classe contenant les managers des entités pour la base de donnée.
 */
class AbstractManagers
{
public:
    static const int NbrEntity = InfoEntity::NbrEntity;  //!< Nombre de type d'entity à gérer

protected:
    QSqlQuery m_requete;                            //!< Requéte commune aux manageurs.
    AbstractManager * m_managers[NbrEntity];        //!< Tableau des manageurs.
    VersionBddManager m_managerVersion;             //!< Manager de l'entité version de la base de bonnée.

public:
    //! Constructeur.
    AbstractManagers(const QSqlQuery & req = QSqlQuery())
        : m_requete(req)
        {}

    //! Creé la table de l'entité VersionBdd
    void creerVersion();

    //! Retourne le manager des entités de ID, id.
    AbstractManager * get(int id)
    {
        if(id >= 0 and id < NbrEntity)
        {
            return m_managers[id];
        }
        else
        {
            throw std::invalid_argument("Identifiant d'entité invalide dans la fonction get.");
        }
    }

    //! Returne la version courante de la base de donnée.
    VersionBdd getVersion();

    //! Returne le numero de version de la base de donnée.
    int numVersion();

    //! Enregistre le numéro de version de la base de donnée.
    void saveVersion(int num);

    //! Modifie le pointeur vers l'objet requête.
    void setRequete(const QSqlQuery & req, bool force = false);
};

#endif // ABSTRACTMANAGERS_H
