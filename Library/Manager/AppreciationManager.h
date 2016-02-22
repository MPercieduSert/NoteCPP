#ifndef APPRECIATIONMANAGER_H
#define APPRECIATIONMANAGER_H

#include "ManagerAnnee.h"
#include "../Entities/Appreciation.h"

class AppreciationManager : public ManagerAnnee<Appreciation>
{
public:
    AppreciationManager(const Annee &annee);
    AppreciationManager(QSqlDatabase & bdd, const Annee &annee);
     ~AppreciationManager()  {}

protected:
     void bindValues(const Appreciation & appreciation)
    {
        m_requete.bindValue(0,appreciation.date());
        m_requete.bindValue(1,appreciation.note());
        m_requete.bindValue(2,appreciation.saisie());
        m_requete.bindValue(3,appreciation.texte());
    }
     void bindValuesUnique(const Appreciation &appreciation)
    {
        m_requete.bindValue(0,appreciation.note());
    }
     void fromRequete(Appreciation & appreciation)
    {
        appreciation.setDate(m_requete.value(0).toDateTime());
        appreciation.setNote(m_requete.value(1).toInt());
        appreciation.setSaisie(m_requete.value(2).toBool());
        appreciation.setTexte(m_requete.value(3).toString());
    }
     Appreciation * newFromRequete()
    {
        return new Appreciation(m_requete.value(1).toDateTime(),
                                m_requete.value(2).toInt(),
                                m_requete.value(3).toBool(),
                                m_requete.value(4).toString(),
                                m_requete.value(0).toInt());
    }
};

#endif // APPRECIATIONMANAGER_H
