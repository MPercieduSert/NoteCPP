#include "GroupeManager.h"

GroupeManager::GroupeManager()
    : ManagerTemp("groupe",
              QVector<QString>()<<"num"<<"type",
              QVector<int>()<<Groupe::NumPos<<Groupe::TypePos) {}

GroupeManager::GroupeManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"groupe",
              QVector<QString>()<<"num"<<"type",
              QVector<int>()<<Groupe::NumPos<<Groupe::TypePos) {}
