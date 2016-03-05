/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/02/2016
 */

/*! \defgroup groupeEntity Entitées
 * \brief Ensemble de classes représentant les entitées de la base de donnée.
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

// Macro pour les entitées

//Constructeurs

//! \ingroup groupeEntity
//! Constructeur par défaut.
#define CONSTR_DEFAUT(ENTITY) \
    /*! \brief Constructeur par défaut fixant l'identifiant de l'entitée à 0.*/ \
    ENTITY() \
    {}

//! \ingroup groupeEntity
//! Constructeur recopiant l'entitée entity.
#define CONSTR_ENTITY(ENTITY) \
    /*! \brief Constructeur recopiant les attributs l'entitée entity.*/ \
    ENTITY(const Entity & entity) \
    : Entity(entity.id()) \
    {set(convert(entity));}

//! \ingroup groupeEntity
//! Constructeur fixant l'identifiant.
#define CONSTR_ID(ENTITY) \
    /*! \brief Constructeur fixant l'identifiant de l'entitée.*/ \
    ENTITY(int id) \
    : Entity(id)   {}

//! \ingroup groupeEntity
//! Constructeur de recopie.
#define CONSTR_RECOPIE(ENTITY) \
    /*! \brief Constructeur de recopie.*/ \
    ENTITY(const ENTITY & entity) \
    : Entity(entity.id()) \
    {set(entity);}

//! \ingroup groupeEntity
//! Destructeur par défaut.
#define DESTRUCT(ENTITY) \
    /*! \brief Destructeur.*/ \
    ~ENTITY() \
    {}

//! \ingroup groupeEntity
//! Regroupe les macros des constructeurs et la macro du destructeur par défaut.
#define CONSTR_MACRO(ENTITY) \
    CONSTR_DEFAUT(ENTITY) \
    CONSTR_ENTITY(ENTITY) \
    CONSTR_ID(ENTITY) \
    CONSTR_RECOPIE(ENTITY) \
    DESTRUCT(ENTITY)

//Convertion

//! \ingroup groupeEntity
//! Macro définisant le menbre convert permettant la conversion de pointeur après vérification.
#define CONVERT_ENTITY_PTR(ENTITY) \
    /*! \brief Convertit la référence entity en une référence de type ENTITY, aprés vérification.*/ \
    static ENTITY * convert(Entity *entity) \
    {if(verifEntity(entity)) \
        {return (ENTITY*) entity;} \
    else \
        {throw std::invalid_argument("Mauvaise correspondance des Entity");}}

//! \ingroup groupeEntity
//! Macro définisant le menbre convert permettant la conversion de référence constante après vérification.
#define CONVERT_ENTITY_REF(ENTITY) \
    /*! \brief Convertit la référence constante entity en une référence constante de type ENTITY, aprés vérification.*/ \
    static ENTITY & convert(Entity & entity) \
    {if(verifEntity(entity)) \
        {return *((ENTITY*) &entity);} \
    else \
        {throw std::invalid_argument("Mauvaise correspondance des Entity");}}

//! \ingroup groupeEntity
//! Macro définisant le menbre convert permettant la conversion de référence constante après vérification.
#define CONVERT_ENTITY_CONST_REF(ENTITY) \
    /*! \brief Convertit le pointeur entity en un pointeur de type ENTITY, aprés vérification.*/ \
    static const ENTITY & convert(const Entity & entity) \
    {if(verifEntity(entity)) \
        {return *((ENTITY*) &entity);} \
    else \
        {throw std::invalid_argument("Mauvaise correspondance des Entity");}}

//! \ingroup groupeEntity
//! Macro définissant le membre idEntity renvoyant l'identifiant du type l'entitée.
#define ID_ENTITY(ENTITY) entityId \
    /*! \brief Renvoie l'identifiant du type ENTITY.*/ \
    idEntity() const \
    {return IdEntity;}

//! \ingroup groupeEntity
//! Macro définissant le membre static verifEntity testant si un pointeur est du type du type de l'entitée.
#define VERIF_ENTITY_PTR(ENTITY) \
    /*! \brief Test si le pointeur entity est aussi un pointeur de type ENTITY.*/ \
    static bool verifEntity(Entity * entity) \
    {return IdEntity == entity->idEntity();}

