/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYNOM
#define ENTITYNOM

#include "Entity.h"

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut nom.
 */
class NomEntity : public Entity
{
    ATTRIBUT_ENTITY_STR_NOT_EMPTY(Nom,nom)
public:
    //! Positions des attributs.
    enum Position {Id = Entity::Id,
                   Nom = Entity::NbrAtt,
                   NbrAtt};

    using Entity::Entity;
    BASE_ENTITY_ABS(NomEntity)

    //! Constructeur à partir des valeurs attributs.
    NomEntity(const QString & nom, int id = 0)
        : Entity(id), m_nom(nom) {}

    MEMBRE_ATT_1(NomEntity,Entity,Nom,nom)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut nom et nc.
 */
class NcNomEntity : public NomEntity
{
    ATTRIBUT_ENTITY_STR_NOT_EMPTY(Nc,nc)
public:
    //! Positions des attributs.
    enum Position {Id = NomEntity::Id,
                   Nom = NomEntity::Nom,
                   Nc = NomEntity::NbrAtt,
                   NbrAtt};

    using NomEntity::NomEntity;
    BASE_ENTITY_ABS(NcNomEntity)

    //! Constructeur à partir des valeurs attributs.
    NcNomEntity(const QString & nc, const QString & nom, int id = 0)
        : NomEntity(nom,id), m_nc(nc) {}

    MEMBRE_ATT_1(NcNomEntity,NomEntity,Nc,nc)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut nom et type.
 */
class TypeNomEntity : public NomEntity
{
    ATTRIBUT_ENTITY_INT_SUP(Type,type,0)
public:
    //! Positions des attributs.
    enum Position {Id = NomEntity::Id,
                   Nom = NomEntity::Nom,
                   Type = NomEntity::NbrAtt,
                   NbrAtt};

    BASE_ENTITY_ABS(TypeNomEntity)

    //! Constructeur.
    TypeNomEntity(int id)
        : NomEntity(id) {}

    //! Constructeur à partir des valeurs attributs.
    TypeNomEntity(const QString & nom, int type, int id = 0)
        : NomEntity(nom,id), m_type(type) {}

    MEMBRE_ATT_1(TypeNomEntity,NomEntity,Type,type)
};


/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant les attributs nom, nc et type.
 */
class TypeNcNomEntity : public TypeNomEntity
{
    ATTRIBUT_ENTITY_STR_NOT_EMPTY(Nc,nc)
public:
    //! Positions des attributs.
    enum Position {Id = TypeNomEntity::Id,
                   Nom = TypeNomEntity::Nom,
                   Type = TypeNomEntity::Type,
                   Nc = TypeNomEntity::NbrAtt,
                   NbrAtt};

    using TypeNomEntity::TypeNomEntity;
    BASE_ENTITY_ABS(TypeNcNomEntity)

    //! Constructeur à partir des valeurs attributs.
    TypeNcNomEntity(const QString & nc, const QString & nom, int type = 0, int id = 0)
        : TypeNomEntity(nom,type,id), m_nc(nc) {}

    MEMBRE_ATT_1(TypeNcNomEntity,TypeNomEntity,Nc,nc)
};

#endif // ENTITYNOM
