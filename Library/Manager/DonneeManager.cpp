#include "DonneeManager.h"

DonneeManager::DonneeManager(QSqlQuery &req)
    :ManagerSql<DonneeLinkSql>(req)
{

}

