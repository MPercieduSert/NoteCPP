#ifndef TYPEGROUPEMANAGER_H
#define TYPEGROUPEMANAGER_H

#include "ManagerTemp.h"
#include "../Entities/TypeGroupe.h"

class TypeGroupeManager : public ManagerTemp<TypeGroupe>
{
public:
    TypeGroupeManager();
    TypeGroupeManager(QSqlDatabase & bdd);
     ~TypeGroupeManager() {}

protected:
     void bindValues(const TypeGroupe & typeGroupe)
    {
        m_requete.bindValue(0,typeGroupe.alpha());
        m_requete.bindValue(1,typeGroupe.classe());
        m_requete.bindValue(2,typeGroupe.nom());
        m_requete.bindValue(3,typeGroupe.type());
    }
     void bindValuesUnique(const TypeGroupe &typeGroupe)
    {
        m_requete.bindValue(0,typeGroupe.classe());
        m_requete.bindValue(1,typeGroupe.nom());
    }
     void fromRequete(TypeGroupe & typeGroupe)
    {
        typeGroupe.setAlpha(m_requete.value(0).toInt());
        typeGroupe.setClasse(m_requete.value(1).toInt());
        typeGroupe.setNom(m_requete.value(2).toString());
        typeGroupe.setType(m_requete.value(3).toInt());
    }
     TypeGroupe * newFromRequete()
    {
        return new TypeGroupe(m_requete.value(1).toInt(),
                              m_requete.value(2).toInt(),
                              m_requete.value(3).toString(),
                              m_requete.value(4).toInt(),
                              m_requete.value(0).toInt());
    }
};

#endif // TYPEGROUPEMANAGER_H
