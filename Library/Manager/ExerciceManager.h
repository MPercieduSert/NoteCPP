#ifndef EXERCICEMANAGER_H
#define EXERCICEMANAGER_H

#include "ManagerSql.h"
#include "../Entities/Exercice.h"

class ExerciceManager : public ManagerSql<Exercice>
{
//

public:
    ExerciceManager();
    ExerciceManager(QSqlDatabase & bdd);
    virtual ~ExerciceManager()   {}

protected:
    virtual void bindValues(const Exercice & exercice)
    {
        m_requete.bindValue(0,exercice.enonce());
        m_requete.bindValue(1,exercice.feuille());
        m_requete.bindValue(2,exercice.niveau());
        m_requete.bindValue(3,exercice.num());
        m_requete.bindValue(4,exercice.pere());
        m_requete.bindValue(5,exercice.version());
        m_requete.bindValue(6,exercice.correction());
        m_requete.bindValue(7,exercice.source());
        m_requete.bindValue(8,exercice.titre());
    }
    virtual void bindValuesUnique(const Exercice &exercice)
    {
        m_requete.bindValue(0,exercice.pere());
        m_requete.bindValue(1,exercice.num());
        m_requete.bindValue(2,exercice.version());
    }
    virtual void fromRequete(Exercice & exercice)
    {
        exercice.setEnonce(m_requete.value(0).toString());
        exercice.setFeuille(m_requete.value(1).toBool());
        exercice.setNiveau(m_requete.value(2).toInt());
        exercice.setNum(m_requete.value(3).toInt());
        exercice.setPere(m_requete.value(4).toInt());
        exercice.setVersion(m_requete.value(5).toInt());
        exercice.setCorrection(m_requete.value(6).toString());
        exercice.setTitre(m_requete.value(7).toString());
    }
    virtual Exercice * newFromRequete()
    {
        return new Exercice(m_requete.value(1).toString(),
                            m_requete.value(2).toBool(),
                            m_requete.value(3).toInt(),
                            m_requete.value(4).toInt(),
                            m_requete.value(5).toInt(),
                            m_requete.value(6).toInt(),
                            m_requete.value(0).toInt(),
                            m_requete.value(7).toString(),
                            m_requete.value(8).toInt(),
                            m_requete.value(9).toString());
    }
};

#endif // EXERCICEMANAGER_H
