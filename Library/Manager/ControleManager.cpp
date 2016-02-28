#include "ControleManager.h"

ControleManager::ControleManager()
    : ManagerSql("controle",
              QVector<QString>()<<"classe"<<"date"<<"decimale"<<"minima"<<"nom"<<"saisie"<<"total"<<"type",
              QVector<int>()<<Controle::ClassePos<<Controle::NomPos) {}

ControleManager::ControleManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"controle",
              QVector<QString>()<<"classe"<<"date"<<"decimale"<<"minima"<<"nom"<<"saisie"<<"total"<<"type",
              QVector<int>()<<Controle::ClassePos<<Controle::NomPos) {}
