/*Auteur: PERCIE DU SERT Maxime
 *Date: 06/06/2017
 */
#ifndef TABCOURS_H
#define TABCOURS_H

#include "TabAbstractModule.h"

/*! \ingroup groupeFen
 * \brief Classe de l'onglet des cours.
 */
class TabCours : public TabAbstractModule
{
    Q_OBJECT
public:
    //! Constructeur.
    explicit TabCours(int index, TabModule *parent = 0);

    //! Destructeur.
    ~TabCours() {}

public slots:
    //! Action à effectuer lorsque l'onglet devient actif.
    void becomeCurrent() const;
};

#endif // TABCOURS_H
