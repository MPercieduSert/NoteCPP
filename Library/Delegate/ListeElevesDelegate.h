/*Auteur: PERCIE DU SERT Maxime
 *Date: 13/03/2017
 */
#ifndef LISTEELEVESDELEGATE_H
#define LISTEELEVESDELEGATE_H

#include <QCheckBox>
#include <QDateEdit>
#include <QStyledItemDelegate>

#include "../Model/ListeElevesModel.h"

/*! \defgroup groupeDelegate Délégué
 * \brief Ensemble de classes délégué pour les modèles.
 */

/*! \ingroup groupeDelegate
 * \brief Délégué pour le model héritnt de ListesEleveModel.
 */
class ListeElevesDelegate : public QStyledItemDelegate
{
    Q_OBJECT
protected:

public:
    using Indice = ListeElevesModel::Indice;
    //! Constructeur.
    ListeElevesDelegate(QObject * parent = 0) : QStyledItemDelegate(parent) {}
    //! Creer un item pour édité une donnée.
    QWidget * createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const;
    //! Renvoie l'indice correspondant à index.
    Indice indice(const QModelIndex & index) const
        {return ((ListeElevesModel *) index.model())->indice(index);}
    //! Modifie l'éditeur avec la donnée du modèle.
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
};

#endif // LISTEELEVESDELEGATE_H
