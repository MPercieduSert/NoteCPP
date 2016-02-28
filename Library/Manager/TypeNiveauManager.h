#ifndef TYPENIVEAUMANAGER_H
#define TYPENIVEAUMANAGER_H

#include "ManagerSql.h"
#include "../Entities/TypeNiveau.h"

class TypeNiveauManager : public ManagerSql<TypeNiveau>
{
public:
    TypeNiveauManager();
    TypeNiveauManager(QSqlDatabase & bdd);
     ~TypeNiveauManager()    {}

protected:
     void bindValues(const TypeNiveau & typeNiveau)
    {
        m_requete.bindValue(0,typeNiveau.nom());
    }
     void bindValuesUnique(const TypeNiveau &typeNiveau)
    {
        m_requete.bindValue(0,typeNiveau.nom());
    }
     void fromRequete(TypeNiveau & typeNiveau)
    {
        typeNiveau.setNom(m_requete.value(0).toString());
    }
     TypeNiveau * newFromRequete()
    {
        return new TypeNiveau(m_requete.value(1).toString(),
                              m_requete.value(0).toInt());
    }
};

#endif // TYPENIVEAUMANAGER_H
