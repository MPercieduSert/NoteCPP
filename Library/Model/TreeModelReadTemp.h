/*Auteur: PERCIE DU SERT Maxime
 *Date: 13/10/2016
 */
#ifndef TREEMODELREADTEMP_H
#define TREEMODELREADTEMP_H

#include "MAbstractTreeModel.h"
#include "../Div/Tree.h"
#include <QMessageBox>

/*! \ingroup groupeModel
 * \brief Classe template des models de type arbre non-modifiable.
 */
template<class Ent> class TreeModelReadTemp : public MAbstractTreeModel
{
protected:
    QStringList m_header;   //!< List des noms des colonnes.
    Tree<Ent> m_tree;       //!< Arbre de donnée.

public:
    //! Constructeur.
    TreeModelReadTemp(QObject *parent = 0) : MAbstractTreeModel(parent) {}

    //! Destructeur.
    ~TreeModelReadTemp() {}

    //! Renvoie le nombre de colonnes.
    int columnCount(const QModelIndex & /*parent = QModelIndex()*/) const
        {return Ent::NbrAtt;}

    //! Renvoie la donnée correspondant à l'index et au role.
    QVariant data(const QModelIndex &index, int role) const;

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
    return item->data().data(index.column());
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
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole && section < m_header.count())
        return m_header.at(section);
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
