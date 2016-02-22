#include "AppreciationManager.h"

AppreciationManager::AppreciationManager(const Annee & annee)
    : ManagerAnnee("appreciation",
                   QVector<QString>()<<"date"<<"note"<<"saisie"<<"texte",
                   QVector<int>()<<Appreciation::TextePos,
                   annee) {}

AppreciationManager::AppreciationManager(QSqlDatabase & bdd, const Annee & annee)
    : ManagerAnnee(bdd,"appreciation",
                   QVector<QString>()<<"date"<<"note"<<"saisie"<<"texte",
                   QVector<int>()<<Appreciation::TextePos,
                   annee) {}
