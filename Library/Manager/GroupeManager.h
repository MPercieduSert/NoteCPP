#ifndef GROUPEMANAGER_H
#define GROUPEMANAGER_H

#include "ManagerTemp.h"
#include "../Entities/Groupe.h"

class GroupeManager : public ManagerTemp<Groupe>
{
public:
    GroupeManager();
    GroupeManager(QSqlDatabase & bdd);
     ~GroupeManager()     {}

protected:
     void bindValues(const Groupe & groupe)
    {
        m_requete.bindValue(0,groupe.num());
        m_requete.bindValue(1,groupe.type());
    }
     void bindValuesUnique(const Groupe &groupe)
    {
        m_requete.bindValue(0,groupe.num());
        m_requete.bindValue(1,groupe.type());
    }
     void fromRequete(Groupe & groupe)
    {
        groupe.setNum(m_requete.value(0).toInt());
        groupe.setType(m_requete.value(1).toInt());
    }
     Groupe * newFromRequete()
    {
        return new Groupe(m_requete.value(1).toInt(),
                          m_requete.value(2).toInt(),
                          m_requete.value(0).toInt());
    }
};

#endif // GROUPEMANAGER_H
