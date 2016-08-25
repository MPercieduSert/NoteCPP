/*Auteur: PERCIE DU SERT Maxime
 *Date: 23/05/2016
 */
#ifndef TABABSTRACTMODULE_H
#define TABABSTRACTMODULE_H

#include <QVBoxLayout>
#include <QWidget>

#include "FenPrincipale.h"
#include "TabModule.h"

#include "../Div/Bdd.h"

/*! \ingroup groupeFen
 * \brief Classe mère des onglets.
 */
class TabAbstractModule : public QWidget
{
    Q_OBJECT
protected:
    Bdd * m_bdd;                    //!< Pointeur sur la base de donnée
    int m_index;                    //!< Indice dans le tableau de type dans le TabModule parent
    QVBoxLayout *m_mainLayout;      //!< Layout principal de la fenêtre
    TabModule * m_parent;           //!< Pointeur sur la fenêtre contenant l'onglet


public:
    //! Constructeur
    explicit TabAbstractModule(int index, TabModule *parent);

    //! Destructeur
    ~TabAbstractModule() {}  
signals:

public slots:
    //! Action à effectuer lorsque l'onglet devient actif.
    virtual void becomeCurrent() const = 0;

    /*virtual void coller()   {}
    virtual void copier()   {}
    virtual void effacer()   {}
    virtual void sauvegarder()   {}*/
};

#endif // TABABSTRACTMODULE_H
