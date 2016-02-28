#include "ClasseManager.h"

ClasseManager::ClasseManager()
    : ManagerSql("classe",
              QVector<QString>()<<"annee"<<"nbr_phase"<<"niveau"<<"num",
              QVector<int>()<<Classe::AnneePos<<Classe::NiveauPos<<Classe::NumPos) {}

ClasseManager::ClasseManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"classe",
              QVector<QString>()<<"annee"<<"nbr_phase"<<"niveau"<<"num",
              QVector<int>()<<Classe::AnneePos<<Classe::NiveauPos<<Classe::NumPos) {}