//! \ingroup groupeEntity
//! Macro définissant le membre static verifEntity testant si une référence est du type du type de l'entitée.
#define VERIF_ENTITY_REF(ENTITY) \
    /*! \brief Test si la référence entity est aussi une référence de type ENTITY.*/ \
    static bool verifEntity(const Entity & entity) \
    {return IdEntity == entity.idEntity();}

//! \ingroup groupeEntity
//! Regroupe les macros permettant la conversion des entitées.
#define CONVERT_MACRO(ENTITY) \
    CONVERT_ENTITY_PTR(ENTITY) \
    CONVERT_ENTITY_REF(ENTITY) \
    CONVERT_ENTITY_CONST_REF(ENTITY) \
    ID_ENTITY(ENTITY) \
    VERIF_ENTITY_PTR(ENTITY) \
    VERIF_ENTITY_REF(ENTITY)

// Opérateurs

//! \ingroup groupeEntity
//! Macro définissant l'opérateur == avec une Entitée de même type.
#define OP_EGAL(ENTITY) \
    /*! \brief Test d'égalité entre deux entitées de type ENTITY, c'est-à-dire l'égalité de tous les attributs..*/ \
    bool operator == (const ENTITY & entity) const \
    {return egal(entity);}

//! \ingroup groupeEntity
//! Macro définissant l'opérateur == avec une Entity.
#define OP_EGAL_ENTITY(ENTITY) \
    /*! \brief Test d'égalité entre une entitée de type ENTITY et une référence Entity sur une entitée de type ENTITY, c'est-à-dire l'égalité de tous les attributs.*/ \
    bool operator == (const Entity & entity) const\
    {return egal(convert(entity));}

//! \ingroup groupeEntity
//! Macro définissant l'opérateur << avec une Entity.
#define OP_INJ(ENTITY) \
    /*! \brief Modifient les valeurs des attributs de l'entitée avec celles des attributs de entity.*/ \
    void operator << (const ENTITY & entity) \
    {setId(entity.id()); \
    set(entity);}

//! \ingroup groupeEntity
//! Macro définissant l'opérateur << avec une Entity.
#define OP_INJ_ENTITY(ENTITY) \
    /*! \brief Modifient les valeurs des attributs de l'entitée avec celles des attributs de entity.*/ \
    void operator << (const Entity & entity) \
    {setId(entity.id()); \
    set(convert(entity));}

//! \ingroup groupeEntity
//! Regroupe les macros des opérateurs.
#define OP_MACRO(ENTITY) \
    OP_EGAL(ENTITY) \
    OP_EGAL_ENTITY(ENTITY) \
    OP_INJ(ENTITY) \
    OP_INJ_ENTITY(ENTITY)

//Membre Divers

//! \ingroup groupeEntity
//! Macro définissant le membre NbrAtt renvoyant le nombre de valeurs de l'entitée.
#define NBR_VALUE(ENTITY) \
    /*! \brief Renvoie le nombre de valeur des entititées de type ENTITY.*/ \
    int nbrAtt() const \
    {return NbrAtt;}

//! \ingroup groupeEntity
//! Regroupe les macros de divers membres.
#define MEMBRE_DIVER_MACRO(ENTITY) \
    NBR_VALUE(ENTITY)

//! \ingroup groupeEntity
//! Macro permettant d'incorporer les macros communes à toutes les entitées.
#define INCLUCE_METHODE(ENTITY) \
    CONSTR_MACRO(ENTITY) \
    CONVERT_MACRO(ENTITY) \
    OP_MACRO(ENTITY) \
    MEMBRE_DIVER_MACRO(ENTITY)

//Getteurs et Setteurs de différent attribut courant.

