#include "TypeNiveauManager.h"

TypeNiveauManager::TypeNiveauManager()
    : ManagerTemp("typeNiveau",
              QVector<QString>()<<"nom",
              QVector<int>()<<TypeNiveau::NomPos) {}

TypeNiveauManager::TypeNiveauManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"typeNiveau",
              QVector<QString>()<<"nom",
              QVector<int>()<<TypeNiveau::NomPos) {}
