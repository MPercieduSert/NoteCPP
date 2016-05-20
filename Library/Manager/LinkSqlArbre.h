/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/04/2016
 */
#ifndef LINKSQLARBRE_H
#define LINKSQLARBRE_H

#include "AttributsMacroLinkSql.h"
#include "LinkSqlDivers.h"

// Définition des attributs d'un arbre.
ATTRIBUT_LINK(Feuille,feuille,Bool,bool)
ATTRIBUT_LINK(Niveau,niveau,Int,int)
ATTRIBUT_LINK_NULL_TO_ZERO(Parent,parent,Int,int)

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des lien entre les entités de type arbre de programation et leurs représentations en base de donnée.
 */
template <class Ent> class ArbreLinkSql : public NumLinkSql<Ent>,
                                          public FeuilleAttributSql<Ent>,
                                          public NiveauAttributSql<Ent>,
                                          public ParentAttributSqlNullToZero<Ent>
{
protected:
    using FeuilleAttributSql<Ent>::feuille;
    using FeuilleAttributSql<Ent>::setFeuille;
    using NiveauAttributSql<Ent>::niveau;
    using NiveauAttributSql<Ent>::setNiveau;
    using ParentAttributSqlNullToZero<Ent>::parent;
    using ParentAttributSqlNullToZero<Ent>::setParent;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    ArbreLinkSql(QSqlQuery * requete)
        : ReqSql(requete)
    {}

    //! Destructeur.
    ~ArbreLinkSql()
    {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        NumLinkSql<Ent>::bindValues(entity);
        setFeuille(entity);
        setNiveau(entity);
        setParent(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        NumLinkSql<Ent>::fromRequete(entity);
        entity.setFeuille(feuille());
        entity.setNiveau(niveau());
        entity.setParent(parent());
    }

protected:
    //! Construteur protégé.
    ArbreLinkSql()
    {}
};

/*! \ingroup groupeLinkSqlBase
* \brief Classe mère des liens entre une entité ayant seulement l'attribut d'un arbre (feuille, niveau, num, parent et id).
*/
template<class Ent> class ArbreOnlyLinkSql : public ArbreLinkSql<Ent>
{
protected:
    using ArbreLinkSql<Ent>::id;
    using ArbreLinkSql<Ent>::feuille;
    using ArbreLinkSql<Ent>::niveau;
    using ArbreLinkSql<Ent>::num;
    using ArbreLinkSql<Ent>::parent;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    ArbreOnlyLinkSql(QSqlQuery * requete)
        : ArbreLinkSql<Ent>(requete)
    {}

    //! Destructeur.
    ~ArbreOnlyLinkSql()
        {}

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
};
#endif // LINKSQLARBRE_H
