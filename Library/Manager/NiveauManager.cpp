#include "NiveauManager.h"

NiveauManager::NiveauManager()
    : ManagerTemp("niveau",
              QVector<QString>()<<"colle"<<"nom"<<"type",
              QVector<int>()<<Niveau::NomPos) {}

NiveauManager::NiveauManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"niveau",
              QVector<QString>()<<"colle"<<"nom"<<"type",
              QVector<int>()<<Niveau::NomPos) {}
