#include "ClasseManager.h"

ClasseManager::ClasseManager(QSqlQuery &req)
    :ManagerSql<ClasseLinkSql>(req)
{

}
