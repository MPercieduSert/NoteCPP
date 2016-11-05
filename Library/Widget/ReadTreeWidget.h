/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/10/2016
 */
#ifndef READTREEWIDGET_H
#define READTREEWIDGET_H

#include <QTreeView>
#include <QWidget>
#include "../Model/TreeModelReadTemp.h"

/*! \ingroup groupeModel
 * \brief Classe template de type arbre non-modifiable.
 */
template<class Ent> class ReadTreeWidget : public QWidget
{
protected:
    TreeModelReadTemp<Ent> * m_model;       //!< Model
    QTreeView * m_view;                     //!< Vue

public:
    //! Constructeur.
    ReadTreeWidget(const Tree<Ent> & tree, QWidget * parent = 0);

    //! Destructeur.
    ~ReadTreeWidget() {}

    //! Modifie les données affichées par le widget.
    void setDataTree(const Tree<Ent> & tree)
        {m_model->setDataTree(tree);}

    //! renvoie la l'élément sélectionnée.
    Ent value() const
    {QModelIndex index = m_view->currentIndex();
        if (index.isValid())
            return static_cast<TreeItem<Ent>*>(index.internalPointer())->data();
        else
            return Ent();
    }
};

template<class Ent> ReadTreeWidget<Ent>::ReadTreeWidget(const Tree<Ent> &tree, QWidget * parent) : QWidget(parent)
{
    m_model = new TreeModelReadTemp<Ent>(parent);
    m_model->setDataTree(tree);
    m_view = new QTreeView(this);
    m_view->setModel(m_model);
}

#endif // READTREEWIDGET_H
