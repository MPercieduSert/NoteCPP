/*Auteur: PERCIE DU SERT Maxime
 *Date: 13/10/2016
 */
#ifndef TREEMODELREADTEMP_H
#define TREEMODELREADTEMP_H

#include "MAbstractTreeModel.h"
#include "../Div/Tree.h"
#include <QMessageBox>
#include <QItemSelection>

/*! \ingroup groupeModel
 * \brief Classe template des models de type arbre non-modifiable.
 */
template<class Ent> class TreeModelReadTemp : public MAbstractTreeModel
{
protected:
    QList<typename Ent::Position> m_atts;   //!< Liste des attributs à afficher.
    QStringList m_header;   //!< Liste des noms des colonnes.
    Tree<Ent> m_tree;       //!< Arbre de donnée.

public:
    //! Constructeur.
    TreeModelReadTemp(const QList<typename Ent::Position> & atts = QList<typename Ent::Position>(), QObject *parent = 0) : MAbstractTreeModel(parent), m_atts(atts) {}

    //! Destructeur.
    ~TreeModelReadTemp() {}

    //! Renvoie le nombre de colonnes.
    int columnCount() const
        {return m_atts.isEmpty() ? Ent::NbrAtt : m_atts.count();}

    //! Renvoie le nombre de colonnes.
    int columnCount(const QModelIndex & /*parent*/) const
        {return columnCount();}

    //! Renvoie la donnée correspondant à l'index et au role.
    QVariant data(const QModelIndex &index, int role) const;

    //! Renvoie un index sur le premier (dans le sens de parcourt) noeud de l'arbre ayant pour donnée un entité d'identifiant id.
    QItemSelection foundId(int id) const;

    //! Renvoie les labels des colonnes
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    //! Renvoie l'index correxpondant à la ligne et au parent.
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;

    //! Renvoie l'index du parent.
    QModelIndex parent(const QModelIndex &index) const;

    //! Renvoie le nombre de d'enfants.
    int rowCount(const QModelIndex &parent = QModelIndex()) const
        {return getItem(parent)->childCount();}

    //! Modifie l'arbre de donnée.
    void setDataTree(const Tree<Ent> & tree)
        {m_tree = tree;}

protected:
    TreeItem<Ent> *getItem(const QModelIndex &index) const;
};

template<class Ent> QVariant TreeModelReadTemp<Ent>::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    TreeItem<Ent> *item = getItem(index);
    return m_atts.isEmpty() ? item->data().data(index.column()) : item->data().data(m_atts.at(index.column()));
}

template<class Ent> QItemSelection TreeModelReadTemp<Ent>::foundId(int id) const
{
    typename TreeItem<Ent>::iterator i = m_tree.begin();
    while(i != m_tree.end() && (*i)->data().id() != id )
        ++i;
    if(i != m_tree.end())
        return QItemSelection(createIndex((*i)->position(),0,(*i)),createIndex((*i)->position(),m_atts.count()-1,(*i)));
    else
        return QItemSelection();
}

template<class Ent> TreeItem<Ent>* TreeModelReadTemp<Ent>::getItem(const QModelIndex & index) const
{
    if (index.isValid())
    {
        TreeItem<Ent> *item = static_cast<TreeItem<Ent>*>(index.internalPointer());
        if (item)
            return item;
    }
    return m_tree.root();
}

template<class Ent> QVariant TreeModelReadTemp<Ent>::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        if(!m_header.isEmpty() && section < m_header.count())
            return m_header.at(section);
        else
            return m_atts.isEmpty() ? Ent::nomAttribut(section) : Ent::nomAttribut(m_atts.at(section));
    }
    return QVariant();
}

template<class Ent> QModelIndex TreeModelReadTemp<Ent>::index(int row, int column, const QModelIndex &parent) const
{  
    if (parent.isValid() && parent.column() != 0)
          return QModelIndex();

      TreeItem<Ent> *parentItem = getItem(parent);
      TreeItem<Ent> *childItem = parentItem->child(row);
      if (childItem)
          return createIndex(row, column, childItem);
      else
          return QModelIndex();
}

template<class Ent> QModelIndex TreeModelReadTemp<Ent>::parent(const QModelIndex &index) const
{
    if (index.isValid())
    {
        TreeItem<Ent> * child = getItem(index);
        TreeItem<Ent> * parent = child->parent();
        if(parent)
            return createIndex(parent->position(), 0, parent);
    }
    return QModelIndex();
}

#endif // TREEMODELREADTEMP_H
