/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef ATTRIBUTSMACROLINKSQL_H
#define ATTRIBUTSMACROLINKSQL_H

#include <QDate>
#include "../Entities/Entity.h"
#include "ReqSql.h"

/*! \defgroup groupeAttributSql Attribut
 * \ingroup groupeLinkSql
 * \brief Ensemble des attributs des liens.
 */

/*! \defgroup groupeMacroAttributSql Macros définissant les attributs
 * \ingroup groupeAttributSql
 * \brief Ensemble des macros définissant les attributs des liens.
 */

//! \ingroup groupeMacroAttributSql
//! Macro définisant les attributs des liens de type diféérent de QVariant.
#define ATTRIBUT_LINK(NOM,nom,TYPE,type) /*! \ingroup groupeAttributSql */ \
    /*! \brief Classe de la l'attribut NOM ## . */ \
    template<class T> class NOM ## AttributSql : public virtual ReqSql \
    {protected: \
    /*! \brief Constructeur. */ \
    NOM ## AttributSql() {} \
    /*! \brief Alias de l'accesseur. */ \
    type nom (int pos = Info<T>::NOM ## Pos) const {return to ## TYPE(pos);} \
    /*! \brief Alias du mutateurs. */ \
    void set ## NOM (const T & entity,int pos = Info<T>::NOM ## Pos) {m_requete->bindValue(pos,entity.nom());}};

//! \ingroup groupeMacroAttributSql
//! Macro définisant les attributs des liens de type diféérent de QVariant.
#define ATTRIBUT_LINK_NULL_TO_ZERO(NOM,nom,TYPE,type) /*! \ingroup groupeAttributSql */ \
    /*! \brief Classe de la l'attribut NOM ## . */ \
    template<class T> class NOM ## AttributSqlNullToZero : public virtual ReqSql \
    {protected: \
    /*! \brief Constructeur. */ \
    NOM ## AttributSqlNullToZero() {} \
    /*! \brief Alias de l'accesseur. */ \
    type nom (int pos = Info<T>::NOM ## Pos) const {return to ## TYPE(pos);} \
    /*! \brief Alias du mutateurs. */ \
    void set ## NOM (const T & entity,int pos = Info<T>::NOM ## Pos) {m_requete->bindValue(pos,zeroToNull(entity.nom()));}};

//Variant
//! \ingroup groupeMacroAttributSql
//! Macro définisant les attributs des liens de type QVariant.
#define ATTRIBUT_QVARIANT_LINK(NOM,nom) /*! \ingroup groupeAttributSql */ \
    /*! \brief Classe de la l'attribut NOM ## . */ \
    template<class T> class NOM ## AttributSql : public virtual ReqSql \
    {protected: \
    /*! \brief Constructeur. */ \
    NOM ## AttributSql() {} \
    /*! \brief Alias de l'accesseur. */ \
    QVariant nom (int pos = Info<T>::NOM ## Pos) const {return m_requete->value(pos);} \
    /*! \brief Alias du mutateurs. */ \
    void set ## NOM (const T & entity,int pos = Info<T>::NOM ## Pos) {m_requete->bindValue(pos,entity.nom());}};

// Définition de l'attribut SQL Id.
/*! \ingroup groupeAttributSql
 * \brief Classe de la l'attribut id.
 */
template<class T> class IdAttributSql : public virtual ReqSql
{
protected:
    //! Constructeur.
    IdAttributSql()
    {}

    //! Alias de l'accesseur.
    int id(int pos = Info<T>::IdPos) const
        {return toInt(pos);}

public:
    //! Alias du mutateurs.
    void setId(const Entity & entity,int pos = Info<T>::IdPos)
        {m_requete->bindValue(pos,entity.id());}
};

// Définition des attributs classiques
ATTRIBUT_LINK(Date,date,Date,QDate)
ATTRIBUT_LINK(Id1,id1,Int,int)
ATTRIBUT_LINK(Id2,id2,Int,int)
ATTRIBUT_LINK(Nc,nc,String,QString)
ATTRIBUT_LINK(Nom,nom,String,QString)
ATTRIBUT_LINK(Num,num,Int,int)
ATTRIBUT_LINK(Prenom,prenom,String,QString)
ATTRIBUT_LINK(Texte,texte,String,QString)
ATTRIBUT_LINK(Type,type,Int,int)
ATTRIBUT_QVARIANT_LINK(Valeur,valeur)

#endif // ATTRIBUTSMACROLINKSQL_H
