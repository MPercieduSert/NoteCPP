/*Auteur: PERCIE DU SERT Maxime
 *Date: 17/03/2016
 */
#ifndef ATTRIBUTSIMPLE_H
#define ATTRIBUTSIMPLE_H

#include <array>
#include <QDate>
#include <QMessageBox>
#include <QString>
#include <QVariant>
#include <utility>

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
#define SINGLE_ATTRIBUT(ATTRIBUT,MERE,MERETEMPLATE,NOM,nom,type) /*! \ingroup groupeBaseAttributEntity \brief Classe de l'attribut ATTRIBUT.*/ \
    class ATTRIBUT: public MERETEMPLATE { \
    public: \
    using MERETEMPLATE::MERE; \
    using MERETEMPLATE::get; \
    using MERETEMPLATE::set; \
    /*! Positions des attributs.*/ \
    enum Position {NOM, NbrAtt = 1}; \
    /*! \brief Retourne un QVariant contenant la donnée souhaitée, pos doit être valide.*/ \
    QVariant dataP(int /*pos*/) const {return get();} \
    /*! Nom de la classe de l'attribut.*/ \
    QString nameAttribut() const {return #ATTRIBUT;} \
    /*! Nom de l'attribut.*/ \
    static QString nomAttribut(int /*pos*/=0) {return #NOM;} \
    /*! Accesseur de l'attribut nom.*/ \
    type nom() const {return get();} \
    /*! Mutateur de l'attribut.*/ \
    void set(const ATTRIBUT & entity) {set(entity.get());}\
    /*! Mutateur de l'attribut nom.*/ \
    void set ## NOM(type valeur) {set(valeur);} \
    /*! Opérateur égalité */ \
    bool operator ==(const ATTRIBUT & entity) const {return MERETEMPLATE::operator ==(entity);}};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe signalant la fin d'une branche d'attribut.
 */
class NoAttribut;

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs des entités.
 */
class AttributEntity
{
public:

    //! Constructeur, pour le constructeur par défaut la valeur n'est pas valide.
    AttributEntity()
        {}

    using AttPre = NoAttribut;
    using AttSuiv = NoAttribut;

    //! Renvoie la validité de la valeur.
    virtual bool isValid() const
        {return isValidAttribut();}

    //! Renvoie la validité de la valeur.
    virtual bool isValidAttribut() const
        {return true;}

    //! Renvoie le nom de l'attribut.
    virtual QString nameAttribut() const = 0;

    //! Renvoie une chaine de caractère contenant le nom, la valeur est la validité de l'attribut.
    virtual QString affiche() const
        {return nameAttribut().append(" (").append(validToString()).append("): ").append(toStringAttribut());}

    //! Renvoie une chaine de caractère contenant la valeur de l'attribut.
    virtual QString toString() const
        {return toStringAttribut();}

    //! Renvoie une chaine de caractère contenant la valeur de l'attribut.
    virtual QString toStringAttribut() const = 0;

    //! Renvoie la chaine "valide" si l'attribut est valide et "invalide" sinon.
    QString validToString() const
        {return isValidAttribut() ? "valide" : "invalide";}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe patron des attribut avec une transimision par reférence dans les accesseurs et mutateurs.
 */
template<class T> class AttributEntityRef : public AttributEntity
{
protected:
    T m_valeur = T();     //!< Valeur de l'attribut.

public:
    using AttType = T;
    CONSTR_DEFAUT(AttributEntityRef)
    CONSTR_AFFECT_DEFAUT(AttributEntityRef)

    //! Constructeur, donner la valeur de l'attribut en argument.
    AttributEntityRef(const T & valeur)
        : m_valeur(valeur)
        {}

    //! Accesseur de l'attribut.
    const T & get() const
        {return m_valeur;}

    //! Accesseur de l'attribut pour la base de données.
    const T & getToBdd() const
        {return m_valeur;}

    //! Mutateur de l'attribut.
    void set(const T & valeur)
        {m_valeur = valeur;}

    //! Renvoie une chaine de caractère contenant la valeur de l'attribut.
    QString toStringAttribut() const
        {return QVariant(m_valeur).toString();}

    //! Retourne un QVariant contenant la donnée souhaitée, pos doit être valide.
    QVariant dataP(int /*pos*/) const
        {return m_valeur;}

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
    using AttType = T;
    CONSTR_DEFAUT(AttributEntityVal)
    CONSTR_AFFECT_DEFAUT(AttributEntityVal)

    //! Constructeur, donner la valeur de l'attribut en argument.
    AttributEntityVal(T valeur)
        : m_valeur(valeur)
        {}

    //! Accesseur de l'attribut.
    T get() const
        {return m_valeur;}

    //! Accesseur de l'attribut pour la base de données.
    T getToBdd() const
        {return m_valeur;}

    //! Mutateur de l'attribut.
    void set(T  valeur)
        {m_valeur = valeur;}

    //! Renvoie une chaine de caractère contenant la valeur de l'attribut.
    QString toStringAttribut() const
        {return QVariant(m_valeur).toString();}

    //! Retourne un QVariant contenant la donnée souhaitée, pos doit être valide.
    QVariant dataP(int /*pos*/) const
        {return m_valeur;}

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
class AttributBool : public AttributEntityVal<bool>
{
public:
    //! Constructeur.
    AttributBool(bool valeur = true)
        :AttributEntityVal<bool>(valeur)
        {}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type date pouvant être nulle.
 */
class AttributDateNull : public AttributEntityRef<QDate>
{
public:
    //! Constructeur.
    AttributDateNull(const QDate & valeur = QDate())
        :AttributEntityRef<QDate>(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValidAttribut() const final
        {return m_valeur.isNull() || m_valeur.isValid();}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type date valide.
 */
class AttributDateValide : public AttributEntityRef<QDate>
{
public:
    //! Constructeur.
    AttributDateValide(const QDate & valeur = QDate())
        :AttributEntityRef<QDate>(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValidAttribut() const final
        {return m_valeur.isValid();}
};

///*! \ingroup groupeBaseAttributEntity
// * \brief Classe mère des attributs de type date pouvant être nulle.
// */
//class AttributDateTime : public AttributEntityRef<QDateTime>
//{
//public:
//    //! Constructeur.
//    AttributDateTime(const QDateTime & valeur = QDateTime())
//        :AttributEntityRef<QDateTime>(valeur)
//        {}
//};

using AttributDateTime = AttributEntityRef<QDateTime>;

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type datetime valide.
 */
class AttributDateTimeCurrent: public AttributEntityRef<QDateTime>
{
public:
    //! Constructeur.
    AttributDateTimeCurrent(const QDateTime & valeur = QDateTime())
        :AttributEntityRef<QDateTime>(valeur)
        {}

    //! Accesseur de l'attribut pour la base de données.
    QDateTime getToBdd() const
        {return QDateTime::currentDateTime();}

    //! Accesseur de l'attribut pour la base de données.
    const QDateTime & getToBdd()
    {
        m_valeur = QDateTime::currentDateTime();
        return m_valeur;
    }

};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type datetime valide.
 */
class AttributDateTimeValide : public AttributEntityRef<QDateTime>
{
public:
    //! Constructeur.
    AttributDateTimeValide(const QDateTime & valeur = QDateTime())
        :AttributEntityRef<QDateTime>(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValidAttribut() const final
        {return m_valeur.isValid();}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type decimale.
 */
class AttributDecimale : public AttributEntityVal<int>
{
public:
    enum {NotFind = -1,
         NbrValues = 16};

    static const std::array<int, NbrValues> Decimale;   //! Liste des inverses des décimales permises.

    //! Constructeur.
    AttributDecimale(int valeur = 1)
        :AttributEntityVal<int>(valeur)
        {}

    //! Renvoie l'inverse de la valeur de Decimale d'indice indice.
    static float atome(int indice)
        {return 1.0 / Decimale.at(indice);}

    //! Renvoie l'inverse de m_valeur.
    float atome() const
        {return 1.0 / m_valeur;}

    //! Renvoie l'indice de valeur dans la list Decimale.
    static int indice(int valeur)
    {
        int i = 0;
        while(i != NbrValues && Decimale[i] != valeur)
            ++i;
        if(i != NbrValues)
            return i;
        else
            return NotFind;
    }

    //! Renvoie l'indice de m_valeur dans la list Decimale.
    int indice() const
    {return indice(m_valeur);}

    //! Teste la validité de la valeur.
    bool isValidAttribut() const final
        {return std::find(Decimale.begin(),Decimale.end(),m_valeur) != Decimale.end();}
};

///*! \ingroup groupeBaseAttributEntity
// * \brief Classe mère des attributs de type double.
// */
//class AttributDouble : public AttributEntityVal<double>
//{
//public:
//    //! Constructeur.
//    AttributDouble(double valeur = 0)
//        : AttributEntityVal<double>(valeur)
//        {}
//};

using AttributDouble = AttributEntityVal<double>;

///*! \ingroup groupeBaseAttributEntity
// * \brief Template des attributs de type entier sana condition.
// */
//class AttributInt : public AttributEntityVal<int>
//{
//public:
//    //! Constructeur.
//    AttributInt(int valeur = 0)
//        :AttributEntityVal<int>(valeur)
//        {}
//};

using AttributInt = AttributEntityVal<int>;

/*! \ingroup groupeBaseAttributEntity
 * \brief Template des attributs de type entier renvoyant Null pour zéro dans la base de données.
 */
class AttributIntNull : public AttributEntityVal<int>
{
public:
    //! Constructeur.
    AttributIntNull(int valeur = 0)
        :AttributEntityVal<int>(valeur)
        {}

    //! Accesseur de l'attribut pour la base de données.
    QVariant getToBdd() const
        {return m_valeur == 0 ? QVariant(QVariant::Int) : m_valeur;}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Template des attributs de type entier positif renvoyant Null pour zéro dans la base de données.
 */
class AttributIntNullPositif : public AttributIntNull
{
public:
    //! Constructeur.
    AttributIntNullPositif(int valeur = 0)
        :AttributIntNull(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValidAttribut() const final
        {return m_valeur >= 0;}

};

/*! \ingroup groupeBaseAttributEntity
 * \brief Template des attributs de type entier supérieur ou égal à N.
 */
template<int N> class AttributIntSup : public AttributEntityVal<int>
{
public:
    //! Constructeur.
    AttributIntSup(int valeur = 0)
        :AttributEntityVal<int>(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValidAttribut() const final
        {return m_valeur >= N;}
};

/*! \ingroup groupeBaseAttributEntity
 * \brief Template des attributs de type entier inférieur ou égal à N.
 */
template<int N> class AttributIntInf : public AttributEntityVal<int>
{
public:
    //! Constructeur.
    AttributIntInf(int valeur = 0)
        :AttributEntityVal<int>(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValidAttribut() const final
        {return m_valeur <= N;}
};

///*! \ingroup groupeBaseAttributEntity
// * \brief Classe mère des attributs de type QString pouvant être vide.
// */
//class AttributString : public AttributEntityRef<QString>
//{
//public:
//    //! Constructeur.
//    AttributString(const QString & valeur = QString())
//        :AttributEntityRef<QString>(valeur)
//        {}
//};

using AttributString = AttributEntityRef<QString>;

/*! \ingroup groupeBaseAttributEntity
 * \brief Classe mère des attributs de type QString non vide.
 */
class AttributStringNotEmpty : public AttributEntityRef<QString>
{
public:
    //! Constructeur.
    AttributStringNotEmpty(const QString & valeur = QString())
        :AttributEntityRef<QString>(valeur)
        {}

    //! Teste la validité de la valeur.
    bool isValidAttribut() const final
        {return !m_valeur.isEmpty();}
};

///*! \ingroup groupeBaseAttributEntity
// * \brief Classe mère des attributs de type QVariant pouvant être vide.
// */
//class AttributVariant : public AttributEntityRef<QVariant>
//{
//public:
//    //! Constructeur.
//    AttributVariant(const QVariant & valeur = QVariant())
//        :AttributEntityRef<QVariant>(valeur)
//        {}
//};

using AttributVariant = AttributEntityRef<QVariant>;

SINGLE_ATTRIBUT(AlphaAttribut,AttributIntSup,AttributIntSup<0>,Alpha,alpha,int)
SINGLE_ATTRIBUT(CardAttribut,AttributIntSup,AttributIntSup<-1>,Card,card,int)
SINGLE_ATTRIBUT(CibleAttribut,AttributIntSup,AttributIntSup<0>,Cible,cible,int)
SINGLE_ATTRIBUT(CreationAttribut,AttributDateTimeValide,AttributDateTimeValide,Creation,creation,QDateTime)
SINGLE_ATTRIBUT(DateValideAttribut,AttributDateValide,AttributDateValide,Date,date,QDate)
SINGLE_ATTRIBUT(DateTimeValideAttribut,AttributDateTimeValide,AttributDateTimeValide,DateTime,dateTime,QDateTime)
SINGLE_ATTRIBUT(DateTimeCurrentAttribut,AttributDateTimeCurrent,AttributDateTimeCurrent,DateTime,dateTime,QDateTime)
SINGLE_ATTRIBUT(DecimaleAttribut,AttributDecimale,AttributDecimale,Decimale,decimale,int)
SINGLE_ATTRIBUT(ExactAttribut,AttributBool,AttributBool,Exact,exact,bool)
SINGLE_ATTRIBUT(IdAttribut,AttributIntSup,AttributIntSup<0>,Id,id,int)
SINGLE_ATTRIBUT(IdCibleAttribut,AttributIntSup,AttributIntSup<1>,IdCible,idCible,int)
SINGLE_ATTRIBUT(IdOrigineAttribut,AttributIntSup,AttributIntSup<1>,IdOrigine,idOrigine,int)
SINGLE_ATTRIBUT(IdProgAttribut,AttributIntNullPositif,AttributIntNullPositif,IdProg,idProg,int)
SINGLE_ATTRIBUT(Id1Attribut,AttributIntSup,AttributIntSup<1>,Id1,id1,int)
SINGLE_ATTRIBUT(Id1NullAttribut,AttributIntNullPositif,AttributIntNullPositif,Id1,id1,int)
SINGLE_ATTRIBUT(Id2Attribut,AttributIntSup,AttributIntSup<1>,Id2,id2,int)
SINGLE_ATTRIBUT(Id2NullAttribut,AttributIntNullPositif,AttributIntNullPositif,Id2,id2,int)
SINGLE_ATTRIBUT(Id3Attribut,AttributIntSup,AttributIntSup<1>,Id3,id3,int)
SINGLE_ATTRIBUT(NcAttribut,AttributStringNotEmpty,AttributStringNotEmpty,Nc,nc,QString)
SINGLE_ATTRIBUT(NomAttribut,AttributStringNotEmpty,AttributStringNotEmpty,Nom,nom,QString)
SINGLE_ATTRIBUT(ModifAttribut,AttributBool,AttributBool,Modif,modif,bool)
SINGLE_ATTRIBUT(ModificationAttribut,AttributDateTimeCurrent,AttributDateTimeCurrent,Modification,modification,QDateTime)
SINGLE_ATTRIBUT(NumAttribut,AttributIntSup,AttributIntSup<0>,Num,num,int)
SINGLE_ATTRIBUT(ParentAttribut,AttributIntNullPositif,AttributIntNullPositif,Parent,parent,int)
SINGLE_ATTRIBUT(OrigineAttribut,AttributIntSup,AttributIntSup<0>,Origine,origine,int)
SINGLE_ATTRIBUT(SaisieAttribut,AttributBool,AttributBool,Saisie,saisie,bool)
SINGLE_ATTRIBUT(TexteAttribut,AttributStringNotEmpty,AttributStringNotEmpty,Texte,texte,QString)
SINGLE_ATTRIBUT(TotalAttribut,AttributIntSup,AttributIntSup<0>,Total,total,int)
SINGLE_ATTRIBUT(TpValAttribut,AttributIntSup,AttributIntSup<0>,TpVal,tpVal,int)
SINGLE_ATTRIBUT(TypeAttribut,AttributIntSup,AttributIntSup<0>,Type,type,int)
SINGLE_ATTRIBUT(ValeurIntAttribut,AttributInt,AttributInt,Valeur,valeur,int)
SINGLE_ATTRIBUT(ValeurDoubleAttribut,AttributDouble,AttributDouble,Valeur,valeur,double)
SINGLE_ATTRIBUT(ValeurVariantAttribut,AttributVariant,AttributVariant,Valeur,valeur,QVariant)

#endif // ATTRIBUTSIMPLE_H
