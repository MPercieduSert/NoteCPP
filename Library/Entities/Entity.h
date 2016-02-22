/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/02/2016
 */

/*! \defgroup groupeEntity Entitées
 * \brief Ensemble de classes représentant les entitées en base de donnée.
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <QDate>
#include <QDateTime>
#include <QList>
#include <QPair>
#include <QString>
#include <QVariant>
#include <QVector>
#include <stdexcept>

// Macro pour les entitées

//! \ingroup groupeEntity
//! Constructeur par défaut.
#define CONSTR_DEFAUT(ENTITY_TYPE) ENTITY_TYPE() \
    {}

//! \ingroup groupeEntity
//! Constructeur fixant l'identifiant.
#define CONSTR_ID(ENTITY_TYPE) ENTITY_TYPE(int id) \
    : Entity(id)   {}

//! \ingroup groupeEntity
//! Macro définisant le menbre convert permettant la conversion de pointeur après vérification.
#define CONVERT_ENTITY_PTR(ENTITY_TYPE)     static ENTITY_TYPE * convert(Entity *entity)            \
{if(verifEntity(entity))                                                                            \
    {return (ENTITY_TYPE*) entity;}\                                                                \
else                                                                                                \
    {throw std::runtime_error("Mauvaise correspondance des Entity");}                               \
}

//! \ingroup groupeEntity
//! Macro définisant le menbre convert permettant la conversion de référence après vérification.
#define CONVERT_ENTITY_REF(ENTITY_TYPE)     static ENTITY_TYPE & convert(const Entity & entity)     \
{if(verifEntity(entity))                                                                            \
    {return *((ENTITY_TYPE*) &entity);}                                                             \
else                                                                                                \
    {throw std::runtime_error("Mauvaise correspondance des Entity");}                               \
}

//! \ingroup groupeEntity
//! Destructeur par défaut.
#define DESTRUCT(ENTITY_TYPE) ENTITY_TYPE() \
    {}

//! \ingroup groupeEntity
//! Macro définissant le membre idEntity renvoyant l'identifiant du type l'entitée.
#define ID_ENTITY entityId idEntity() const     \
    {return IdEntity;}

//! \ingroup groupeEntity
//! Macro définissant le membre nbrValue renvoyant le nombre de valeurs de l'entitée.
#define NBR_VALUE int nbrValue() const          \
    {return NbrValue;}

//! \ingroup groupeEntity
//! Macro définissant le membre static verifEntity testant si une référence est du type du type de l'entitée.
#define VERIF_ENTITY_REF static bool verifEntity(const Entity & entity)     \
    {return IdEntity == entity.idEntity();}

//! \ingroup groupeEntity
//! Macro définissant le membre static verifEntity testant si un pointeur est du type du type de l'entitée.
#define VERIF_ENTITY_PTR static bool verifEntity(Entity * entity)           \
    {return IdEntity == entity->idEntity();}
//! \ingroup groupeEntity
//! Macro permettant d'incorporer les macros communes à toutes les entitées.
#define INCLUCE_METHODE(ENTITY_TYPE)                                                                    \
    /*! \brief Constructeur par défaut fixant l'identifiant de l'entitée à 0.*/                         \
    CONSTR_DEFAUT(ENTITY_TYPE)                                                                          \
    /*! \brief Constructeur par défaut fixant l'identifiant de l'entitée.*/                             \
    CONSTR_DEFAUT(ENTITY_TYPE)                                                                          \
    /*! \brief Converti la référence entity en une référence de type ENTITY_TYPE, aprés vérification.*/ \
    CONVERT_ENTITY_REF(ENTITY_TYPE)                                                                     \
    /*! \brief Converti le pointeur entity en un pointeur de type ENTITY_TYPE, aprés vérification.*/    \
    CONVERT_ENTITY_PTR(ENTITY_TYPE)                                                                     \
    /*! \brief Renvoie l'identifiant du type ENTITY_TYPE.*/                                             \
    ID_ENTITY                                                                                           \
    /*! \brief Renvoie le nombre de valeur des entititées de type ENTITY_TYPE.*/                        \
    NBR_VALUE                                                                                           \
    /*! \brief Test si la référence entity est aussi une référence de type ENTITY_TYPE.*/               \
    VERIF_ENTITY_REF                                                                                    \
    /*! \brief Test si le pointeur entity est aussi un pointeur de type ENTITY_TYPE.*/                  \
    VERIF_ENTITY_PTR                                                                                    \

//! \ingroup groupeEntity
//! Liste des erreurs survenues lors de la modification d'une entitée.
//! Sous la forme de paires (identitfiant de l'entitée, position de l'attribut).
typedef QList<QPair<int,int> > ErrList;
/*
class Annee;
class Appreciation;
class Attribut;
class Attribut_bareme;
class Attribut_exercice;
class Bareme;
class Classe;
class Commentaire;
class Coefficient;
class Controle;
class Controle_exercice;
class Eleve;
class Eleve_groupe;
class Exercice;
class Groupe;
class Note;
class NumControle;
class Niveau;
class Point;
class Source;
class TypeControle;
class TypeGroupe;
class TypeNiveau;
*/


