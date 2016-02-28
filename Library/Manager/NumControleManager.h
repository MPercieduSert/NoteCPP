#ifndef NUMCONTROLEMANAGER_H
#define NUMCONTROLEMANAGER_H

#include "ManagerSql.h"
#include "../Entities/NumControle.h"

class NumControleManager : public ManagerSql<NumControle>
{
public:
    NumControleManager();
    NumControleManager(QSqlDatabase & bdd);
     ~NumControleManager()   {}

protected:
     void bindValues(const NumControle & numControle)
    {
        m_requete.bindValue(0,numControle.classe());
        m_requete.bindValue(1,numControle.num());
        m_requete.bindValue(2,numControle.type());
    }
     void bindValuesUnique(const NumControle &numControle)
    {
        m_requete.bindValue(0,numControle.classe());
        m_requete.bindValue(1,numControle.type());
    }
     void fromRequete(NumControle & numControle)
    {
        numControle.setClasse(m_requete.value(0).toInt());
        numControle.setNum(m_requete.value(1).toInt());
        numControle.setType(m_requete.value(2).toInt());
    }
     NumControle * newFromRequete()
    {
        return new NumControle(m_requete.value(1).toInt(),
                               m_requete.value(2).toInt(),
                               m_requete.value(3).toInt(),
                               m_requete.value(0).toInt());
    }
};

#endif // NUMCONTROLEMANAGER_H