//! \ingroup groupeEntity
//! Implémentation des getteur et setteur d'un booléen.
#define GET_SET_BOOL(nom,Nom) \
    /*! \brief Retourne la valeur de l'attribut nom.*/ \
    bool nom() const {return m_ ## nom;} \
    /*! \brief Modifie l'attribut nom.*/ \
    void set ## Nom(bool bb) \
    {m_ ## nom = bb;}

//! \ingroup groupeEntity
//! Implémentation des getteur et setteur d'un attribut date valide.
#define GET_SET_DATE_VALIDE(nom,Nom) \
    /*! \brief Retourne la valeur de l'attribut nom.*/ \
    const QDate & nom() const {return m_ ## nom;} \
    /*! \brief Modifie l'attribut nom.*/ \
    void set ## Nom(const QDate & date) \
    {if(date.isValid()) \
        {m_ ## nom = date;} \
    else \
        {m_erreurs.append(QPair<int,int>(m_id,Nom ## Pos));}}

//! \ingroup groupeEntity
//! Implémentation des getteur et setteur d'une clé.
#define GET_SET_ID(ATT) \
    /*! \brief Retourne la valeur de la clé id ## ATT.*/ \
    int id ## ATT() const {return m_id ## ATT;} \
    /*! \brief Modifie la clé id ## ATT.*/ \
    void setId ## ATT(int id) \
    {if(id > 0) \
        {m_id ## ATT = id;} \
    else \
        {m_erreurs.append(QPair<int,int>(m_id,Id ## ATT ## Pos));}}

//! \ingroup groupeEntity
//! Implémentation des getteur et setteur d'un entier sans condition.
#define GET_SET_INT(nom,Nom) \
    /*! \brief Retourne la valeur de l'attribut nom.*/ \
    int nom() const {return m_ ## nom;} \
    /*! \brief Modifie l'attribut nom.*/ \
    void set ## Nom(int n) \
    {m_ ## nom = n;}

//! \ingroup groupeEntity
//! Implémentation des getteur et setteur d'un entier positif.
#define GET_SET_INT_SUP(nom,Nom,MIN) \
    /*! \brief Retourne la valeur de l'attribut nom.*/ \
    int nom() const {return m_ ## nom;} \
    /*! \brief Modifie l'attribut nom.*/ \
    void set ## Nom(int n) \
    {if(n >= MIN) \
        {m_ ## nom = n;} \
    else \
        {m_erreurs.append(QPair<int,int>(m_id,Nom ## Pos));}}

//! \ingroup groupeEntity
//! Implémentation des getteur et setteur d'un attribut de type QString non vide.
#define GET_SET_TEXTE_NOT_NULL(nom,Nom) \
    /*! \brief Retourne la valeur de l'attribut nom.*/ \
    const QString & nom() const {return m_ ## nom;} \
    /*! \brief Modifie l'attribut nom.*/ \
    void set ## Nom(const QString & txt) \
    {if(!txt.isEmpty()) \
        {m_ ## nom = txt;} \
    else \
        {m_erreurs.append(QPair<int,int>(m_id,Nom ## Pos));}}

//! \ingroup groupeEntity
//! Implémentation des getteur et setteur d'un attribut de type QString pouvant être vide vide.
#define GET_SET_TEXTE_NULL(nom,Nom) \
    /*! \brief Retourne la valeur de l'attribut nom.*/ \
    const QString & nom() const {return m_ ## nom;} \
    /*! \brief Modifie l'attribut nom.*/ \
    void set ## Nom(const QString & txt) \
    {m_ ## nom = txt;} \

//! \ingroup groupeEntity
//! Liste des erreurs survenues lors de la modification d'une entitée.
//! Sous la forme de paires (identitfiant de l'entitée, position de l'attribut).
typedef QList<QPair<int,int> > ErrList;

/*! \ingroup groupeEntity
 * \brief Classe abstraite de base des entitées.
 */

class Entity
{
public:
    //! Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.
    enum position {IdPos = 0,
                   PosPos = -1};

    //! Liste des identifiants des types d'entitées.
    enum entityId  {AnneeId = 0,
                    ArbreId = -2,
                    ArbreAttributId = 1,
                    ArbreCoursId = 2,
                    ArbreDonneeId = 3,
                    ArbreEnonceId = 4,
                    ArbreExerciceId = 5,
                    AttributId = 6,
                    AttributCommentaireId = 7,
                    AttributCorrectionId = 8,
                    AttributCoursId = 9,
                    AttributBaremeId = 10,
                    AttributExerciceId = 11,
                    BaremeId = 12,
                    ClasseId = 13,
                    CoefficientId = 14,
                    CommentaireId = 15,
                    CompteurTypeComtrole = 16,
                    ControleId = 17,
                    CorrectionId = 18,
                    CorrectionParId = 19,
                    CoursId = 20,
                    CoursParId = 21,
                    DansEtablissementId = 22,
                    DansClasseId = 23,
                    DansGroupeId = 24,
                    DonneeId = 25,
                    EleveId = 26,
                    EnonceId = 27,
                    EntityId = -1,
                    EtablissementId = 28,
                    ExerciceId = 29,
                    ExerciceParId = 30,
                    FormeId = 31,
                    GroupeId = 32,
                    GroupePourId = 33,
                    MisClasseId = 34,
                    MisEleveId = 35,
                    MisGroupeId = 36,
                    NiveauId = 37,
                    NoteId = 38,
                    PointId = 39,
                    RelEntityId = -3,
                    SourceId = 40,
                    SurClasseId = 41,
                    SurEleveId = 42,
                    SurEtablissementId = 43,
                    SurNiveauId = 44,
                    SurSourceId = 45,
                    TexteId = 46,
                    TypeControleId = 47,
                    TypeCours = 48,
                    TypeNiveauId = 49,
                    TypeUtilisationId = 50,
                    Utilisation = 51,
                    UtilisationExerciceId = 52
                   };

    static const entityId IdEntity = EntityId;  //!< Identifiant du type de l'entitée.
    static constexpr char Name[] = "Entity";    //!< Nom de l'entitée.
    static const int NbrAtt = 1;                //!< Nombre d'attributs de l'entitée.
    static constexpr std::array<const char*, NbrAtt> Att {{"ID"}}; //!< Tableau des attributs de l'entitée.
    //static const int NbrEnsUni = 0;             //!< Nombre d'ensemble d'attributs uniques de l'entitée autre que l'identifiant.
    //static constexpr std::array<const char*, NbrEnsUni> EnsUni {{}};      //!< Tableau des chaines des ensembles d'attributs uniques de l'entitée.

protected:    
    ErrList m_erreurs;                          //!< Liste des erreurs survenues lors de la modification de l'entitée.
    int m_id;                                   //!< Identifiant de l'entitée.

public:
    //! Constructeur par défaut fixant l'identifiant de l'entitée à 0.
    Entity()
        : m_id(0)
        {}

    //! Constructeur par défaut fixant l'identifiant de l'entitée.
    Entity(int id)
        {setId(id);}

    //! Destructeur.
    ~Entity()
        {}

    //! Renvoie une référence sur la liste des erreurs sur la modification de l'entitée.
    const ErrList & erreurs() const
        {return m_erreurs;}

    //! Renvoie l'identifiant de l'entitée.
    int id() const
        {return m_id;}

    //! Teste si l'entitée est nouvelle ou si elle provient de la base de donnée en regardant si elle poséde un identifiant non-nul.
    bool isNew() const
        {return m_id == 0;}

    //! Renvoie l'identifiant du type de l'entitée.
    virtual entityId idEntity() const
        {return IdEntity;}

    //! Teste si l'entitée est valide, c'est-à-dire si les attributs de l'entitée sont valides.
    virtual bool isValid() const
        {return m_erreurs.isEmpty() && (m_id >= 0);}

    //! Modifie l'identifiant de l'entitée.
    void setId(int id)
    {
        if(id >= 0)
        {
            m_id = id;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,IdPos));
        }
    }

    //! Modifient les valeurs des attributs de l'entitée avec celles des attributs de entity.
    virtual void operator << (const Entity & entity) = 0;

    //! Opérateur testant l'égalité de deux entitées, c'est-à-dire l'égalité de tous les attributs.
    virtual bool operator == (const Entity & entity) const =0;

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument, c'est-à-dire l'égalité de tous les attributs.
    bool egal(const Entity & entity) const
    {
        return m_id == entity.m_id;
    }
};

#endif // ENTITY_H
