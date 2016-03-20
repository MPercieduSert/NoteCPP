#include "NiveauLinkSql.h"

void NiveauLinkSql::creer()
{
    exec(QString("create table ")
         .append(Table)
         .append(" (ID integer primary key,"
                 "IDtp integer not null,"
                 "nc text not null,"
                 "nm text not null,"
                 "constraint UNniv unique (nm),"
                 "foreign key (IDtp) references ").append(NiveauLinkSql<TypeNiveau>::Table).append(")"));
    m_requete.finish();
}

QString NiveauLinkSql::writeStringUnique() const
{
    QString sql("SELECT ID FROM ");
    sql.append(Table).append(" WHERE nm=? LIMIT 1");
    sql.squeeze();
    return sql;
}
