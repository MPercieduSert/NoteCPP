#include "TypeGroupeManager.h"

TypeGroupeManager::TypeGroupeManager()
    : ManagerTemp("typeGroupe",
              QVector<QString>()<<"alpha"<<"classe"<<"nom"<<"type",
              QVector<int>()<<TypeGroupe::ClassePos<<TypeGroupe::NomPos) {}

TypeGroupeManager::TypeGroupeManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"typeGroupe",
              QVector<QString>()<<"alpha"<<"classe"<<"nom"<<"type",
              QVector<int>()<<TypeGroupe::ClassePos<<TypeGroupe::NomPos) {}
