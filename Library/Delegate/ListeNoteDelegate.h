/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/01/2017
 */
#ifndef LISTENOTEDELEGATE_H
#define LISTENOTEDELEGATE_H

#include <QStyledItemDelegate>


//#include "ListeElevesDelegate.h"
#include "../Model/ListeNoteModel.h"
#include "../Widget/SpinBoxNote.h"

/*! \ingroup groupeDelegate
 * \brief Délégué pour le model ListeNoteModel.
 */
class ListeNoteDelegate : public QStyledItemDelegate
{
    Q_OBJECT
protected:

public:
    using Indice = ListeElevesModel::Indice;
    //! Constructeur.
    ListeNoteDelegate(QObject * parent = 0)
        : QStyledItemDelegate(parent)
    {}
    //! Creer un item pour édité une donnée.
    QWidget * createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const;
    //! Renvoie l'indice correspondant à index.
    Indice indice(const QModelIndex & index) const
        {return ((ListeElevesModel *) index.model())->indice(index);}
    /*//! Modifie l'éditeur avec la donnée du modèle.
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //! Modifie la donnée dans le modèle.
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;*/
};

#endif // LISTENOTEDELEGATE_H