/*! \ingroup groupeEntity
 * \brief Classe abstraite de base des entitées.
 */

class Entity
{
    /*friend class Annee;
    friend class Appreciation;
    friend class Attribut;
    friend class Attribut_bareme;
    friend class Attribut_exercice;
    friend class Bareme;
    friend class Classe;
    friend class Commentaire;
    friend class Coefficient;
    friend class Controle;
    friend class Controle_exercice;
    friend class Eleve;
    friend class Eleve_groupe;
    friend class Exercice;
    friend class Groupe;
    friend class Note;
    friend class NumControle;
    friend class Niveau;
    friend class Point;
    friend class Source;
    friend class TypeControle;
    friend class TypeGroupe;
    friend class TypeNiveau;*/

public:
    //! Position des donnée dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.
    enum position {IdPos = 0,
                   PosPos = -1};

    //! Liste des identifiants des types d'entitées.
    enum entityId  {AnneeId = 5,
                    AppreciationId = 6,
                    AttributId = 2,
                    Attribut_baremeId = 7,
                    Attribut_exerciceId = 8,
                    BaremeId = 3,
                    ClasseId = 9,
                    CommentaireId = 10,
                    CoefficientId = 11,
                    ControleId = 12,
                    Controle_exerciceId = 13,
                    EleveId = 4,
                    Eleve_groupeId = 14,
                    EntityId = -1,
                    EntityAnneeId = -2,
                    ExerciceId = 15,
                    GroupeId = 16,
                    NoteId = 1,
                    NumControleId = 17,
                    NiveauId = 18,
                    PointId = 0,
                    SourceId = 22,
                    TypeControleId = 19,
                    TypeGroupeId = 20,
                    TypeNiveauId = 21};

    static const entityId IdEntity = EntityId;  //!< Identifiant du type de l'entitée.
    static const int NbrValue = 1;              //!< Nombre de valeur de l'entitée.

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

    //virtual int idAnnee() const                 {return 0;}

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

    /*
    virtual void setValue(int pos, const QVariant & val)
    {
        if(pos == IdPos)
        {
            setId(val.toInt());
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
    virtual QVariant value(int pos) const
    {
        if(pos == IdPos)
        {
            return QVariant(m_id);
        }
        else
        {
            return QVariant();
        }
    }*/

    //! Modifient les valeurs des attributs de l'entitée avec celles des attributs de entity.
    virtual void operator << (const Entity & entity) = 0;

    //! Opérateur testant l'égalité de deux entitées, c'est-à-dire l'égalité de tous les attributs.
    virtual bool operator == (const Entity & entity) const =0;

protected:
    /*void notDef() const                          {throw std::runtime_error("Fonction non définie");}

    virtual void setBool1(bool bb)                         {notDef();}
    virtual void setBool2(bool bb)                         {notDef();}
    virtual void setBool3(bool bb)                         {notDef();}
    virtual void setDate1(const QDate &  date)                         {notDef();}
    virtual void setDate2(const QDate &  date)                         {notDef();}
    virtual void setDateTime(const QDateTime &  date)                     {notDef();}
    virtual void setDouble(double dd)                       {notDef();}
    virtual void setInt1(int kk)                          {notDef();}
    virtual void setInt2(int kk)                          {notDef();}
    virtual void setInt3(int kk)                          {notDef();}
    virtual void setInt4(int kk)                          {notDef();}
    virtual void setInt5(int kk)                          {notDef();}
    virtual void setInt6(int kk)                          {notDef();}
    virtual void setString1(const QString & string)                       {notDef();}
    virtual void setString2(const QString & string)                       {notDef();}
    virtual void setString3(const QString & string)                       {notDef();}
    virtual void setString4(const QString & string)                       {notDef();}

    virtual bool valueBool1() const                 {notDef();return false;}
    virtual bool valueBool2() const                 {notDef();return false;}
    virtual bool valueBool3() const                 {notDef();return false;}
    virtual const QDate & valueDate1() const                {notDef();return QDate();}
    virtual const QDate & valueDate2() const                {notDef();return QDate();}
    virtual const QDateTime & valueDateTime() const        {notDef();return QDateTime();}
    virtual double valueDouble() const                {notDef();return -1;}
    virtual int valueInt1() const                   {notDef();return -1;}
    virtual int valueInt2() const                   {notDef();return -1;}
    virtual int valueInt3() const                   {notDef();return -1;}
    virtual int valueInt4() const                   {notDef();return -1;}
    virtual int valueInt5() const                   {notDef();return -1;}
    virtual int valueInt6() const                   {notDef();return -1;}
    virtual const QString & valueString1() const    {notDef();return QString();}
    virtual const QString & valueString2() const    {notDef();return QString();}
    virtual const QString & valueString3() const    {notDef();return QString();}
    virtual const QString & valueString4() const    {notDef();return QString();}*/
};

#endif // ENTITY_H
