/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/02/2016
 */
#ifndef ELEVE_H
#define ELEVE_H

#include "AttributEntityAlias.h"
#include "EntityNom.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Eleve.
 */
class Eleve : public NomEntity<Eleve>, public FilleAttribut, public NaissanceAttribut, public PrenomAttribut
{
public:
    //! Constructeur par defaut.
    Eleve(int id = 0)
        : NomEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    Eleve(bool fille, const QDate & naissance, const QString &nom, const QString &prenom, int id = 0)
        : NomEntity(nom, id),
          FilleAttribut(fille),
          NaissanceAttribut(naissance),
          PrenomAttribut(prenom)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Eleve(const QDate & naissance, const QString &nom, const QString &prenom)
        : NomEntity(nom),
          NaissanceAttribut(naissance),
          PrenomAttribut(prenom)
    {}

    //! Renvoie F si l'éléve est une fille et M sinon.
    QChar afficheFille() const                      {return fille() ? QChar('F'): QChar('M');}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return NomEntity::isValid()
                && FilleAttribut::valide()
                && NaissanceAttribut::valide()
                && PrenomAttribut::valide();
    }

    //! Destructeur.
    ~Eleve()
    {}

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Eleve & entity) const
    {
        return NomEntity::egal(entity)
                &&(fille() == entity.fille())
                &&(naissance() == entity.naissance())
                &&(prenom() == entity.prenom());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Eleve & entity)
    {
        NomEntity::set(entity);
        setFille(entity.fille());
        setNaissance(entity.naissance());
        setPrenom(entity.prenom());
    }
};

#endif // ELEVE_H
