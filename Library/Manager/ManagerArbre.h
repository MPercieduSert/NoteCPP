/*Auteur: PERCIE DU SERT Maxime
 *Date: 16/09/2016
 */
#ifndef MANAGERARBRE_H
#define MANAGERARBRE_H

#include "InfoBddBase.h"
#include "ManagerSql.h"
#include "UniqueSqlBase.h"
#include "../Entities/Arbre.h"
#include <cstdlib>

//! \ingroup groupeBaseManager
//! Coprs des deux methodes save pour les arbres.
#define SAVE_ARBRE if(node.isValid()) \
    {if(node.isNew()) add(node); \
    else \
        {if(!sameInBdd(node)) modify(node);}} \
else \
    throw std::invalid_argument(messageErreurs(node).append("\n Erreur de validité").toStdString());

//! \ingroup groupeBaseManager
//! Coprs des deux methodes saveStUnstable pour les arbres.
#define SAVESTUNSTABLE_ARBRE if(node.isValid()) \
    {if(node.isNew()) addUnstable(node); \
    else \
        {if(!sameInBdd(node)) modifyStableUnstable(node);}} \
else \
    throw std::invalid_argument(messageErreurs(node).append("\n Erreur de validité").toStdString());

//! \ingroup groupeBaseManager
//! Coprs des deux methodes saveUnstable pour les arbres.
#define SAVEUNSTABLE_ARBRE if(node.isValid()) \
    {if(node.isNew()) addUnstable(node); \
    else \
        {if(!sameInBdd(node)) modifyUnstable(node);}} \
else \
    throw std::invalid_argument(messageErreurs(node).append("\n Erreur de validité").toStdString());

/*! \ingroup groupeBaseManager
 * \brief Classe des manageurs pour les entités de type arbre.
 */
class ManagerArbre : public ManagerSql<Arbre,ArbreUniqueSql<Arbre>>
{
protected:
    typedef ManagerSql<Arbre,ArbreUniqueSql<Arbre>> ManagerSqlArbre;
    QString m_sqlGetParent;

public:
    using ManagerSqlArbre::save;
    using ManagerSqlArbre::sameInBdd;

    //! Constructeur.
    ManagerArbre(const QString & table, const QMap<int,QString> & att, const QVector<QMap<int,int>> & attUnique);

    //! Destructeur.
    ~ManagerArbre()  {}

    //! Teste si le noeud d'identifiant idNode est un descendant du noeud d'identifiant idAncestry.
    bool areRelated(int idNode, int idAncestry)
    {
        while(idNode != 0 && idNode != idAncestry)
            idNode = getParent(idNode);
        return idNode != 0;
    }

    //! Crée dans la base de donnée la table associée à l'entité du manageur.
    void creer()
    {
        QMap<int,QString> key;
        key.insert(Arbre::Parent,table());
        creerSql(ArbreInfoBdd<Arbre>::creerAttribut(),ArbreInfoBdd<Arbre>::attributUnique(),key);
    }

    //! Supprime de la base de donnée le noeud node ainsi que tous ses déscendants (opération stable).
    void del(const Arbre & node);

    //! Returne l'identifiant du parent du noeud d'identifiant id.
    int getParent(int id)
    {
        prepare(m_sqlGetParent);
        bindValue(0,id);
        exec();
        if(next())
            return value<int>();
        else
            return -1;
    }

    //! Teste s'il y a dans la base de donnée un noeud ayant exactement les mêmes attributs id, num et parent.
    bool sameInBdd(const Arbre & node)
    {
        Arbre nodeBdd(node.id());
        if(get(nodeBdd))
            return nodeBdd.num() == node.num() && nodeBdd.parent() == node.parent();
        else
            return false;
    }

    //! Réimplémentation des la méthode save.
    void save(Arbre & node)
        {SAVE_ARBRE}

    //! Réimplémentation des la méthode save.
    void save(const Arbre & node)
        {SAVE_ARBRE}

    //! Réimplémentation des la méthode save.
    void saveStUnstable(Arbre & node)
        {SAVESTUNSTABLE_ARBRE}

    //! Réimplémentation des la méthode save.
    void saveStUnstable(const Arbre & node)
        {SAVESTUNSTABLE_ARBRE}

    //! Réimplémentation des la méthode save.
    void saveUnstable(Arbre & node)
        {SAVEUNSTABLE_ARBRE}

    //! Réimplémentation des la méthode save.
    void saveUnstable(const Arbre & node)
        {SAVEUNSTABLE_ARBRE}

protected:
    //! Réimplémentation de la méthode add(opération stable).
    void add(Arbre & node);

    //! Réimplémentation de la méthode add(opération stable).
    void add(const Arbre & node);

    //! Réimplémentation de la méthode add.
    void addUnstable(Arbre & node);

    //! Réimplémentation de la méthode add.
    void addUnstable(const Arbre & node);

    //! Supprime de la base de donnée le noeud d'identifiant id ainsi que tous ses déscendants (opération stable).
    void del(int id);

    //! Supprime de la base de donnée le noeud node ainsi que tous ses déscendants.
    void delUnstable(const Arbre &node);

    //! Modifie en base de données le noeud de de couple (parent, num) identique à node en (parent,-num). Renvoie false si le noeud de couple (parent, num) correspond à node.
    bool deplace(const Arbre & node);

    //! Réimplémentation de la méthode modify.
    void modify(const Arbre & node);

    //! Réimplémentation de la méthode modify.
    void modifyUnstable(const Arbre & node);

    //! Réimplémentation de la méthode modify.
    void modifyStableUnstable(const Arbre & node);
};



#endif // MANAGERARBRE_H
