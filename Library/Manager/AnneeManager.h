#ifndef ANNEEMANAGER_H
#define ANNEEMANAGER_H

#include "ManagerTemp.h"
#include "../Entities/Annee.h"

class AnneeManager : public ManagerTemp<Annee>
{
public:
    AnneeManager();
    AnneeManager(QSqlDatabase & bdd);
    ~AnneeManager() {}

protected:
    bool add(Entity & entity)
    {
        saveAnneeEncours(entity);
        return ManagerTemp<Annee>::add(entity);
    }
    bool modify(const Entity & entity)
    {
        saveAnneeEncours(entity);
        return ManagerTemp<Annee>::modify(entity);
    }
    void bindValues(const Annee & annee)
    {
        m_requete.bindValue(0,annee.encours());
        m_requete.bindValue(1,annee.rentree());
    }
    void bindValuesUnique(const Annee &annee)
    {
        m_requete.bindValue(0,annee.rentree());
    }
    void fromRequete(Annee & annee)
    {
        annee.setEncours(m_requete.value(0).toBool());
        annee.setRentree(m_requete.value(1).toInt());
    }
    Annee * newFromRequete()
    {
        return new Annee(m_requete.value(1).toBool(),
                         m_requete.value(2).toInt(),
                         m_requete.value(0).toInt());
    }
    void saveAnneeEncours(const Entity & entity)
    {
        if(entity.value(Annee::EncoursPos).toBool())
        {
            m_requete.exec("UPDATE annee SET encours = 0 WHERE encours = 1");
            affError();
        }
    }
};

#endif // ANNEEMANAGER_H
