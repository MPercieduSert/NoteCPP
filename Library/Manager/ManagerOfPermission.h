/*Auteur: PERCIE DU SERT Maxime
 *Date: 10/09/2017
 */
#ifndef MANAGEROFPERMISSION_H
#define MANAGEROFPERMISSION_H

#include "ManagerSql.h"

// Macro pour manageur.
//! \ingroup groupeBaseManager
//! Coprs des deux methodes add.
#define ADD_PERMISSION if(entity.num() != NoExists) addParent(entity);

/*! \ingroup groupeBaseManager
 * \brief Classe template mère des différents manageurs de permissions.
 */
template<class Ent, class Unique> class ManagerOfPermission : virtual public ManagerSql<Ent,Unique>
{
public:
    enum {NoExists = 0};

protected:
    using ManagerSqlEnt = ManagerSql<Ent,Unique>;
    using ManagerSqlEnt::del;
public:
    using ManagerSqlEnt::exists;
    using ManagerSqlEnt::get;

    //! Constructeur
    ManagerOfPermission (const QString & table, const QMap<int,QString> & att, const QVector<QMap<int,int>> & attUnique)
        : ManagerSql<Ent,Unique>(table, att, attUnique)
    {}

    //! Teste s'il y a dans la base de donnée une entité ayant exactement les mêmes attributs (identifiant compris).
    bool sameInBdd(const Ent & entity)
    {
        if(entity.num() == NoExists)
            return !exists(entity);
        else
        {
            Ent entityT(entity.id());
            return get(entityT) ? entityT == entity : false;
        }
    }

    //! Teste s'il y a dans la base de donnée une entité d'identifiant id ayant exactement les mêmes attributs.
    bool sameInBdd(const Ent & entity, int id)
    {
        if(entity.num() == NoExists)
            return !exists(Ent(id));
        else
        {
            Ent entityT(id);
            if(!get(entity))
                return false;
            entityT.setId(entity.id());
            return entityT == entity;
        }
    }

protected:
    //! Constructeur.
    ManagerOfPermission() = default;

    //! Insert la nouvelle entité entity dans la base de donnée
    //! et assigne l'identifiant de l'entité insérée en base de donnée à entity.
    void add(Ent & entity)
        {ADD_PERMISSION}

    //! Insert la nouvelle entité entity dans la base de donnée.
    void add(const Ent & entity)
        {ADD_PERMISSION}

    //! Appelle la fonction d'insertion parent souhaitée.
    virtual void addParent(Ent & entity)
        {ManagerSqlEnt::add(entity);}

    //! Appelle la fonction d'insertion parent souhaitée.
    virtual void addParent(const Ent & entity)
        {ManagerSqlEnt::add(entity);}

    //! Met à jour l'entité entity en base de donnée.
    void modify(const Ent & entity)
    {
        if(entity.num() != NoExists)
            modifyParent(entity);
        else
            del(entity.id());
    }

    //! Met à jour l'entité entity en base de donnée d'identifiant id avec les valeurs d'entity.
    void modify(const Ent & entity, int id)
    {
        if(entity.num() != NoExists)
            modifyParent(entity, id);
        else
            del(id);
    }

    //! Appelle la fonction de modification parent souhaitée.
    virtual void modifyParent(const Ent & entity)
        {ManagerSqlEnt::modify(entity);}

    //! Appelle la fonction de modification parent souhaitée.
    virtual void modifyParent(const Ent & entity, int id)
        {ManagerSqlEnt::modify(entity,id);}
};

#endif // MANAGEROFPERMISSION_H
