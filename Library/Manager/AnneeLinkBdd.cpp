#include "AnneeLinkSql.h"

void AnneeLinkSql::creer()
{
    exec(QString("create table ")
         .append(Name)
         .append(" (ID integer primary key,"
                 "an integer not null,"
                 "constraint IDan unique (an))"));
    m_requete.finish();
}

QString AnneeLinkSql::writeStringUnique() const
{
    QString sql("SELECT ID FROM ");
    sql.append(Name).append(" WHERE an=? LIMIT 1");
    sql.squeeze();
    return sql;
}
