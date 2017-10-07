/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/09/2016
 */
#ifndef TREEMODELEDITTEMP_H
#define TREEMODELEDITTEMP_H

#include <QStack>
#include "../Manager/AbstractManager.h"
#include "TreeModelReadTemp.h"

/*! \ingroup groupeModel
 * \brief Classe template des models de type arbre modifiable.
 */
template<class Ent> class TreeModelEditTemp : public TreeModelReadTemp<Ent>
{
public:
    using TreeModelReadTemp<Ent>::TreeModelReadTemp;

    //! Renvoie les autorisations de modification pour un index donné.
    virtual bool autorisation(const QModelIndex & /*index*/, bdd::Autorisation /*role*/) const
        {return true;}

    //! Renvoie les drapeaux de l'index spécifié.
    Qt::ItemFlags flags(const QModelIndex &index) const;

    //! Créer une nouvelle entité
    virtual bool hydrateNewEntity(Ent & /*entity*/, int /*row*/ = 0, const QModelIndex &/*parent*/ = QModelIndex())
        {return true;}

    //! Insert des lignes dans le model.
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());

    //! Supprime l'entité de la base de donnée si nécéssaire.
    virtual bool removeEntity(const Ent & /*entity*/)
        {return true;}

    //! Supprime des lignes dans le model.
    bool removeRows(int row, int count, const QModelIndex &parent);

protected:
    using TreeModelReadTemp<Ent>::beginInsertRows;
    using TreeModelReadTemp<Ent>::beginRemoveRows;
    using TreeModelReadTemp<Ent>::beginResetModel;
    using TreeModelReadTemp<Ent>::createIndex;
    using TreeModelReadTemp<Ent>::endInsertRows;
    using TreeModelReadTemp<Ent>::endRemoveRows;  
    using TreeModelReadTemp<Ent>::endResetModel;
    using TreeModelReadTemp<Ent>::getItem;
    using TreeModelReadTemp<Ent>::parent;
};

template<class Ent> Qt::ItemFlags TreeModelEditTemp<Ent>::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

template<class Ent> bool TreeModelEditTemp<Ent>::insertRows(int row, int count, const QModelIndex &parent)
{
    if(!parent.isValid())
        return false;
    int comp = 0;
    for(int i = 0; i != count; ++i)
    {
        Ent entity;
        if(hydrateNewEntity(entity, row, parent))
        {
            beginInsertRows(parent,row,row);
                getItem(parent)->insertChild(row, entity);
            endInsertRows();
            ++row;
            ++comp;
        }
    }
    return comp == count;
}

template<class Ent> bool TreeModelEditTemp<Ent>::removeRows(int row, int count, const QModelIndex &parentIndex)
{
    if(!parentIndex.isValid())
        return false;
    int comp = 0;
    for(int i = 0; i != count; ++i)
    {
        QStack<TreeItem<Ent> *> pile;
        pile.push(getItem(parentIndex)->child(row));
        bool remove = true;
        while(!pile.isEmpty() && remove)
        {
            if(pile.top()->hasChild())
                pile.push(pile.top()->lastChild());
            else
            {
                int n = pile.top()->position();
                remove = removeEntity(pile.top()->data());
                if(remove)
                {
                    beginRemoveRows(parent(createIndex(0,0,pile.top())),n,n);
                        delete pile.pop();
                    endRemoveRows();
                }
            }
        }
        if(pile.isEmpty())
            ++comp;
        ++row;
    }
    return comp == count;
}

#endif // TREEMODELEDITTEMP_H
