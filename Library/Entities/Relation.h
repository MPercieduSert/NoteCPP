/*Auteur: PERCIE DU SERT Maxime
 *Date: 24/03/2016
 */

#ifndef RELATION
#define RELATION

#include "EntityRelation.h"

// Macros definissant les info sur les relations.

/*! \defgroup groupeInfoMacroEntity Information
 * \ingroup groupeMacroEntity
 * \brief Ensemble des macros définissant les informations sur les entité.
 */

//! \ingroup groupeInfoMacroEntity
//! Macro définissant les informations sur les entités de type relation simple.
#define INFO_REL_DATE(ENTITY,ID1,ID2) \
    /*! \ingroup groupeInfoEntity*/ \
    /*! \brief Information sur l'entité ENTITY.*/ \
    struct ENTITY ## Info{ \
        static const int ID = InfoEntity::ENTITY ## Id; \
        static constexpr char Name[] {#ENTITY}; \
        ATTRIBUT_3(Id ## ID1,Id ## ID2,Date)};

//! \ingroup groupeInfoMacroEntity
//! Macro définissant les informations sur les entités de type relation simple.
#define INFO_REL_DATE_VAL(ENTITY,ID1,ID2) \
    /*! \ingroup groupeInfoEntity*/ \
    /*! \brief Information sur l'entité ENTITY.*/ \
    struct ENTITY ## Info{ \
        static const int ID = InfoEntity::ENTITY ## Id; \
        static constexpr char Name[] {#ENTITY}; \
        ATTRIBUT_4(Id ## ID1,Id ## ID2,Date,Valeur)};

//! \ingroup groupeInfoMacroEntity
//! Macro définissant les informations sur les entités de type relation simple.
#define INFO_REL_NUM(ENTITY,ID1,ID2) \
    /*! \ingroup groupeInfoEntity*/ \
    /*! \brief Information sur l'entité ENTITY.*/ \
    struct ENTITY ## Info{ \
        static const int ID = InfoEntity::ENTITY ## Id; \
        static constexpr char Name[] {#ENTITY}; \
        ATTRIBUT_3(Id ## ID1,Id ## ID2,Num)};

//! \ingroup groupeInfoMacroEntity
//! Macro définissant les informations sur les entités de type relation simple.
#define INFO_REL_SIMPLE(ENTITY,ID1,ID2) \
    /*! \ingroup groupeInfoEntity*/ \
    /*! \brief Information sur l'entité ENTITY.*/ \
    struct ENTITY ## Info{ \
        static const int ID = InfoEntity::ENTITY ## Id; \
        static constexpr char Name[] {#ENTITY}; \
        ATTRIBUT_2(Id ## ID1,Id ## ID2)};

// Macros definissant les relations.

//! \ingroup groupeMacroEntity
//! Macro Implémentant une classe de relation daté.
#define REL_DATE(ENTITY,ID1,ID2) \
    INFO_REL_DATE(ENTITY,ID1,ID2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entité ENTITY.*/ \
    class ENTITY : public DateRelationEntity<ENTITY,ENTITY ## Info> \
    {public: \
    RELATION_ALIAS_2_CLE(ID1,ID2) \
    /*! \brief Constructeur par defaut.*/ \
    ENTITY(int id = 0):DateRelationEntity(id) {} \
    /*! \brief Constructeur à partir des valeurs attributs.*/ \
    ENTITY(int id ## ID1, int id ## ID2, const QDate & date = QDate(), int id = 0):DateRelationEntity(id ## ID1,id ## ID2,date,id) {} \
    /*! \brief Constructeur de recopie.*/ \
    ENTITY(const ENTITY & entity):DateRelationEntity(entity) {} \
    /*! \brief Destructeur.*/ \
    ~ENTITY() {}};

//! \ingroup groupeMacroEntity
//! Macro Implémentant une classe de relation daté (valide).
#define REL_DATE_VAL(ENTITY,ID1,ID2) \
    INFO_REL_DATE_VAL(ENTITY,ID1,ID2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entité ENTITY.*/ \
class ENTITY : public ValeurDateRelationEntity<ENTITY,ENTITY ## Info> \
{public: \
    RELATION_ALIAS_2_CLE(ID1,ID2) \
    /*! \brief Constructeur par defaut.*/ \
    ENTITY(int id = 0):ValeurDateRelationEntity(id) {} \
    /*! \brief Constructeur à partir des valeurs attributs.*/ \
    ENTITY(int id ## ID1, int id ## ID2, const QDate & date = QDate(), const QVariant & valeur = QVariant(), int id = 0) \
        :ValeurDateRelationEntity(id ## ID1,id ## ID2,date,valeur,id) {} \
    /*! \brief Constructeur de recopie.*/ \
    ENTITY(const ENTITY & entity):ValeurDateRelationEntity(entity) {} \
    /*! \brief Destructeur.*/ \
    ~ENTITY() {}};

//! \ingroup groupeMacroEntity
//! Macro Implémentant une classe de relation numéroté.
#define REL_NUM(ENTITY,ID1,ID2) \
    INFO_REL_NUM(ENTITY,ID1,ID2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entité ENTITY.*/ \
class ENTITY : public NumRelationEntity<ENTITY,ENTITY ## Info> \
{public: \
    RELATION_ALIAS_2_CLE(ID1,ID2) \
    /*! \brief Constructeur par defaut.*/ \
    ENTITY(int id = 0):NumRelationEntity(id) {} \
    /*! \brief Constructeur à partir des valeurs attributs.*/ \
    ENTITY(int id ## ID1, int id ## ID2, int num = 0, int id = 0):NumRelationEntity(id ## ID1,id ## ID2,num,id) {} \
    /*! \brief Constructeur de recopie.*/ \
    ENTITY(const ENTITY & entity):NumRelationEntity(entity) {} \
    /*! \brief Destructeur.*/ \
    ~ENTITY() {}};

//! \ingroup groupeMacroEntity
//! Macro Implémentant une classe de relation simple.
#define REL_SIMPLE(ENTITY,ID1,ID2) \
    INFO_REL_SIMPLE(ENTITY,ID1,ID2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entité ENTITY.*/ \
class ENTITY : public RelationEntity<ENTITY,ENTITY ## Info> \
{public: \
    RELATION_ALIAS_2_CLE(ID1,ID2) \
    /*! \brief Constructeur par defaut.*/ \
    ENTITY(int id = 0):RelationEntity(id) {} \
    /*! \brief Constructeur à partir des valeurs attributs.*/ \
    ENTITY(int id ## ID1, int id ## ID2, int id = 0):RelationEntity(id ## ID1,id ## ID2,id) {} \
    /*! \brief Constructeur de recopie.*/ \
    ENTITY(const ENTITY & entity):RelationEntity(entity) {} \
    /*! \brief Destructeur.*/ \
    ~ENTITY() {}};

#endif // RELATION

