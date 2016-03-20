/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */

#ifndef ARBRELINKSQL_H
#define ARBRELINKSQL_H

#include "LinkSqlUniqueSimple.h"
#include "../Entities/Arbre.h"

/*! \ingroup groupeLinkSql
 * \brief Classe mère des lien entre les entitées de type arbre de programation et leurs représentations en base de donnée.
 */

template <class T> class ArbreLinkSql : public LinkSqlUniqueSimple<T>
{
    USING_LINKSQL(T)

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    ArbreLinkSql(QSqlQuery & requete);

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const T & arbre)
    {
        m_requete.bindValue(T::FeuillePos, arbre.feuille());
        m_requete.bindValue(T::NiveauPos, arbre.niveau());
        m_requete.bindValue(T::NumPos, arbre.num());
        m_requete.bindValue(T::ParentPos, zeroToNull(arbre.parent()));
    }

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    void creer();

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(T & arbre)
    {
        arbre.setFeuille(m_requete.value(T::FeuillePos).toBool());
        arbre.setNiveau(m_requete.value(T::NiveauPos).toInt());
        arbre.setNum(m_requete.value(T::NumPos).toInt());
        arbre.setParent(m_requete.value(T::ParentPos).toInt());
    }

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    T * newFromRequete()
    {
        return new T(m_requete.value(T::FeuillePos).toBool(),
                               m_requete.value(T::NiveauPos).toInt(),
                               m_requete.value(T::NumPos).toInt(),
                               m_requete.value(T::ParentPos).toInt(),
                               m_requete.value(T::IdPos).toInt());
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const T & arbre)
    {
        m_requete.bindValue(0, arbre.num());
        m_requete.bindValue(1, zeroToNull(arbre.parent()));
    }

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne.
    QString writeStringUnique() const;
};

template<class T> ArbreLinkSql<T>::ArbreLinkSql(QSqlQuery & requete)
    : LinkSqlUniqueSimple<T>(requete,writeStringUnique())
    {}

template<class T> void ArbreLinkSql<T>::creer()
{
    exec(QString("create table ")
         .append(Table)
         .append(" (ID integer primary key,"
                 "fl integer not null,"
                 "nv integer not null,"
                 "nm integer not null,"
                 "pt integer,"
                 "constraint UN").append(Table).append(" unique (pt, nm),")
                 .append("foreign key (pt) references ").append(Table).append(")"));
    m_requete.finish();
}

template<class T> QString ArbreLinkSql<T>::writeStringUnique() const
{
    QString sql("SELECT ID FROM ");
    sql.append(Table).append(" WHERE nm=? AND pr=? LIMIT 1");
    sql.squeeze();
    return sql;
}
#endif // ARBRELINKSQL_H
