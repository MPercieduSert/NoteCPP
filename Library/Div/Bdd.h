/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/02/2016
 */
#ifndef BDD_H
#define BDD_H

#include "AbstractBdd.h"

namespace bdd {
    enum miseAJourBdd{
        creationInitial = creationBdd::initiale,
        creationTable20160527,
        Donnees20160527,
        endMiseAJour
    };

    enum typeEtablissement { Primaire = 1,
                             College,
                             LyceeGeneral,
                             LyceePro,
                             Prepa,
                             Universite,
                             Iut,
                             EcoleInge
    };
}

/*! \ingroup groupeFile
 * \brief Gestionnaire de la base de donnée.
 */
class Bdd : public AbstractBdd
{
public:
    static const int version_bdd = 100;
    static const int version_bdd_creer = 100;

    //! Constructeur. Donner en argument le type ainsi que le chemin de la base de donnée.
    Bdd(const QString & dbtype = "", const QString & fileName = "")
        : AbstractBdd(dbtype,fileName,bdd::miseAJourBdd::endMiseAJour-1)
    {}

    //! Destructeur. Referme la base de donnée.
    ~Bdd()
        {}

protected:
    //! Mise à jour de la base de donnée.
    void listeMiseAJourBdd(int version);
};

#endif // BDD_H
