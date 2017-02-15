/*Auteur: PERCIE DU SERT Maxime
 *Date: 23/05/2016
 */
#ifndef TABMENU_H
#define TABMENU_H

#include <QGridLayout>
#include <QGroupBox>
#include <QMap>
#include <QPushButton>
#include <QSignalMapper>
#include <QVBoxLayout>
#include <QWidget>
#include <stdexcept>
#include "FenPrincipale.h"
#include "TabAbstractModule.h"

/*! \ingroup groupeFen
 * \brief Fenêtre menu d'une annee
 */
class TabMenu : public TabAbstractModule
{
    Q_OBJECT
protected:
    //! Ordre de position dans le layout principal
    enum position{classe,
                  bouton};

    // Donnée
    Annee m_annee;                                  //!< Annee du menu
    QList<QGroupBox *> m_listeGroupeEtab;           //!< Liste des groupes de classes par établissement.
    // QMap<int,QPushButton*> m_classeButtonMap;

    // Widget
    QPushButton *m_newClasseButton;                 //!< Bouton pour créer une nouvelle classe
    QSignalMapper *m_classeMapper;                  //!< Lie les boutons des classes à leur actions

    // Layout
    QHBoxLayout *m_classeLayout;                    //!< Calque des classes

public:
    //! Constructeur
    explicit TabMenu(int idAn, TabModule *parent = 0);

protected:
    //! Crée ou rafraichit la zone des boutons de classes.
    void classeLayout();

signals:

public slots:
    //! Action à effectuer lorsque l'onglet devient actif.
    void becomeCurrent() const;

    //! Ouvre la fenêtre de création d'une classe et rafraichit les boutons des classes.
    void creerClasse();
};

#endif // TABMENU_H
