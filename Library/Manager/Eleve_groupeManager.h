#ifndef ELEVE_GROUPEMANAGER_H
#define ELEVE_GROUPEMANAGER_H

#include "ManagerTemp.h"
#include "../Entities/Eleve_groupe.h"

class Eleve_groupeManager : public ManagerTemp<Eleve_groupe>
{
public:
    Eleve_groupeManager();
    Eleve_groupeManager(QSqlDatabase & bdd);
    virtual ~Eleve_groupeManager()   {}

protected:
    virtual void bindValues(const Eleve_groupe & eleve_groupe)
    {
        m_requete.bindValue(0,eleve_groupe.eleve());
        m_requete.bindValue(1,eleve_groupe.groupe());
    }
    virtual void bindValuesUnique(const Eleve_groupe &eleve_groupe)
    {
        m_requete.bindValue(0,eleve_groupe.eleve());
        m_requete.bindValue(1,eleve_groupe.groupe());
    }
    virtual void fromRequete(Eleve_groupe & eleve_groupe)
    {
        eleve_groupe.setEleve(m_requete.value(0).toInt());
        eleve_groupe.setGroupe(m_requete.value(1).toInt());
    }
    virtual Eleve_groupe * newFromRequete()
    {
        return new Eleve_groupe(m_requete.value(1).toInt(),
                                m_requete.value(2).toInt(),
                                m_requete.value(0).toInt());
    }
};

#endif // ELEVE_GROUPEMANAGER_H
