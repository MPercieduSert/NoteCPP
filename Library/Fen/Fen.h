/*Auteur: PERCIE DU SERT Maxime
 *Date: 11/02/2016
 */

/*! \ingroup groupeFen
 *
 * \brief Classe parente des fenêtres autre que la fenêtre principale.
 */

#ifndef FEN_H
#define FEN_H

#include <QWidget>

class FenPrincipale;

class Fen : public QWidget
{
    Q_OBJECT
protected:
    FenPrincipale * m_parent;   //!< Pointeur sur la fenêtre principale.

public:
    //! Constructeur.
    explicit Fen(FenPrincipale *parent = 0);

    //! Renvoie un pointeur sur la fenêtre principale.
    FenPrincipale * parent() const
        {return m_parent;}
signals:

public slots:
};

#endif // FEN_H
