/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYDIVERS
#define ENTITYDIVERS

#include "Entity.h"

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut num.
 */
template<class Ent> class NumEntity : public EntityTemp<Ent>, public NumAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    NumEntity(int id = 0)
        : EntityTemp<Ent>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NumEntity(int num, int id)
        : EntityTemp<Ent>(id), NumAttribut(num)
    {}

    //! Constructeur de recopie.
    NumEntity(const NumEntity<Ent> & entity)
        : EntityTemp<Ent>(entity), NumAttribut(entity.num())
    {}

    //! Destructeur.
    ~NumEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return EntityTemp<Ent>::isValid()
                && NumAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return Entity::egal(entity)
                && (num() == entity.num());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        Entity::set(entity);
        setNum(entity.num());
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut texte.
 */
template<class Ent> class TexteEntity : public EntityTemp<Ent>, public TexteAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    TexteEntity(int id = 0)
        : EntityTemp<Ent>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    TexteEntity(const QString & txt, int id = 0)
        : EntityTemp<Ent>(id), TexteAttribut(txt)
    {}

    //! Constructeur de recopie.
    TexteEntity(const TexteEntity<Ent> & entity)
        : EntityTemp<Ent>(entity), TexteAttribut(entity.texte())
    {}

    //! Destructeur.
    ~TexteEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return EntityTemp<Ent>::isValid()
                && TexteAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return Entity::egal(entity)
                && (texte() == entity.texte());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        Entity::set(entity);
        setTexte(entity.texte());
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant seulement un attribut texte.
 */
template<int N = 0> class TexteOnlyEntity : public TexteEntity<TexteOnlyEntity<N> >
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    TexteOnlyEntity(int id = 0)
        : TexteEntity<TexteOnlyEntity<N> >(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    TexteOnlyEntity(const QString & txt, int id = 0)
        : TexteEntity<TexteOnlyEntity<N> >(txt,id)
    {}

    //! Constructeur de recopie.
    TexteOnlyEntity(const TexteOnlyEntity<N> & entity)
        : TexteEntity<TexteOnlyEntity<N> >(entity)
    {}

    //! Destructeur.
    ~TexteOnlyEntity()
    {}
};
#endif // ENTITYDIVERS

