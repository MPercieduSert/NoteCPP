#include "ExerciceManager.h"

ExerciceManager::ExerciceManager()
    : ManagerTemp("exercice",
              QVector<QString>()<<"enonce"<<"feuille"<<"niveau"<<"num"<<"pere"<<"version"<<"correction"<<"source"<<"titre",
              QVector<int>()<<Exercice::PerePos<<Exercice::NumPos<<Exercice::VersionPos) {}

ExerciceManager::ExerciceManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"exercice",
              QVector<QString>()<<"enonce"<<"feuille"<<"niveau"<<"num"<<"pere"<<"version"<<"correction"<<"source"<<"titre",
              QVector<int>()<<Exercice::PerePos<<Exercice::NumPos<<Exercice::VersionPos) {}
