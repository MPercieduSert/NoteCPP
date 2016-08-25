/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYDIVERS
#define ENTITYDIVERS

#include "Entity.h"

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut num.
 */
class NumEntity : public Entity
{
    ATTRIBUT_ENTITY_INT_SUP(Num,num,0)
public:
    using Entity::Entity;
    BASE_ENTITY_ABS(NumEntity)

    //! Constructeur à partir des valeurs attributs.
    NumEntity(int num, int id)
        : Entity(id), m_num(num) {}

    MEMBRE_ATT_1(NumEntity,Entity,Num,num)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut datetime et num.
 */
class DateTimeNumEntity : public NumEntity
{
    ATTRIBUT_ENTITY_DATETIME_VALIDE(Date,date)
public:
    using NumEntity::NumEntity;
    BASE_ENTITY_ABS(DateTimeNumEntity)

    //! Constructeur à partir des valeurs attributs.
    DateTimeNumEntity(const QDateTime & date, int num, int id = 0)
        : NumEntity(num,id), m_date(date) {}

    MEMBRE_ATT_1(DateTimeNumEntity,NumEntity,Date,date)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut texte.
 */
class TexteEntity : public Entity
{
    ATTRIBUT_ENTITY_STR_NOT_EMPTY(Texte,texte)
public:
    using Entity::Entity;
    BASE_ENTITY_ABS(TexteEntity)

    //! Constructeur à partir des valeurs attributs.
    TexteEntity(const QString & txt, int id = 0)
        : Entity(id), m_texte(txt) {}

    MEMBRE_ATT_1(TexteEntity,Entity,Texte,texte)
};

#endif // ENTITYDIVERS
