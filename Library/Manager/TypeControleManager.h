#ifndef TYPECONTROLEMANAGER_H
#define TYPECONTROLEMANAGER_H

#include "ManagerTemp.h"
#include "../Entities/TypeControle.h"

class TypeControleManager : public ManagerTemp<TypeControle>
{
public:
    TypeControleManager();
    TypeControleManager(QSqlDatabase & bdd);
     ~TypeControleManager()  {}

protected:
     void bindValues(const TypeControle & typeControle)
    {
        m_requete.bindValue(0,typeControle.appreciation());
        m_requete.bindValue(1,typeControle.decimale());
        m_requete.bindValue(2,typeControle.modifT());
        m_requete.bindValue(3,typeControle.nc());
        m_requete.bindValue(4,typeControle.nom());
        m_requete.bindValue(5,typeControle.total());
    }
     void bindValuesUnique(const TypeControle &typeControle)
    {
        m_requete.bindValue(0,typeControle.nom());
    }
     void fromRequete(TypeControle & typeControle)
    {
        typeControle.setAppreciation(m_requete.value(0).toBool());
        typeControle.setDecimale(m_requete.value(1).toInt());
        typeControle.setModifT(m_requete.value(2).toBool());
        typeControle.setNc(m_requete.value(3).toString());
        typeControle.setNom(m_requete.value(4).toString());
        typeControle.setTotal(m_requete.value(5).toInt());
    }
     TypeControle * newFromRequete()
    {
        return new TypeControle(m_requete.value(1).toBool(),
                                m_requete.value(2).toInt(),
                                m_requete.value(3).toBool(),
                                m_requete.value(4).toString(),
                                m_requete.value(5).toString(),
                                m_requete.value(6).toInt(),
                                m_requete.value(0).toInt());
    }
};

#endif // TYPECONTROLEMANAGER_H
