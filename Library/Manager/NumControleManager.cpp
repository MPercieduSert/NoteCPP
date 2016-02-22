#include "NumControleManager.h"

NumControleManager::NumControleManager()
    : ManagerTemp("numControle",
              QVector<QString>()<<"classe"<<"num"<<"type",
              QVector<int>()<<NumControle::ClassePos<<NumControle::TypePos) {}

NumControleManager::NumControleManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"numControle",
              QVector<QString>()<<"classe"<<"num"<<"type",
              QVector<int>()<<NumControle::ClassePos<<NumControle::TypePos) {}
