#include "AnneeManager.h"

AnneeManager::AnneeManager()
    : ManagerTemp("annee",
              QVector<QString>()<<"encours"<<"rentree",
              QVector<int>()<<Annee::RentreePos)  {}

AnneeManager::AnneeManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"annee",
              QVector<QString>()<<"encours"<<"rentree",
              QVector<int>()<<Annee::RentreePos)  {}
