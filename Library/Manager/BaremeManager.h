#ifndef BAREMEMANAGER_H
#define BAREMEMANAGER_H

#include "ManagerTemp.h"
#include "../Entities/Bareme.h"

class BaremeManager : public ManagerTemp<Bareme>
{
public:
    BaremeManager();
    BaremeManager(QSqlDatabase & bdd);
     ~BaremeManager()    {}

protected:
     void bindValues(const Bareme & bareme)
    {
        m_requete.bindValue(0,bareme.controle());
        m_requete.bindValue(1,bareme.exercice());
        m_requete.bindValue(2,bareme.fraction());
        m_requete.bindValue(3,bareme.num());
        m_requete.bindValue(4,bareme.nom());
        m_requete.bindValue(5,bareme.valeur());
    }
     void bindValuesUnique(const Bareme &bareme)
    {
        m_requete.bindValue(0,bareme.controle());
        m_requete.bindValue(1,bareme.exercice());
        m_requete.bindValue(2,bareme.num());
    }
     void fromRequete(Bareme & bareme)
    {
        bareme.setControle(m_requete.value(0).toInt());
        bareme.setExercice(m_requete.value(1).toInt());
        bareme.setFraction(m_requete.value(2).toInt());
        bareme.setNum(m_requete.value(3).toInt());
        bareme.setNom(m_requete.value(4).toString());
        bareme.setValeur(m_requete.value(5).toInt());
    }
     Bareme * newFromRequete()
    {
        return new Bareme(m_requete.value(1).toInt(),
                            m_requete.value(2).toInt(),
                            m_requete.value(3).toInt(),
                            m_requete.value(4).toInt(),
                            m_requete.value(5).toString(),
                            m_requete.value(6).toInt(),
                            m_requete.value(0).toInt());
    }
};

#endif // BAREMEMANAGER_H
