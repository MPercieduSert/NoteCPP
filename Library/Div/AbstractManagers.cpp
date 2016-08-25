#include "AbstractManagers.h"

void AbstractManagers::creerVersion()
{
    m_managerVersion.creer();
    saveVersion(bdd::creationBdd::initiale);
}

VersionBdd AbstractManagers::getVersion()
{
    int max = m_managerVersion.fonctionAgrega<int>(bdd::Max,VersionBdd::numPos);
    VersionBdd ver(QDateTime(),max);
    m_managerVersion.getUnique(ver);
    return ver;
}

int AbstractManagers::numVersion()
    {return m_managerVersion.fonctionAgrega<int>(bdd::Max,VersionBdd::numPos);}

void AbstractManagers::saveVersion(int num)
    {m_managerVersion.save(VersionBdd(QDateTime::currentDateTime(), num));}

void AbstractManagers::setRequete(const QSqlQuery & req, bool force)
{
    QSqlQuery * ptr_requete = &m_requete;
    m_requete = req;
    if (force || ptr_requete != &m_requete)
        AbstractManagerSql::setRequete(&m_requete);
}
