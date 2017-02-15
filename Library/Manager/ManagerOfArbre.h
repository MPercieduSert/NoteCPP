/*Auteur: PERCIE DU SERT Maxime
 *Date: 10/09/2016
 */
#ifndef MANAGEROFARBRE_H
#define MANAGEROFARBRE_H

#include "ManagerArbre.h"
#include "../Div/Tree.h"

//! \ingroup groupeBaseManager
//! Coprs des deux methodes save pour les arbres.
#define SAVE_MANAGER_OF_ARBRE if(entity.isValid()) \
    {if(entity.isNew()) \
        throw std::invalid_argument("Les nouvelles entités de type arbre ne peut être sauvé dans la base de données uniquement à travers un arbre."); \
    else \
        {if(exists(entity)) \
            {if(!sameInBdd(entity)) \
                {if(existsUnique(entity) <= bdd::Meme) modify(entity); \
                else \
                    throw std::invalid_argument(messageErreursUnique(entity).append("\n Erreur d'unicité :  il existe déjà dans la base de donnée une entité ayant les mêmes valeurs d'attributs unique que l'entité modifiée.").toStdString());}} \
        else \
            {if(existsUnique(entity) == bdd::Aucun) \
                add(entity); \
            else \
                throw std::invalid_argument(messageErreursUnique(entity).append("\n Erreur d'unicité : il existe déjà dans la base de donnée une entité ayant les mêmes valeurs d'attributs unique que cette nouvelle entité.").toStdString());}}} \
    else \
        throw std::invalid_argument(messageErreurs(entity).append("\n Erreur de validité").toStdString());

namespace bdd {
    //! Enumeration des différent type de sauvegarde d'un arbre.
    enum TreeSave {EntityOnly,
                   AddLeaf,
                   WithoutDelete,
                   InternalChange,
                   ExternalChange};

}

/*! \ingroup groupeBaseManager
 * \brief Classe template mère des différents manageurs pour les entités de type arbre.
 */
template<class Ent, class Link, class Unique> class ManagerOfArbre : public ManagerSql<Ent,Link,Unique>
{
protected:
    ManagerArbre m_managerArbre;

    typedef ManagerSql<Ent,Link,Unique> ManagerSqlEnt;

    using ManagerSqlEnt::m_link;
    using ManagerSqlEnt::m_sqlAdd;
    using ManagerSqlEnt::execFinish;

    using ManagerSqlEnt::prepare;
    using ManagerSqlEnt::messageErreurs;
    using ManagerSqlEnt::messageErreursUnique;
    using ManagerSqlEnt::modify;
    using ManagerSqlEnt::table;

public:
    using ManagerSqlEnt::attribut;
    using ManagerSqlEnt::existsUnique;
    using ManagerSqlEnt::exists;
    using ManagerSqlEnt::get;
    using ManagerSqlEnt::sameInBdd;
    using ManagerSqlEnt::save;

    //! Constructeur
    ManagerOfArbre(const QString & table, const QMap<int,QString> & att, const QVector<QMap<int,int>> & attUnique,const QString & tableArbre,const QMap<int,QString> & attArbre = ArbreInfoBdd::attribut());

    //! Creer la table.
    void creerSql(const QMap<int,QPair<bdd::createSql,bool>>& attCaract,
               const QVector<QMap<int,int>> & attUnique = QVector<QMap<int,int>>(),
               const QMap<int,QString> & foreignKey = QMap<int,QString>())
    {
        m_managerArbre.creer();
        ManagerSqlEnt::creerSql(attCaract,attUnique,foreignKey);
    }

    //! Renvoie l'arbre racine entity.
    Tree<Ent> getArbre(const Ent & entity)
    {
        Ent ent(entity.id());
        if(get(ent))
        {
            Tree<Ent> tree(ent);
            getArbreRec(tree.root());
            return tree;
        }
        else
            throw std::invalid_argument("L'entité transmise en argument de getArbre n'est pas valide.");
    }

    //! Renvoie l'arbre l'entity d'identifiant.
    Tree<Ent> getArbre(int id)
        {return getArbre(Ent(id));}

    //! Enregistre l'entité entity en base de donnée.
    void save(Ent & entity)
    {
        SAVE_MANAGER_OF_ARBRE
    }

    //! Enregistre l'entité entity en base de donnée.
    void save(const Ent & entity)
    {
        SAVE_MANAGER_OF_ARBRE
    }

    //! Enregistre l'arbre d'entités.
    void save(Tree<Ent> & tree, bdd::TreeSave n = bdd::TreeSave::ExternalChange);

protected:
    //! Insert la nouvelle entité entity dans la base de donnée.
    virtual void add(Ent & entity)
    {
        prepare(m_sqlAdd);
        m_link.bindValues(entity);
        m_link.setId(entity,m_link.nbrAtt()-1);
        execFinish();
    }

    //! Insert la nouvelle entité entity dans la base de donnée.
    virtual void add(const Ent & entity)
    {
        prepare(m_sqlAdd);
        m_link.bindValues(entity);
        m_link.setId(entity,m_link.nbrAtt()-1);
        execFinish();
    }

    //! Supprime de la table en base de donnée l'entité d'identifiant id.
    void del(int id)
    {
        ManagerSqlEnt::del(id);
        m_managerArbre.del(Arbre(id));
    }

    //! Supprime de la Base de données les noeuds hors de l'arbre.
    void deleteLeafOutOf(TreeItem<Ent> * tree);

    //! Permet de lire réccursivement un arbre.
    void getArbreRec(TreeItem<Ent> * tree);

    //! Sauve un arbre où le changement de structure consite seulement l'ajout de nouveaux noeuds.
    void saveAddLeaf(TreeItem<Ent> * tree);
    //! Sauve un arbre où le changement de structure consite en l'ajout de nouveaux noeuds, des permutations à l'interieur de l'arbre et le déplasement de noeuds extérieur à l'arbre.
    void saveExt(TreeItem<Ent> * tree, int idRoot);

    //! Sauve un arbre où le changement de structure consite seulement l'ajout de nouveaux noeuds et des permutations à l'interieur de l'arbre.
    void saveWithoutDelete(TreeItem<Ent> * tree);

    //! Réécrie la chaine de requète m_sqlAdd.
    void writeStringSql();
};

