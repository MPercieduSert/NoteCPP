#include "ClasseLinkSql.h"

void ClasseLinkSql::creer()
{
    exec(QString("create table ")
         .append(Table)
         .append(" (ID integer primary key,"
                 "IDan integer not null,"
                 "IDetab interger not null,"
                 "IDniv interger not null,"
                 "nm interger not null,"
                 "constraint UNcl unique (IDan, IDniv, IDetab, nm),"
                 "foreign key (IDan) references ").append(AnneeLinkSql<Annee>::Table).append(","
                 "foreign key (IDetab) references ").append(EtablissementLinkSql<EtablissementLinkSql<Etablissement>::Table).append(","
                 "foreign key (IDniv) references ").append(NiveauLinkSql<Niveau>::Table).append(")"));
    m_requete.finish();
}

QString ClasseLinkSql::writeStringUnique() const
{
    QString sql("SELECT ID FROM ");
    sql.append(Table).append(" WHERE IDan=? AND IDetab=? AND IDniv=? AND nm=?  LIMIT 1");
    sql.squeeze();
    return sql;
}

