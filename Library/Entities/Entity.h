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

/*! \defgroup groupeMacroEntity Macros pour les entitées
 * \ingroup groupeEntity
 * \brief Ensemble des macros pour les entitées.
 */

//Constructeurs

/*! \defgroup groupeConstrMacroEntity Constructeurs
 * \ingroup groupeMacroEntity
 * \brief Ensemble des macros implémentant des constructeurs et destructeurs d'entitées.
 */

//! \ingroup groupeConstrMacroEntity
//! Constructeur par défaut.
#define CONSTR_DEFAUT(ENTITY) \
    /*! \brief Constructeur par défaut fixant l'identifiant de l'entitée à 0.*/ \
    ENTITY() \
    {}

//! \ingroup groupeConstrMacroEntity
//! Constructeur recopiant l'entitée entity.
#define CONSTR_ENTITY(ENTITY) \
    /*! \brief Constructeur recopiant les attributs l'entitée entity.*/ \
    ENTITY(const Entity & entity) \
    : Entity(entity.id()) \
    {set(convert(entity));}

//! \ingroup groupeConstrMacroEntity
//! Constructeur fixant l'identifiant.
#define CONSTR_ID(ENTITY) \
    /*! \brief Constructeur fixant l'identifiant de l'entitée.*/ \
    ENTITY(int id) \
    : Entity(id)   {}

//! \ingroup groupeConstrMacroEntity
//! Constructeur de recopie.
#define CONSTR_RECOPIE(ENTITY) \
    /*! \brief Constructeur de recopie.*/ \
    ENTITY(const ENTITY & entity) \
    : Entity(entity.id()) \
    {set(entity);}

//! \ingroup groupeConstrMacroEntity
//! Destructeur par défaut.
#define DESTRUCT(ENTITY) \
    /*! \brief Destructeur.*/ \
    ~ENTITY() \
    {}

//! \ingroup groupeConstrMacroEntity
//! Regroupe les macros des constructeurs et la macro du destructeur par défaut.
#define CONSTR_MACRO(ENTITY) \
    CONSTR_DEFAUT(ENTITY) \
    CONSTR_ENTITY(ENTITY) \
    CONSTR_ID(ENTITY) \
    CONSTR_RECOPIE(ENTITY) \
    DESTRUCT(ENTITY)

//Convertion

/*! \defgroup groupeConvertMacroEntity Conversion
 * \ingroup groupeMacroEntity
 * \brief Ensemble des macros implémentant les méthodes statiques de conversion des références et pointeurs d'entitées.
 */

//! \ingroup groupeConvertMacroEntity
//! Macro définisant le menbre convert permettant la conversion de pointeur après vérification.
#define CONVERT_ENTITY_PTR(ENTITY) \
    /*! \brief Convertit la référence entity en une référence de type ENTITY, aprés vérification.*/ \
    static ENTITY * convert(Entity *entity) \
    {if(verifEntity(entity)) \
        {return (ENTITY*) entity;} \
    else \
        {throw std::invalid_argument("Mauvaise correspondance des Entity");}}

//! \ingroup groupeConvertMacroEntity
//! Macro définisant le menbre convert permettant la conversion de référence constante après vérification.
#define CONVERT_ENTITY_REF(ENTITY) \
    /*! \brief Convertit la référence constante entity en une référence constante de type ENTITY, aprés vérification.*/ \
    static ENTITY & convert(Entity & entity) \
    {if(verifEntity(entity)) \
        {return *((ENTITY*) &entity);} \
    else \
        {throw std::invalid_argument("Mauvaise correspondance des Entity");}}

//! \ingroup groupeConvertMacroEntity
//! Macro définisant le menbre convert permettant la conversion de référence constante après vérification.
#define CONVERT_ENTITY_CONST_REF(ENTITY) \
    /*! \brief Convertit le pointeur entity en un pointeur de type ENTITY, aprés vérification.*/ \
    static const ENTITY & convert(const Entity & entity) \
    {if(verifEntity(entity)) \
        {return *((ENTITY*) &entity);} \
    else \
        {throw std::invalid_argument("Mauvaise correspondance des Entity");}}

//! \ingroup groupeConvertMacroEntity
//! Macro définissant le membre idEntity renvoyant l'identifiant du type l'entitée.
#define ID_ENTITY(ENTITY) entityId \
    /*! \brief Renvoie l'identifiant du type ENTITY.*/ \
    idEntity() const \
    {return IdEntity;}

//! \ingroup groupeConvertEntity
//! Macro définissant les menbres statique IdEntity et Name.
#define VAR_STAT_IDENTITY_NAME(ENTITY) \
    /*! \brief Identifiant du type de l'entitée.*/ \
    static const entityId IdEntity = ENTITY ## Id; \
    static constexpr char Name[] = #ENTITY;    //!< Nom de l'entitée.

