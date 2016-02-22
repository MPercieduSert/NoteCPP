#include "TypeControleManager.h"

TypeControleManager::TypeControleManager()
    : ManagerTemp("typeControle",
              QVector<QString>()<<"appreciation"<<"decimale"<<"modifT"<<"nc"<<"nom"<<"total",
              QVector<int>()<<TypeControle::NomPos) {}

TypeControleManager::TypeControleManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"typeControle",
              QVector<QString>()<<"appreciation"<<"decimale"<<"modifT"<<"nc"<<"nom"<<"total",
              QVector<int>()<<TypeControle::NomPos) {}
