#include "ArbreLinkSql.h"

void ArbreLinkSql::creer(const QString & name)
{
    exec(QString("create table ")
         .append(name)
         .append(" (ID integer primary key,"
                 "fl integer not null,"
                 "nv integer not null,"
                 "nm integer not null,"
                 "pt integer,"
                 "constraint GR").append(name).append(" unique (pt, nm),")
                 .append("foreign key (pt) references ").append(name).append(")"));
    m_requete.finish();
}

QString ArbreLinkSql::writeStringUnique() const
{
    QString sql("SELECT ID FROM ");
    sql.append(Name).append(" WHERE nm=? AND pr=? LIMIT 1");
    sql.squeeze();
    return sql;
}