//! \ingroup groupeConvertMacroEntity
//! Macro définissant le membre static verifEntity testant si un pointeur est du type du type de l'entitée.
#define VERIF_ENTITY_PTR(ENTITY) \
    /*! \brief Test si le pointeur entity est aussi un pointeur de type ENTITY.*/ \
    static bool verifEntity(Entity * entity) \
    {return IdEntity == entity->idEntity();}

//! \ingroup groupeConvertMacroEntity
//! Macro définissant le membre static verifEntity testant si une référence est du type du type de l'entitée.
#define VERIF_ENTITY_REF(ENTITY) \
    /*! \brief Test si la référence entity est aussi une référence de type ENTITY.*/ \
    static bool verifEntity(const Entity & entity) \
    {return IdEntity == entity.idEntity();}

//! \ingroup groupeConvertMacroEntity
//! Regroupe les macros permettant la conversion des entitées.
#define CONVERT_MACRO(ENTITY) \
    CONVERT_ENTITY_PTR(ENTITY) \
    CONVERT_ENTITY_REF(ENTITY) \
    CONVERT_ENTITY_CONST_REF(ENTITY) \
    ID_ENTITY(ENTITY) \
    VAR_STAT_IDENTITY_NAME(ENTITY) \
    VERIF_ENTITY_PTR(ENTITY) \
    VERIF_ENTITY_REF(ENTITY)

// Opérateurs

/*! \defgroup groupeOpMacroEntity Opérateurs
 * \ingroup groupeMacroEntity
 * \brief Ensemble des macros implémentant des opérateurs pour les entitées.
 */


//! \ingroup groupeOpMacroEntity
//! Macro définissant l'opérateur == avec une Entitée de même type.
#define OP_EGAL(ENTITY) \
    /*! \brief Test d'égalité entre deux entitées de type ENTITY, c'est-à-dire l'égalité de tous les attributs..*/ \
    bool operator == (const ENTITY & entity) const \
    {return egal(entity);}

//! \ingroup groupeOpMacroEntity
//! Macro définissant l'opérateur == avec une Entity.
#define OP_EGAL_ENTITY(ENTITY) \
    /*! \brief Test d'égalité entre une entitée de type ENTITY et une référence Entity sur une entitée de type ENTITY, c'est-à-dire l'égalité de tous les attributs.*/ \
    bool operator == (const Entity & entity) const\
    {return egal(convert(entity));}

//! \ingroup groupeOpMacroEntity
//! Macro définissant l'opérateur << avec une Entity.
#define OP_INJ(ENTITY) \
    /*! \brief Modifient les valeurs des attributs de l'entitée avec celles des attributs de entity.*/ \
    void operator << (const ENTITY & entity) \
    {setId(entity.id()); \
    set(entity);}

//! \ingroup groupeOpMacroEntity
//! Macro définissant l'opérateur << avec une Entity.
#define OP_INJ_ENTITY(ENTITY) \
    /*! \brief Modifient les valeurs des attributs de l'entitée avec celles des attributs de entity.*/ \
    void operator << (const Entity & entity) \
    {setId(entity.id()); \
    set(convert(entity));}

//! \ingroup groupeOpMacroEntity
//! Regroupe les macros des opérateurs.
#define OP_MACRO(ENTITY) \
    OP_EGAL(ENTITY) \
    OP_EGAL_ENTITY(ENTITY) \
    OP_INJ(ENTITY) \
    OP_INJ_ENTITY(ENTITY)

//Membre Divers

/*! \defgroup groupeDivEntity Divers
 * \ingroup groupeMacroEntity
 * \brief Ensemble de divers macros pour les entitées.
 */

//! \ingroup groupeDivEntity
//! Macro définissant le membre NbrAtt renvoyant le nombre de valeurs de l'entitée.
#define NBR_VALUE(ENTITY) \
    /*! \brief Renvoie le nombre de valeur des entititées de type ENTITY.*/ \
    int nbrAtt() const \
    {return NbrAtt;}

//! \ingroup groupeDivEntity
//! Regroupe les macros de divers membres.
#define MEMBRE_DIVER_MACRO(ENTITY) \
    NBR_VALUE(ENTITY)

//! \ingroup groupeDivEntity
//! Macro permettant d'incorporer les macros communes à toutes les entitées.
#define INCLUCE_METHODE(ENTITY) \
    CONSTR_MACRO(ENTITY) \
    CONVERT_MACRO(ENTITY) \
    OP_MACRO(ENTITY) \
    MEMBRE_DIVER_MACRO(ENTITY)

//Nom et position des attributs de l'entitée.

