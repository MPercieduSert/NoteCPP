#include "EleveManager.h"

EleveManager::EleveManager()
    : ManagerSql("eleve",
              QVector<QString>()<<"classe"<<"fille"<<"naissance"<<"nom"<<"prenom"<<"abandon",
              QVector<int>()<<Eleve::NomPos<<Eleve::PrenomPos<<Eleve::NaissancePos) {}

EleveManager::EleveManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"eleve",
              QVector<QString>()<<"classe"<<"fille"<<"naissance"<<"nom"<<"prenom"<<"abandon",
              QVector<int>()<<Eleve::NomPos<<Eleve::PrenomPos<<Eleve::NaissancePos) {}
