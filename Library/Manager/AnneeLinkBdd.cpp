#include "AnneeLinkSql.h"

bool AnneeLinkSql::creer()
{
    return m_requete.exec("create table an ("
                              "ID integer primary key,"
                              "an integer not null,"
                              "constraint IDan unique (an))");
}

QString AnneeLinkSql::writeStringUnique() const
{
    QString sql("SELECT ID FROM ");
    sql.append(Name).append(" WHERE an=? LIMIT 1");
    sql.squeeze();
    return sql;
}
