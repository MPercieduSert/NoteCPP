#ifndef ATTRIBUT_EXERCICEMANAGER_H
#define ATTRIBUT_EXERCICEMANAGER_H

#include "ManagerTemp.h"
#include "../Entities/Attribut_exercice.h"

class Attribut_exerciceManager : public ManagerTemp<Attribut_exercice>
{
public:
    Attribut_exerciceManager();
    Attribut_exerciceManager(QSqlDatabase & bdd);
     ~Attribut_exerciceManager() {}

protected:
     void bindValues(const Attribut_exercice & attribut_exercice)
    {
        m_requete.bindValue(0,attribut_exercice.attribut());
        m_requete.bindValue(1,attribut_exercice.exercice());
    }
     void bindValuesUnique(const Attribut_exercice &attribut_exercice)
    {
        m_requete.bindValue(0,attribut_exercice.attribut());
        m_requete.bindValue(1,attribut_exercice.exercice());
    }
     void fromRequete(Attribut_exercice & attribut_exercice)
    {
        attribut_exercice.setAttribut(m_requete.value(0).toInt());
        attribut_exercice.setExercice(m_requete.value(1).toInt());
    }
     Attribut_exercice * newFromRequete()
    {
        return new Attribut_exercice(m_requete.value(1).toInt(),
                                     m_requete.value(2).toInt(),
                                     m_requete.value(0).toInt());
    }
};

#endif // ATTRIBUT_EXERCICEMANAGER_H
