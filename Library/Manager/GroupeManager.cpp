#include "GroupeManager.h"

GroupeManager::GroupeManager()
    : ManagerSql("groupe",
              QVector<QString>()<<"num"<<"type",
              QVector<int>()<<Groupe::NumPos<<Groupe::TypePos) {}

GroupeManager::GroupeManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"groupe",
              QVector<QString>()<<"num"<<"type",
              QVector<int>()<<Groupe::NumPos<<Groupe::TypePos) {}