/*! \defgroup groupeNomPosEntity Nom et position
 * \ingroup groupeMacroEntity
 * \brief Ensemble de macros définisant le nom et la position des attributs d'une entitée.
 */

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom et la position d'un attributs
#define NOM_POS_1_ATT(ATT1) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, IdPos = 1}; \
    /*!< Nombre d'attributs de l'entitée. */ \
    static const int NbrAtt = 2; \
    /*! \brief Tableau des attributs de l'entitée.*/ \
    static constexpr std::array<const char*,NbrAtt> Att {{#ATT1, "ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom et la position de deux attributs
#define NOM_POS_2_ATT(ATT1,ATT2) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, IdPos = 2}; \
    /*!< Nombre d'attributs de l'entitée. */ \
    static const int NbrAtt = 3; \
    /*! \brief Tableau des attributs de l'entitée.*/ \
    static constexpr std::array<const char*,NbrAtt> Att {{#ATT1, #ATT2, "ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom et la position de trois attributs
#define NOM_POS_3_ATT(ATT1,ATT2,ATT3) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, IdPos = 3}; \
    /*!< Nombre d'attributs de l'entitée. */ \
    static const int NbrAtt = 4; \
    /*! \brief Tableau des attributs de l'entitée.*/ \
    static constexpr std::array<const char*,NbrAtt> Att {{#ATT1, #ATT2, #ATT3, "ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom et la position de quatre attributs
#define NOM_POS_4_ATT(ATT1,ATT2,ATT3,ATT4) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, IdPos = 4}; \
    /*!< Nombre d'attributs de l'entitée. */ \
    static const int NbrAtt = 5; \
    /*! \brief Tableau des attributs de l'entitée.*/ \
    static constexpr std::array<const char*,NbrAtt> Att {{#ATT1, #ATT2, #ATT3, #ATT4, "ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom et la position de cinq attributs
#define NOM_POS_5_ATT(ATT1,ATT2,ATT3,ATT4,ATT5) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, IdPos = 5}; \
    /*!< Nombre d'attributs de l'entitée. */ \
    static const int NbrAtt = 6; \
    /*! \brief Tableau des attributs de l'entitée.*/ \
    static constexpr std::array<const char*,NbrAtt> Att {{#ATT1, #ATT2, #ATT3, #ATT4, #ATT5, "ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom et la position de cinq attributs
#define NOM_POS_6_ATT(ATT1,ATT2,ATT3,ATT4,ATT5,ATT6) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, ATT6 ## Pos = 5, IdPos = 6}; \
    /*!< Nombre d'attributs de l'entitée. */ \
    static const int NbrAtt = 7; \
    /*! \brief Tableau des attributs de l'entitée.*/ \
    static constexpr std::array<const char*,NbrAtt> Att {{#ATT1, #ATT2, #ATT3, #ATT4, #ATT5, #ATT6, "ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom et la position de cinq attributs
#define NOM_POS_7_ATT(ATT1,ATT2,ATT3,ATT4,ATT5,ATT6,ATT7) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, ATT6 ## Pos = 5, ATT7 ## Pos = 6, IdPos = 7}; \
    /*!< Nombre d'attributs de l'entitée. */ \
    static const int NbrAtt = 8; \
    /*! \brief Tableau des attributs de l'entitée.*/ \
    static constexpr std::array<const char*,NbrAtt> Att {{#ATT1, #ATT2, #ATT3, #ATT4, #ATT5, #ATT6, #ATT7, "ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom et la position de cinq attributs
#define NOM_POS_8_ATT(ATT1,ATT2,ATT3,ATT4,ATT5,ATT6,ATT7,ATT8) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, ATT6 ## Pos = 5, ATT7 ## Pos = 6, ATT8 ## Pos = 7, IdPos = 8}; \
    /*!< Nombre d'attributs de l'entitée. */ \
    static const int NbrAtt = 9; \
    /*! \brief Tableau des attributs de l'entitée.*/ \
    static constexpr std::array<const char*,NbrAtt> Att {{#ATT1, #ATT2, #ATT3, #ATT4, #ATT5, #ATT6, #ATT7, #ATT8, "ID"}};

//Accesseurs et mutateurs de différent attribut courant

/*! \defgroup groupeGetSetEntity Accesseurs et mutateurs
 * \ingroup groupeMacroEntity
 * \brief Ensemble macros implémentant les accesseurs et mutateurs des entitées.
 */

//! \ingroup groupeGetSetEntity
//! Implémentation des getteur et setteur d'un booléen.
#define GET_SET_BOOL(nom,Nom) \
    /*! \brief Retourne la valeur de l'attribut nom.*/ \
    bool nom() const {return m_ ## nom;} \
    /*! \brief Modifie l'attribut nom.*/ \
    void set ## Nom(bool bb) \
    {m_ ## nom = bb;}

//! \ingroup groupeGetSetEntity
//! Implémentation des getteur et setteur d'un attribut date.
#define GET_SET_DATE(nom,Nom) \
    /*! \brief Retourne la valeur de l'attribut nom.*/ \
    const QDate & nom() const {return m_ ## nom;} \
    /*! \brief Modifie l'attribut nom.*/ \
    void set ## Nom(const QDate & date) \
    {m_ ## nom = date;}

//! \ingroup groupeGetSetEntity
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

//! \ingroup groupeGetSetEntity
//! Implémentation des getteur et setteur d'un attribut date valide.
#define GET_SET_DATETIME_VALIDE(nom,Nom) \
    /*! \brief Retourne la valeur de l'attribut nom.*/ \
    const QDateTime & nom() const {return m_ ## nom;} \
    /*! \brief Modifie l'attribut nom.*/ \
    void set ## Nom(const QDateTime & date) \
    {if(date.isValid()) \
        {m_ ## nom = date;} \
    else \
        {m_erreurs.append(QPair<int,int>(m_id,Nom ## Pos));}}
//! \ingroup groupeGetSetEntity
//! Implémentation des getteur et setteur d'un double.
#define GET_SET_DOUBLE(nom,Nom) \
    /*! \brief Retourne la valeur de l'attribut nom.*/ \
    double nom() const {return m_ ## nom;} \
    /*! \brief Modifie l'attribut nom.*/ \
    void set ## Nom(double d) \
    {m_ ## nom = d;}

//! \ingroup groupeGetSetEntity
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

//! \ingroup groupeGetSetEntity
//! Implémentation des getteur et setteur d'un entier sans condition.
#define GET_SET_INT(nom,Nom) \
    /*! \brief Retourne la valeur de l'attribut nom.*/ \
    int nom() const {return m_ ## nom;} \
    /*! \brief Modifie l'attribut nom.*/ \
    void set ## Nom(int n) \
    {m_ ## nom = n;}

//! \ingroup groupeGetSetEntity
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

//! \ingroup groupeGetSetEntity
//! Implémentation des getteur et setteur d'un attribut Qvariant.
#define GET_SET_QVARIANT_NOT_NULL(nom,Nom) \
    /*! \brief Retourne la valeur de l'attribut nom.*/ \
    const QVariant & nom() const {return m_ ## nom;} \
    /*! \brief Modifie l'attribut nom.*/ \
    void set ## Nom(const QVariant & valeur) \
    {if(!valeur.isNull()) \
        {m_ ## nom = valeur;} \
    else \
        {m_erreurs.append(QPair<int,int>(m_id,Nom ## Pos));}}

//! \ingroup groupeGetSetEntity
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

//! \ingroup groupeGetSetEntity
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
    enum entityId  {EntityId = -1,
                    ArbreEntityId = -2,
                    AnneeId,
                    ArbreAttributId,
                    ArbreCoursId,
                    ArbreDonneeId,
                    ArbreEnonceId,
                    ArbreExerciceId,
                    AttributId,
                    AttributCommentaireId,
                    AttributCorrectionId,
                    AttributCoursId,
                    AttributBaremeId,
                    AttributExerciceId,
                    BaremeId,
                    ClasseId,
                    ClasseEleveId,
                    CoefficientId,
                    CommentaireId,
                    CommentaireClasseId,
                    CommentaireEleveId,
                    CommentaireGroupeId,
                    CompteurTypeControleId,
                    ControleId,
                    CorrectionId,
                    CoursId,
                    DonneeId,
                    DonneeClasseId,
                    DonneeEleveId,
                    DonneeEtablissementId,
                    DonneeNiveauId,
                    DonneeSourceId,
                    EleveId,
                    EnonceId,
                    EtablissementId ,
                    EtablissementNiveauId,
                    ExerciceId,
                    ExerciceCorrectionId,
                    ExerciceUtilisationId,
                    FormeId,
                    GroupeId,
                    GroupeEleveId,
                    NiveauId,
                    NiveauPrecedentId,
                    NoteId,
                    PointId,
                    SourceId,
                    SourceExerciceId,
                    SourceCorrectionId,
                    SourceCoursId,
                    TexteId,
                    TypeControleId,
                    TypeCours,
                    TypeNiveauId,
                    TypeUtilisationId,
                    Utilisation
                   };

    VAR_STAT_IDENTITY_NAME(Entity)
    //static const entityId IdEntity = EntityId;  //!< Identifiant du type de l'entitée.
    //static constexpr char Name[] = "Entity";    //!< Nom de l'entitée.
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
