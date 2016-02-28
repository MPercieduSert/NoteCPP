#include "SourceManager.h"

SourceManager::SourceManager()
    : ManagerSql("Source",
              QVector<QString>()<<"nom"<<"type",
              QVector<int>()<<Source::NomPos<<Source::TypePos) {}

SourceManager::SourceManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"Source",
              QVector<QString>()<<"nom"<<"type",
              QVector<int>()<<Source::NomPos<<Source::TypePos) {}
