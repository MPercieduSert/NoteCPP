/*Auteur: PERCIE DU SERT Maxime
 *Date: 14/08/2017
 */
#ifndef MANAGEROFARBREMODIFCONTROLE_H
#define MANAGEROFARBREMODIFCONTROLE_H

#include "ManagerOfModifControle.h"
#include "ManagerOfArbre.h"

/*! \ingroup groupeBaseManager
 * \brief Classe template mère des différents manageurs pour les entités de type arbre avec un controle de modification.
 */
template<class Ent, class Unique> class ManagerOfArbreModifControle : public ManagerOfArbre<Ent,Unique>,
                                                                      public ManagerOfModifControle<Ent,Unique>
{
protected:
    using ManagerArbreEnt = ManagerOfArbre<Ent,Unique>;
    using ManagerMC = ManagerOfModifControle<Ent,Unique>;

    using ManagerArbreEnt::add;
    using ManagerMC::fermer;
    using ManagerMC::modify;
    using ManagerMC::ouvrir;

public:
    using ManagerArbreEnt::save;
    using ManagerArbreEnt::get;
    using ManagerMC::getAutorisation;
    using ManagerMC::getRestriction;
    using ManagerMC::setAutorisation;
    using ManagerMC::setRestriction;

    //! Constructeur.
    ManagerOfArbreModifControle(const QString & table, const QMap<int,QString> & att, const QVector<QMap<int,int>> & attUnique,const QString & tableArbre,const QMap<int,QString> & attArbre = ArbreInfoBdd<Arbre>::attribut());

    //! Enregistre l'entité entity en base de donnée ainsi que sa nouvelle autorisation de modification.
    void save(Ent & entity, bdd::Autorisation autorisation, bool bb = false)
        {ManagerMC::save(entity, autorisation, bb);}

    //! Enregistre l'entité entity en base de donnée ainsi que sa nouvelle autorisation de modification..
    void save(const Ent & entity, bdd::Autorisation autorisation, bool bb)
    {
        ouvrir();
        save(entity);
        fermer();
        setAutorisation(entity, autorisation, bb);
    }

    //! Enregistre l'entité entity en base de donnée ainsi que ses nouvelles autorisations de modification.
    void save(Ent & entity, const QMap<bdd::Autorisation,bool> & autorisations)
        {ManagerMC::save(entity, autorisations);}

    //! Enregistre l'entité entity en base de donnée ainsi que ses nouvelles autorisation de modification..
    void save(const Ent & entity, const QMap<bdd::Autorisation,bool> & autorisations)
    {
        ouvrir();
        save(entity);
        fermer();
        setAutorisation(entity, autorisations);
    }

    //! Enregistre l'entité entity en base de donnée ainsi que ses nouvelles restriction de modification.
    void save(Ent & entity, const QList<bdd::Autorisation> restriction)
    {
        ouvrir();
        save(entity);
        fermer();
        setRestriction(entity, restriction);
    }

    //! Enregistre l'entité entity en base de donnée ainsi que ses nouvelles restrictions de modification..
    void save(const Ent & entity, const QList<bdd::Autorisation> restriction)
    {
        ouvrir();
        save(entity);
        fermer();
        setRestriction(entity, restriction);
    }

protected:
    //! Constructeur.
    ManagerOfArbreModifControle(const QString & tableArbre,const QMap<int,QString> & attArbre = ArbreInfoBdd<Arbre>::attribut());

    //! Supprime de la table en base de donnée l'entité d'identifiant id.
    void del(int id)
    {
        if(getAutorisation(Ent(id), bdd::Suppr))
            ManagerArbreEnt::del(id);
        else
        {
            Ent entity(id);
            get(entity);
            throw std::invalid_argument(QString("Erreur d'autorisation de modification' :  l'entité suivante n'est pas suprimable:\n").append(entity.affiche()).toStdString());
        }
    }
};

template<class Ent, class Unique> ManagerOfArbreModifControle<Ent,Unique>::ManagerOfArbreModifControle(const QString & table,
                                                                                              const QMap<int,QString> & att,
                                                                                              const QVector<QMap<int,int>> & attUnique,
                                                                                              const QString & tableArbre,
                                                                                              const QMap<int,QString> & attArbre)
    : ManagerSql<Ent,Unique>(table,att,attUnique), ManagerOfArbre<Ent,Unique>(tableArbre,attArbre)
{}

template<class Ent, class Unique> ManagerOfArbreModifControle<Ent,Unique>::ManagerOfArbreModifControle(const QString & tableArbre,
                                                                                          const QMap<int,QString> & attArbre)
    : ManagerOfArbre<Ent,Unique>(tableArbre,attArbre)
{}

#endif // MANAGEROFARBREMODIFCONTROLE_H
