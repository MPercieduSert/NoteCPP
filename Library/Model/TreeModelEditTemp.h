/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/09/2016
 */
#ifndef TREEMODELEDITTEMP_H
#define TREEMODELEDITTEMP_H

#include "TreeModelReadTemp.h"

/*! \ingroup groupeModel
 * \brief Classe template des models de type arbre modifiable.
 */
template<class Ent> class TreeModelEditTemp : public TreeModelReadTemp<Ent>
{
public:
    enum itemRole{
        EstSupprimable = Qt::UserRole
    };

    using TreeModelReadTemp<Ent>::TreeModelReadTemp;

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
    using TreeModelReadTemp<Ent>::getItem;
    using TreeModelReadTemp<Ent>::beginInsertRows;
    using TreeModelReadTemp<Ent>::beginRemoveRows;
    using TreeModelReadTemp<Ent>::endRemoveRows;
    using TreeModelReadTemp<Ent>::endInsertRows;
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

template<class Ent> bool TreeModelEditTemp<Ent>::removeRows(int row, int count, const QModelIndex &parent)
{
    if(!parent.isValid())
        return false;
    int comp = 0;
    for(int i = 0; i != count; ++i)
    {
        if(removeEntity(getItem(parent)->child(row)->data()))
        {
            beginRemoveRows(parent,row,row);
                getItem(parent)->removeChild(row);
            endRemoveRows();
            ++row;
            ++comp;
        }
    }
    return comp == count;
}

#endif // TREEMODELEDITTEMP_H
