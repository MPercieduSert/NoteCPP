/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/08/2017
 */
#ifndef TREEMODELMOTCLE_H
#define TREEMODELMOTCLE_H


#include <array>
#include "TreeModelEditTemp.h"
#include "../Dialog/NewMotCleDialog.h"
#include "../Div/Bdd.h"
#include "../Entities/MotCle.h"

/*! \ingroup groupeModel
 * \brief Model de gestion des motcle.
 */
class TreeModelMotCle : public TreeModelEditTemp<MotCle>
{
public:
    //! Enumération des permission de motcle possible.
    enum perm {
        BaremeIndex,
        CommentaireIndex,
        ControleIndex,
        CoursIndex,
        EnonceIndex,
        ExerciceIndex,
        MotCleIndex,
        TexteIndex,
        TypeControleIndex,
        TypeUtilisationIndex,
        UtilisationIndex,
        NbrIndex
    };

    //! Enumeration des nombres de colonnes.
    enum {
        NomMotCleIndex,
        NcMotCleIndex,
        NbrColumnMotCle,
        NbrColumnSup = 1,
        NbrColumn = NbrColumnMotCle + NbrColumnSup + NbrIndex
    };

protected:
    //! Type des permitions associées à un mot clé.
    using PermList = std::array<int,NbrIndex>;
    Bdd * m_bdd;                                //!< Pointeur vers la base de donnée.
    PermList m_cibleList;                       //!< Liste des valeurs de cible associé à chaque index de colonnes.
    std::array<QString,NbrIndex> m_headerPerm;  //!< Noms des colonnes.
    QMap<int,PermList> m_permission;            //!< Map des permitions indexé par l'identifiant du mot clé associé.

public:
    //! Constructeur.
    TreeModelMotCle(Bdd * bdd, QObject *parent = 0);

    //! Destructeur.
    ~TreeModelMotCle() {}

    //! Renvoie les autorisations de modification pour un index donné.
    bool autorisation(const QModelIndex & index, bdd::Autorisation autoris) const;

    //! Renvoie le numero de cible correspond à l'index
    int cible(const QModelIndex & index) const
    {
        if(NbrColumnMotCle <= index.column() && index.column() < NbrColumnMotCle + NbrIndex)
            return m_cibleList[index.column() - NbrColumnMotCle];
        else
            return -1;
    }

    //! Renvoie le nombre de colonnes.
    int columnCount(const QModelIndex & /*parent*/) const
        {return NbrColumn;}

    //! Renvoie la donnée correspondant à l'index et au role.
    QVariant data(const QModelIndex &index, int role) const;

    //! Renvoie les drapeaux de l'index spécifié.
    Qt::ItemFlags flags(const QModelIndex &index) const;

    //! Renvoie les labels des colonnes
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    //! Créer une nouvelle entité
    virtual bool hydrateNewEntity(MotCle &entity, int row = 0, const QModelIndex &parent = QModelIndex());

    //! Renvoie l'identifiant de l'entité associée à la donnée.
    int id(const QModelIndex & index) const;

    //! Supprime l'entité de la base de donnée si nécéssaire.
    bool removeEntity(const MotCle & entity);

    //! Enregistre les données.
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
};

#endif // TREEMODELMOTCLE_H
