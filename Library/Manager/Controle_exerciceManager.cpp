#include "Controle_exerciceManager.h"

Controle_exerciceManager::Controle_exerciceManager()
    : ManagerTemp("controle_exercice",
              QVector<QString>()<<"controle"<<"exercice"<<"num",
              QVector<int>()<<Controle_exercice::ControlePos<<Controle_exercice::ExercicePos) {}

Controle_exerciceManager::Controle_exerciceManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"controle_exercice",
              QVector<QString>()<<"controle"<<"exercice"<<"num",
              QVector<int>()<<Controle_exercice::ControlePos<<Controle_exercice::ExercicePos) {}
