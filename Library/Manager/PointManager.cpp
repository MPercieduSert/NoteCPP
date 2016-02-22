#include "PointManager.h"

PointManager::PointManager(const Annee &annee)
    : ManagerAnnee("point",
                   QVector<QString>()<<"bareme"<<"commentaire"<<"date"<<"note"<<"saisie"<<"valeur",
                   QVector<int>()<<Point::BaremePos<<Point::NotePos,
                   annee) {}

PointManager::PointManager(QSqlDatabase & bdd, const Annee &annee)
    : ManagerAnnee(bdd,"point",
                   QVector<QString>()<<"bareme"<<"commentaire"<<"date"<<"note"<<"saisie"<<"valeur",
                   QVector<int>()<<Point::BaremePos<<Point::NotePos,
                   annee) {}
