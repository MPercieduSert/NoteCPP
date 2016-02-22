#include "CoefficientManager.h"

CoefficientManager::CoefficientManager(const Annee &annee)
    : ManagerAnnee("coefficient",
                   QVector<QString>()<<"controle"<<"indice"<<"valeur",
                   QVector<int>()<<Coefficient::ControlePos<<Coefficient::IndicePos,
                   annee) {}

CoefficientManager::CoefficientManager(QSqlDatabase & bdd, const Annee &annee)
    : ManagerAnnee(bdd,"coefficient",
                   QVector<QString>()<<"controle"<<"indice"<<"valeur",
                   QVector<int>()<<Coefficient::ControlePos<<Coefficient::IndicePos,
                   annee) {}
