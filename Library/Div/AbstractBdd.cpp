#include "AbstractBdd.h"

AbstractBdd::AbstractBdd(const QString & dbtype, const QString &fileName, int version) : FileInterface(fileName,"Data Base files (*.db)"),
   m_bdd(QSqlDatabase::addDatabase(dbtype)),
   m_version(version)
{
    m_bdd.setDatabaseName(fileName);
}

AbstractBdd::~AbstractBdd()
{
    m_bdd.close();
}

bool AbstractBdd::copy(const QString & name)
{
    AbstractBdd bdd(name, m_bdd.driverName(),0);
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
    if(openBdd())
    {
        m_manager.creerVersion();
        miseAJourBdd();
        return true;
    }
    return false;
}

void AbstractBdd::miseAJourBdd()
{
    if(m_version != m_manager.numVersion())
    {
        if(m_version > m_manager.numVersion())
        {
            while(m_version != m_manager.numVersion())
            {
                listeMiseAJourBdd(m_manager.numVersion());
            }
        }
        else
        {
            QString str("La base de données est d'une version plus récente que le programme: \n");
            str.append("Version de la base de données requis par le programmen :").append(QString::number(m_version)).append(".\n");
            str.append("Version de la base de données :").append(QString::number(m_manager.numVersion())).append(".\n");
            throw std::runtime_error(str.toStdString());
        }
    }
}

bool AbstractBdd::open()
{
    if(openBdd())
    {
        miseAJourBdd();
        return true;
    }
    return false;
}


bool AbstractBdd::openBdd()
{
    if(m_bdd.open())
    {
        setBdd();
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
