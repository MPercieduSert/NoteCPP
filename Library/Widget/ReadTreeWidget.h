/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/10/2016
 */
#ifndef READTREEWIDGET_H
#define READTREEWIDGET_H

#include <QScrollArea>
#include <QTreeView>
#include <QWidget>
#include "../Model/TreeModelReadTemp.h"

/*! \ingroup groupeWidget
 * \brief Classe template des widget de type arbre non-modifiable.
 */
template<class Ent> class ReadTreeWidget : public QTreeView
{
protected:
    TreeModelReadTemp<Ent> * m_model;       //!< Model

public:
    //! Constructeur.
    ReadTreeWidget(const Tree<Ent> & tree, const QList<typename Ent::Position> atts = QList<typename Ent::Position>(), QWidget * parent = 0);

    //! Destructeur.
    ~ReadTreeWidget() {}

    //! Selectionne l'item correspondant au première item d'identifiant id dans l'arbre.
    void select(int id);

    //! Modifie les données affichées par le widget.
    void setDataTree(const Tree<Ent> & tree)
        {m_model->setDataTree(tree);}

    //! renvoie l'élément sélectionnée.
    Ent value() const
    {
        QModelIndex index = currentIndex();
        if (index.isValid())
            return static_cast<TreeItem<Ent>*>(index.internalPointer())->data();
        else
            return Ent();
    }
};

template<class Ent> ReadTreeWidget<Ent>::ReadTreeWidget(const Tree<Ent> &tree,const QList<typename Ent::Position> atts, QWidget * parent) : QTreeView(parent)
{
    m_model = new TreeModelReadTemp<Ent>(atts, parent);
    m_model->setDataTree(tree);
    setModel(m_model);
}

template<class Ent> void ReadTreeWidget<Ent>::select(int id)
    {selectionModel()->select(m_model->foundId(id),QItemSelectionModel::Select);}

#endif // READTREEWIDGET_H
