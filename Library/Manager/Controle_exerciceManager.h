#ifndef CONTROLE_EXERCICEMANAGER_H
#define CONTROLE_EXERCICEMANAGER_H

#include "ManagerSql.h"
#include "../Entities/Controle_exercice.h"

class Controle_exerciceManager : public ManagerSql<Controle_exercice>
{
public:
    Controle_exerciceManager();
    Controle_exerciceManager(QSqlDatabase & bdd);
     ~Controle_exerciceManager()  {}

protected:
     void bindValues(const Controle_exercice & controle_exercice)
    {
        m_requete.bindValue(0,controle_exercice.controle());
        m_requete.bindValue(1,controle_exercice.exercice());
        m_requete.bindValue(2,controle_exercice.num());
    }
     void bindValuesUnique(const Controle_exercice &controle_exercice)
    {
        m_requete.bindValue(0,controle_exercice.controle());
        m_requete.bindValue(1,controle_exercice.exercice());
    }
     void fromRequete(Controle_exercice & controle_exercice)
    {
        controle_exercice.setControle(m_requete.value(0).toInt());
        controle_exercice.setExercice(m_requete.value(1).toInt());
        controle_exercice.setNum(m_requete.value(2).toInt());
    }
     Controle_exercice * newFromRequete()
    {
        return new Controle_exercice(m_requete.value(1).toInt(),
                                     m_requete.value(2).toInt(),
                                     m_requete.value(3).toInt(),
                                     m_requete.value(0).toInt());
    }
};

#endif // CONTROLE_EXERCICEMANAGER_H
