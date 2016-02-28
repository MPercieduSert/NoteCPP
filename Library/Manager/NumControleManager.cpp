#include "NumControleManager.h"

NumControleManager::NumControleManager()
    : ManagerSql("numControle",
              QVector<QString>()<<"classe"<<"num"<<"type",
              QVector<int>()<<NumControle::ClassePos<<NumControle::TypePos) {}

NumControleManager::NumControleManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"numControle",
              QVector<QString>()<<"classe"<<"num"<<"type",
              QVector<int>()<<NumControle::ClassePos<<NumControle::TypePos) {}
