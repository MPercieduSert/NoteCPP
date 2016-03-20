/*Auteur: PERCIE DU SERT Maxime
 *Date: 02/03/2016
 */

#ifndef NOMLINKSQL_H
#define NOMLINKSQL_H

#include "LinkSqlUniqueSimple.h"
#include "../Entities/TypeNiveau.h"

/*! \ingroup groupeLinkSql
 * \brief Patron des liens entre les entitée de type nom de programation et sa représentation en base de donnée.
 */

template<class T> class NomLinkSql : public LinkSqlUniqueSimple<T>
{
    USING_LINKSQL(T)

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NomLinkSql(QSqlQuery & requete)
        : LinkSqlUniqueSimple<T>(requete,writeStringUnique())
        {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const T & entity)
        {m_requete.bindValue(T::NomPos,entity.nom());}

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    void creer();

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(T & entity)
        {entity.setNom(m_requete.value(T::NomPos).toString());}

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    T * newFromRequete()
    {
        return new T(m_requete.value(T::NomPos).toString(),
                              m_requete.value(T::IdPos).toInt());
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const T & entity)
        {m_requete.bindValue(0,entity.nom());}

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne.
    QString writeStringUnique() const;
};

typedef NomLinkSql<TypeNiveau> TypeNiveauLinkSql;

void NomLinkSql<TypeNiveau>::creer()
{
    exec(QString("create table ")
         .append(Table)
         .append(" (ID integer primary key,"
                 "nm text not null,"
                 "constraint UNtpniv unique (nm))"));
    m_requete.finish();
}

QString NomLinkSql<TypeNiveau>::writeStringUnique() const
{
    QString sql("SELECT ID FROM ");
    sql.append(Table).append(" WHERE nm=? LIMIT 1");
    sql.squeeze();
    return sql;
}
#endif // NOMLINKSQL_H
