#include "Manager.h"

Manager::Manager(QSqlDatabase & bdd, const QString &tableName, const QVector<QString> & colonne, const QVector<int> & colonneUnique) :
    m_colonneUnique(colonneUnique),
    m_requete(bdd),
    m_tableName(tableName)
{
    writeStringQuery();
    m_requete.setForwardOnly(true);
}

Manager::Manager(const QString &tableName, const QVector<QString> & colonne, const QVector<int> & colonneUnique) :
    m_colonneUnique(colonneUnique),
    m_requete(QSqlDatabase()),
    m_tableName(tableName)
{
    m_colonne<<"id";
    m_colonne<<colonne;
    writeStringQuery();
    m_requete.setForwardOnly(true);
}

QString Manager::messageErreurs(const Entity & entity) const
{
    QString message("Entity invalid:");
    message.append(QString::number(entity.idEntity())+"\n"+m_tableName+"\n"+QString::number(entity.id()));
    if(!entity.erreurs().isEmpty())
    {
        message.append("\n Erreurs :\n");
        QPair<int,int> erreur;
        foreach (erreur, entity.erreurs())
        {
            message.append(QString::number(erreur.second)+" :"+m_colonne.at(erreur.second)+"\n");
        }
    }
    else
    {
        message.append("/n pas d'erreurs");
    }
    return message;
}

void Manager::writeStringQuery()
{
    QString colonnes;
    for(int i = 0; i != nbrColonne(); ++i) colonnes.append(m_colonne.at(i)).append(",");
    colonnes.chop(1);

    //SQL Add
    m_sqlAdd = QString("INSERT INTO ");
    m_sqlAdd.append(m_tableName).append(" (").append(colonnes).append(") VALUES (");
    for(int i = 0; i != nbrColonne(); ++i) m_sqlAdd.append("?,");
    m_sqlAdd.chop(1);
    m_sqlAdd.append(")");

    //SQL Exists
    m_sqlExists = QString("SELECT 1 FROM ");
    m_sqlExists.append(m_tableName).append(" WHERE id=? LIMIT 1");

    //SQL ExistsUnique
    m_sqlExistsUnique = QString("SELECT 1 FROM ");
    m_sqlExistsUnique.append(m_tableName).append(" WHERE ");
    for(int i = 0; i != m_colonneUnique.size(); ++i)
        m_sqlExistsUnique.append(m_colonne.at(m_colonneUnique.at(i))).append("=? AND ");
    m_sqlExistsUnique.chop(5);
    m_sqlExistsUnique.append(" LIMIT 1");

    //SQL Get
    m_sqlGet = QString("SELECT ");
    m_sqlGet.append(colonnes).append(" FROM ").append(m_tableName).append(" WHERE id=?");

    //SQL GetList
    m_sqlGetList = QString("SELECT id,");
    m_sqlGetList.append(colonnes).append(" FROM ").append(m_tableName).append(" ORDER BY ");

    //SQL GetListWhere
    m_sqlGetListWhere = QString("SELECT id,");
    m_sqlGetListWhere.append(colonnes).append(" FROM ").append(m_tableName).append(" WHERE ").append("%1=?");

    //SQL Modify
    m_sqlModify = QString("UPDATE "),
    m_sqlModify.append(m_tableName).append(" SET ");
    for(int i = 0; i != m_colonne.size(); ++i) m_sqlModify.append(m_colonne.at(i)).append("=?,");
    m_sqlModify.chop(1);
    m_sqlModify.append("WHERE id=?");
}
