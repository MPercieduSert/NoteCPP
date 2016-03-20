/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */

/*! \defgroup groupeLinkSql Liens
 * \ingroup groupeManager
 * \brief Ensemble des liens entre les entitées de programation et les entitées en base de donnée.
 */

#ifndef LINKSQL_H
#define LINKSQL_H

#include <array>
#include <initializer_list>
#include <QSqlQuery>
#include "Manager.h"
#include "../Entities/Entity.h"
#include "../Entities/Annee.h"
#include "../Entities/Arbre.h"
#include "../Entities/Classe.h"
#include "../Entities/Donnee.h"
#include "../Entities/Eleve.h"
#include "../Entities/Etablissement.h"
#include "../Entities/Exercice.h"
#include "../Entities/Niveau.h"
#include "../Entities/TypeNiveau.h"

/*! \ingroup groupeLinkSql
 * \brief Macro rappelant les attributs de LinkSql dans les classes patrons.
 */
#define USING_LINKSQL(T) public : \
    using LinkSql<T>::NbrAtt; \
    using LinkSql<T>::Att; \
    using LinkSql<T>::Table; \
protected: \
    using LinkSql<T>::m_requete; \
    using LinkSql<T>::exec;


/*! \ingroup groupeLinkSql
 * \brief Classe mère des liens entre les entitées de programation et les entitées en base de donnée.
 */

template<class T> class LinkSql
{
public:
    static const int NbrAtt; //!< Nombre d'attributs dans la table en base de donnée.
    static const std::array<const char*, NbrAtt> Att; //!< Tableau des attributs de l'entitée en base de donnée.
    static const char Table[];    //!< Nom de la table de l'entitée en base de donnée.

protected:
    QSqlQuery & m_requete;  //!< Référence vers la requète employée dans le manageur.

public:
    typedef T Ent;
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur,
    //! le nom de la table associée à l'entitée dans la base de donnée et la liste des noms des colonnes.
    LinkSql(QSqlQuery & requete);

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    virtual void bindValues(const T & entity) = 0;

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    virtual void creer() = 0;

    //! Hydrate l'entitée entity avec à partir de la requète.
    virtual void fromRequete(T & entity) = 0;

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    virtual T * newFromRequete() = 0;

    //! Teste s'il existe une entitée ayant les mêmes valeurs d'attributs uniques que l'entitée entity en base de donnée.
    //! Si le test est positif, l'identitfiant de l'entitée entity est remplacé par celui l'entitée en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    virtual Manager::ExisteUni existsUnique(T & entity) = 0;

    //! Teste s'il existe une entitée ayant les mêmes valeurs d'attributs uniques que l'entitée entity en base de donnée.
    virtual Manager::ExisteUni existsUnique(const T & entity) = 0;

protected:
    //! Lance une execption contenant le message d'erreur de la derniere requète SQL exéctuter.
    void affError() const;

    //! Exécute la dernière requète préparée et lance une execption si celle-ci n'est pas valide.
    void exec()
    {
        if(m_requete.exec())
        {
            affError();
        }
    }

    //! Exécute la requéte SQL donnée en argument et lance une execption si celle-ci n'est pas valide.
    void exec(const QString & requete)
    {
        if(m_requete.exec(requete))
        {
            affError();
        }
    }

    //! Convertit un entier en QVariant, en remplaçant 0 par QVariant(QVariant::String).
    QVariant zeroToNull(int n) const
    {
        return n != 0 ? n : QVariant(QVariant::Int);
    }
};

template<class T> const int LinkSql<T>::NbrAtt = T::NbrAtt;

template<class T> LinkSql<T>::LinkSql(QSqlQuery & requete)
    : m_requete(requete)
    {}

template<class T> void LinkSql<T>::affError() const
{
    QSqlError err(m_requete.lastError());
    throw std::invalid_argument(err.text().append("\n"+err.nativeErrorCode()+"\n"+m_requete.lastQuery()).toStdString());
}

#endif // LINKSQL_H
