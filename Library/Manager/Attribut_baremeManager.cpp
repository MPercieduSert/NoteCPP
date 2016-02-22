#include "Attribut_baremeManager.h"

Attribut_baremeManager::Attribut_baremeManager()
    : ManagerTemp("attribut_bareme",
              QVector<QString>()<<"attribut"<<"bareme",
              QVector<int>()<<Attribut_bareme::AttributPos<<Attribut_bareme::BaremePos) {}

Attribut_baremeManager::Attribut_baremeManager(QSqlDatabase & bdd)
    : ManagerTemp(bdd,"attribut_bareme",
              QVector<QString>()<<"attribut"<<"bareme",
              QVector<int>()<<Attribut_bareme::AttributPos<<Attribut_bareme::BaremePos) {}
