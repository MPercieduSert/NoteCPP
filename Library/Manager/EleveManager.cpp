#include "EleveManager.h"

EleveManager::EleveManager()
    : ManagerTemp("eleve",
              QVector<QString>()<<"classe"<<"fille"<<"naissance"<<"nom"<<"prenom"<<"abandon",
              QVector<int>()<<Eleve::NomPos<<Eleve::PrenomPos<<Eleve::NaissancePos) {}

EleveManager::EleveManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"eleve",
              QVector<QString>()<<"classe"<<"fille"<<"naissance"<<"nom"<<"prenom"<<"abandon",
              QVector<int>()<<Eleve::NomPos<<Eleve::PrenomPos<<Eleve::NaissancePos) {}
