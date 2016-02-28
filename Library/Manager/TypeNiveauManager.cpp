#include "TypeNiveauManager.h"

TypeNiveauManager::TypeNiveauManager()
    : ManagerSql("typeNiveau",
              QVector<QString>()<<"nom",
              QVector<int>()<<TypeNiveau::NomPos) {}

TypeNiveauManager::TypeNiveauManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"typeNiveau",
              QVector<QString>()<<"nom",
              QVector<int>()<<TypeNiveau::NomPos) {}
