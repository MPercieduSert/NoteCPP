/*Auteur: PERCIE DU SERT Maxime
 *Date: 15/08/2017
 */
#ifndef GESTIONAUTORISATIONCIBLE_H
#define GESTIONAUTORISATIONCIBLE_H

#include <QList>
#include "AbstractGestionAutorisation.h"
#include "AbstractManager.h"

template<class Ent, class Restrict> class GestionAutorisationCible : public AbstractGestionAutorisation<Ent>
{
protected:
    const int m_cible;  //!< Identifiant de ciblage de l'entité Ent.
    AbstractManagerTemp<Restrict> * m_managerRestriction;   //!< Pointeur vers le gertionnaire des restriction.

public:
    GestionAutorisationCible(int cible, AbstractManagerTemp<Restrict> * manager = nullptr)
        : m_cible(cible), m_managerRestriction(manager)
    {}

    //! Demande l'autorisation de modification pour une entité donnée.
    bool getAutorisation(const Ent & entity, bdd::Autorisation autorisation)
        {return !m_managerRestriction->existsUnique(Restrict(entity.id(), m_cible, autorisation));}

    //! Demande la liste des restrictions de modification pour une entité donnée.
    QList<int> getRestriction(const Ent & entity)
    {
        ListPtr<Restrict> listeRestrict(m_managerRestriction->getList(Restrict::IdCible, entity.id(), Restrict::Cible, m_cible, Restrict:: Num));
        QList<int> listeNum;
        for(typename ListPtr<Restrict>::iterator i = listeRestrict.begin(); i != listeRestrict.end(); i++)
            listeNum.append((*i).num());
        return listeNum;
    }

    //! Modifie une autorisation de modification pour une entité donnée.
    void setAutorisation(const Ent & entity, bdd::Autorisation autorisation, bool bb)
    {
        Restrict restriction(entity.id(), m_cible, autorisation);
        bool existRestric = m_managerRestriction->existsUnique(restriction);
        if(bb)
        {
            if(existRestric)
                m_managerRestriction->del(restriction);
        }
        else
        {
            if(!existRestric)
                m_managerRestriction->save(restriction);
        }
    }

    //! Accesseur du manageur de restriction.
    AbstractManagerTemp<Restrict> * managerRestriction() const
        {return m_managerRestriction;}

    //! Mutateur du manageur de restriction.
    void setManagerRestriction(AbstractManagerTemp<Restrict> * manager)
        {m_managerRestriction = manager;}
};

#endif // GESTIONAUTORISATIONCIBLE_H
