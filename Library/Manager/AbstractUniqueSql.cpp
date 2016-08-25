#include "AbstractUniqueSql.h"

QString AbstractUniqueSql::uniqueString(const QString & table, const QMap<int,QString> & att) const
{
    QString sql("SELECT ID FROM ");
    sql.append(table).append(" WHERE");
    for(QMap<int,QString>::const_iterator i = att.cbegin(); i != att.cend(); ++i)
    {
        if(i.key() < 0 || i.key() >= att.size())
            throw std::invalid_argument(QString("Indice d'attribut unique sql invalide de la table : ")
                                        .append(table).append(" ").append(QString::number(i.key())).append(" -> ").append(i.value()).toStdString());
        sql.append(" ").append(i.value()).append("=? AND");
    }
    sql.chop(3);
    sql.append("LIMIT 1");
    sql.squeeze();
    return sql;
}