template<class Ent, class Link, class Unique> ManagerOfArbre<Ent,Link,Unique>::ManagerOfArbre(const QString & table,
                                                                                              const QMap<int,QString> & att,
                                                                                              const QVector<QMap<int,int>> & attUnique,
                                                                                              const QString & tableArbre,
                                                                                              const QMap<int,QString> & attArbre)
    : ManagerSqlEnt(table,att,attUnique),
      m_managerArbre(tableArbre,attArbre,ArbreInfoBdd::attributUnique())
    {writeStringSql();}

template<class Ent, class Link, class Unique> void ManagerOfArbre<Ent,Link,Unique>::deleteLeafOutOf(TreeItem<Ent> * tree)
{
    if(tree->hasChild())
    {
        ListPtr<Arbre> childs = m_managerArbre.getList(Arbre::Parent,tree->data().id(),Arbre::Num);
        for(ListPtr<Arbre>::iterator i = childs.begin(); i != childs.end(); ++i)
        {
            if((*i).num() < 0 || (*i).num() >= tree->childCount())
                del((*i).id());
        }
        for(typename QList<TreeItem<Ent>*>::const_iterator i = tree->childs().cbegin(); i != tree->childs().cend(); ++i)
            deleteLeafOutOf(*i);
    }
    else
    {
        ListPtr<Arbre> childs = m_managerArbre.getList(Arbre::Parent,tree->data().id());
        for(ListPtr<Arbre>::iterator i = childs.begin(); i != childs.end(); ++i)
            del((*i).id());
    }
}

template<class Ent, class Link, class Unique> void ManagerOfArbre<Ent,Link,Unique>::getArbreRec(TreeItem<Ent> * tree)
{
    ListPtr<Arbre> childs = m_managerArbre.getList(Arbre::Parent,tree->data().id(),Arbre::Num);
    for(ListPtr<Arbre>::iterator i = childs.begin(); i != childs.end(); ++i)
    {
        TreeItem<Ent> * child = tree->addChild(Ent((*i).id()));
        get(child->modifData());
        if(!(*i).feuille())
            getArbreRec(child);
    }
}

