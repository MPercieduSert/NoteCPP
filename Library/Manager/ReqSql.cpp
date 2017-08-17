#include "ReqSql.h"

QSqlQuery * ReqSql::m_requete = 0;

void ReqSql::affError() const
{
    QSqlError err(m_requete->lastError());
    if(err.isValid())
        throw std::invalid_argument(err.text().append("\n"+err.nativeErrorCode()+m_requete->lastQuery()).toStdString());
}

QString ReqSql::createSqlString(bdd::createSql n)
{
    using namespace bdd;
    switch (n)
    {
    case createSql::Primary:
        return "integer primary key";
    case createSql::Bool:
    case createSql::Integer:
        return "integer";
    case createSql::DateTime:
    case createSql::Date:
    case createSql::Text:
        return "text";
    case createSql::Variant:
    case createSql::Blob:
        return "blob";
    case createSql::Double:
    case createSql::Real:
        return "real";
    case createSql::Numeric:
        return "numeric";
    case createSql::NotNull:
        return "not null";
    case createSql::Constraint:
        return "constraint";
    case createSql::Unique:
        return "unique";
    case createSql::Foreign:
        return "foreign key";
    case createSql::Ref:
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
    case wordSql::Create:
        return "CREATE TABLE";
    default:
        throw std::invalid_argument("Invalid argument dans wordSqlString");
    }
}
