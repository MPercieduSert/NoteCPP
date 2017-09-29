/*Auteur: PERCIE DU SERT Maxime
 *Date: 08/09/2017
 */
#ifndef MANAGEROFMODIFCONTROLEPERMISSION_H
#define MANAGEROFMODIFCONTROLEPERMISSION_H

#include "ManagerOfModifControle.h"
#include "ManagerOfPermission.h"

/*! \ingroup groupeBaseManager
 * \brief Classe template mère des différents manageurs à modification controlée de permission.
 */
template<class Ent, class Unique> class ManagerOfModifControlePermission : public ManagerOfPermission<Ent,Unique>,
                                                                           public ManagerOfModifControle<Ent,Unique>
{
protected:
    using ManagerPermission = ManagerOfPermission<Ent,Unique>;
    using ManagerMC = ManagerOfModifControle<Ent,Unique>;

    using ManagerPermission::add;

public:
    using ManagerPermission::sameInBdd;
    using ManagerMC::del;

    //! Constructeur
    ManagerOfModifControlePermission (const QString & table, const QMap<int,QString> & att, const QVector<QMap<int,int>> & attUnique)
        : ManagerSql<Ent,Unique>(table, att, attUnique)
    {}

protected:
    //! Constructeur.
    ManagerOfModifControlePermission() = default;

    //! Appelle la fonction d'insertion parent souhaitée.
    void addParent(Ent & entity)
        {ManagerMC::add(entity);}

    //! Appelle la fonction d'insertion parent souhaitée.
    void addParent(const Ent & entity)
        {ManagerMC::add(entity);}

    //! Supprime de la table en base de donnée l'entité d'identifiant id.
    bool del(int id)
        {return ManagerMC::del(id);}

    //! Réimplemente modify.
    void modify(const Ent & entity)
        {ManagerPermission::modify(entity);}

    //! Réimplemente modify.
    void modify(const Ent & entity, int id)
        {ManagerPermission::modify(entity,id);}

    //! Appelle la fonction de modification parent souhaitée.
    void modifyParent(const Ent & entity)
        {ManagerMC::modify(entity);}

    //! Appelle la fonction de modification parent souhaitée.
    void modifyParent(const Ent & entity, int id)
        {ManagerMC::modify(entity,id);}
};

#endif // MANAGEROFMODIFCONTROLEPERMISSION_H
