#include "BaremeManager.h"

BaremeManager::BaremeManager()
    : ManagerSql("bareme",
              QVector<QString>()<<"controle"<<"exercice"<<"fraction"<<"num"<<"nom"<<"valeur",
              QVector<int>()<<Bareme::ControlePos<<Bareme::ExercicePos<<Bareme::NumPos) {}

BaremeManager::BaremeManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"bareme",
              QVector<QString>()<<"controle"<<"exercice"<<"fraction"<<"num"<<"nom"<<"valeur",
              QVector<int>()<<Bareme::ControlePos<<Bareme::ExercicePos<<Bareme::NumPos) {}
