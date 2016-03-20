/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/03/2016
 */

#ifndef ATTRIBUTENTITYALIAS_H
#define ATTRIBUTENTITYALIAS_H

#include "AttributEntity.h"

/*! \defgroup groupeAttributAlias Alias des attributs des entitées
 * \ingroup groupeAttributEntity
 * \brief Ensemble des classes d'attributs d'entitées fixant un alias des accesseurs et mutateurs.
 */

/*! \defgroup groupeMacroAttributAlias Macro définissant les alias
 * \ingroup groupeAttributAlias
 * \brief Ensemble des macros définissant les classes d'attributs d'entitées.
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

ALIAS_BOOL(Feuille,feuille)
ALIAS_BOOL(Fille,fille)
ALIAS_BOOL(PrBareme,prBareme)
ALIAS_BOOL(PrCommentaire,prCommentaire)
ALIAS_BOOL(PrCorrection,prCorrection)
ALIAS_BOOL(PrCours,prCours)
ALIAS_BOOL(PrExercice,prExercice)

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

ALIAS_DATE(Entree,entree)
ALIAS_DATE(Sortie,sortie)

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

ALIAS_DATE_VALIDE(Date,date)
ALIAS_DATE_VALIDE(Naissance,naissance)

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

ALIAS_ID(An)
ALIAS_ID(Cl)
ALIAS_ID(Etab)
ALIAS_ID(Niv)
ALIAS_ID(Tp)
ALIAS_ID(1)
ALIAS_ID(2)

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

ALIAS_ID_NULL(An)
ALIAS_ID_NULL(Cl)

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

ALIAS_INT_SUP(An,an,1,0)
ALIAS_INT_SUP(Alpha,alpha,0,0)
ALIAS_INT_SUP(Card,card,-1,-1)
ALIAS_INT_SUP(Niveau,niveau,0,0)
ALIAS_INT_SUP(Num,num,0,0)
ALIAS_INT_SUP(Parent,parent,0,0)
ALIAS_INT_SUP(Sur,sur,0,0)
ALIAS_INT_SUP(Type,type,0,0)
ALIAS_INT_SUP(TpVal,tpVal,0,0)

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

ALIAS_STR_NOT_EMPTY(Nc,nc)
ALIAS_STR_NOT_EMPTY(Nom,nom)
ALIAS_STR_NOT_EMPTY(Prenom,prenom)
ALIAS_STR_NOT_EMPTY(Texte,texte)

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

ALIAS_VARIANT(Valeur,valeur)

/*! \ingroup groupeAttributAlias
 * \brief Classe de l'identifiant des entitées.
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

#endif // ATTRIBUTENTITYALIAS_H
