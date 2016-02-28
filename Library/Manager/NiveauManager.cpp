#include "NiveauManager.h"

NiveauManager::NiveauManager()
    : ManagerSql("niveau",
              QVector<QString>()<<"colle"<<"nom"<<"type",
              QVector<int>()<<Niveau::NomPos) {}

NiveauManager::NiveauManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"niveau",
              QVector<QString>()<<"colle"<<"nom"<<"type",
              QVector<int>()<<Niveau::NomPos) {}
