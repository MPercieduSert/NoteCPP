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

/*! \ingroup groupeFile
 * \brief Macro permettant de spécifier le membre get.
 */
#define DEF_GET_MANAGER(ENTITY) template<> inline ManagerOf<ENTITY> Managers::get<ENTITY>() const {return m_ ## ENTITY ## Manager;}

/*! \ingroup groupeFile
 * \brief Macro permettant de spécifier le membre get.
 */
#define MANAGER_TAB(ENTITY) m_managers[Info<ENTITY>::ID]=&m_ ## ENTITY ## Manager;

/*! \ingroup groupeFile
 *  \brief Classe mère de la classe contenant les managers des entités pour la base de donnée.
 */
class AbstractManagers
{
public:
    static const int NbrEntity = CaracteristiqueEntity::NbrEntity; //! Nombre de type d'entity à gérer

protected:
    QSqlQuery m_requete;                //! Requéte commune aux manageurs.
    AbstractManagerSql * m_managers[NbrEntity];     //! Tableau des manageurs.

public:
    AbstractManagers(const QSqlQuery & req = QSqlQuery())
        : m_requete(req)
        {}

    //! Retourne le manager des entités de ID, id.
    Manager * get(int id)
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

    //! Modifie le pointeur vers l'objet requête.
    void setRequete(const QSqlQuery & req, bool force = false);
};

#endif // ABSTRACTMANAGERS_H
