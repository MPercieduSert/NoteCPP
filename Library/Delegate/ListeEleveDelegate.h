/*Auteur: PERCIE DU SERT Maxime
 *Date: 15/07/2016
 */
#ifndef LISTEELEVEDELEGATE_H
#define LISTEELEVEDELEGATE_H

#include <QCheckBox>
#include <QDateEdit>
#include <QStyledItemDelegate>

#include "../Entities/Annee.h"
#include "../Model/ListeEleveModel.h"

/*! \defgroup groupeDelegate Délégué
 * \brief Ensemble de classes délégué pour les modèles.
 */

/*! \ingroup groupeDelegate
 * \brief Délégué pour le model ListeEleveModel.
 */
class ListeEleveDelegate : public QStyledItemDelegate
{
    Q_OBJECT
protected:
    Annee m_annee; //!< Année de la classe

public:
    //! Constructeur.
    ListeEleveDelegate(const Annee & annee, QObject * parent = 0);
    //! Creer un item pour édité une donnée.
    QWidget * createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const;
    //! Modifie l'éditeur avec la donnée du modèle.
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //! Modifie la donnée dans le modèle.
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
};

#endif // LISTEELEVEDELEGATE_H
