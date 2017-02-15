/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/02/2016
 */
#ifndef BDD_H
#define BDD_H

#include "AbstractBdd.h"

namespace bdd {
    //! Enumération des mise-à-jour de la base de donnée.
    enum miseAJourBdd{
        creationInitial = creationBdd::initiale,
        creationTable20170110,
        Donnees20170110,
        endMiseAJour
    };

    //! Enumération des types d'établissement.
    enum typeEtablissement { Primaire = 1,
                             College,
                             LyceeGeneral,
                             LyceePro,
                             Prepa,
                             Universite,
                             Iut,
                             EcoleInge
    };

    //! Enumération des cibles.
    enum cible {AnneeCb = 0,
                AttributCb = 1,
                BaremeCb = 2,
                ClasseCb = 3,
                CommentaireCb = 4,
                CoursCb = 5,
                DonneeCb = 6,
                EleveCb = 7,
                EnonceCb = 8,
                EtablissementCb = 9,
                ExerciceCb = 10,
                FormeCb = 11,
                GroupeCb = 12,
                NiveauCb = 13,
                NoteCb = 14,
                PointCb = 15,
                TexteCb = 16,
                TypeControleCb = 17,
                TypeCoursCb = 18,
                TypeNiveauCb = 19,
                SourceCb = 20
               };
}

/*! \ingroup groupeFile
 * \brief Gestionnaire de la base de donnée.
 */
class Bdd : public AbstractBdd
{
public:
    //static const int version_bdd = 100;
    //static const int version_bdd_creer = 100;

    //! Constructeur. Donner en argument le type ainsi que le chemin de la base de donnée.
    Bdd(const QString & dbtype = "", const QString & fileName = "")
        : AbstractBdd(dbtype,fileName,bdd::miseAJourBdd::endMiseAJour-1)
    {}

    //! Destructeur. Referme la base de donnée.
    ~Bdd()
        {}

    //! Renvoie l'identifiant de la donnée d'idProg fourni
    int idDonnee(typename Donnee::prog idP);

protected:
    //! Mise à jour de la base de donnée.
    void listeMiseAJourBdd(int version);
};

#endif // BDD_H

