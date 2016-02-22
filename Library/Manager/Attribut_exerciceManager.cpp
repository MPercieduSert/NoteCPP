#include "Attribut_exerciceManager.h"

Attribut_exerciceManager::Attribut_exerciceManager()
    : ManagerTemp("attribut_exercice",
              QVector<QString>()<<"attribut"<<"exercice",
              QVector<int>()<<Attribut_exercice::AttributPos<<Attribut_exercice::ExercicePos) {}

Attribut_exerciceManager::Attribut_exerciceManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"attribut_exercice",
              QVector<QString>()<<"attribut"<<"exercice",
              QVector<int>()<<Attribut_exercice::AttributPos<<Attribut_exercice::ExercicePos) {}
