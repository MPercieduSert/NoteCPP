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
#include <QSqlQuery>
#include "Manager.h"
#include "../Entities/Entity.h"

// Macro pour les link.

//! \ingroup groupeLinkBdd
//! Implémente le méthode existeUnique pour les référence.
#define UNIQUE(ENTITY) Manager::ExisteUni existsUnique(ENTITY & entity)\
{m_requete.prepare(m_unique);\
bindValuesUnique(entity);\
m_requete.exec();\
if(m_requete.next())\
    {entity.setId(m_requete.value(0).toInt());\
    m_requete.finish();\
    return Manager::Tous;}\
    else\
    {m_requete.finish();\
    return Manager::Aucun;}}

//! \ingroup groupeLinkBdd
//! Implémente le méthode existeUnique pour les références constante.
#define UNIQUE_CONST(ENTITY) Manager::ExisteUni existsUnique(const ENTITY & entity)\
{m_requete.prepare(m_unique);\
bindValuesUnique(entity);\
m_requete.exec();\
if(m_requete.next())\
    {m_requete.finish();\
    return Manager::Tous;}\
    else\
    {m_requete.finish();\
    return Manager::Aucun;}}

//! \ingroup groupeLinkBdd
//! Insère les deux méthodes existeUnique.
#define METHODE_UNIQUE(ENTITY) \
    /*! \brief Teste s'il existe une entitée ayant les mêmes valeurs d'attributs uniques que l'entitée entity en base de donnée. Si le test est positif, l'identitfiant de l'entitée entity est remplacé par celui l'entitée en base de donnée ayant les mêmes valeurs d'attributs uniques.*/ \
    UNIQUE(ENTITY) \
    /*! \brief Teste s'il existe une entitée ayant les mêmes valeurs d'attributs uniques que l'entitée entity en base de donnée. */ \
    UNIQUE_CONST(ENTITY)

/*! \ingroup groupeLinkSql
 * \brief Classe mère des liens entre les entitées de programation et les entitées en base de donnée.
 */

class LinkSql
{
public:
    static constexpr char Name[] = "LinkBdd";    //!< Nom de l'entitée en base de donnée.
    static constexpr std::array<const char*, Entity::NbrAtt> Att {{"ID"}};   //!< Tableau des attributs de l'entitée en base de donnée.
    //static const int NbrAtt = 1;                //!< Nombre d'attributs de l'entitée en en base de donnée.
    //static const int NbrEnsUni = 0;             //!< Nombre d'ensemble d'attributs uniques de l'entitée autre que l'identifiant.
    //static constexpr std::array<const char*, NbrEnsUni> EnsUni {{}}; //!< Tableau des chaines des ensembles d'attributs uniques de l'entitée.

protected:
    QSqlQuery & m_requete;  //!< Référence vers la requète employée dans le manageur.

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    LinkSql(QSqlQuery & requete): m_requete(requete)
        {}

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

    //! Convertit un QVariant en entier, en remplaçant 0 par QVariant(QVariant::String).

    //! Convertit un entier en QVariant, en remplaçant 0 par QVariant(QVariant::String).
    QVariant zeroToNull(int n) const
    {
        return n != 0 ? n : QVariant(QVariant::Int);
    }
};
/*  Methode à implémenter dans les classes filles.

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const T & entity)
    {

    }

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const T & entity)
    {

    }

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    bool creer();

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(T & entity)

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    T * newFromRequete()
    {

    }

protected:
    //! Ecrit la chaine pour initialiser m_unique.
    QString writeStringUnique() const;
*/
/*
    //! Teste s'il existe une entitée ayant les mêmes valeurs d'attributs uniques que l'entitée entity en base de donnée.
    //! Si le test est positif, l'identitfiant de l'entitée entity est remplacé par celui l'entitée en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    Manager::ExisteUni existsUnique(Entity & entity)
    {

    }

    //! Teste s'il existe une entitée ayant les mêmes valeurs d'attributs uniques que l'entitée entity en base de donnée.
    Manager::ExisteUni existsUnique(const Entity & entity)
    {

    }
*/
#endif // LINKSQL_H
