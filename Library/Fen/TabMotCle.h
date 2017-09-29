/*Auteur: PERCIE DU SERT Maxime
 *Date: 17/08/2017
 */
#ifndef TABMOTCLE_H
#define TABMOTCLE_H

#include <QHBoxLayout>
#include <QSplitter>
#include <QTreeView>

#include "TabAbstractModule.h"
#include "../Delegate/MotCleDelegate.h"
#include "../Model/TreeModelMotCle.h"
#include "../Widget/MotCleWidget.h"

/*! \ingroup groupeFen
 * \brief Classe de l'onglet de gestion des mots clés.
 */
class TabMotCle : public TabAbstractModule
{
    Q_OBJECT
protected:

    QTreeView * m_treeWidget;      //!< Affichage de l'arbre des mots clés.
    MotCleWidget * m_motCleWidget;      //!< Widget d'attribution des mot clés.
    QSplitter * m_horizontalSplitter;     //!< Splitter horizontale.

public:
    //! Constructeur.
    explicit TabMotCle(int index, TabModule *parent = 0);

    //! Destructeur.
    ~TabMotCle() {}

public slots:
    //! Action à effectuer lorsque l'onglet devient actif.
    void becomeCurrent() const;
};

#endif // TABMOTCLE_H
