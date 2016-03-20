/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/02/2016
 */

/*! \defgroup groupeManager Manageurs
 * \brief Ensemble de classes représentant les Managers des entitées de la base de donnée.
 */

#ifndef MANAGER_H
#define MANAGER_H

#include <QSqlError>

#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include "../Entities/Entity.h"
#include "../Entities/ListEntities.h"

// Macro pour manageur..

//! \ingroup groupeManager
//! Coprs des deux methodes save.
#define SAVE if(entity.isValid()) \
{if(entity.isNew()) \
    {if(existsUnique(entity) == Aucun) \
        {add(entity);} \
     else \
        {throw std::invalid_argument(messageErreursUnique(entity).toStdString());}} \
else \
    {if(!sameInBdd(entity)) \
        {if(existsUnique(entity) <= Meme) \
            {modify(entity);} \
        else \
            {throw std::invalid_argument(messageErreursUnique(entity).toStdString());}}}} \
else \
    {throw std::invalid_argument(messageErreurs(entity).toStdString());}

/*! \ingroup groupeManager
 * \brief Classe abstraite de base des manageurs.
 *
 * Classe abstraite de base des manageurs.
 * Un Manageur est un gestionnaire associé à un type d'entitée,
 * permettant de faire le lien entre ce type d'entitée et la table correspondante en base donnée.
 * Cette classe joue le rôle d'interface pour les différents manageurs.
 */

class Manager
{
public:
    //! Les différents cas des résultats des tests d'existence d'unicité.
    enum ExisteUni {Aucun = 0,  //!< Aucun des ensembles d'unicité n'existent en base de donnée.
                    Tous = 1,   //!< Tous les ensembles d'unicité existent en base de donnée et concordent.
                    Meme = 2,  //!< Certains des ensembles d'unicité existent en base de donnée dans la même entitée avec le même identifiant.
                    Autre = 3,  //!< Certains des ensembles d'unicité existent en base de donnée dans la même entitée avec un autre identifiant.
                    Conflit = 4//!< Certains des ensembles d'unicité existent en base de donnée dans des entitées.
                    };

    //! Constructeur vide.
    Manager()  {}

    //! Destructeur.
    ~Manager() {}

    //! Crée dans la base de donnée la table associée l'entitée du manageur.
    virtual void creer() = 0;

    //! Supprime de la table en base de donnée l'entitée entity.
    virtual void del(Entity & entity)
    {
        del(entity.id());
        entity.setId(0);
    }

    //! Supprime de la table en base de donnée l'entitée entity.
    virtual void del(const Entity & entity)
        {del(entity.id());}

    //! Teste s'il existe une entitée de même identifiant que entity en base de donnée.
    virtual bool exists(const Entity & entity) = 0;

    //! Teste s'il existe une entitée ayant les mêmes valeurs d'attributs uniques que l'entitée entity en base de donnée.
    //! Si le test est positif, l'identitfiant de l'entitée entity est remplacé par celui l'entitée en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    virtual Manager::ExisteUni existsUnique(Entity & entity) = 0;

    //! Teste s'il existe une entitée ayant les mêmes valeurs d'attributs uniques que l'entitée entity en base de donnée.
    virtual Manager::ExisteUni existsUnique(const Entity & entity) = 0;

    //! Hydrate l'entitée entity avec les valeurs des attributs de l'entitée enregistrée en base de donnée
    //! ayant le même identifiant que entity.
    //! Retourne True si l'opération s'est correctement déroulée.
    virtual bool get(Entity & entity) = 0;

    //! Renvoie la liste des entitées de la table ordonnée suivant la colonne d'identifiant ordre.
    virtual ListEntities<Entity> getList(int ordre) = 0;

    //! Renvoie la liste des entitées de la table vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant la colonne d'identifiant ordre.
    virtual ListEntities<Entity> getList(int cle, const QVariant & value, int ordre) = 0;

    //! Renvoie la liste des entitées de la table vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant les colonnes d'identifiant ordre1 puis ordre2.
    virtual ListEntities<Entity> getList(int cle, const QVariant & value, int ordre1, int ordre2) = 0;

    //! Renvoie la liste des entitées de la table vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1 et valeur de la colonne d'identifiant cle2 = value2,
    //! ordonnée suivant la colonne d'identifiant ordre.
    virtual ListEntities<Entity> getList(int cle1, int cle2, const QVariant & value1, const QVariant & value2, int ordre) = 0;

    //! Hydrate l'entitée entity avec les valeurs des attributs de l'entitée enregistrée en base de donnée
    //! ayant les mêmes valeurs pour les attributs uniques.
    //! Retourne True si l'opération s'est correctement déroulée.
    bool getUnique(Entity & entity)
    {
        if(existsUnique(entity) == Manager::Tous)
        {
            return get(entity);
        }
        else
        {
            return false;
        }
    }

    //! Teste s'il y a dans la base de donnée une entitée ayant exactement les mêmes valeurs d'attributs (identifiant compris).
    virtual bool sameInBdd(const Entity & entity) = 0;

    //! Enregistre l'entitée entity en base de donnée et assigne l'identifiant de l'entitée insérée en base de donnée à entity.
    virtual void save(Entity & entity)
    {
        SAVE
    }

    //! Enregistre l'entitée entity en base de donnée.
    virtual void save(const Entity & entity)
    {
        SAVE
    }

protected:
    //! Insert la nouvelle entitée entity dans la base de donnée
    //! et assigne l'identifiant de l'entitée insérée en base de donnée à entity.
    virtual void add(Entity & entity) = 0;

    //! Insert la nouvelle entitée entity dans la base de donnée.
    virtual void add(const Entity & entity) = 0;

    //! Supprime de la table en base de donnée l'entitée d'identifiant id.
    virtual void del(int id) = 0;

    //! Message d'erreurs si l'entitée entity n'est pas valide.
    virtual QString messageErreurs(const Entity & entity) const = 0;

    //! Message d'erreurs s'il existe déjà en base de donnée une entitée ayant les mêmes valeurs d'attributs uniques que entity.
    virtual QString messageErreursUnique(const Entity & entity) const = 0;

    //! Met à jour l'entitée entity en base de donnée.
    virtual void modify(const Entity & entity) = 0;
};

#endif // MANAGER_H
