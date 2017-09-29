/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/08/2017
 */
#ifndef MOTCLEDELEGATE_H
#define MOTCLEDELEGATE_H

#include <QComboBox>
#include <QContextMenuEvent>
#include <QEvent>
#include <QMenu>
#include <QPainter>
#include <QStyledItemDelegate>
#include "../Model/TreeModelMotCle.h"


/*! \ingroup groupeDelegate
 * \brief Délégué pour le model TreeModelMotCle.
 */
class MotCleDelegate: public QStyledItemDelegate
{
    Q_OBJECT
protected:

public:
    //! Constructeur.
    MotCleDelegate(QObject * parent = 0)
        : QStyledItemDelegate(parent)
    {}
    //! Creer un item pour édité une donnée.
    QWidget * createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const;
    //! Affiche la donnée.
    /*void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;*/
    //! Modifie l'éditeur avec la donnée du modèle.
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //! Modifie la donnée dans le modèle.
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    //! Gestionnaire des événement;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
protected:
    //! Affiche un menu contextuel
    void showContextMenu(QAbstractItemModel *model, const QModelIndex &index, const QPoint& globalPos);
};

#endif // MOTCLEDELEGATE_H
