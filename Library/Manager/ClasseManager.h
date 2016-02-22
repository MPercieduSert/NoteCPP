#ifndef CLASSEMANAGER_H
#define CLASSEMANAGER_H

#include "ManagerTemp.h"
#include "../Entities/Classe.h"

class ClasseManager : public ManagerTemp<Classe>
{
//annee, nbr_phase, niveau, num)
public:
    ClasseManager();
    ClasseManager(QSqlDatabase & bdd);
     ~ClasseManager()     {}

protected:
     void bindValues(const Classe & classe)
    {
        m_requete.bindValue(0,classe.annee());
        m_requete.bindValue(1,classe.nbr_phase());
        m_requete.bindValue(2,classe.niveau());
        m_requete.bindValue(3,classe.num());
    }
     void bindValuesUnique(const Classe &classe)
    {
        m_requete.bindValue(0,classe.annee());
        m_requete.bindValue(1,classe.niveau());
        m_requete.bindValue(2,classe.num());
    }
     void fromRequete(Classe & classe)
    {
        classe.setAnnee(m_requete.value(0).toInt());
        classe.setNbr_phase(m_requete.value(1).toInt());
        classe.setNiveau(m_requete.value(2).toInt());
        classe.setNum(m_requete.value(3).toInt());
    }
     Classe * newFromRequete()
    {
        return new Classe(m_requete.value(1).toInt(),
                            m_requete.value(2).toInt(),
                            m_requete.value(3).toInt(),
                            m_requete.value(4).toInt(),
                            m_requete.value(0).toInt());
    }
};

#endif // CLASSEMANAGER_H
