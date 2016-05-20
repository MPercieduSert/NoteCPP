/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/02/2016
 */
#ifndef BDD_H
#define BDD_H

#include "AbstractBdd.h"

/*! \ingroup groupeFile
 * \brief Gestionnaire de la base de donnée.
 */

class Bdd : public AbstractBdd
{
public:
    //! Constructeur. Donner en argument le type ainsi que le chemin de la base de donnée.
    Bdd(const QString & dbtype = "", const QString & fileName = "")
        : AbstractBdd(dbtype,fileName)
    {}

    //! Destructeur. Referme la base de donnée.
    ~Bdd()
        {}

    //! Retourne le nom de la classe.
    QString afficheClasse(const Classe & classe, Classe::affichage = Classe::Numeric);
};

#endif // BDD_H
