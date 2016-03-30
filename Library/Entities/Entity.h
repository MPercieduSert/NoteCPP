/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/02/2016
 */
#ifndef ENTITY_H
#define ENTITY_H

#include <array>
#include <QDate>
#include <QDateTime>
#include <QList>
#include <QPair>
#include <QString>
#include <QVariant>
#include <QVector>
#include <string>
#include <stdexcept>

#include "AttributEntityMacroAlias.h"

/*! \defgroup groupeEntity Entités
 * \brief Ensemble de classes représentant les entités de la base de donnée.
 */

/*! \defgroup groupeBaseEntity Classes de base des entités
 * \ingroup groupeEntity
 * \brief Ensemble des classes de base des entités.
 */

// Macro pour les entités

/*! \defgroup groupeMacroEntity Classes de base des entités
 * \ingroup groupeEntity
 * \brief Ensemble des Macros des entités.
 */

//Enumeration des positions et les variables statiques de EntityTemp

/*! \defgroup groupeNomPosEntity Enumeration des positions et les variables statiques de EntityTemp.
 * \ingroup groupeMacroEntity
 * \brief Ensemble de macrosdéfinissant l'numeration des positions et les variables statiques de EntityTemp.
 */

//! \ingroup groupeNomPosEntity
//! Macro définisant la position d'un attribut.
#define ATTRIBUT_1(ATT1) \
    /*! \brief Nombre d'attribut de l'entité.*/ \
    static const int NbrAtt = 2; \
    /*! \brief Tableau des noms des attributs de l'entité.*/ \
    static constexpr std::array<const char *, NbrAtt> Att{{#ATT1,"ID"}}; \
    /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, IdPos = 1};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de deux attributs.
#define ATTRIBUT_2(ATT1,ATT2) \
    /*! \brief Nombre d'attribut de l'entité.*/ \
    static const int NbrAtt = 3; \
    /*! \brief Tableau des noms des attributs de l'entité.*/ \
    static constexpr std::array<const char *, NbrAtt> Att{{#ATT1,#ATT2,"ID"}}; \
    /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, IdPos = 2};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de trois attributs.
#define ATTRIBUT_3(ATT1,ATT2,ATT3) \
    /*! \brief Nombre d'attribut de l'entité.*/ \
    static const int NbrAtt = 4; \
    /*! \brief Tableau des noms des attributs de l'entité.*/ \
    static constexpr std::array<const char *, NbrAtt> Att{{#ATT1,#ATT2,#ATT3,"ID"}}; \
    /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, IdPos = 3};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de quatre attributs.
#define ATTRIBUT_4(ATT1,ATT2,ATT3,ATT4) \
    /*! \brief Nombre d'attribut de l'entité.*/ \
    static const int NbrAtt = 5; \
    /*! \brief Tableau des noms des attributs de l'entité.*/ \
    static constexpr std::array<const char *, NbrAtt> Att{{#ATT1,#ATT2,#ATT3,#ATT4,"ID"}}; \
    /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, IdPos = 4};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de cinq attributs.
#define ATTRIBUT_5(ATT1,ATT2,ATT3,ATT4,ATT5) \
    /*! \brief Nombre d'attribut de l'entité.*/ \
    static const int NbrAtt = 6; \
    /*! \brief Tableau des noms des attributs de l'entité.*/ \
    static constexpr std::array<const char *, NbrAtt> Att{{#ATT1,#ATT2,#ATT3,#ATT4,#ATT5,"ID"}}; \
    /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, IdPos = 5};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de six attributs.
#define ATTRIBUT_6(ATT1,ATT2,ATT3,ATT4,ATT5,ATT6) \
    /*! \brief Nombre d'attribut de l'entité.*/ \
    static const int NbrAtt = 7; \
    /*! \brief Tableau des noms des attributs de l'entité.*/ \
    static constexpr std::array<const char *, NbrAtt> Att{{#ATT1,#ATT2,#ATT3,#ATT4,#ATT5,#ATT6,"ID"}}; \
    /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, ATT6 ## Pos = 5, IdPos = 6};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de sept attributs.
#define ATTRIBUT_7(ATT1,ATT2,ATT3,ATT4,ATT5,ATT6,ATT7) \
    /*! \brief Nombre d'attribut de l'entité.*/ \
    static const int NbrAtt = 8; \
    /*! \brief Tableau des noms des attributs de l'entité.*/ \
    static constexpr std::array<const char *, NbrAtt> Att{{#ATT1,#ATT2,#ATT3,#ATT4,#ATT5,#ATT6,#ATT7,"ID"}}; \
    /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, ATT6 ## Pos = 5, ATT7 ## Pos = 6, IdPos = 7};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de huit attributs.
#define ATTRIBUT_8(ATT1,ATT2,ATT3,ATT4,ATT5,ATT6,ATT7,ATT8) \
    /*! \brief Nombre d'attribut de l'entité.*/ \
    static const int NbrAtt = 9; \
    /*! \brief Tableau des noms des attributs de l'entité.*/ \
    static constexpr std::array<const char *, NbrAtt> Att{{#ATT1,#ATT2,#ATT3,#ATT4,#ATT5,#ATT6,#ATT7,#ATT8,"ID"}}; \
    /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, ATT6 ## Pos = 5, ATT7 ## Pos = 6, ATT7 ## Pos = 7, IdPos = 8};

/*! \ingroup groupeBaseEntity
 * \brief Classe abstraite de base des entités.
 */
class Entity : public IdAttributEntity
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    Entity(int id = 0)
        : IdAttributEntity(id)
    {}

    //! Constructeur de recopie.
    Entity(const Entity & entity)
        : Entity(entity.id())
    {}

    //! Destructeur.
    ~Entity()
    {}

    //! Teste si l'entité est nouvelle ou si elle provient de la base de donnée en regardant si elle poséde un identifiant non-nul.
    bool isNew() const
    {return id() == 0;}

    //! Renvoie l'identifiant du type de l'entité.
    virtual int idEntity() const = 0;

    //! Teste si l'entité est valide, c'est-à-dire si les attributs de l'entité sont valides.
    virtual bool isValid() const
    {return IdAttributEntity::valide();}

    //! Modifient les valeurs des attributs de l'entité avec celles des attributs de entity.
    virtual void operator << (const Entity & entity) = 0;

    //! Opérateur testant l'égalité de deux entités, c'est-à-dire l'égalité de tous les attributs.
    virtual bool operator == (const Entity & entity) const = 0;

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument, c'est-à-dire l'égalité de tous les attributs.
    bool egal(const Entity & entity) const
    {return id() == entity.id();}

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Entity & entity)
    {setId(entity.id());}
};

/*! \ingroup groupeBaseEntity
 * \brief Classe Patron abstraite implémentant une partie des méthodes virtuels des entités.
 */
template<class Ent, class Info> class EntityTemp : public Entity, public Info
{
public:
    //! Constructeur.
    EntityTemp(int id = 0)
        : Entity(id)
    {}

    //! Constructeur de recopie.
    EntityTemp(const EntityTemp<Ent,Info> & entity)
        : Entity(entity)
    {}

    //! Convertit la référence entity en une référence de type ENTITY, aprés vérification.
    static Ent * convert(Entity *entity)
    {
        if(verifEntity(entity))
        {
            return (Ent*) entity;
        }
        else
        {
            throw std::invalid_argument("Mauvaise correspondance des Entity");
        }
    }

    //!  Convertit la référence constante entity en une référence constante de type ENTITY, aprés vérification.
    static Ent & convert(Entity & entity)
    {
        if(verifEntity(entity))
        {
            return *((Ent*) &entity);
        }
        else
        {
            throw std::invalid_argument("Mauvaise correspondance des Entity");
        }
    }

    //! Convertit le pointeur entity en un pointeur de type ENTITY, aprés vérification.
    static const Ent & convert(const Entity & entity)
    {
        if(verifEntity(entity))
        {
            return *((Ent*) &entity);
        }
        else
        {
            throw std::invalid_argument("Mauvaise correspondance des Entity");
        }
    }

    //! Renvoie l'identifiant du type de l'entité.
    int idEntity() const
        {return Info::ID;}

    //! Renvoie le nom de l'entité.
    static QString name()
        {return Info::Name;}

    //! Test si le pointeur entity est aussi un pointeur de ce type d'entité.
    static bool verifEntity(Entity * entity)
    {return Info::ID == entity->idEntity();}

    //! Test si la référence entity est aussi une référence de ce type d'entité.
    static bool verifEntity(const Entity & entity)
    {return Info::ID == entity.idEntity();}

    //! Test d'égalité entre deux entités de même type, c'est-à-dire l'égalité de tous les attributs.
    bool operator == (const Ent & entity) const
    {return egal(entity);}

    //! Test d'égalité entre une entité et une référence Entity sur une entité de type que la première, c'est-à-dire l'égalité de tous les attributs.
    bool operator == (const Entity & entity) const
    {return egal(convert(entity));}

    //! Modifient les valeurs des attributs de l'entité avec celles des attributs de entity.
    void operator << (const Ent & entity)
    {set(entity);}

    //! Modifient les valeurs des attributs de l'entité avec celles des attributs de entity qui doit être de même type que la première opérande.
    void operator << (const Entity & entity)
    {set(convert(entity));}

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument, c'est-à-dire l'égalité de tous les attributs.
    virtual bool egal(const Ent & entity) const = 0;

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    virtual void set(const Ent & entity) = 0;
};

#endif // ENTITY_H
