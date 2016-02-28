#include "ArbreLinkSql.h"

QString ArbreLinkSql::writeStringUnique() const
{
    QString sql("SELECT ID FROM ");
    sql.append(Name).append(" WHERE nm=? AND pr=? LIMIT 1");
    sql.squeeze();
    return sql;
}
