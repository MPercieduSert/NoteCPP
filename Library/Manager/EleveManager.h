#ifndef ELEVEMANAGER_H
#define ELEVEMANAGER_H

#include "ManagerTemp.h"
#include "../Entities/Eleve.h"

class EleveManager : public ManagerTemp<Eleve>
{
public:
    EleveManager();
    EleveManager(QSqlDatabase & bdd);
     ~EleveManager()  {}

protected:
     void bindValues(const Eleve & eleve)
    {
        m_requete.bindValue(0,eleve.classe());
        m_requete.bindValue(1,eleve.fille());
        m_requete.bindValue(2,eleve.naissance());
        m_requete.bindValue(3,eleve.nom());
        m_requete.bindValue(4,eleve.prenom());
        m_requete.bindValue(5,eleve.abandon());
    }
     void bindValuesUnique(const Eleve &eleve)
    {
        m_requete.bindValue(0,eleve.nom());
        m_requete.bindValue(1,eleve.prenom());
        m_requete.bindValue(2,eleve.naissance());
    }
     void fromRequete(Eleve & eleve)
    {
        eleve.setClasse(m_requete.value(0).toInt());
        eleve.setFille(m_requete.value(1).toBool());
        eleve.setNaissance(m_requete.value(2).toDate());
        eleve.setNom(m_requete.value(3).toString());
        eleve.setPrenom(m_requete.value(4).toString());
        eleve.setAbandon(m_requete.value(5).toDate());
    }
     Eleve * newFromRequete()
    {
        return new Eleve(m_requete.value(1).toInt(),
                         m_requete.value(2).toBool(),
                         m_requete.value(3).toDate(),
                         m_requete.value(4).toString(),
                         m_requete.value(5).toString(),
                         m_requete.value(0).toInt(),
                         m_requete.value(6).toDate());
    }
};

#endif // ELEVEMANAGER_H
