/*Auteur: PERCIE DU SERT Maxime
 *Date: 14/08/2017
 */
#ifndef MANAGEROFARBRESIMPLEMODIFCONTROLE_H
#define MANAGEROFARBRESIMPLEMODIFCONTROLE_H

#include "ManagerOfModifControle.h"
#include "ManagerOfArbreSimple.h"

/*! \ingroup groupeBaseManager
 * \brief Classe template mère des différents manageurs pour les entités de type arbre simple avec un controle de modification.
 */
template<class Ent, class Unique> class ManagerOfArbreSimpleModifControle : public ManagerOfArbreSimple<Ent,Unique>,
                                                                      public ManagerOfModifControle<Ent,Unique>
{
protected:
    using ManagerArbreEnt = ManagerOfArbreSimple<Ent,Unique>;
    using ManagerMC = ManagerOfModifControle<Ent,Unique>;

    using ManagerMC::modify;

public:
    using ManagerArbreEnt::get;
    using ManagerMC::save;
    using ManagerMC::getAutorisation;

    //! Constructeur.
    ManagerOfArbreSimpleModifControle(const QString & table, const QMap<int,QString> & att, const QVector<QMap<int,int>> & attUnique);

    //! Enregistre l'entité entity en base de donnée.
    void save(Ent & entity)
        {ManagerArbreEnt::save(entity);}

    //! Enregistre l'entité entity en base de donnée.
    void save(const Ent & entity)
        {ManagerArbreEnt::save(entity);}

protected:
    //! Constructeur.
    ManagerOfArbreSimpleModifControle() = default;

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

template<class Ent, class Unique> ManagerOfArbreSimpleModifControle<Ent,Unique>::ManagerOfArbreSimpleModifControle(const QString & table,
                                                                                              const QMap<int,QString> & att,
                                                                                              const QVector<QMap<int,int>> & attUnique)
    : ManagerSql<Ent,Unique>(table,att,attUnique)
{}


#endif // MANAGEROFARBRESIMPLEMODIFCONTROLE_H
