#ifndef COEFFICIENTMANAGER_H
#define COEFFICIENTMANAGER_H

#include "ManagerAnnee.h"
#include "../Entities/Coefficient.h"
class CoefficientManager : public ManagerAnnee<Coefficient>
{
public:
    CoefficientManager(const Annee & annee);
    CoefficientManager(QSqlDatabase & bdd, const Annee & annee);
     ~CoefficientManager()    {}

protected:
     void bindValues(const Coefficient & coefficient)
    {
        m_requete.bindValue(0,coefficient.controle());
        m_requete.bindValue(1,coefficient.indice());
        m_requete.bindValue(2,coefficient.valeur());
    }
     void bindValuesUnique(const Coefficient &coefficient)
    {
        m_requete.bindValue(0,coefficient.controle());
        m_requete.bindValue(1,coefficient.indice());
    }
     void fromRequete(Coefficient & coefficient)
    {
        coefficient.setControle(m_requete.value(0).toInt());
        coefficient.setIndice(m_requete.value(1).toInt());
        coefficient.setValeur(m_requete.value(2).toDouble());
    }
     Coefficient * newFromRequete()
    {
        return new Coefficient(m_requete.value(1).toInt(),
                         m_requete.value(2).toInt(),
                         m_requete.value(3).toDouble(),
                         m_requete.value(0).toInt());
    }
};

#endif // COEFFICIENTMANAGER_H
