#include "TypeNiveauLinkSql.h"

void TypeNiveauLinkSql::creer()
{
    exec(QString("create table ")
         .append(Name)
         .append(" (ID integer primary key,"
                 "nm text not null,"
                 "constraint IDtp_niv unique (nm))"));
    m_requete.finish();
}

QString TypeNiveauLinkSql::writeStringUnique() const
{
    QString sql("SELECT ID FROM ");
    sql.append(Name).append(" WHERE nm=? LIMIT 1");
    sql.squeeze();
    return sql;
}
