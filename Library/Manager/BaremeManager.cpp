#include "BaremeManager.h"

BaremeManager::BaremeManager()
    : ManagerTemp("bareme",
              QVector<QString>()<<"controle"<<"exercice"<<"fraction"<<"num"<<"nom"<<"valeur",
              QVector<int>()<<Bareme::ControlePos<<Bareme::ExercicePos<<Bareme::NumPos) {}

BaremeManager::BaremeManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"bareme",
              QVector<QString>()<<"controle"<<"exercice"<<"fraction"<<"num"<<"nom"<<"valeur",
              QVector<int>()<<Bareme::ControlePos<<Bareme::ExercicePos<<Bareme::NumPos) {}
