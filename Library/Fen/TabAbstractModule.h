/*Auteur: PERCIE DU SERT Maxime
 *Date: 23/05/2016
 */
#ifndef TABABSTRACTMODULE_H
#define TABABSTRACTMODULE_H

#include <QVBoxLayout>
#include <QWidget>

#include "TabModule.h"

/*! \ingroup groupeFen
 * \brief Classe mère des onglets.
 */
class TabAbstractModule : public QWidget
{
    Q_OBJECT
protected:
    int m_index;                    //!< Indice dans le tableau de type dans le TabModule parent
    QVBoxLayout *m_mainLayout;      //!< Layout principal de la fenêtre
    TabModule * m_parent;           //!< Pointeur sur la fenêtre contenant l'onglet


public:
    //! Constructeur.
    explicit TabAbstractModule(int index, TabModule *parent);

    //! Destructeur.
    ~TabAbstractModule() {}

    //! Renvoie un pointeur sur la base de donnée.
    Bdd * bdd() const
        {return m_parent->bdd();}

    //! Renvoie un pointeur sur le noyau.
    Noyau * noyau() const
        {return m_parent->noyau();}
signals:



public slots:
    //! Action à effectuer lorsque l'onglet devient actif.
    virtual void becomeCurrent() const = 0;

    //! A réimplémenter pour effectuer l'action coller.
    virtual void coller()   {}

    //! A réimplémenter pour effectuer l'action copier.
    virtual void copier()   {}

    //! A réimplémenter pour effectuer l'action copier.
    virtual void couper()   {}

    //! A réimplémenter pour effectuer l'action effacer.
    virtual void effacer()   {}

    //! A réimplémenter pour effectuer l'action sauvegarder.
    virtual void save()   {}

    //! A réimplémenter pour effectuer l'action sauvegarder comme.
    virtual void saveAs()   {}
};

#endif // TABABSTRACTMODULE_H
