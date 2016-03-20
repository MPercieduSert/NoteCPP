#include "EtablissementLinkSql.h"

void EtablissementLinkSql::creer()
{
    exec(QString("create table ")
         .append(Table)
         .append(" (ID integer primary key,"
                 "nc text not null,"
                 "nm text not null,"
                 "tp integer not null,"
                 "constraint UNetab unique (nm))"));
    m_requete.finish();
}

QString EtablissementLinkSql::writeStringUnique() const
{
    QString sql("SELECT ID FROM ");
    sql.append(Table).append(" WHERE nm=? LIMIT 1");
    sql.squeeze();
    return sql;
}
