/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/02/2016
 */
#ifndef MANAGER_H
#define MANAGER_H

/*! \defgroup groupeManager Manageurs
 * \brief Ensemble de classes représentant les managers des entités de la base de donnée.
 */

/*! \defgroup groupeBaseManager Classe de bases des manageurs
 * \ingroup groupeManager
 * \brief Ensemble de classes de base des manageurs.
 */

#include <QSqlError>

#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include "../Entities/Entity.h"
#include "../Div/ListPtr.h"

/*! \ingroup groupeBaseManager
 * \brief Espace de nom pour la base de donnée.
 */
namespace bdd {
    //! Identifiant pour les fonctions d'agrega.
    enum Agrega {Max,
                Min,
                Moyenne,
                Nombre,
                Somme,
                NbrAgrega};

    //! Les différents types de conditions
    enum Condition {Egal,
                   Inf,
                   Sup,
                   InfEgal,
                   SupEgal,
                   Different};

    //! Les différents cas des résultats des tests d'existence d'unicité.
    enum ExisteUni {Aucun = 0,  //!< Aucun des ensembles d'unicité n'existent en base de donnée.
                Tous = 1,   //!< Tous les ensembles d'unicité existent en base de donnée et concordent.
                Meme = 2,   //!< Certains des ensembles d'unicité existent en base de donnée dans la même entité avec le même identifiant.
                Autre = 3,  //!< Certains des ensembles d'unicité existent en base de donnée dans la même entité avec un autre identifiant.
                Conflit = 4 //!< Certains des ensembles d'unicité existent en base de donnée dans des entités différentes.
                };
};

/*! \ingroup groupeBaseManager
 * \brief Classe abstraite de base des manageurs.
 *
 * Classe abstraite de base des manageurs.
 * Un manageur est un gestionnaire associé à un type d'entité,
 * permettant de faire le lien entre ce type d'entité et la table correspondante en base donnée.
 * Cette classe joue le rôle d'interface pour les différents manageurs.
 */
class Manager
{
public:   
    //! Constructeur vide.
    Manager()  {}

    //! Destructeur.
    ~Manager() {}

    //! Crée dans la base de donnée la table associée à l'entité du manageur.
    virtual void creer() = 0;

    //! Supprime de la table en base de donnée l'entité entity.
    virtual void del(Entity & entity)
    {
        del(entity.id());
        entity.setId(0);
    }

    //! Supprime de la table en base de donnée l'entité entity.
    virtual void del(const Entity & entity)
        {del(entity.id());}

    //! Teste s'il existe une entité de même identifiant que entity en base de donnée.
    virtual bool exists(const Entity & entity) = 0;

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui de l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    virtual bdd::ExisteUni existsUnique(Entity & entity) = 0;

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée.
    virtual bdd::ExisteUni existsUnique(const Entity & entity) = 0;

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrée en base de donnée
    //! ayant le même identifiant que entity.
    //! Retourne True si l'opération s'est correctement déroulée.
    virtual bool get(Entity & entity) = 0;

    /*//! Renvoie la liste des entités de la table ordonnée suivant la colonne d'identifiant ordre.
    virtual ListPtr<Entity> getList(int ordre) = 0;

    //! Renvoie la liste des entités de la table vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant la colonne d'identifiant ordre.
    virtual ListPtr<Entity> getList(int cle, const QVariant & value, int ordre) = 0;

    //! Renvoie la liste des entités de la table vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant les colonnes d'identifiant ordre1 puis ordre2.
    virtual ListPtr<Entity> getList(int cle, const QVariant & value, int ordre1, int ordre2) = 0;

    //! Renvoie la liste des entités de la table vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1 et valeur de la colonne d'identifiant cle2 = value2,
    //! ordonnée suivant la colonne d'identifiant ordre.
    virtual ListPtr<Entity> getList(int cle1, int cle2, const QVariant & value1, const QVariant & value2, int ordre) = 0;*/

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrée en base de donnée
    //! ayant les mêmes valeurs pour les attributs uniques.
    //! Retourne True si l'opération s'est correctement déroulée.
    virtual bool getUnique(Entity & entity) = 0;

    //! Teste s'il y a dans la base de donnée une entité ayant exactement les mêmes valeurs d'attributs (identifiant compris).
    virtual bool sameInBdd(const Entity & entity) = 0;

    //! Enregistre l'entité entity en base de donnée et assigne l'identifiant de l'entité insérée en base de donnée à entity.
    virtual void save(Entity & entity) = 0;

    //! Enregistre l'entité entity en base de donnée.
    virtual void save(const Entity & entity) = 0;

protected:
    //! Supprime de la table en base de donnée l'entité d'identifiant id.
    virtual void del(int id) = 0;

    //! Message d'erreurs si l'entité entity n'est pas valide.
    virtual QString messageErreurs(const Entity & entity) const = 0;

    //! Message d'erreurs s'il existe déjà en base de donnée une entité ayant les mêmes valeurs d'attributs uniques que entity.
    virtual QString messageErreursUnique(const Entity & entity) const = 0;
};

#endif // MANAGER_H
