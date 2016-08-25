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

namespace bdd {
    enum createSql{primary,
                   integer,
                   text,
                   blob,
                   real,
                   numeric,
                   notNull,
                   constraint,
                   unique,
                   foreign,
                   ref,
                   NbrType};

    enum wordSql{create};
}

/*! \ingroup groupeBaseManager
 * \brief Classe mère des liens contenant la référence sur l'objet de requète ouvert sur le base de donnée.
 */
class ReqSql
{
protected:
    static QSqlQuery * m_requete;  //!< Référence vers la requète employée dans le manageur.

public:
    //! Constructeur.
    ReqSql()
        {}

    //! Destructeur.
    ~ReqSql()
        {}

    //! Lance une execption contenant le message d'erreur de la derniere requète SQL exéctuter.
    void affError() const;

    //! Renvoie une QString correspondant au type.
    static QString createSqlString(bdd::createSql n);

    //! Modifie le pointeur vers l'objet requête.
    static void setRequete(QSqlQuery * req)
        {m_requete = req;}

    //! Renvoie une QString correspondant au type.
    static QString wordSqlString(bdd::wordSql n);

protected:
    //! Transmet une valeur à la requète.
    template<class T> void bindValue(int n, const T & value)
        {m_requete->bindValue(n,value);}

    //! Exécute la dernière requète préparée et lance une execption si celle-ci n'est pas valide.
    void exec()
    {
        m_requete->exec();
        affError();
    }

    //! Exécute la requéte SQL donnée en argument et lance une execption si celle-ci n'est pas valide.
    void exec(const QString & requete)
    {
        m_requete->exec(requete);
        affError();
    }

    //! Exécute la dernière requète préparée et lance une execption si celle-ci n'est pas valide.
    void execFinish()
    {
        exec();
        finish();
    }

    //! Exécute la requéte SQL donnée en argument et lance une execption si celle-ci n'est pas valide.
    void execFinish(const QString & requete)
    {
        exec(requete);
        finish();
    }

    //! Termine la requète.
    void finish()
        {m_requete->finish();}

    //! Place la requète sur la position suivante.
    bool next()
        {return m_requete->next();}

    //! Prepare la requète SQL.
    void prepare(const QString & requete)
        {m_requete->prepare(requete);}

    //! Récupère la nième valeur de la requète au type T.
    template<class T> T value(int n = 0) const
        {return m_requete->value(n).value<T>();}

    //! Convertit un entier en QVariant, en remplaçant 0 par QVariant(QVariant::Int).
    template<class T> QVariant zeroToNull(T n) const
        {return n != 0 ? n : QVariant(QVariant::Int);}
};

#endif // REQSQL_H
