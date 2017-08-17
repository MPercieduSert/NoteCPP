/*Auteur: PERCIE DU SERT Maxime
 *Date: 15/08/2017
 */
#ifndef ABSTRACTGESTIONAUTORISATION_H
#define ABSTRACTGESTIONAUTORISATION_H

#include <QList>
#include <QMap>
#include "AbstractManager.h"

/*! \ingroup groupeBaseManager
 * \brief Classe template abstraite mère des différents gestionnaire d'autorisation.
 */
template<class Ent> class AbstractGestionAutorisation
{
public:
    AbstractGestionAutorisation() = default;

    //! Demande l'autorisation de modification pour une entité donnée.
    virtual bool getAutorisation(const Ent & entity, bdd::Autorisation autorisation) = 0;

    //! Demande la liste des restrictions de modification pour une entité donnée.
    virtual QList<int> getRestriction(const Ent & entity) = 0;

    //! Modifie une autorisation de modification pour une entité donnée.
    virtual void setAutorisation(const Ent & entity, bdd::Autorisation autorisation, bool bb) = 0;

    //! Modifie les autorisations de modification pour une entité donnée.
    virtual void setAutorisation(const Ent & entity, QMap<bdd::Autorisation,bool> autorisations)
    {
        for(QMap<bdd::Autorisation,bool>::const_iterator i = autorisations.cbegin(); i != autorisations.cend(); i++)
            setAutorisation(entity, i.key(), i.value());
    }

    //! Ajoute les restrictions de modification pour une entité donnée.
    virtual void setRestriction(const Ent & entity, QList<bdd::Autorisation> restrictions)
    {
        for(QList<bdd::Autorisation>::const_iterator i = restrictions.cbegin(); i != restrictions.cend(); i++)
            setAutorisation(entity, *i, false);
    }
};

#endif // ABSTRACTGESTIONAUTORISATION_H
