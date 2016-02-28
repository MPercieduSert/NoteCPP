#include "Attribut_baremeManager.h"

Attribut_baremeManager::Attribut_baremeManager()
    : ManagerSql("attribut_bareme",
              QVector<QString>()<<"attribut"<<"bareme",
              QVector<int>()<<Attribut_bareme::AttributPos<<Attribut_bareme::BaremePos) {}

Attribut_baremeManager::Attribut_baremeManager(QSqlDatabase & bdd)
    : ManagerSql(bdd,"attribut_bareme",
              QVector<QString>()<<"attribut"<<"bareme",
              QVector<int>()<<Attribut_bareme::AttributPos<<Attribut_bareme::BaremePos) {}
