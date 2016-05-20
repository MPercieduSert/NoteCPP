/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYNOM
#define ENTITYNOM

#include "Entity.h"

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut nom.
 */
template<class Ent> class NomEntity : public EntityTemp<Ent>, public NomAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    NomEntity(int id = 0)
        : EntityTemp<Ent>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NomEntity(const QString & nom, int id = 0)
        : EntityTemp<Ent>(id), NomAttribut(nom)
    {}

    //! Constructeur de recopie.
    NomEntity(const NomEntity<Ent> & entity)
        : EntityTemp<Ent>(entity), NomAttribut(entity.nom())
    {}

    //! Destructeur.
    ~NomEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return EntityTemp<Ent>::isValid()
                && NomAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return Entity::egal(entity)
                && (nom() == entity.nom());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        Entity::set(entity);
        setNom(entity.nom());
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut nom et type.
 */
template<class Ent> class TypeNomEntity : public NomEntity<Ent>, public TypeAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    TypeNomEntity(int id = 0)
        : NomEntity<Ent>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    TypeNomEntity(const QString & nom, int type = 0, int id = 0)
        : NomEntity<Ent>(nom,id),
          TypeAttribut(type)
    {}

    //! Constructeur de recopie.
    TypeNomEntity(const TypeNomEntity<Ent> & entity)
        : NomEntity<Ent>(entity), TypeAttribut(entity.type())
    {}

    //! Destructeur.
    ~TypeNomEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return NomEntity<Ent>::isValid()
                && TypeAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return NomEntity<Ent>::egal(entity)
                && (type() == entity.type());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        NomEntity<Ent>::set(entity);
        setType(entity.type());
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut nom et nc.
 */
template<class Ent> class NcNomEntity : public NomEntity<Ent>, public NcAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    NcNomEntity(int id = 0)
        : NomEntity<Ent>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NcNomEntity(const QString & nc, const QString & nom, int id = 0)
        : NomEntity<Ent>(nom,id),
          NcAttribut(nc)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    NcNomEntity(const QString & nom)
        : NomEntity<Ent>(nom)
    {}

    //! Constructeur de recopie.
    NcNomEntity(const NcNomEntity<Ent> & entity)
        : NomEntity<Ent>(entity), NcAttribut(entity.nc())
    {}

    //! Destructeur.
    ~NcNomEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return NomEntity<Ent>::isValid()
                && NcAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return NomEntity<Ent>::egal(entity)
                && (nc() == entity.nc());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        NomEntity<Ent>::set(entity);
        setNc(entity.nc());
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant les attributs nom, nc et type.
 */
template<class Ent> class TypeNcNomEntity : public NcNomEntity<Ent>, public TypeAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    TypeNcNomEntity(int id = 0)
        : NcNomEntity<Ent>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    TypeNcNomEntity(const QString & nc, const QString & nom, int type = 0, int id = 0)
        : NcNomEntity<Ent>(nc,nom,id),
          TypeAttribut(type)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    TypeNcNomEntity(const QString & nom, int type = 0)
        : NcNomEntity<Ent>(nom), TypeAttribut(type)
    {}

    //! Constructeur de recopie.
    TypeNcNomEntity(const TypeNcNomEntity<Ent> & entity)
        : NcNomEntity<Ent>(entity), TypeAttribut(entity.type())
    {}

    //! Destructeur.
    ~TypeNcNomEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return NcNomEntity<Ent>::isValid()
                && TypeAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return NcNomEntity<Ent>::egal(entity)
                && (type() == entity.type());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        NcNomEntity<Ent>::set(entity);
        setType(entity.type());
    }
};


/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant seulements les attributs nom et type.
 */
template<int N = 0> class NomTypeOnlyEntity : public TypeNomEntity<NomTypeOnlyEntity<N> >
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    NomTypeOnlyEntity(int id = 0)
        : TypeNomEntity<NomTypeOnlyEntity<N> >(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NomTypeOnlyEntity(const QString & nom, int type = 0, int id = 0)
        : TypeNomEntity<NomTypeOnlyEntity<N> >(nom,type,id)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    NomTypeOnlyEntity(const QString & nom, int type = 0)
        : TypeNomEntity<NomTypeOnlyEntity<N> >(nom,type)
    {}

    //! Constructeur de recopie.
    NomTypeOnlyEntity(const NomTypeOnlyEntity<N> & entity)
        : TypeNomEntity<NomTypeOnlyEntity<N> >(entity)
    {}

    //! Destructeur.
    ~NomTypeOnlyEntity()
    {}
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant seulements les attributs nom, nc et type.
 */
template<int N = 0> class NcNomTypeOnlyEntity : public TypeNcNomEntity<NcNomTypeOnlyEntity<N> >
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    NcNomTypeOnlyEntity(int id = 0)
        : TypeNcNomEntity<NcNomTypeOnlyEntity<N> >(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NcNomTypeOnlyEntity(const QString & nc, const QString & nom, int type = 0, int id = 0)
        : TypeNcNomEntity<NcNomTypeOnlyEntity<N> >(nc,nom,type,id)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    NcNomTypeOnlyEntity(const QString & nom, int type = 0)
        : TypeNcNomEntity<NcNomTypeOnlyEntity<N> >(nom,type)
    {}

    //! Constructeur de recopie.
    NcNomTypeOnlyEntity(const NcNomTypeOnlyEntity<N> & entity)
        : TypeNcNomEntity<NcNomTypeOnlyEntity<N> >(entity)
    {}

    //! Destructeur.
    ~NcNomTypeOnlyEntity()
    {}
};

#endif // ENTITYNOM
