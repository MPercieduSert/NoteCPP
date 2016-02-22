#include "CommentaireManager.h"

CommentaireManager::CommentaireManager(const Annee &annee)
    : ManagerAnnee("commentaire",
                   QVector<QString>()<<"texte"<<"type",
                   QVector<int>()<<Commentaire::TextePos,
                   annee) {}


CommentaireManager::CommentaireManager(QSqlDatabase & bdd, const Annee &annee)
    : ManagerAnnee(bdd,"commentaire",
                   QVector<QString>()<<"texte"<<"type",
                   QVector<int>()<<Commentaire::TextePos,
                   annee) {}
