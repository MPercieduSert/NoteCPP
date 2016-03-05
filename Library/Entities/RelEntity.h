/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/03/2016
 */

#ifndef RELENTITY_H
#define RELENTITY_H

#include "Entity.h"

// Macro pour les RelEntity.

//! \ingroup groupeEntity
//! Déclaration des variables statiques.
#define VAR_STAT_REL_SIMPLE(ID1,ID2,NOM) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {Id ## ID1 ## Pos = 0, Id ## ID2 ## Pos = 1, IdPos = 2}; \
    /*! \brief Identifiant du type de l'entitée. */ \
    static const entityId IdEntity = NOM ## Id; \
    /*! \brief Nom de l'entitée. */ \
    static constexpr char Name[] = #NOM; \
    /*! \brief Nombre d'attributs de l'entitée.*/ \
    static const int NbrAtt = 3; \
    /*! \brief Tableau des attributs de l'entitée.*/ \
    static constexpr std::array<const char*,NbrAtt> Att {{"Id" #ID1, "Id" #ID2, "ID"}};

//Constructeurs

//! \ingroup groupeEntity
//! Constructeur par défaut d'une relation.
#define CONSTR_REL_DEFAUT(ENTITY) \
    /*! \brief Constructeur par défaut fixant l'identifiant de l'entitée à 0.*/ \
    ENTITY() \
    {}

//! \ingroup groupeEntity
//! Constructeur recopiant une relation à partir d'une Entity.
#define CONSTR_REL_ENTITY(ENTITY) \
    /*! \brief Constructeur recopiant les attributs l'entitée entity.*/ \
    ENTITY(const Entity & entity) \
    : RelEntity(convert(entity)) \
    {set(convert(entity));}

//! \ingroup groupeEntity
//! Constructeur fixant l'identifiant pour une relation.
#define CONSTR_REL_ID(ENTITY) \
    /*! \brief Constructeur fixant l'identifiant de l'entitée.*/ \
    ENTITY(int id) \
    : RelEntity(id)   {}

//! \ingroup groupeEntity
//! Constructeur de recopie pour une relation.
#define CONSTR_REL_RECOPIE(ENTITY) \
    /*! \brief Constructeur de recopie.*/ \
    ENTITY(const ENTITY & entity) \
    : RelEntity(entity.id1(),entity.id2(),entity.id()) \
    {set(entity);}

//! \ingroup groupeEntity
//! Constructeur simple à partir des valeurs d'attributs.
#define CONSTR_REL_SIMPLE(ENTITY) \
    /*! \brief Constructeur à partir des valeurs attributs.*/ \
    ENTITY(int id1, int id2, int id) \
    : RelEntity(id1,id2,id) {}

//! \ingroup groupeEntity
//! Constructeur recopiant une relation simple à partir d'une Entity.
#define CONSTR_REL_SIMPLE_ENTITY(ENTITY) \
    /*! \brief Constructeur recopiant les attributs l'entitée entity.*/ \
    ENTITY(const Entity & entity) \
    : RelEntity(convert(entity)) {}

//! \ingroup groupeEntity
//! Constructeur de recopie pour une relation simple.
#define CONSTR_REL_SIMPLE_RECOPIE(ENTITY) \
    /*! \brief Constructeur de recopie.*/ \
    ENTITY(const ENTITY & entity) \
    : RelEntity(entity.id1(),entity.id2(),entity.id()) \
    {}

//! \ingroup groupeEntity
//! Regroupe les macros des constructeurs et la macro du destructeur par défaut pour une relation.
#define CONSTR_REL_MACRO(ENTITY) \
    CONSTR_REL_DEFAUT(ENTITY) \
    CONSTR_REL_ENTITY(ENTITY) \
    CONSTR_REL_ID(ENTITY) \
    CONSTR_REL_RECOPIE(ENTITY) \
    DESTRUCT(ENTITY)

//! \ingroup groupeEntity
//! Regroupe les macros des constructeurs et la macro du destructeur par défaut pour une relation simple.
#define CONSTR_REL_SIMPLE_MACRO(ENTITY) \
    CONSTR_REL_DEFAUT(ENTITY) \
    CONSTR_REL_SIMPLE_ENTITY(ENTITY) \
    CONSTR_REL_ID(ENTITY) \
    CONSTR_REL_SIMPLE_RECOPIE(ENTITY) \
    CONSTR_REL_SIMPLE(ENTITY) \
    DESTRUCT(ENTITY)

//Opérateurs

//! \ingroup groupeEntity
//! Macro définissant l'opérateur << avec une relation.
#define OP_INJ_REL(ENTITY) \
    /*! \brief Modifient les valeurs des attributs de l'entitée avec celles des attributs de entity.*/ \
    void operator << (const ENTITY & entity) \
    {setId(entity.id()); \
    RelEntity::set(entity); \
    set(entity);}

//! \ingroup groupeEntity
//! Macro définissant l'opérateur << avec une relation simple.
#define OP_INJ_REL_SIMPLE(ENTITY) \
    /*! \brief Modifient les valeurs des attributs de l'entitée avec celles des attributs de entity.*/ \
    void operator << (const ENTITY & entity) \
    {setId(entity.id()); \
    RelEntity::set(entity);}

//! \ingroup groupeEntity
//! Macro définissant l'opérateur << avec une Entity pour une realtion.
#define OP_INJ_REL_ENTITY(ENTITY) \
    /*! \brief Modifient les valeurs des attributs de l'entitée avec celles des attributs de entity.*/ \
    void operator << (const Entity & entity) \
    {setId(entity.id()); \
    const ENTITY & ref = convert(entity); \
    RelEntity::set(ref); \
    set(ref);}

//! \ingroup groupeEntity
//! Macro définissant l'opérateur << avec une Entity pour une relation simple.
#define OP_INJ_REL_SIMPLE_ENTITY(ENTITY) \
    /*! \brief Modifient les valeurs des attributs de l'entitée avec celles des attributs de entity.*/ \
    void operator << (const Entity & entity) \
    {setId(entity.id()); \
    RelEntity::set(convert(entity));}

//! \ingroup groupeEntity
//! Regroupe les macros des opérateurs pour les relations.
#define OP_REL_MACRO(ENTITY) \
    OP_EGAL(ENTITY) \
    OP_EGAL_ENTITY(ENTITY) \
    OP_INJ_REL(ENTITY) \
    OP_INJ_REL_ENTITY(ENTITY)

//! \ingroup groupeEntity
//! Regroupe les macros des opérateurs pour les relations simples.
#define OP_REL_SIMPLE_MACRO(ENTITY) \
    OP_EGAL(ENTITY) \
    OP_EGAL_ENTITY(ENTITY) \
    OP_INJ_REL(ENTITY) \
    OP_INJ_REL_ENTITY(ENTITY)

//Méthodes Communes

//! \ingroup groupeEntity
//! Macro permettant d'incorporer les macros communes à toutes les relations.
#define INCLUCE_REL_METHODE(ENTITY) \
    CONSTR_REL_MACRO(ENTITY) \
    CONVERT_MACRO(ENTITY) \
    OP_REL_MACRO(ENTITY) \
    MEMBRE_DIVER_MACRO(ENTITY)

//! \ingroup groupeEntity
//! Macro permettant d'incorporer les macros communes à toutes les relations.
#define INCLUCE_REL_SIMPLE_METHODE(ENTITY) \
    CONSTR_REL_SIMPLE_MACRO(ENTITY) \
    CONVERT_MACRO(ENTITY) \
    OP_REL_SIMPLE_MACRO(ENTITY) \
    MEMBRE_DIVER_MACRO(ENTITY)

//Getteurs et Setteurs pour les deux clés.

//! \ingroup groupeEntity
//! Implémentation des getteur et setteur d'une clé.
#define GET_SET_ID_REL(ATT,N) \
    /*! \brief Retourne la valeur de la clé id ## ATT.*/ \
    int id ## ATT() const {return m_id ## N;} \
    /*! \brief Modifie la clé id ## ATT.*/ \
    void set ## ATT(int id) \
    {if(id > 0) \
        {m_id ## N = id;} \
    else \
        {m_erreurs.append(QPair<int,int>(m_id,Id ## ATT ## Pos));}}

//Coprs de classe des relations simples.

//! \ingroup groupeEntity
//! Coprs de classe des relations simples.
#define REL_SIMPLE(ID1,ID2,NOM) \
    VAR_STAT_REL_SIMPLE(ID1,ID2,NOM) \
    INCLUCE_REL_SIMPLE_METHODE(NOM) \
    GET_SET_ID_REL(ID1,1) \
    GET_SET_ID_REL(ID2,2)

/*! \ingroup groupeEntity
 * \brief Classe mère des entitées représentatives d'une relation.
 */

class RelEntity : public Entity
{
public:
    //! Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.
    enum position {Id1Pos = 0,
                   Id2Pos = 1,
                   IdPos = 2};

    static const entityId IdEntity = RelEntityId;   //!< Identifiant du type de l'entitée.
    static constexpr char Name[] = "RelEntity";     //!< Nom de l'entitée.
    static const int NbrAtt = 3;                //!< Nombre d'attributs de l'entitée.
    static constexpr std::array<const char*,NbrAtt> Att {{"Id1", "Id2" "ID"}};  //!< Tableau des attributs de l'entitée.

protected:
    int m_id1;  //!< Clé1
    int m_id2;  //!< Clé2

public:
    INCLUCE_METHODE(RelEntity)

    //! Constructeur à partir des valeurs attributs.
    RelEntity(int id1, int id2, int id)
        : Entity(id)
    {
        setId1(id1);
        setId2(id2);
    }

    GET_SET_ID(1)
    GET_SET_ID(2)

    //! Teste si l'entitée est valide.
    bool isValid() const
        {return Entity::isValid() && (m_id1 > 0) && (m_id2 > 0);}

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const RelEntity & entity) const
    {
        return Entity::egal(entity)
                && (m_id1 == entity.m_id1)
                && (m_id2 == entity.m_id2);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const RelEntity & entity)
    {
        setId1(entity.id1());
        setId2(entity.id2());
    }
};

#endif // RELENTITY_H
