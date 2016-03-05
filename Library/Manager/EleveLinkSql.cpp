#include "EleveLinkSql.h"

void EleveLinkSql::creer()
{
    exec(QString("create table ")
         .append(Name)
         .append(" (ID integer primary key,"
                 "fl integer not null,"
                 "ne text not null,"
                 "nm text not null,"
                 "pnm text not null,"
                 "constraint GRel unique (ne, nm, pnm))"));
    m_requete.finish();
}

QString EleveLinkSql::writeStringUnique() const
{
    QString sql("SELECT ID FROM ");
    sql.append(Name).append(" WHERE ne=? AND nm=? AND pnm=? LIMIT 1");
    sql.squeeze();
    return sql;
}
