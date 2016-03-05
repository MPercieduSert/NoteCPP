#include "DonneeLinkSql.h"

void DonneeLinkSql::creer()
{
    exec(QString("create table ")
         .append(Name)
         .append(" (ID integer primary key,"
                 "cd inteder not null,"
                 "nm text not null,"
                 "sur integer not null,"
                 "tp integer not null,"
                 "tp_vl integer not null,"
                 "foreign key (ID) references arb_dn)"));
    m_requete.finish();
}