template<class Ent, class Link, class Unique> void ManagerOfArbre<Ent,Link,Unique>::save(Tree<Ent> & tree, bdd::TreeSave n)
{
    using namespace bdd;
    if(n == TreeSave::EntityOnly)
    {
        for(typename TreeItem<Ent>::iterator i = tree.begin(); i != tree.end(); ++i)
            save((*i)->data());
    }
    else
    {
        if(tree.root()->data().isNew())
        {
            Arbre node(0,0);
            m_managerArbre.save(node);
            tree.root()->modifData().setId(node.id());
        }
        save(tree.root()->data());
        switch (n) {
        case TreeSave::AddLeaf:
            saveAddLeaf(tree.root());
            break;

        case TreeSave::WithoutDelete:
            saveWithoutDelete(tree.root());
            break;

        case TreeSave::InternalChange:
            saveWithoutDelete(tree.root());
            deleteLeafOutOf(tree.root());
            break;

        case TreeSave::ExternalChange:
            saveExt(tree.root(),tree.root()->data().id());
            deleteLeafOutOf(tree.root());
            break;

        case TreeSave::EntityOnly:
            break;
        }
    }
}

template<class Ent, class Link, class Unique> void ManagerOfArbre<Ent,Link,Unique>::saveAddLeaf(TreeItem<Ent> * tree)
{
    int i = 0;
    for(typename QList<TreeItem<Ent>*>::const_iterator child = tree->childs().cbegin(); child != tree->childs().cend(); ++i, ++child)
    {
        if((*child)->data().isNew())
        {
            Arbre node(i,(*child)->parent()->data().id());
            m_managerArbre.save(node);
            (*child)->modifData().setId(node.id());
        }
        save((*child)->data());
        if((*child)->hasChild())
            saveAddLeaf(*child);
    }
}

template<class Ent, class Link, class Unique> void ManagerOfArbre<Ent,Link,Unique>::saveWithoutDelete(TreeItem<Ent> * tree)
{
    int i = 0;
    int idParent = tree->parent()->data().id();
    for(typename QList<TreeItem<Ent>*>::const_iterator child = tree->childs().cbegin(); child != tree->childs().cend(); ++i, ++child)
    {
        Arbre node(i,idParent,(*child)->data().id());
        m_managerArbre.saveUnstable(node);
        if((*child)->data().isNew())
            (*child)->modifData().setId(node.id());
        save((*child)->data());
        if((*child)->hasChild())
            saveWithoutDelete(*child);
    }
}

template<class Ent, class Link, class Unique> void ManagerOfArbre<Ent,Link,Unique>::saveExt(TreeItem<Ent> * tree, int idRoot)
{
    int i = 0;
    int idParent = tree->parent()->data().id();
    for(typename QList<TreeItem<Ent>*>::const_iterator child = tree->childs().cbegin(); child != tree->childs().cend(); ++i, ++child)
    {
        Arbre node(i,idParent,(*child)->data().id());
        if(node.id() == 0 || m_managerArbre.areRelated(idParent,idRoot))
            m_managerArbre.saveUnstable(node);
        else
            m_managerArbre.saveStUnstable(node);
        if((*child)->data().isNew())
            (*child)->modifData().setId(node.id());
        save((*child)->data());
        if((*child)->hasChild())
            saveExt(*child,idRoot);
    }
}

template<class Ent, class Link, class Unique> void ManagerOfArbre<Ent,Link,Unique>::writeStringSql()
{
    m_sqlAdd.clear();
    m_sqlAdd.append("INSERT INTO ").append(table()).append("(");
    for(int i = 1; i != m_link.nbrAtt(); ++i)
        m_sqlAdd.append(attribut(i)).append(",");
    m_sqlAdd.append(attribut(Ent::Id));
    m_sqlAdd.append(") VALUES(");
    for(int i = 0; i != m_link.nbrAtt(); ++i)
        m_sqlAdd.append("?,");
    m_sqlAdd.chop(1);
    m_sqlAdd.append(")");
    m_sqlAdd.squeeze();
}
#endif // MANAGEROFARBRE_H
