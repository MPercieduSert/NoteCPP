#include "AbstractManagers.h"

void AbstractManagers::setRequete(const QSqlQuery & req, bool force)
{
    QSqlQuery * ptr_requete = &m_requete;
    m_requete = req;
    if (force || ptr_requete != &m_requete)
    {
        for(int i = 0; i < NbrEntity; ++i)
            m_managers[i]->setRequete(&m_requete);
    }
}
