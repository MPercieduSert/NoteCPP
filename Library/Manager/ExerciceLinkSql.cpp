#include "ExerciceLinkSql.h"

void ExerciceLinkSql::creer()
{
    exec(QString("create table ")
         .append(Name)
         .append(" ID integer primary key,"
                 "IDarbex integer not null,"
                 "dt text not null,"
                 "tp interger not null,"
                 "vr interger not null,"
                 "rs text,"
                 "txt text,"
                 "tr text,"
                 "constraint GRex unique (IDarbex, vr),"
                 "foreign key (IDarbex) references arb_ex);"));
    m_requete.finish();
}

QString ExerciceLinkSql::writeStringUnique() const
{
    QString sql("SELECT ID FROM ");
    sql.append(Name).append(" WHERE IDarbex=? AND vr=? AND pnm=? LIMIT 1");
    sql.squeeze();
    return sql;
}
