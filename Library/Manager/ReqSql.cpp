#include "ReqSql.h"

QSqlQuery * ReqSql::m_requete = 0;

void ReqSql::affError() const
{
    QSqlError err(m_requete->lastError());
    if(err.isValid())
    {
        throw std::invalid_argument(err.text().append("\n"+err.nativeErrorCode()+"\n"+m_requete->lastQuery()).toStdString());
    }
}

QString ReqSql::createSqlString(bdd::createSql n)
{
    using namespace bdd;
    switch (n)
    {
    case createSql::primary:
        return "integer primary key";
    case createSql::integer:
        return "integer";
    case createSql::text:
        return "text";
    case createSql::blob:
        return "blob";
    case createSql::real:
        return "real";
    case createSql::numeric:
        return "numeric";
    case createSql::notNull:
        return "not null";
    case createSql::constraint:
        return "constraint";
    case createSql::unique:
        return "unique";
    case createSql::foreign:
        return "foreign key";
    case createSql::ref:
        return "references";
    default:
        throw std::invalid_argument("Invalid argument dans createSqlString");
    }
}

QString ReqSql::wordSqlString(bdd::wordSql n)
{
    using namespace bdd;
    switch (n)
    {
    case wordSql::create:
        return "CREATE TABLE";
    default:
        throw std::invalid_argument("Invalid argument dans wordSqlString");
    }
}
