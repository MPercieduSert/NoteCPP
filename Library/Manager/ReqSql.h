/*Auteur: PERCIE DU SERT Maxime
 *Date: 24/03/2016
 */

#ifndef REQSQL_H
#define REQSQL_H

#include <QDate>
#include <QDateTime>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QMessageBox>

/*! \ingroup groupeBaseManager
 * \brief Macro rappelant les méthodes de ReqSql dans les classes patrons.
 */
#define USING_REQSQL(T) using T::exec; \
using T::finish; \
using T::next; \
using T::prepare; \
using T::toInt;

/*! \ingroup groupeBaseManager
 * \brief Classe mère des liens contenant la référence sur l'objet de requète ouvert sur le base de donnée.
 */
class ReqSql
{
protected:
    QSqlQuery * m_requete;  //!< Référence vers la requète employée dans le manageur.

public:
    //! Constructeur.
    ReqSql(QSqlQuery * requete = 0)
        : m_requete(requete)
    {}

    //! Lance une execption contenant le message d'erreur de la derniere requète SQL exéctuter.
    void affError() const;

    //! Modifie le pointeur vers l'objet requête.
    void setRequete(QSqlQuery * req)
        {m_requete = req;}

    //! Destructeur.
    ~ReqSql()
        {}

protected:
    //! Transmet une valeur à la requète.
    void bindValue(int n, const QVariant & value)
        {m_requete->bindValue(n,value);}

    //! Exécute la dernière requète préparée et lance une execption si celle-ci n'est pas valide.
    void exec()
    {
        if(m_requete->exec())
        {
            affError();
        }
    }

    //! Exécute la requéte SQL donnée en argument et lance une execption si celle-ci n'est pas valide.
    void exec(const QString & requete)
    {
        if(m_requete->exec(requete))
        {
            affError();
        }
    }

    //! Exécute la dernière requète préparée et lance une execption si celle-ci n'est pas valide.
    void execFinish()
    {
        if(m_requete->exec())
        {
            affError();
        }
        finish();
    }

    //! Exécute la requéte SQL donnée en argument et lance une execption si celle-ci n'est pas valide.
    void execFinish(const QString & requete)
    {
        if(m_requete->exec(requete))
        {
            affError();
        }
        finish();
    }

    //! Termine la requète.
    void finish()
        {m_requete->finish();}

    //! Place la requète sur la position suivante.
    bool next()
        {return m_requete->next();}

    //! Prepare la requète SQL.
    void prepare(const QString & sql)
        {m_requete->prepare(sql);}

    //! Convertit la nième valeur de la requète en un entier.
    int toBool(int n = 0) const
        {return m_requete->value(n).toBool();}

    //! Convertit la nième valeur de la requète en un QDate.
    QDate toDate(int n = 0) const
        {return m_requete->value(n).toDate();}

    //! Convertit la nième valeur de la requète en un QDateTime.
    QDateTime toDateTime(int n = 0) const
        {return m_requete->value(n).toDateTime();}

    //! Convertit la nième valeur de la requète en un entier.
    int toInt(int n = 0) const
        {return m_requete->value(n).toInt();}

    //! Convertit la nième valeur de la requète en un QString.
    QString toString(int n = 0) const
        {return m_requete->value(n).toString();}

    //! Récupère la nième valeur de la requète.
    QVariant toVariant(int n = 0) const
        {return m_requete->value(n);}

    //! Convertit un entier en QVariant, en remplaçant 0 par QVariant(QVariant::Int).
    QVariant zeroToNull(int n) const
        {return n != 0 ? n : QVariant(QVariant::Int);}
};

#endif // REQSQL_H
