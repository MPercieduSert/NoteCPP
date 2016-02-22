#include "SourceManager.h"

SourceManager::SourceManager()
    : ManagerTemp("Source",
              QVector<QString>()<<"nom"<<"type",
              QVector<int>()<<Source::NomPos<<Source::TypePos) {}

SourceManager::SourceManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"Source",
              QVector<QString>()<<"nom"<<"type",
              QVector<int>()<<Source::NomPos<<Source::TypePos) {}
