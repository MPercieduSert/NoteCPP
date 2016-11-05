#include "AbstractLinkSql.h"

QString AbstractLinkSql::creer(const QMap<int,QPair<bdd::createSql,bool>>& attCaract, const QMap<int, QString> &foreignKey) const
{
    QString sql(wordSqlString(bdd::wordSql::create));
    sql.append(" ").append(m_table).append("(").append(attribut(Entity::Id)).append(" ").append(createSqlString(bdd::createSql::primary));
    for(int i = 1; i != m_nbrAtt; ++i)
    {
        sql.append(",").append(attribut(i)).append(" ").append(createSqlString(attCaract.value(i).first));
        if(attCaract.value(i).second)
            sql.append(" ").append(createSqlString(bdd::createSql::notNull));
    }
    for(QMap<int, QString>::const_iterator i = foreignKey.cbegin(); i != foreignKey.cend(); ++i)
        sql.append(",").append(createSqlString(bdd::createSql::foreign)).append("(").append(attribut(i.key())).append(") ")
            .append(createSqlString(bdd::createSql::ref)).append(" ").append(i.value());
    return sql;
}
