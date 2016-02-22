#include "AttributManager.h"

AttributManager::AttributManager()
    : ManagerTemp("attribut",
              QVector<QString>()<<"feuille"<<"niveau"<<"nom"<<"num"<<"pere"<<"nc",
              QVector<int>()<<Attribut::NumPos<<Attribut::PerePos) {}

AttributManager::AttributManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"attribut",
              QVector<QString>()<<"feuille"<<"niveau"<<"nom"<<"num"<<"pere"<<"nc",
              QVector<int>()<<Attribut::NumPos<<Attribut::PerePos) {}
