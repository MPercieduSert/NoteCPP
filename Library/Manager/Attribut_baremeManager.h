#ifndef ATTRIBUT_BAREMEMANAGER_H
#define ATTRIBUT_BAREMEMANAGER_H

#include "ManagerSql.h"
#include "../Entities/Attribut_bareme.h"

class Attribut_baremeManager : public ManagerSql<Attribut_bareme>
{
public:
    Attribut_baremeManager();
    Attribut_baremeManager(QSqlDatabase & bdd);
     ~Attribut_baremeManager()   {}

protected:
     void bindValues(const Attribut_bareme & attribut_bareme)
    {
        m_requete.bindValue(0,attribut_bareme.attribut());
        m_requete.bindValue(1,attribut_bareme.bareme());
    }
     void bindValuesUnique(const Attribut_bareme &attribut_bareme)
    {
        m_requete.bindValue(0,attribut_bareme.attribut());
        m_requete.bindValue(1,attribut_bareme.bareme());
    }
     void fromRequete(Attribut_bareme & attribut_bareme)
    {
        attribut_bareme.setAttribut(m_requete.value(0).toInt());
        attribut_bareme.setBareme(m_requete.value(1).toInt());
    }
     Attribut_bareme * newFromRequete()
    {
        return new Attribut_bareme(m_requete.value(1).toInt(),
                                   m_requete.value(2).toInt(),
                                   m_requete.value(0).toInt());
    }
};

#endif // ATTRIBUT_BAREMEMANAGER_H
