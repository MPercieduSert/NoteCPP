#include "ControleManager.h"

ControleManager::ControleManager()
    : ManagerTemp("controle",
              QVector<QString>()<<"classe"<<"date"<<"decimale"<<"minima"<<"nom"<<"saisie"<<"total"<<"type",
              QVector<int>()<<Controle::ClassePos<<Controle::NomPos) {}

ControleManager::ControleManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"controle",
              QVector<QString>()<<"classe"<<"date"<<"decimale"<<"minima"<<"nom"<<"saisie"<<"total"<<"type",
              QVector<int>()<<Controle::ClassePos<<Controle::NomPos) {}
