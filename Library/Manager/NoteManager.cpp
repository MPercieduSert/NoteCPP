#include "NoteManager.h"

NoteManager::NoteManager(const Annee &annee)
    : ManagerAnnee("note",
                   QVector<QString>()<<"appreciation"<<"controle"<<"date"<<"eleve"<<"saisie"<<"valeur",
                   QVector<int>()<<Note::ControlePos<<Note::ElevePos,
                   annee) {}

NoteManager::NoteManager(QSqlDatabase & bdd, const Annee &annee)
    : ManagerAnnee(bdd,"note",
                   QVector<QString>()<<"appreciation"<<"controle"<<"date"<<"eleve"<<"saisie"<<"valeur",
                   QVector<int>()<<Note::ControlePos<<Note::ElevePos,
                   annee) {}
