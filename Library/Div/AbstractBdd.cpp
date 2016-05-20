#include "AbstractBdd.h"

AbstractBdd::AbstractBdd(const QString & dbtype, const QString &fileName) : FileInterface(fileName,"Data Base files (*.db)"),
   m_bdd(QSqlDatabase::addDatabase(dbtype))
{
    m_bdd.setDatabaseName(fileName);
}

AbstractBdd::~AbstractBdd()
{
    m_bdd.close();
}

bool AbstractBdd::copy(const QString & name)
{
    AbstractBdd bdd(name, m_bdd.driverName());
    if(bdd.exists() && bdd.isValid())
    {
        QFile file(name);
        return file.copy(m_fileName);
    }
    else
    {
        return false;
    }
}

bool AbstractBdd::creer()
{
    if(m_bdd.open())
    {
        for(int id = 0; id < AbstractManagers::NbrEntity; ++id)
            m_manager.get(id)->creer();
        return true;
    }
    return false;
}

void AbstractBdd::setBdd()
{
    QSqlQuery req = QSqlQuery(m_bdd);
    req.setForwardOnly(true);
    m_manager.setRequete(req);
}

void AbstractBdd::setFileName(const QString & fileName)
{
    FileInterface::setFileName(fileName);
    if(m_bdd.isOpen())
    {
        m_bdd.close();
    }
    m_bdd.setDatabaseName(fileName);
}
