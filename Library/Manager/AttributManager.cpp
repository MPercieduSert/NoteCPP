#include "AttributManager.h"

AttributManager::AttributManager()
    : ManagerSql("attribut",
              QVector<QString>()<<"feuille"<<"niveau"<<"nom"<<"num"<<"pere"<<"nc",
              QVector<int>()<<Attribut::NumPos<<Attribut::PerePos) {}

AttributManager::AttributManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"attribut",
              QVector<QString>()<<"feuille"<<"niveau"<<"nom"<<"num"<<"pere"<<"nc",
              QVector<int>()<<Attribut::NumPos<<Attribut::PerePos) {}
