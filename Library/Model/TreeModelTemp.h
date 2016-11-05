/*Auteur: PERCIE DU SERT Maxime
 *Date: 13/10/2016
 */
#ifndef TREEMODELTEMP_H
#define TREEMODELTEMP_H

#include "TreeModelReadTemp.h"

/*! \ingroup groupeModel
 * \brief Classe template des models de type d'arbre modifiable.
 */
template<class Ent> class TreeModelTemp : public TreeModelReadTemp<Ent>
{
public:
    //! Constructeur.
    TreeModelTemp(QObject *parent = 0) : TreeModelReadTemp<Ent>(parent) {}

    //! Destructeur.
    ~TreeModelTemp() {}

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole);
    bool setHeaderData(int section, Qt::Orientation orientation,
                       const QVariant &value, int role = Qt::EditRole);

    bool insertColumns(int position, int columns,
                       const QModelIndex &parent = QModelIndex());
    bool removeColumns(int position, int columns,
                       const QModelIndex &parent = QModelIndex());
    bool insertRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex());
    bool removeRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex());
};
#endif // TREEMODELTEMP_H
