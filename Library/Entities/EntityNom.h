/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYNOM
#define ENTITYNOM

#include "Entity.h"

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut nom.
 */
template<class Ent, class Info> class NomEntity : public EntityTemp<Ent,Info>, public NomAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    NomEntity(int id = 0)
        : EntityTemp<Ent,Info>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NomEntity(const QString & nom, int id = 0)
        : EntityTemp<Ent,Info>(id), NomAttribut(nom)
    {}

    //! Constructeur de recopie.
    NomEntity(const NomEntity<Ent,Info> & entity)
        : EntityTemp<Ent,Info>(entity), NomAttribut(entity.nom())
    {}

    //! Destructeur.
    ~NomEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return EntityTemp<Ent,Info>::isValid()
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
template<class Ent, class Info> class TypeNomEntity : public NomEntity<Ent,Info>, public TypeAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    TypeNomEntity(int id = 0)
        : NomEntity<Ent,Info>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    TypeNomEntity(const QString & nom, int type = 0, int id = 0)
        : NomEntity<Ent,Info>(nom,id),
          TypeAttribut(type)
    {}

    //! Constructeur de recopie.
    TypeNomEntity(const TypeNomEntity<Ent,Info> & entity)
        : NomEntity<Ent,Info>(entity), TypeAttribut(entity.type())
    {}

    //! Destructeur.
    ~TypeNomEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return NomEntity<Ent,Info>::isValid()
                && TypeAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return NomEntity<Ent,Info>::egal(entity)
                && (type() == entity.type());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        NomEntity<Ent,Info>::set(entity);
        setType(entity.type());
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut nom et nc.
 */
template<class Ent, class Info> class NcNomEntity : public NomEntity<Ent,Info>, public NcAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    NcNomEntity(int id = 0)
        : NomEntity<Ent,Info>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NcNomEntity(const QString & nc, const QString & nom, int id = 0)
        : NomEntity<Ent,Info>(nom,id),
          NcAttribut(nc)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    NcNomEntity(const QString & nom)
        : NomEntity<Ent,Info>(nom)
    {}

    //! Constructeur de recopie.
    NcNomEntity(const NcNomEntity<Ent,Info> & entity)
        : NomEntity<Ent,Info>(entity), NcAttribut(entity.nc())
    {}

    //! Destructeur.
    ~NcNomEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return NomEntity<Ent,Info>::isValid()
                && NcAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return NomEntity<Ent,Info>::egal(entity)
                && (nc() == entity.nc());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        NomEntity<Ent,Info>::set(entity);
        setNc(entity.nc());
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant les attributs nom, nc et type.
 */
template<class Ent, class Info> class TypeNcNomEntity : public NcNomEntity<Ent,Info>, public TypeAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    TypeNcNomEntity(int id = 0)
        : NcNomEntity<Ent,Info>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    TypeNcNomEntity(const QString & nc, const QString & nom, int type = 0, int id = 0)
        : NcNomEntity<Ent,Info>(nc,nom,id),
          TypeAttribut(type)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    TypeNcNomEntity(const QString & nom, int type = 0)
        : NcNomEntity<Ent,Info>(nom), TypeAttribut(type)
    {}

    //! Constructeur de recopie.
    TypeNcNomEntity(const TypeNcNomEntity<Ent,Info> & entity)
        : NcNomEntity<Ent,Info>(entity), TypeAttribut(entity.type())
    {}

    //! Destructeur.
    ~TypeNcNomEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return NcNomEntity<Ent,Info>::isValid()
                && TypeAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return NcNomEntity<Ent,Info>::egal(entity)
                && (type() == entity.type());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        NcNomEntity<Ent,Info>::set(entity);
        setType(entity.type());
    }
};


/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant seulements les attributs nom et type.
 */
template<class Info> class NomTypeOnlyEntity : public TypeNomEntity<NomTypeOnlyEntity<Info>,Info>
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    NomTypeOnlyEntity(int id = 0)
        : TypeNomEntity<NomTypeOnlyEntity<Info>,Info>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NomTypeOnlyEntity(const QString & nom, int type = 0, int id = 0)
        : TypeNomEntity<NomTypeOnlyEntity<Info>,Info>(nom,type,id)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    NomTypeOnlyEntity(const QString & nom, int type = 0)
        : TypeNomEntity<NomTypeOnlyEntity<Info>,Info>(nom,type)
    {}

    //! Constructeur de recopie.
    NomTypeOnlyEntity(const NomTypeOnlyEntity<Info> & entity)
        : TypeNomEntity<NomTypeOnlyEntity<Info>,Info>(entity)
    {}

    //! Destructeur.
    ~NomTypeOnlyEntity()
    {}
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant seulements les attributs nom, nc et type.
 */
template<class Info> class NcNomTypeOnlyEntity : public TypeNcNomEntity<NcNomTypeOnlyEntity<Info>,Info>
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    NcNomTypeOnlyEntity(int id = 0)
        : TypeNcNomEntity<NcNomTypeOnlyEntity<Info>,Info>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NcNomTypeOnlyEntity(const QString & nc, const QString & nom, int type = 0, int id = 0)
        : TypeNcNomEntity<NcNomTypeOnlyEntity<Info>,Info>(nc,nom,type,id)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    NcNomTypeOnlyEntity(const QString & nom, int type = 0)
        : TypeNcNomEntity<NcNomTypeOnlyEntity<Info>,Info>(nom,type)
    {}

    //! Constructeur de recopie.
    NcNomTypeOnlyEntity(const NcNomTypeOnlyEntity<Info> & entity)
        : TypeNcNomEntity<NcNomTypeOnlyEntity<Info>,Info>(entity)
    {}

    //! Destructeur.
    ~NcNomTypeOnlyEntity()
    {}
};

#endif // ENTITYNOM
