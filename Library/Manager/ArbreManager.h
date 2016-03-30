/*Auteur: PERCIE DU SERT Maxime
 *Date: 16/03/2016
 */
#ifndef ARBREMANAGER_H
#define ARBREMANAGER_H

#include "AttributsLinkSql.h"
#include "LinkSqlDivers.h"
#include "LinkSqlUnique.h"
#include "ManagerSql.h"

// Définition des attributs d'un arbre.
ATTRIBUT_LINK(Feuille,feuille,Bool,bool)
ATTRIBUT_LINK(Niveau,niveau,Int,int)
ATTRIBUT_LINK_NULL_TO_ZERO(Parent,parent,Int,int)

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des lien entre les entités de type arbre de programation et leurs représentations en base de donnée.
 */
template <class Ent, class Info> class ArbreLinkSql : public LinkSqlUniqueSimple<NumLinkSql<Ent,Info> >,
                                                        public FeuilleAttributSql<Ent>,
                                                        public NiveauAttributSql<Ent>,
                                                        public ParentAttributSqlNullToZero<Ent>
{
protected:
    using FeuilleAttributSql<Ent>::feuille;
    using FeuilleAttributSql<Ent>::setFeuille;
    using IdAttributSql<Ent>::id;
    using NiveauAttributSql<Ent>::niveau;
    using NiveauAttributSql<Ent>::setNiveau;
    using NumAttributSql<Ent>::num;
    using NumAttributSql<Ent>::setNum;
    using ParentAttributSqlNullToZero<Ent>::parent;
    using ParentAttributSqlNullToZero<Ent>::setParent;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    ArbreLinkSql(QSqlQuery & requete)
        : ReqSql(requete)
    {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        LinkSqlUniqueSimple<NumLinkSql<Ent,Info> >::bindValues(entity);
        setFeuille(entity);
        setNiveau(entity);
        setParent(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        LinkSqlUniqueSimple<NumLinkSql<Ent,Info> >::fromRequete(entity);
        entity.setFeuille(feuille());
        entity.setNiveau(niveau());
        entity.setNum(num());
        entity.setParent(parent());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(feuille(),
                     niveau(),
                     num(),
                     parent(),
                     id());
    }

protected:
    //! Construteur.
    ArbreLinkSql()
    {}

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent & entity)
    {
        setNum(entity,Info::NumUnique);
        setParent(entity,Info::ParentUnique);
    }
};


/*! \ingroup groupeBaseManager
 * \brief Template des manageurs de type arbre.
 */
template<class Ent, class Info> class ArbreManager : public ManagerSql<ArbreLinkSql<Ent,Info> >
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    ArbreManager(QSqlQuery & req);
};

template<class Ent, class Info> ArbreManager<Ent,Info>::ArbreManager(QSqlQuery & req)
    : ManagerSql<ArbreLinkSql<Ent,Info> >(req)
{

}

#endif // ARBREMANAGER_H
