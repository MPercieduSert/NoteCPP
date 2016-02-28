#include "TypeControleManager.h"

TypeControleManager::TypeControleManager()
    : ManagerSql("typeControle",
              QVector<QString>()<<"appreciation"<<"decimale"<<"modifT"<<"nc"<<"nom"<<"total",
              QVector<int>()<<TypeControle::NomPos) {}

TypeControleManager::TypeControleManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"typeControle",
              QVector<QString>()<<"appreciation"<<"decimale"<<"modifT"<<"nc"<<"nom"<<"total",
              QVector<int>()<<TypeControle::NomPos) {}
