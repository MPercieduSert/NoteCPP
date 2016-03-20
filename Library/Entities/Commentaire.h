/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */

#ifndef COMMENTAIRE_H
#define COMMENTAIRE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Commentaire.
 */

class Commentaire : public TexteEntity, public EntityTemp<IdentifiantEntity::CommentaireId,2,Commentaire>
{
public:
    POS_1_ATT(Texte)

    //! Constructeur par defaut.
    Commentaire(int id = 0)
        : TexteEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    Commentaire(const QString & texte, int id = 0)
        : TexteEntity(texte, id)
    {}

    //! Constructeur de recopie.
    Commentaire(const Commentaire & entity)
        : TexteEntity(entity)
    {}

    //! Destructeur.
    ~Commentaire()
    {}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {return TexteEntity::isValid();}

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Commentaire & entity) const
    {return TexteEntity::egal(entity);}

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Commentaire & entity)
    {TexteEntity::set(entity);}
};

#endif // COMMENTAIRE_H
