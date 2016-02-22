#ifndef SOURCEMANAGER_H
#define SOURCEMANAGER_H

#include "ManagerTemp.h"
#include "../Entities/Source.h"

class SourceManager : public ManagerTemp<Source>
{
public:
    SourceManager();
    SourceManager(QSqlDatabase & bdd);
     ~SourceManager()    {}

protected:
     void bindValues(const Source & source)
    {
        m_requete.bindValue(0,source.nom());
        m_requete.bindValue(1,source.type());
    }
     void bindValuesUnique(const Source &source)
    {
        m_requete.bindValue(0,source.nom());
        m_requete.bindValue(1,source.type());
    }
     void fromRequete(Source & source)
    {
        source.setNom(m_requete.value(0).toString());
        source.setType(m_requete.value(1).toInt());
    }
     Source * newFromRequete()
    {
        return new Source(m_requete.value(1).toString(),
                          m_requete.value(2).toInt(),
                          m_requete.value(0).toInt());
    }
};

#endif // SOURCEMANAGER_H
