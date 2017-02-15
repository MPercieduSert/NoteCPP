/*Auteur: PERCIE DU SERT Maxime
 *Date: 15/07/2016
 */
#ifndef LISTEELEVEMODEL_H
#define LISTEELEVEMODEL_H

#include <QList>
#include <QMessageBox>
#include <QMimeData>
#include <QStringList>

#include "MAbstractTableModel.h"
#include "../Div/Bdd.h"
#include "../Entities/Classe.h"
#include "../Entities/Eleve.h"
#include "../Div/VectorPtr.h"

/*! \ingroup groupeModel
 * \brief Model de la liste des éléves.
 */
class ListeEleveModel : public MAbstractTableModel
{
    Q_OBJECT
protected:
    Bdd * m_bdd;                                //!< Lien avec la base de donnée.
    Classe m_classe;                            //!< Classe associé à la liste.
    QVector<VectorPtr<CibleDonnee>> m_dataD;    //!< Ensemble des vecteurs de données sur les éléves.
    VectorPtr<Eleve> m_dataE;                   //!< Vecteur des éléves présent dans la classe.
    QStringList m_header;                       //!< Entêtes des colonnes.

public:
    //! numero des colonnes
    enum indexColum {NomIndex = 0,
                    PrenomIndex = 1,
                    SexeIndex = 2,
                    NaissanceIndex = 3,
                    NbrDonneeEleve};

    //! Constructeur.
    ListeEleveModel(Bdd * bdd, const Classe &classe, QObject * parent = 0);

    //! Destructeur.
    ~ListeEleveModel()  {}

    //! Renvoie le nombre de colonnes.
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    //! Renvoie la donnée d'index et de role spécifié.
    QVariant data(const QModelIndex &index, int role) const;

    //! Renvoie les flags de l'index spécifié.
    Qt::ItemFlags flags(const QModelIndex &index) const;

    //! Renvoie le label des lignes et des colonnes.
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    //! Insert de nouvelles lignes.
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());

    //! Insert de nouvelles colonnes.
    bool insertColumn(const Donnee & dn);

    //! Retire des lignes
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());

    //! Renvoie le nombre de lignes.
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    //! Sauvegarde les données.
    void save();

    //! Modifie la donnée d'index et de role spécifié.
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);

};

#endif // LISTEELEVEMODEL_H
