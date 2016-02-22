#ifndef COMMENTAIREMANAGER_H
#define COMMENTAIREMANAGER_H

#include "ManagerAnnee.h"
#include "../Entities/Commentaire.h"

class CommentaireManager : public ManagerAnnee<Commentaire>
{
public:
    CommentaireManager(const Annee & annee);
    CommentaireManager(QSqlDatabase & bdd, const Annee & annee);
     ~CommentaireManager()    {}

protected:
     void bindValues(const Commentaire & commentaire)
    {
        m_requete.bindValue(0,commentaire.texte());
        m_requete.bindValue(1,commentaire.type());
    }
     void bindValuesUnique(const Commentaire &commentaire)
    {
        m_requete.bindValue(0,commentaire.texte());
    }
     void fromRequete(Commentaire & commentaire)
    {
        commentaire.setTexte(m_requete.value(0).toString());
        commentaire.setType(m_requete.value(1).toInt());
    }
     Commentaire * newFromRequete()
    {
        return new Commentaire(m_requete.value(1).toString(),
                               m_requete.value(2).toInt(),
                               m_requete.value(0).toInt());
    }
};

#endif // COMMENTAIREMANAGER_H
