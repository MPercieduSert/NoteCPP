/*Auteur: PERCIE DU SERT Maxime
 *Date: 17/03/2016
 */
#ifndef ATTRIBUTENTITY_H
#define ATTRIBUTENTITY_H

#include <utility>
#include <QDate>
#include <QString>
#include <QVariant>

#include "../Div/Macro.h"

/*! \defgroup groupeAttributEntity Attributs des entités
 * \ingroup groupeEntity
 * \brief Ensemble de classes représentant les attributs des entités de la base de donnée.
 */

/*! \defgroup groupeBaseAttributEntity Classes de base des attributs des entités
 * \ingroup groupeAttributEntity
 * \brief Ensemble de classes représentant les attributs des entités de la base de donnée.
 */

//! \ingroup groupeBaseAttributEntity
//! Macro définisant les alias de l'accesseur et du mutateurs d'une clé numéroté.
#define ALIAS_CLE(NOM,NUM) /*! \brief Alias de l'accesseur de id ## NUM. */ \
    int id ## NOM () const {return id ## NUM ();} \
    /*! \brief Alias du mutateurs de id ## NUM. */ \
    void setId ## NOM (int n) {setId ## NUM (n);}

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut dans les entités.
 */
#define ATTRIBUT_ENTITY(NOM,nom,TYPE,type) protected: \
    TYPE m_ ## nom; /*!> Attribut nom */ \
    public: \
    /*! Accesseur de l'attribut nom.*/ \
    type nom() const {return m_ ## nom.get();} \
    /*! Mutateur de l'attribut nom.*/ \
    void set ## NOM(type valeur) {m_ ## nom.set(valeur);}

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut avec transmission par valeur dans les entités.
 */
#define ATTRIBUT_ENTITY_VAL(NOM,nom,TYPE,type) ATTRIBUT_ENTITY(NOM,nom,TYPE ## Attribut,type)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut avec transmission par référence dans les entités.
 */
#define ATTRIBUT_ENTITY_REF(NOM,nom,TYPE,type) ATTRIBUT_ENTITY(NOM,nom,TYPE ## Attribut, const type &)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut de type bool dans les entités.
 */
#define ATTRIBUT_ENTITY_BOOL(NOM,nom) ATTRIBUT_ENTITY_VAL(NOM,nom,Bool,bool)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut de type QDate pouvant être nulle dans les entités.
 */
#define ATTRIBUT_ENTITY_DATE_NULL(NOM,nom) ATTRIBUT_ENTITY_REF(NOM,nom,DateNull,QDate)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut de type QDate ne pouvant pas être nulle dans les entités.
 */
#define ATTRIBUT_ENTITY_DATE_VALIDE(NOM,nom) ATTRIBUT_ENTITY_REF(NOM,nom,DateValide,QDate)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut de type QDateTime dans les entités.
 */
#define ATTRIBUT_ENTITY_DATETIME(NOM,nom) ATTRIBUT_ENTITY_REF(NOM,nom,DateTime,QDateTime)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut de type QDateTime valide dans les entités.
 */
#define ATTRIBUT_ENTITY_DATETIME_VALIDE(NOM,nom) ATTRIBUT_ENTITY_REF(NOM,nom,DateTimeValide,QDateTime)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut de type double dans les entités.
 */
#define ATTRIBUT_ENTITY_DOUBLE(NOM,nom) ATTRIBUT_ENTITY_VAL(NOM,nom,Double,double)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut de type int dans les entités.
 */
#define ATTRIBUT_ENTITY_INT(NOM,nom) ATTRIBUT_ENTITY(NOM,nom,IntAttribut,int)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut de type int inférieur ou égale à N dans les entités.
 */
#define ATTRIBUT_ENTITY_INT_INF(NOM,nom,N) ATTRIBUT_ENTITY(NOM,nom,IntInfAttribut<N>,int)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut de type int supérieur ou égale à N dans les entités.
 */
#define ATTRIBUT_ENTITY_INT_SUP(NOM,nom,N) ATTRIBUT_ENTITY(NOM,nom,IntSupAttribut<N>,int)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un identifiant dans les entités.
 */
#define ATTRIBUT_ENTITY_ID(NOM) ATTRIBUT_ENTITY_INT_SUP(Id ## NOM,id ## NOM,1)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un identifiant pouvant être nulle dans les entités.
 */
#define ATTRIBUT_ENTITY_ID_NULL(NOM) ATTRIBUT_ENTITY_INT_SUP(Id ## NOM,id ## NOM,0)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut de type QString pouvant être vide dans les entités.
 */
#define ATTRIBUT_ENTITY_STR(NOM,nom) ATTRIBUT_ENTITY_REF(NOM,nom,String,QString)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut de type QString ne pouvant pas être vide dans les entités.
 */
#define ATTRIBUT_ENTITY_STR_NOT_EMPTY(NOM,nom) ATTRIBUT_ENTITY_REF(NOM,nom,StringNotEmpty,QString)

/*! \ingroup groupeBaseAttributEntity
 * \brief Macro de déclaration d'un attribut de type QVariant dans les entités.
 */
#define ATTRIBUT_ENTITY_VARIANT(NOM,nom) ATTRIBUT_ENTITY_REF(NOM,nom,Variant,QVariant)

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs des entités.
 */
class AttributEntity
{
public:
    //! Constructeur, pour le constructeur par défaut la valeur n'est pas valide.
    AttributEntity()
        {}

    //! Renvoie la validité de la valeur.
    virtual bool isValid() const
        {return true;}

    //! Renvoie une chaine de caractère contenant la valeur de l'attribut.
    virtual QString toString() const = 0;

    //! Renvoie la chaine "valide" si l'attribut est valide et "invalide" sinon.
    QString validToString() const
        {return isValid() ? "valide" : "invalide";}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe patron des attribut avec une transimision par reférence dans les accesseurs et mutateurs.
 */
template<class T> class AttributEntityRef : public AttributEntity
{
protected:
    T m_valeur = T();     //!< Valeur de l'attribut.

public:
    CONSTR_DEFAUT(AttributEntityRef)
    CONSTR_AFFECT_DEFAUT(AttributEntityRef)

    //! Constructeur, donner la valeur de l'attribut en argument.
    AttributEntityRef(const T & valeur)
        : m_valeur(valeur)
        {}

    //! Accesseur de l'attribut.
    const T & get() const
        {return m_valeur;}

    //! Mutateur de l'attribut.
    void set(const T & valeur)
        {m_valeur = valeur;}

    //! Renvoie une chaine de caractère contenant la valeur de l'attribut.
    QString toString() const
        {return QVariant(m_valeur).toString();}

    //! Teste l'égalité entre les deux attributs.
    bool operator == (const AttributEntityRef<T> & att) const
        {return m_valeur == att.m_valeur;}

    //! Teste l'égalité entre les deux attributs.
    bool operator == (const T & valeur) const
        {return m_valeur == valeur;}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe patron des attribut avec une transimision par valeur dans les accesseurs et mutateurs.
 */
template<class T> class AttributEntityVal : public AttributEntity
{
protected:
    T m_valeur = T(); //!< Valeur de l'attribut.

public:
    CONSTR_DEFAUT(AttributEntityVal)
    CONSTR_AFFECT_DEFAUT(AttributEntityVal)

    //! Constructeur, donner la valeur de l'attribut en argument.
    AttributEntityVal(T valeur)
        : m_valeur(valeur)
        {}

    //! Accesseur de l'attribut.
    T get() const
        {return m_valeur;}

    //! Mutateur de l'attribut.
    void set(T  valeur)
        {m_valeur = valeur;}

    //! Renvoie une chaine de caractère contenant la valeur de l'attribut.
    QString toString() const
        {return QVariant(m_valeur).toString();}

    //! Teste l'égalité entre les deux attributs.
    bool operator == (const AttributEntityVal<T> & entity) const
        {return m_valeur == entity.m_valeur;}

    //! Teste l'égalité entre les deux attributs.
    bool operator == (T valeur) const
        {return m_valeur == valeur;}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type Bool.
 */
class BoolAttribut : public AttributEntityVal<bool>
{
public:
    //! Constructeur.
    BoolAttribut(bool valeur = true)
        :AttributEntityVal<bool>(valeur)
        {}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type date pouvant être nulle.
 */
class DateNullAttribut : public AttributEntityRef<QDate>
{
public:
    //! Constructeur.
    DateNullAttribut(const QDate & valeur = QDate())
        :AttributEntityRef<QDate>(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValid() const final
        {return m_valeur.isNull() || m_valeur.isValid();}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type date valide.
 */
class DateValideAttribut : public AttributEntityRef<QDate>
{
public:
    //! Constructeur.
    DateValideAttribut(const QDate & valeur = QDate())
        :AttributEntityRef<QDate>(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValid() const final
        {return m_valeur.isValid();}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type date pouvant être nulle.
 */
class DateTimeAttribut : public AttributEntityRef<QDateTime>
{
public:
    //! Constructeur.
    DateTimeAttribut(const QDateTime & valeur = QDateTime())
        :AttributEntityRef<QDateTime>(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValid() const final
        {return true;}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type datetime valide.
 */
class DateTimeValideAttribut : public AttributEntityRef<QDateTime>
{
public:
    //! Constructeur.
    DateTimeValideAttribut(const QDateTime & valeur = QDateTime())
        :AttributEntityRef<QDateTime>(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValid() const final
        {return m_valeur.isValid();}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type double.
 */
class DoubleAttribut : public AttributEntityVal<double>
{
public:
    //! Constructeur.
    DoubleAttribut(double valeur = 0)
        : AttributEntityVal<double>(valeur)
        {}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Template des attributs de type entier sana condition.
 */
class IntAttribut : public AttributEntityVal<int>
{
public:
    //! Constructeur.
    IntAttribut(int valeur = 0)
        :AttributEntityVal<int>(valeur)
        {}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Template des attributs de type entier supérieur ou égal à N.
 */
template<int N> class IntSupAttribut : public AttributEntityVal<int>
{
public:
    //! Constructeur.
    IntSupAttribut(int valeur = 0)
        :AttributEntityVal<int>(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValid() const final
        {return m_valeur >= N;}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Template des attributs de type entier inférieur ou égal à N.
 */
template<int N> class IntInfAttribut : public AttributEntityVal<int>
{
public:
    //! Constructeur.
    IntInfAttribut(int valeur = 0)
        :AttributEntityVal<int>(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValid() const final
        {return m_valeur <= N;}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type QString pouvant être vide.
 */
class StringAttribut : public AttributEntityRef<QString>
{
public:
    //! Constructeur.
    StringAttribut(const QString & valeur = QString())
        :AttributEntityRef<QString>(valeur)
        {}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type QString non vide.
 */
class StringNotEmptyAttribut : public AttributEntityRef<QString>
{
public:
    //! Constructeur.
    StringNotEmptyAttribut(const QString & valeur = QString())
        :AttributEntityRef<QString>(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValid() const final
        {return !m_valeur.isEmpty();}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type QVariant pouvant être vide.
 */
class VariantAttribut : public AttributEntityRef<QVariant>
{
public:
    //! Constructeur.
    VariantAttribut(const QVariant & valeur = QVariant())
        :AttributEntityRef<QVariant>(valeur)
        {}
};

#endif // ATTRIBUTENTITY_H
