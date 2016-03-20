/*Auteur: PERCIE DU SERT Maxime
 *Date: 17/03/2016
 */

#ifndef ATTRIBUTENTITY_H
#define ATTRIBUTENTITY_H

#include <QDate>
#include <QString>
#include <QVariant>

/*! \defgroup groupeAttributEntity Attributs des entitées
 * \ingroup groupeEntity
 * \brief Ensemble de classes représentant les attributs des entitées de la base de donnée.
 */

/*! \ingroup groupeAttributEntity
 * \brief Classe mère des attributs des entitées.
 */
class AttributEntity
{
protected:
    bool m_valide;  //!< Enregistre la validité de la valeur de l'attribut.

public:
    //! Constructeur, pour le constructeur par défaut la valeur n'est pas valide.
    AttributEntity(bool valide = false)
        {m_valide = valide;}

    //! Modifie la validité de la valeur.
    void setValide(bool valide = true)
        {m_valide = valide;}

    //! Renvoie la validité de la valeur.
    bool valide() const
        {return m_valide;}

    //! Teste de validité.
    virtual void TestValide() = 0;
};

/*! \ingroup groupeAttributEntity
 * \brief Classe patron des attribut avec une transimision par reférence dans les accesseurs et mutateurs.
 */
template<class T> class AttributEntityRef : public AttributEntity
{
protected:
    T m_valeur;     //!< Valeur de l'attribut.

public:
    //! Constructeur par defaut.
    AttributEntityRef()
        {TestValide();}

    //! Constructeur, donner la valeur de l'attribut en argument.
    AttributEntityRef(const T & valeur)
        : m_valeur(valeur)
        {TestValide();}

    //! Teste l'égalité entre les deux attributs.
    bool egal(const AttributEntityRef<T> & entity) const
        {return m_valeur == entity.m_valeur;}

    //! Accesseur de l'attribut.
    const T & get() const
        {return m_valeur;}

    //! Mutateur de l'attribut.
    void set(const T & valeur)
    {
        m_valeur = valeur;
        TestValide();
    }

    //! Mutateur de l'attribut.
    void set(const AttributEntityRef<T> & entity)
        {set(entity.get());}
};

/*! \ingroup groupeAttributEntity
 * \brief Classe patron des attribut avec une transimision par valeur dans les accesseurs et mutateurs.
 */
template<class T> class AttributEntityVal : public AttributEntity
{
protected:
    T m_valeur; //!< Valeur de l'attribut.
    bool m_valide;  //!< Enregistre la validité de la valeur de l'attribut.

public:
    //! Constructeur par defaut.
    AttributEntityVal()
        {TestValide();}

    //! Constructeur, donner la valeur de l'attribut en argument.
    AttributEntityVal(T valeur)
        : m_valeur(valeur)
        {TestValide();}

    //! Teste l'égalité entre les deux attributs.
    bool egal(const AttributEntityVal<T> & entity) const
        {return m_valeur == entity.m_valeur;}

    //! Accesseur de l'attribut.
    T get() const
        {return m_valeur;}

    //! Mutateur de l'attribut.
    void set(T  valeur)
    {
        m_valeur = valeur;
        TestValide();
    }

    //! Mutateur de l'attribut.
    void set(const AttributEntityVal<T> & entity)
        {set(entity.get());}
};

/*! \ingroup groupeAttributEntity
 * \brief Classe mère des attributs de type entier positif.
 */
class BoolAttribut : public AttributEntityVal<bool>
{
public:
    //! Constructeur.
    BoolAttribut(bool valeur)
        :AttributEntityVal<bool>(valeur)
        {}

    //! Teste la validité de la valeur.
    void TestValide() final
        {setValide(true);}
};

/*! \ingroup groupeAttributEntity
 * \brief Classe mère des attributs de type entier positif.
 */
class DateNullAttribut : public AttributEntityRef<QDate>
{
public:
    //! Constructeur.
    DateNullAttribut(const QDate & valeur)
        :AttributEntityRef<QDate>(valeur)
        {}

    //! Teste la validité de la valeur.
    void TestValide() final
        {setValide(m_valeur.isNull() || m_valeur.isValid());}
};

class DateValideAttribut : public AttributEntityRef<QDate>
{
public:
    //! Constructeur.
    DateValideAttribut(const QDate & valeur)
        :AttributEntityRef<QDate>(valeur)
        {}

    //! Teste la validité de la valeur.
    void TestValide() final
        {setValide(m_valeur.isValid());}
};

/*! \ingroup groupeAttributEntity
 * \brief Classe mère des attributs de type entier supérieur ou égal à N.
 */
template<int N> class IntSupAttribut : public AttributEntityVal<int>
{
public:
    //! Constructeur.
    IntSupAttribut(int valeur)
        :AttributEntityVal<int>(valeur)
        {}

    //! Teste la validité de la valeur.
    void TestValide() final
        {setValide(m_valeur >= N);}
};

/*! \ingroup groupeAttributEntity
 * \brief Classe mère des attributs de type QString pouvant être vide.
 */
class StringAttribut : public AttributEntityRef<QString>
{
public:
    //! Constructeur.
    StringAttribut(const QString & valeur)
        :AttributEntityRef<QString>(valeur)
        {}

    //! Teste la validité de la valeur.
    void TestValide() final
        {setValide(true);}
};

/*! \ingroup groupeAttributEntity
 * \brief Classe mère des attributs de type QString non vide.
 */
class StringNotEmptyAttribut : public AttributEntityRef<QString>
{
public:
    //! Constructeur.
    StringNotEmptyAttribut(const QString & valeur)
        :AttributEntityRef<QString>(valeur)
        {}

    //! Teste la validité de la valeur.
    void TestValide() final
        {setValide(!m_valeur.isEmpty());}
};

/*! \ingroup groupeAttributEntity
 * \brief Classe mère des attributs de type QVariant pouvant être vide.
 */
class VariantAttribut : public AttributEntityRef<QVariant>
{
public:
    //! Constructeur.
    VariantAttribut(const QVariant & valeur)
        :AttributEntityRef<QVariant>(valeur)
        {}

    //! Teste la validité de la valeur.
    void TestValide() final
        {setValide(true);}
};
#endif // ATTRIBUTENTITY_H
