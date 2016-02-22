#include "ClasseManager.h"

ClasseManager::ClasseManager()
    : ManagerTemp("classe",
              QVector<QString>()<<"annee"<<"nbr_phase"<<"niveau"<<"num",
              QVector<int>()<<Classe::AnneePos<<Classe::NiveauPos<<Classe::NumPos) {}

ClasseManager::ClasseManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"classe",
              QVector<QString>()<<"annee"<<"nbr_phase"<<"niveau"<<"num",
              QVector<int>()<<Classe::AnneePos<<Classe::NiveauPos<<Classe::NumPos) {}
