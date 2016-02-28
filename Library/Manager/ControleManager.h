#ifndef CONTROLEMANAGER_H
#define CONTROLEMANAGER_H

#include "ManagerSql.h"
#include "../Entities/Controle.h"
class ControleManager : public ManagerSql<Controle>
{
public:
    ControleManager();
    ControleManager(QSqlDatabase & bdd);
     ~ControleManager()   {}

protected:
     void bindValues(const Controle & controle)
    {
        m_requete.bindValue(0,controle.classe());
        m_requete.bindValue(1,controle.date());
        m_requete.bindValue(2,controle.decimale());
        m_requete.bindValue(3,controle.minima());
        m_requete.bindValue(4,controle.nom());
        m_requete.bindValue(5,controle.saisie());
        m_requete.bindValue(6,controle.total());
        m_requete.bindValue(7,controle.type());
    }
     void bindValuesUnique(const Controle &controle)
    {
        m_requete.bindValue(0,controle.classe());
        m_requete.bindValue(1,controle.nom());
    }
     void fromRequete(Controle & controle)
    {
        controle.setClasse(m_requete.value(0).toInt());
        controle.setDate(m_requete.value(1).toDate());
        controle.setDecimale(m_requete.value(2).toInt());
        controle.setMinima(m_requete.value(3).toInt());
        controle.setNom(m_requete.value(4).toString());
        controle.setSaisie(m_requete.value(5).toBool());
        controle.setTotal(m_requete.value(6).toInt());
        controle.setType(m_requete.value(7).toInt());
    }
     Controle * newFromRequete()
    {
        return new Controle(m_requete.value(1).toInt(),
                            m_requete.value(2).toDate(),
                            m_requete.value(3).toInt(),
                            m_requete.value(4).toInt(),
                            m_requete.value(5).toString(),
                            m_requete.value(6).toBool(),
                            m_requete.value(7).toInt(),
                            m_requete.value(8).toInt(),
                            m_requete.value(0).toInt());
    }
};

#endif // CONTROLEMANAGER_H
