#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include "ManagerAnnee.h"
#include "../Entities/Note.h"
class NoteManager : public ManagerAnnee<Note>
{
public:
    NoteManager(const Annee & annee);
    NoteManager(QSqlDatabase & bdd, const Annee & annee);
     ~NoteManager()  {}

protected:
     void bindValues(const Note & note)
    {
        m_requete.bindValue(0,note.appreciation());
        m_requete.bindValue(1,note.controle());
        m_requete.bindValue(2,note.date());
        m_requete.bindValue(3,note.eleve());
        m_requete.bindValue(4,note.saisie());
        m_requete.bindValue(5,note.valeur());
    }
     void bindValuesUnique(const Note &note)
    {
        m_requete.bindValue(0,note.controle());
        m_requete.bindValue(1,note.eleve());
    }
     void fromRequete(Note & note)
    {
        note.setAppreciation(m_requete.value(0).toBool());
        note.setControle(m_requete.value(1).toInt());
        note.setDate(m_requete.value(2).toDateTime());
        note.setEleve(m_requete.value(3).toInt());
        note.setSaisie(m_requete.value(4).toBool());
        note.setValeur(m_requete.value(5).toInt());
    }
     Note * newFromRequete()
    {
        return new Note(m_requete.value(1).toBool(),
                        m_requete.value(2).toInt(),
                        m_requete.value(3).toDateTime(),
                        m_requete.value(4).toInt(),
                        m_requete.value(5).toBool(),
                        m_requete.value(6).toInt(),
                        m_requete.value(0).toInt());
    }
};

#endif // NOTEMANAGER_H
