#include "TypeGroupeManager.h"

TypeGroupeManager::TypeGroupeManager()
    : ManagerSql("typeGroupe",
              QVector<QString>()<<"alpha"<<"classe"<<"nom"<<"type",
              QVector<int>()<<TypeGroupe::ClassePos<<TypeGroupe::NomPos) {}

TypeGroupeManager::TypeGroupeManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"typeGroupe",
              QVector<QString>()<<"alpha"<<"classe"<<"nom"<<"type",
              QVector<int>()<<TypeGroupe::ClassePos<<TypeGroupe::NomPos) {}
