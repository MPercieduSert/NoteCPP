#ifndef ATTRIBUTMANAGER_H
#define ATTRIBUTMANAGER_H

#include "ManagerSql.h"
#include "../Entities/Attribut.h"

class AttributManager : public ManagerSql<Attribut>
{
public:
    AttributManager();
    AttributManager(QSqlDatabase & bdd);
     ~AttributManager()  {}

protected:
     void bindValues(const Attribut & attribut)
    {
        m_requete.bindValue(0,attribut.feuille());
        m_requete.bindValue(1,attribut.niveau());
        m_requete.bindValue(2,attribut.nom());
        m_requete.bindValue(3,attribut.num());
        m_requete.bindValue(4,attribut.pere());
        m_requete.bindValue(5,attribut.nc());
    }
     void bindValuesUnique(const Attribut &attribut)
    {
        m_requete.bindValue(0,attribut.num());
        m_requete.bindValue(1,attribut.pere());
    }
     void fromRequete(Attribut & attribut)
    {
        attribut.setFeuille(m_requete.value(0).toBool());
        attribut.setNiveau(m_requete.value(1).toInt());
        attribut.setNom(m_requete.value(2).toString());
        attribut.setNum(m_requete.value(3).toInt());
        attribut.setPere(m_requete.value(4).toInt());
        attribut.setNc(m_requete.value(5).toString());
    }
     Attribut * newFromRequete()
    {
        return new Attribut(m_requete.value(1).toBool(),
                            m_requete.value(2).toInt(),
                            m_requete.value(3).toString(),
                            m_requete.value(4).toInt(),
                            m_requete.value(5).toInt(),
                            m_requete.value(0).toInt(),
                            m_requete.value(6).toString());
    }
};

#endif // ATTRIBUTMANAGER_H
