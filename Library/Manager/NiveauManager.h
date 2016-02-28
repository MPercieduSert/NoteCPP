#ifndef NIVEAUMANAGER_H
#define NIVEAUMANAGER_H

#include "ManagerSql.h"
#include "../Entities/Niveau.h"
class NiveauManager : public ManagerSql<Niveau>
{
public:
    NiveauManager();
    NiveauManager(QSqlDatabase & bdd);
    ~NiveauManager()    {}

protected:
     void bindValues(const Niveau & niveau)
    {
        m_requete.bindValue(0,niveau.colle());
        m_requete.bindValue(1,niveau.nom());
        m_requete.bindValue(2,niveau.type());
    }
     void bindValuesUnique(const Niveau &niveau)
    {
        m_requete.bindValue(0,niveau.nom());
    }
     void fromRequete(Niveau & niveau)
    {
        niveau.setColle(m_requete.value(0).toBool());
        niveau.setNom(m_requete.value(1).toString());
        niveau.setType(m_requete.value(2).toInt());
    }
     Niveau * newFromRequete()
    {
        return new Niveau(m_requete.value(1).toBool(),
                          m_requete.value(2).toString(),
                          m_requete.value(3).toInt(),
                          m_requete.value(0).toInt());
    }
};

#endif // NIVEAUMANAGER_H
