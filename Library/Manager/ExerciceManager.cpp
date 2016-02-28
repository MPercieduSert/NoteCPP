#include "ExerciceManager.h"

ExerciceManager::ExerciceManager()
    : ManagerSql("exercice",
              QVector<QString>()<<"enonce"<<"feuille"<<"niveau"<<"num"<<"pere"<<"version"<<"correction"<<"source"<<"titre",
              QVector<int>()<<Exercice::PerePos<<Exercice::NumPos<<Exercice::VersionPos) {}

ExerciceManager::ExerciceManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"exercice",
              QVector<QString>()<<"enonce"<<"feuille"<<"niveau"<<"num"<<"pere"<<"version"<<"correction"<<"source"<<"titre",
              QVector<int>()<<Exercice::PerePos<<Exercice::NumPos<<Exercice::VersionPos) {}
