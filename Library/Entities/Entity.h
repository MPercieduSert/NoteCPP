/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/02/2016
 */
#ifndef ENTITY_H
#define ENTITY_H

#include <QMessageBox>

#include <array>
#include <QDate>
#include <QDateTime>
#include <QList>
#include <QPair>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QVector>
#include <string>
#include <stdexcept>

#include "AttributMultiple.h"
#include "InfoEntityBase.h"

/*! \defgroup groupeEntity Entités
 * \brief Ensemble de classes représentant les entités de la base de donnée.
 */

/*! \defgroup groupeBaseEntity Classes de base des entités
 * \ingroup groupeEntity
 * \brief Ensemble des classes de base des entités.
 */

// Macro pour les entités
/*! \defgroup groupeMacroEntity Macro de base des entités
 * \ingroup groupeEntity
 * \brief Ensemble des Macros des entités.
 */

/*! \ingroup groupeMacroEntity
 * \brief Macro définissant les menbre static d'une entité.
 */
#define MEMBRE_STATIC(ENTITY) /*! \brief Renvoie le nom de l'entité.*/ \
    QString name() const {return Name();} \
    /*! \brief Renvoie le nom de l'entité.*/ \
    static QString Name() {return QString(#ENTITY);} \

/*! \ingroup groupeMacroEntity
 * \brief Macro a placer au début de la déclaration d'une entité.
 */
#define BASE_ENTITY(ENTITY) \
    CONSTR_DEFAUT(ENTITY) \
    CONSTR_AFFECT_DEFAUT(ENTITY) \
    DESTR_VIDE(ENTITY) \
    MEMBRE_STATIC(ENTITY)

/*! \ingroup groupeMacroEntity
 * \brief Macro a placer au début de la déclaration d'une entité abstraite.
 */
#define BASE_ENTITY_ABS(ENTITY) \
    CONSTR_DEFAUT(ENTITY) \
    CONSTR_AFFECT_DEFAUT(ENTITY) \
    DESTR_VIDE(ENTITY)

/*! \ingroup groupeBaseEntity
 * \brief Classe abstraite de base des entités.
 *
 * Lorsque l'on crée une nouvelle entité il faut :
 *  - créer une classe fille de Entity (ou créer un synonyme d'une classe prédéfinie à l'étape suivante).
 *  - Implémenter les différents constructeurs.
 *  - Placer la macro BASE_ENTITY(nom de la classe).
 *  - Créer si nécessaire une classe Unique Sql pour l'entité.
 *  - Rentrer les informations SQL pour faire le lien avec les entités correspondantes dans la base de donnée.
 *  - Ajouter un manager de l'entité dans Managers (membre, def_get (dans .h) et manager_tab (dans .cpp)).
 */
class Entity : public IdAttribut
{
public:
    //! Position des attributs.
    enum Position {Id,
                   NbrAtt};
    //! Identifiant de l'entité.
    enum IdentifiantEntity{ID = InfoEntity::entityBaseId::entityId};

    using IdAttribut::IdAttribut;

    CONSTR_AFFECT_DEFAUT(Entity)
    CONSTR_DEFAUT(Entity)

    //! Destructeur.
    virtual ~Entity() {}

    //! Renvoie une chaine de caractère contenant les noms, les validités et les valeurs des attributs.
    virtual QString affiche() const
        {return QString(name()).append("\n").append(IdAttribut::affiche());}

    //! Retourne un QVariant contenant la donnée souhaitée ou un QVariant nulle si num est invalide.
    virtual QVariant data(int pos) const
    {return pos == Id ? id() : QVariant();}

    //! Teste si l'entité est nouvelle ou si elle provient de la base de donnée en regardant si elle poséde un identifiant non-nul.
    bool isNew() const
        {return id() == 0;}

    //! Renvoie l'identifiant du type de l'entité.
    virtual int idEntity() const = 0;

    //! Teste si l'entité est valide, c'est-à-dire si les attributs de l'entité sont valides.
    virtual bool isValid() const
        {return IdAttribut::isValid();}

    //! Renvoie le nom de l'entité.
    virtual QString name() const = 0;

    //! Renvoie le nombre d'attribut de l'entité.
    virtual int nbrAtt() const = 0;

    //! Renvoie une chaine de caractère contenant les valeurs de l'attribut.
    virtual QString toString() const
        {return IdAttribut::toString();}

    //! Modifient les valeurs des attributs de l'entité avec celles des attributs de entity.
    virtual void operator << (const Entity & entity) = 0;

    //! Opérateur testant l'égalité de deux entités, c'est-à-dire l'égalité de tous les attributs.
    virtual bool operator == (const Entity & entity) const
        {return id() == entity.id();}

protected:
    //! Retourne un QVariant contenant la donnée souhaitée, num doit être valide.
    QVariant dataP(int /*pos*/) const
    {return id();}

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Entity & entity)
        {setId(entity.id());}
};

template <class Attribut> class EntityAttributs : public Attributs<Entity,Attribut>
{
public:
    enum {NbrAtt = Attribut::NbrAtt + Entity::NbrAtt,      //!< Nombre d'attribut de l'entité.
         };

    using Attributs<Entity,Attribut>::setId;

    CONSTR_DESTR_DEFAUT(EntityAttributs)

    //! Constructeur.
    EntityAttributs(int id)
        {setId(id);}

    //! Renvoie le nombre d'attribut de l'entité.
    int nbrAtt() const
        {return NbrAtt;}

    //! Retourne un QVariant contenant la donnée souhaitée ou un QVariant nulle si num est invalide.
    static QString nomAttribut(int num)
        {return num < EntityAttributs<Attribut>::NbrAtt ? Attributs<Entity,Attribut>::nomAttribut(num) : QString();}

    //! Modifient les valeurs des attributs de l'entité avec celles des attributs de entity.
    void operator << (const EntityAttributs<Attribut> & entity)
        {set(entity);}
};

template <class Attributs, int IDM> class EntityAttributsID : public EntityAttributs<Attributs>
{
public:
    enum {ID = IDM,         //!< Identifiant de l'attribut.
         };

    using EntAtt = EntityAttributs<Attributs>;
    using EntAtt::EntityAttributs;
    using EntAtt::operator ==;

protected:
    using EntAtt::set;

public:

    CONSTR_DESTR_DEFAUT(EntityAttributsID)

    //! Convertit la référence entity en une référence de type ENTITY, aprés vérification.
    static EntityAttributsID<Attributs,IDM> * convert(Entity *entity)
    {
        if(verifEntity(entity))
            return (EntityAttributsID<Attributs,IDM>*) entity;
        else
            throw std::invalid_argument("Mauvaise correspondance des Entity");
    }

    //! Convertit la référence constante entity en une référence constante de type ENTITY, aprés vérification.
    static EntityAttributsID<Attributs,IDM> & convert(Entity & entity)
    {
        if(verifEntity(entity))
            return *((EntityAttributsID<Attributs,IDM>*) &entity);
        else
            throw std::invalid_argument("Mauvaise correspondance des Entity");
    }

    //*! Convertit le pointeur entity en un pointeur de type ENTITY, aprés vérification.
    static const EntityAttributsID<Attributs,IDM> & convert(const Entity & entity)
    {
        if(verifEntity(entity))
            return *((EntityAttributsID<Attributs,IDM>*) &entity);
        else
            throw std::invalid_argument("Mauvaise correspondance des Entity");
    }

    //! Renvoie l'identifiant du type de l'entité.
    int idEntity() const
        {return ID;}

    //! Test si le pointeur entity est aussi un pointeur de ce type d'entité.
    static bool verifEntity(Entity * entity)
        {return ID == entity->idEntity();}

    //! Test si la référence entity est aussi une référence de ce type d'entité.
    static bool verifEntity(const Entity & entity)
        {return ID == entity.idEntity();}

    /*! \brief Opérateur d'égalité.*/ \
    bool operator == (const Entity & entity) const
        {return verifEntity(entity) && EntityAttributs<Attributs>::operator == (convert(entity));}

    //! Modifient les valeurs des attributs de l'entité avec celles des attributs de entity qui doit être de même type que la première opérande.
    void operator << (const Entity & entity)
        {set(convert(entity));}
};

#endif // ENTITY_H
