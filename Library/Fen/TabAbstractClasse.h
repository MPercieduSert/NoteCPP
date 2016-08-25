/*Auteur: PERCIE DU SERT Maxime
 *Date: 11/07/2016
 */
#ifndef TABABSTRACTCLASSE_H
#define TABABSTRACTCLASSE_H

#include "TabAbstractTableau.h"
#include "../Entities/Classe.h"

/*! \ingroup groupeFen
 * \brief Classe mère des onglets contenant des tableaux pour une classe.
 */
class TabAbstractClasse : public TabAbstractTableau
{
    Q_OBJECT
protected:
    Annee m_annee;              //!< Annee
    Classe m_classe;            //!< CLasse


public:
    //! Constructeur.
    explicit TabAbstractClasse(int idClasse, TabModule *parent = 0);
    //! Destructeur.
    ~TabAbstractClasse() {}
    //! Renvoye une référence sur la classe associée à l'onglet.
    const Classe & classe() const
        {return m_classe;}

signals:

public slots:
};

#endif // TABABSTRACTCLASSE_H
