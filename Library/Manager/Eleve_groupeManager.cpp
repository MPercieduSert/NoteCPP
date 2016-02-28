#include "Eleve_groupeManager.h"

Eleve_groupeManager::Eleve_groupeManager()
    : ManagerSql("eleve_groupe",
              QVector<QString>()<<"eleve"<<"groupe",
              QVector<int>()<<Eleve_groupe::ElevePos<<Eleve_groupe::GroupePos) {}

Eleve_groupeManager::Eleve_groupeManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"eleve_groupe",
              QVector<QString>()<<"eleve"<<"groupe",
              QVector<int>()<<Eleve_groupe::ElevePos<<Eleve_groupe::GroupePos) {}
