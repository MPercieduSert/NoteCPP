/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/03/2016
 */
#ifndef ATTRIBUTENTITYMACROALIAS
#define ATTRIBUTENTITYMACROALIAS

#include "AttributEntity.h"

/*! \defgroup groupeAttributAlias Alias des attributs des entités
 * \ingroup groupeAttributEntity
 * \brief Ensemble des classes d'attributs d'entités fixant un alias des accesseurs et mutateurs.
 */

/*! \defgroup groupeMacroAttributAlias Macro définissant les alias
 * \ingroup groupeAttributAlias
 * \brief Ensemble des macros définissant les classes d'attributs d'entités.
 */

//! \ingroup groupeMacroAttributAlias
//! Macro définisant les alias de l'accesseur et du mutateurs d'une clé numéroté.
#define ALIAS_CLE(NOM,NUM) /*! \brief Alias de l'accesseur de id ## NUM. */ \
    int id ## NOM () const {return id ## NUM ();} \
    /*! \brief Alias du mutateurs de id ## NUM. */ \
    void setId ## NOM (int n) {setId ## NUM (n);}

//! \ingroup groupeMacroAttributAlias
//! Macro définisant les attributs de type bool de valeur par défaut false.
#define ALIAS_BOOL(NOM,nom) /*! \ingroup groupeAttributAlias */ \
    /*! \brief Classe de la l'attribut NOM ## . */ \
   class NOM ## Attribut : public BoolAttribut \
   {public: \
       /*! \brief Constructeur. */ \
       NOM ## Attribut(bool valeur = false) : BoolAttribut(valeur) {} \
       /*! \brief Alias de l'accesseur. */ \
       bool nom () const {return get();} \
       /*! \brief Alias du mutateurs. */ \
       void set ## NOM (bool n) {set(n);}};

//! \ingroup groupeMacroAttributAlias
//! Macro définisant les attributs de type QDate pouvant être soit vide, soit valide de valeur par défaut QDate().
#define ALIAS_DATE(NOM,nom) /*! \ingroup groupeAttributAlias */ \
    /*! \brief Classe de la l'attribut NOM ## . */ \
   class NOM ## Attribut : public DateNullAttribut \
   {public: \
       /*! \brief Constructeur. */ \
       NOM ## Attribut(const QDate & valeur = QDate()) : DateNullAttribut(valeur) {} \
       /*! \brief Alias de l'accesseur. */ \
       const QDate & nom () const {return get();} \
       /*! \brief Alias du mutateurs. */ \
       void set ## NOM (const QDate & valeur) {set(valeur);}};

//! \ingroup groupeMacroAttributAlias
//! Macro définisant les attributs de type QDate devant être valide de valeur par défaut QDate().
#define ALIAS_DATE_VALIDE(NOM,nom) /*! \ingroup groupeAttributAlias */ \
    /*! \brief Classe de la l'attribut NOM ## . */ \
   class NOM ## Attribut : public DateValideAttribut \
   {public: \
       /*! \brief Constructeur. */ \
       NOM ## Attribut(const QDate & valeur = QDate()) : DateValideAttribut(valeur) {} \
       /*! \brief Alias de l'accesseur. */ \
       const QDate & nom () const {return get();} \
       /*! \brief Alias du mutateurs. */ \
       void set ## NOM (const QDate & valeur) {set(valeur);}};

//! \ingroup groupeMacroAttributAlias
//! Macro définisant les clés étrangères.
#define ALIAS_ID(NOM) /*! \ingroup groupeAttributAlias */ \
    /*! \brief Classe de la clé id ## NOM ## . */ \
   class Id ## NOM ## Attribut : public IntSupAttribut<1> \
   {public: \
       /*! \brief Constructeur. */ \
       Id ## NOM ## Attribut(int n = 0) : IntSupAttribut<1>(n) {} \
       /*! \brief Alias de l'accesseur. */ \
       int id ## NOM () const {return get();} \
       /*! \brief Alias du mutateurs. */ \
       void setId ## NOM (int n) {set(n);}};

//! \ingroup groupeMacroAttributAlias
//! Macro définisant les clés étrangères.
#define ALIAS_ID_NULL(NOM) /*! \ingroup groupeAttributAlias */ \
    /*! \brief Classe de la clé id ## NOM ## . */ \
   class Id ## NOM ## NullAttribut : public IntSupAttribut<0> \
   {public: \
       /*! \brief Constructeur. */ \
       Id ## NOM ## NullAttribut(int n = 0) : IntSupAttribut<0>(n) {} \
       /*! \brief Alias de l'accesseur. */ \
       int id ## NOM () const {return get();} \
       /*! \brief Alias du mutateurs. */ \
       void setId ## NOM (int n) {set(n);}};

//! \ingroup groupeMacroAttributAlias
//! Macro définisant les attributs de type entier supérieur ou égal à N de valeur par défaut D.
#define ALIAS_INT_SUP(NOM,nom,N,D) /*! \ingroup groupeAttributAlias */ \
    /*! \brief Classe de la l'attribut NOM ## . */ \
   class NOM ## Attribut : public IntSupAttribut<N> \
   {public: \
       /*! \brief Constructeur. */ \
       NOM ## Attribut(int n = D) : IntSupAttribut<N>(n) {} \
       /*! \brief Alias de l'accesseur. */ \
       int nom () const {return get();} \
       /*! \brief Alias du mutateurs. */ \
       void set ## NOM (int n) {set(n);}};

//! \ingroup groupeMacroAttributAlias
//! Macro définisant les attributs de type QString pouvant être vide de valeur par défaut QString().
#define ALIAS_STR(NOM,nom) /*! \ingroup groupeAttributAlias */ \
    /*! \brief Classe de la l'attribut NOM ## . */ \
   class NOM ## Attribut : public StringAttribut \
   {public: \
       /*! \brief Constructeur. */ \
       NOM ## Attribut(const QString & valeur = QString()) : StringAttribut(valeur) {} \
       /*! \brief Alias de l'accesseur. */ \
       const QString & nom () const {return get();} \
       /*! \brief Alias du mutateurs. */ \
       void set ## NOM (const QString & valeur) {set(valeur);}};

//! \ingroup groupeMacroAttributAlias
//! Macro définisant les attributs de type QString ne pouvant être vide de valeur par défaut QString().
#define ALIAS_STR_NOT_EMPTY(NOM,nom) /*! \ingroup groupeAttributAlias */ \
    /*! \brief Classe de la l'attribut NOM ## . */ \
   class NOM ## Attribut : public StringNotEmptyAttribut \
   {public: \
       /*! \brief Constructeur. */ \
       NOM ## Attribut(const QString & valeur = QString()) : StringNotEmptyAttribut(valeur) {} \
       /*! \brief Alias de l'accesseur. */ \
       const QString & nom () const {return get();} \
       /*! \brief Alias du mutateurs. */ \
       void set ## NOM (const QString & valeur) {set(valeur);}};

//! \ingroup groupeMacroAttributAlias
//! Macro définisant les attributs de type QVariant pouvant être vide de valeur par défaut QVariant().
#define ALIAS_VARIANT(NOM,nom) /*! \ingroup groupeAttributAlias */ \
    /*! \brief Classe de la l'attribut NOM ## . */ \
   class NOM ## Attribut : public VariantAttribut \
   {public: \
       /*! \brief Constructeur. */ \
       NOM ## Attribut(const QVariant & valeur = QVariant()) : VariantAttribut(valeur) {} \
       /*! \brief Alias de l'accesseur. */ \
       const QVariant & nom () const {return get();} \
       /*! \brief Alias du mutateurs. */ \
       void set ## NOM (const QVariant & valeur) {set(valeur);}};

// Définitions des alias

ALIAS_DATE_VALIDE(Date,date)

/*! \ingroup groupeAttributAlias
 * \brief Classe de l'identifiant des entités.
 */
class IdAttributEntity : public IntSupAttribut<0>
{
public:
    //! Constructeur.
    IdAttributEntity(int n = 0)
        :IntSupAttribut<0>(n)
    {}

    //! Alias de l'accesseur.
    int id() const
    {return get();}

    //! Alias du mutateurs.
    void setId(int n)
    {set(n);}
};

// Id1 et Id2
ALIAS_ID(1)
ALIAS_ID(2)

/*! \ingroup groupeAttributAlias
 * \brief Classe de l'attribut nc.
 */
class NcNullAttribut : public StringAttribut
{
public:
    //! Constructeur.
    NcNullAttribut(const QString & valeur = QString())
        :StringAttribut(valeur)
        {}

    //! Alias de l'accesseur.
    const QString & nc() const
        {return get();}

    //! Alias du mutateurs.
    void setNc(const QString & valeur)
        {set(valeur);}
};

ALIAS_STR_NOT_EMPTY(Nc,nc)
ALIAS_STR_NOT_EMPTY(Nom,nom)
ALIAS_INT_SUP(Num,num,0,0)
ALIAS_STR_NOT_EMPTY(Texte,texte)
ALIAS_INT_SUP(Type,type,0,0)
ALIAS_VARIANT(Valeur,valeur)

#endif // ATTRIBUTENTITYMACROALIAS

