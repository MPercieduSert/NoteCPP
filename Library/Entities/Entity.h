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
#include <QStringList>
#include <QVariant>
#include <QVector>
#include <string>
#include <stdexcept>

#include "AttributEntity.h"
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
 * \brief Macro pour la chaine de caractères contenant la valeur des attributs
 */
#define TO_STRING_ENTITY(ATT) .append(#ATT "(").append(m_ ## ATT.validToString()).append(") :").append(m_ ## ATT.toString()).append("\n")

/*! \ingroup groupeMacroEntity
 * \brief Macro définissant ID pour les entités abstraites.
 */
#define ID_ENTITY_ABS(ENTITY) enum {ID = InfoEntity::entityBaseId::ENTITY ## Id};


/*! \ingroup groupeMacroEntity
 * \brief Macro définissant les menbre static d'une entité.
 */
#define MEMBRE_STATIC(ENTITY,IDM) enum {ID = IDM}; \
    /*! \brief Renvoie le nom de l'entité.*/ \
    QString name() const {return Name();} \
    /*! \brief Renvoie le nom de l'entité.*/ \
    static QString Name() {return QString(#ENTITY);} \
    /*! Test si le pointeur entity est aussi un pointeur de ce type d'entité.*/ \
    static bool verifEntity(Entity * entity) {return ID == entity->idEntity();} \
    /*! Test si la référence entity est aussi une référence de ce type d'entité.*/ \
    static bool verifEntity(const Entity & entity) {return ID == entity.idEntity();} \
    /*! \brief Convertit la référence entity en une référence de type ENTITY, aprés vérification. */ \
    static ENTITY * convert(Entity *entity){\
        if(verifEntity(entity)) \
            return (ENTITY*) entity; \
        else \
            throw std::invalid_argument("Mauvaise correspondance des Entity");} \
    /*! \brief  Convertit la référence constante entity en une référence constante de type ENTITY, aprés vérification. */ \
    static ENTITY & convert(Entity & entity){ \
        if(verifEntity(entity)) \
            return *((ENTITY*) &entity); \
        else \
            throw std::invalid_argument("Mauvaise correspondance des Entity");} \
    /*! \brief Convertit le pointeur entity en un pointeur de type ENTITY, aprés vérification. */ \
    static const ENTITY & convert(const Entity & entity){ \
        if(verifEntity(entity)) \
            return *((ENTITY*) &entity); \
        else \
            throw std::invalid_argument("Mauvaise correspondance des Entity");}

/*! \ingroup groupeMacroEntity
 * \brief Macro définissant les opérateur virtuel des entity.
 */
#define MEMBRE_VIRTUEL(ENTITY) /*! \brief Renvoie l'identifiant du type de l'entité.*/ \
    int idEntity() const {return ID;} \
    /*! \brief Test d'égalité entre une entité et une référence Entity sur une entité de même type que la première, c'est-à-dire l'égalité de tous les attributs. */ \
    /*! \brief Renvoie le nombre d'attribut de l'entité.*/ \
    int nbrAtt() const {return NbrAtt;} \
    /*! \brief Opérateur d'égalité.*/ \
    bool operator == (const Entity & entity) const {return operator == (convert(entity));}\
    /*! \brief Modifient les valeurs des attributs de l'entité avec celles des attributs de entity.*/ \
    void operator << (const ENTITY & entity) {set(entity);} \
    /*! Modifient les valeurs des attributs de l'entité avec celles des attributs de entity qui doit être de même type que la première opérande. */ \
    void operator << (const Entity & entity) {set(convert(entity));}

/*! \ingroup groupeMacroEntity
 * \brief Macro a placer au début de la déclaration d'une entité.
 */
#define BASE_ENTITY(ENTITY,ID) \
    CONSTR_DEFAUT(ENTITY) \
    CONSTR_AFFECT_DEFAUT(ENTITY) \
    DESTR_VIDE(ENTITY) \
    MEMBRE_STATIC(ENTITY,ID) \
    MEMBRE_VIRTUEL(ENTITY)

/*! \ingroup groupeMacroEntity
 * \brief Macro a placer au début de la déclaration d'une entité abstraite.
 */
#define BASE_ENTITY_ABS(ENTITY) \
    ID_ENTITY_ABS(ENTITY) \
    CONSTR_DEFAUT(ENTITY) \
    CONSTR_AFFECT_DEFAUT(ENTITY) \
    DESTR_VIDE(ENTITY)

//! \ingroup groupeMacroEntity
//! Macro Implémentant une classe de d'entité définie par défaut.
#define ENTITY_OF_TYPE(ENTITY,TYPE,ID) \
    /*! \ingroup groupeEntity \brief Représentation de l'entité ENTITY.*/ \
    class ENTITY : public TYPE \
    {public: \
    using TYPE::TYPE; \
    BASE_ENTITY(ENTITY,ID)};

//! \ingroup groupeMacroEntity
//! Macro implémentant les membres types d'une entité ayant un attribut de plus que la classe mère.
#define MEMBRE_ATT_1(ENTITY,MERE,NOM,nom) enum {nom ## Pos = MERE::NbrAtt,NbrAtt}; \
    /*! Teste si l'entité est valide.*/ \
    bool isValid() const {return MERE::isValid() && m_ ## nom.isValid();} \
    /*! Renvoie une chaine de caractère contenant la valeur de l'attribut.*/ \
    QString toString() const {return MERE::toString()TO_STRING_ENTITY(nom);} \
    /*! Test d'égalité entre cette entité et celle transmise en argument.*/ \
    bool operator ==(const ENTITY & entity) const {return MERE::operator ==(entity) && m_ ## nom == entity.nom();} \
    protected: \
    /*! Remplace les attributs de l'entité par celle de l'entité transmise.*/ \
    void set(const ENTITY & entity){ \
        MERE::set(entity); \
        set ## NOM(entity.nom());}

//! \ingroup groupeMacroEntity
//! Macro implémentant les membres types d'une entité ayant deux attributs de plus que la classe mère.
#define MEMBRE_ATT_2(ENTITY,MERE,NOM1,nom1,NOM2,nom2) enum {nom1 ## Pos = MERE::NbrAtt,nom2 ## Pos,NbrAtt}; \
    /*! Teste si l'entité est valide.*/ \
    bool isValid() const {return MERE::isValid() && m_ ## nom1.isValid() && m_ ## nom2.isValid();} \
    /*! Renvoie une chaine de caractère contenant la valeur de l'attribut.*/ \
    QString toString() const {return MERE::toString()TO_STRING_ENTITY(nom1)TO_STRING_ENTITY(nom2);} \
    /*! Test d'égalité entre cette entité et celle transmise en argument.*/ \
    bool operator ==(const ENTITY & entity) const {return MERE::operator ==(entity) && m_ ## nom1 == entity.nom1() && m_ ## nom2 == entity.nom2();} \
    protected: \
    /*! Remplace les attributs de l'entité par celle de l'entité transmise.*/ \
    void set(const ENTITY & entity){ \
        MERE::set(entity); \
        set ## NOM1(entity.nom1()); \
        set ## NOM2(entity.nom2());}

//! \ingroup groupeMacroEntity
//! Macro implémentant les membres types d'une entité ayant trois attributs de plus que la classe mère.
#define MEMBRE_ATT_3(ENTITY,MERE,NOM1,nom1,NOM2,nom2,NOM3,nom3) enum {nom1 ## Pos = MERE::NbrAtt,nom2 ## Pos,nom3 ## Pos,NbrAtt}; \
    /*! Teste si l'entité est valide.*/ \
    bool isValid() const {return MERE::isValid() && m_ ## nom1.isValid() && m_ ## nom2.isValid() && m_ ## nom3.isValid();} \
    /*! Renvoie une chaine de caractère contenant la valeur de l'attribut.*/ \
    QString toString() const {return MERE::toString()TO_STRING_ENTITY(nom1)TO_STRING_ENTITY(nom2)TO_STRING_ENTITY(nom3);} \
    /*! Test d'égalité entre cette entité et celle transmise en argument.*/ \
    bool operator ==(const ENTITY & entity) const \
    {return MERE::operator ==(entity) && m_ ## nom1 == entity.nom1() && m_ ## nom2 == entity.nom2() && m_ ## nom3 == entity.nom3();} \
    protected: \
    /*! Remplace les attributs de l'entité par celle de l'entité transmise.*/ \
    void set(const ENTITY & entity){ \
        MERE::set(entity); \
        set ## NOM1(entity.nom1()); \
        set ## NOM2(entity.nom2()); \
        set ## NOM3(entity.nom3());}

//! \ingroup groupeMacroEntity
//! Macro implémentant les membres types d'une entité ayant quatre attributs de plus que la classe mère.
#define MEMBRE_ATT_4(ENTITY,MERE,NOM1,nom1,NOM2,nom2,NOM3,nom3,NOM4,nom4) \
    enum {nom1 ## Pos = MERE::NbrAtt,nom2 ## Pos,nom3 ## Pos,nom4 ## Pos,NbrAtt}; \
    /*! Teste si l'entité est valide.*/ \
    bool isValid() const \
    {return MERE::isValid() && m_ ## nom1.isValid() && m_ ## nom2.isValid() && m_ ## nom3.isValid() && m_ ## nom4.isValid();} \
    /*! Renvoie une chaine de caractère contenant la valeur de l'attribut.*/ \
    QString toString() const \
    {return MERE::toString()TO_STRING_ENTITY(nom1)TO_STRING_ENTITY(nom2)TO_STRING_ENTITY(nom3)TO_STRING_ENTITY(nom4);} \
    /*! Test d'égalité entre cette entité et celle transmise en argument.*/ \
    bool operator ==(const ENTITY & entity) const \
    {return MERE::operator ==(entity) && m_ ## nom1 == entity.nom1() && m_ ## nom2 == entity.nom2() && m_ ## nom3 == entity.nom3() \
        && m_ ## nom4 == entity.nom4();} \
    protected: \
    /*! Remplace les attributs de l'entité par celle de l'entité transmise.*/ \
    void set(const ENTITY & entity){ \
        MERE::set(entity); \
        set ## NOM1(entity.nom1()); \
        set ## NOM2(entity.nom2()); \
        set ## NOM3(entity.nom3()); \
        set ## NOM4(entity.nom4());}

//! \ingroup groupeMacroEntity
//! Macro implémentant les membres types d'une entité ayant cinq attributs de plus que la classe mère.
#define MEMBRE_ATT_5(ENTITY,MERE,NOM1,nom1,NOM2,nom2,NOM3,nom3,NOM4,nom4,NOM5,nom5) \
    enum {nom1 ## Pos = MERE::NbrAtt,nom2 ## Pos,nom3 ## Pos,nom4 ## Pos,nom5 ## Pos,NbrAtt}; \
    /*! Teste si l'entité est valide.*/ \
    bool isValid() const \
    {return MERE::isValid() && m_ ## nom1.isValid() && m_ ## nom2.isValid() && m_ ## nom3.isValid() && m_ ## nom4.isValid() && m_ ## nom5.isValid();} \
    /*! Renvoie une chaine de caractère contenant la valeur de l'attribut.*/ \
    QString toString() const \
    {return MERE::toString()TO_STRING_ENTITY(nom1)TO_STRING_ENTITY(nom2)TO_STRING_ENTITY(nom3)TO_STRING_ENTITY(nom4)TO_STRING_ENTITY(nom5);} \
    /*! Test d'égalité entre cette entité et celle transmise en argument.*/ \
    bool operator ==(const ENTITY & entity) const \
    {return MERE::operator ==(entity) && m_ ## nom1 == entity.nom1() && m_ ## nom2 == entity.nom2() && m_ ## nom3 == entity.nom3() \
        && m_ ## nom4 == entity.nom4() && m_ ## nom5 == entity.nom5();} \
    protected: \
    /*! Remplace les attributs de l'entité par celle de l'entité transmise.*/ \
    void set(const ENTITY & entity){ \
        MERE::set(entity); \
        set ## NOM1(entity.nom1()); \
        set ## NOM2(entity.nom2()); \
        set ## NOM3(entity.nom3()); \
        set ## NOM4(entity.nom4()); \
        set ## NOM5(entity.nom5());}

//! \ingroup groupeMacroEntity
//! Macro implémentant les membres types d'une entité ayant six attributs de plus que la classe mère.
#define MEMBRE_ATT_6(ENTITY,MERE,NOM1,nom1,NOM2,nom2,NOM3,nom3,NOM4,nom4,NOM5,nom5,NOM6,nom6) \
    enum {nom1 ## Pos = MERE::NbrAtt,nom2 ## Pos,nom3 ## Pos,nom4 ## Pos,nom5 ## Pos,nom6 ## Pos,NbrAtt}; \
    /*! Teste si l'entité est valide.*/ \
    bool isValid() const \
    {return MERE::isValid() && m_ ## nom1.isValid() && m_ ## nom2.isValid() && m_ ## nom3.isValid() && m_ ## nom4.isValid() && m_ ## nom5.isValid() \
        && m_ ## nom6.isValid();} \
    /*! Renvoie une chaine de caractère contenant la valeur de l'attribut.*/ \
    QString toString() const \
    {return MERE::toString()TO_STRING_ENTITY(nom1)TO_STRING_ENTITY(nom2)TO_STRING_ENTITY(nom3)TO_STRING_ENTITY(nom4)TO_STRING_ENTITY(nom5) \
        TO_STRING_ENTITY(nom6);} \
    /*! Test d'égalité entre cette entité et celle transmise en argument.*/ \
    bool operator ==(const ENTITY & entity) const \
    {return MERE::operator ==(entity) && m_ ## nom1 == entity.nom1() && m_ ## nom2 == entity.nom2() && m_ ## nom3 == entity.nom3() \
        && m_ ## nom4 == entity.nom4() && m_ ## nom5 == entity.nom5() && m_ ## nom6 == entity.nom6();} \
    protected: \
    /*! Remplace les attributs de l'entité par celle de l'entité transmise.*/ \
    void set(const ENTITY & entity){ \
        MERE::set(entity); \
        set ## NOM1(entity.nom1()); \
        set ## NOM2(entity.nom2()); \
        set ## NOM3(entity.nom3()); \
        set ## NOM4(entity.nom4()); \
        set ## NOM5(entity.nom5()); \
        set ## NOM6(entity.nom6());}

//! \ingroup groupeMacroEntity
//! Macro implémentant les membres types d'une entité ayant sept attributs de plus que la classe mère.
#define MEMBRE_ATT_7(ENTITY,MERE,NOM1,nom1,NOM2,nom2,NOM3,nom3,NOM4,nom4,NOM5,nom5,NOM6,nom6,NOM7,nom7) \
    enum {nom1 ## Pos = MERE::NbrAtt,nom2 ## Pos,nom3 ## Pos,nom4 ## Pos,nom5 ## Pos,nom6 ## Pos,nom7 ## Pos,NbrAtt}; \
    /*! Teste si l'entité est valide.*/ \
    bool isValid() const \
    {return MERE::isValid() && m_ ## nom1.isValid() && m_ ## nom2.isValid() && m_ ## nom3.isValid() && m_ ## nom4.isValid() && m_ ## nom5.isValid() \
        && m_ ## nom6.isValid() && m_ ## nom7.isValid();} \
    /*! Renvoie une chaine de caractère contenant la valeur de l'attribut.*/ \
    QString toString() const \
    {return MERE::toString()TO_STRING_ENTITY(nom1)TO_STRING_ENTITY(nom2)TO_STRING_ENTITY(nom3)TO_STRING_ENTITY(nom4)TO_STRING_ENTITY(nom5) \
        TO_STRING_ENTITY(nom6)TO_STRING_ENTITY(nom7);} \
    /*! Test d'égalité entre cette entité et celle transmise en argument.*/ \
    bool operator ==(const ENTITY & entity) const \
    {return MERE::operator ==(entity) && m_ ## nom1 == entity.nom1() && m_ ## nom2 == entity.nom2() && m_ ## nom3 == entity.nom3() \
        && m_ ## nom4 == entity.nom4() && m_ ## nom5 == entity.nom5() && m_ ## nom6 == entity.nom6() && m_ ## nom7 == entity.nom7();} \
    protected: \
    /*! Remplace les attributs de l'entité par celle de l'entité transmise.*/ \
    void set(const ENTITY & entity){ \
        MERE::set(entity); \
        set ## NOM1(entity.nom1()); \
        set ## NOM2(entity.nom2()); \
        set ## NOM3(entity.nom3()); \
        set ## NOM4(entity.nom4()); \
        set ## NOM5(entity.nom5()); \
        set ## NOM6(entity.nom6()); \
        set ## NOM7(entity.nom7());}

//! \ingroup groupeMacroEntity
//! Macro implémentant les membres types d'une entité ayant huit attributs de plus que la classe mère.
#define MEMBRE_ATT_8(ENTITY,MERE,NOM1,nom1,NOM2,nom2,NOM3,nom3,NOM4,nom4,NOM5,nom5,NOM6,nom6,NOM7,nom7,NOM8,nom8) \
    enum {nom1 ## Pos = MERE::NbrAtt,nom2 ## Pos,nom3 ## Pos,nom4 ## Pos,nom5 ## Pos,nom6 ## Pos,nom7 ## Pos,nom8 ## Pos,NbrAtt}; \
    /*! Teste si l'entité est valide.*/ \
    bool isValid() const \
    {return MERE::isValid() && m_ ## nom1.isValid() && m_ ## nom2.isValid() && m_ ## nom3.isValid() && m_ ## nom4.isValid() && m_ ## nom5.isValid() \
        && m_ ## nom6.isValid() && m_ ## nom7.isValid() && m_ ## nom8.isValid();} \
    /*! Renvoie une chaine de caractère contenant la valeur de l'attribut.*/ \
    QString toString() const \
    {return MERE::toString()TO_STRING_ENTITY(nom1)TO_STRING_ENTITY(nom2)TO_STRING_ENTITY(nom3)TO_STRING_ENTITY(nom4)TO_STRING_ENTITY(nom5) \
        TO_STRING_ENTITY(nom6)TO_STRING_ENTITY(nom7)TO_STRING_ENTITY(nom8);} \
    /*! Test d'égalité entre cette entité et celle transmise en argument.*/ \
    bool operator ==(const ENTITY & entity) const \
    {return MERE::operator ==(entity) && m_ ## nom1 == entity.nom1() && m_ ## nom2 == entity.nom2() && m_ ## nom3 == entity.nom3() \
        && m_ ## nom4 == entity.nom4() && m_ ## nom5 == entity.nom5() && m_ ## nom6 == entity.nom6() && m_ ## nom7 == entity.nom7() \
        && m_ ## nom8 == entity.nom8();} \
    protected: \
    /*! Remplace les attributs de l'entité par celle de l'entité transmise.*/ \
    void set(const ENTITY & entity){ \
        MERE::set(entity); \
        set ## NOM1(entity.nom1()); \
        set ## NOM2(entity.nom2()); \
        set ## NOM3(entity.nom3()); \
        set ## NOM4(entity.nom4()); \
        set ## NOM5(entity.nom5()); \
        set ## NOM6(entity.nom6()); \
        set ## NOM7(entity.nom7()); \
        set ## NOM8(entity.nom8());}

//! \ingroup groupeMacroEntity
//! Macro implémentant les membres types d'une entité ayant huit attributs de plus que la classe mère.
#define MEMBRE_ATT_9(ENTITY,MERE,NOM1,nom1,NOM2,nom2,NOM3,nom3,NOM4,nom4,NOM5,nom5,NOM6,nom6,NOM7,nom7,NOM8,nom8,NOM9,nom9) \
    enum {nom1 ## Pos = MERE::NbrAtt,nom2 ## Pos,nom3 ## Pos,nom4 ## Pos,nom5 ## Pos,nom6 ## Pos,nom7 ## Pos,nom8 ## Pos,nom9 ## Pos,NbrAtt}; \
    /*! Teste si l'entité est valide.*/ \
    bool isValid() const \
    {return MERE::isValid() && m_ ## nom1.isValid() && m_ ## nom2.isValid() && m_ ## nom3.isValid() && m_ ## nom4.isValid() && m_ ## nom5.isValid() \
        && m_ ## nom6.isValid() && m_ ## nom7.isValid() && m_ ## nom8.isValid() && m_ ## nom9.isValid();} \
    /*! Renvoie une chaine de caractère contenant la valeur de l'attribut.*/ \
    QString toString() const \
    {return MERE::toString()TO_STRING_ENTITY(nom1)TO_STRING_ENTITY(nom2)TO_STRING_ENTITY(nom3)TO_STRING_ENTITY(nom4)TO_STRING_ENTITY(nom5) \
        TO_STRING_ENTITY(nom6)TO_STRING_ENTITY(nom7)TO_STRING_ENTITY(nom8)TO_STRING_ENTITY(nom9);} \
    /*! Test d'égalité entre cette entité et celle transmise en argument.*/ \
    bool operator ==(const ENTITY & entity) const \
    {return MERE::operator ==(entity) && m_ ## nom1 == entity.nom1() && m_ ## nom2 == entity.nom2() && m_ ## nom3 == entity.nom3() \
        && m_ ## nom4 == entity.nom4() && m_ ## nom5 == entity.nom5() && m_ ## nom6 == entity.nom6() && m_ ## nom7 == entity.nom7() \
        && m_ ## nom8 == entity.nom8() && m_ ## nom9 == entity.nom9();} \
    protected: \
    /*! Remplace les attributs de l'entité par celle de l'entité transmise.*/ \
    void set(const ENTITY & entity){ \
        MERE::set(entity); \
        set ## NOM1(entity.nom1()); \
        set ## NOM2(entity.nom2()); \
        set ## NOM3(entity.nom3()); \
        set ## NOM4(entity.nom4()); \
        set ## NOM5(entity.nom5()); \
        set ## NOM6(entity.nom6()); \
        set ## NOM7(entity.nom7()); \
        set ## NOM8(entity.nom8()); \
        set ## NOM9(entity.nom9());}

/*! \ingroup groupeBaseEntity
 * \brief Classe abstraite de base des entités.
 *
 * Lorsque l'on crée une nouvelle entité il faut :
 *  - créer une classe fille de Entity (ou créer un synonyme d'une classe prédéfinie à l'étape suivante).
 *  - Place la macro BASE_ENTITY(nom de la classe).
 *  - Implémenter les fonctions virtuelles pure: name
 *  - Implémenter les fonctions: isValid(), toString(), operator ==(), set(const ENTITY &)
 *  - Rentrer les informations SQL pour faire le lien avec les entités correspondantes dans la base de donnée.
 *  - Spécialiser les classe LinkSql et Unique Sql pour l'entité.
 *  - Ajouter un manager de l'entité dans Managers (membre, def_get (dans .h) et manager_tab (dans .cpp)).
 */
class Entity
{
    ATTRIBUT_ENTITY_ID_NULL()

public:
    enum {idPos = 0,
          NbrAtt,
          ID = InfoEntity::entityBaseId::entityId};

    //! Constructeur par défaut fixant l'identifiant de l'entité.
    Entity(int id = 0)
        : m_id(id)
        {}

    CONSTR_AFFECT_DEFAUT(Entity)

    //! Destructeur.
    virtual ~Entity()
        {}

    //! Teste si l'entité est nouvelle ou si elle provient de la base de donnée en regardant si elle poséde un identifiant non-nul.
    bool isNew() const
        {return id() == 0;}

    //! Renvoie l'identifiant du type de l'entité.
    virtual int idEntity() const = 0;

    //! Teste si l'entité est valide, c'est-à-dire si les attributs de l'entité sont valides.
    virtual bool isValid() const
        {return m_id.isValid();}

    //! Renvoie le nom de l'entité.
    virtual QString name() const = 0;

    //! Renvoie le nombre d'attribut de l'entité.
    virtual int nbrAtt() const = 0;

    //! Renvoie une chaine de caractère contenant la valeur de l'attribut.
    virtual QString toString() const
        {return QString(name()).append("\n")TO_STRING_ENTITY(id);}

    //! Modifient les valeurs des attributs de l'entité avec celles des attributs de entity.
    virtual void operator << (const Entity & entity) = 0;

    //! Opérateur testant l'égalité de deux entités, c'est-à-dire l'égalité de tous les attributs.
    virtual bool operator == (const Entity & entity) const
        {return m_id == entity.id();}

protected:
    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Entity & entity)
        {setId(entity.id());}
};

#endif // ENTITY_H
