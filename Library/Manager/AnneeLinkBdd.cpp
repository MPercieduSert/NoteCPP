#include "AnneeLinkSql.h"

void AnneeLinkSql::creer()
{
    exec(QString("create table ")
         .append(Table)
         .append(" (ID integer primary key,"
                 "an integer not null,"
                 "constraint UNan unique (an))"));
    m_requete.finish();
}

QString AnneeLinkSql::writeStringUnique() const
{
    QString sql("SELECT ID FROM ");
    sql.append(Table).append(" WHERE an=? LIMIT 1");
    sql.squeeze();
    return sql;
}
