/*Auteur: PERCIE DU SERT Maxime
 *Date: 17/08/2017
 */
#ifndef TABMOTCLE_H
#define TABMOTCLE_H

#include "TabAbstractModule.h"
#include "../Widget/ReadTreeWidget.h"

/*! \ingroup groupeFen
 * \brief Classe de l'onglet de gestion des mots clés.
 */
class TabMotCle : public TabAbstractModule
{
    Q_OBJECT
protected:
    ReadTreeWidget<MotCle> * m_treeWidget;      //!< Affichage de l'arbre des mots clés.

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
