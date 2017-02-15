/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/01/2017
 */
#ifndef LISTENOTEMODEL_H
#define LISTENOTEMODEL_H

#include <QStringList>

#include "MAbstractTableModel.h"
#include "../Div/Bdd.h"
#include "../Entities/Classe.h"
#include "../Entities/Eleve.h"
#include "../Div/VectorPtr.h"

/*! \ingroup groupeModel
 * \brief Model de la liste des notes d'une classe.
 */
class ListeNoteModel: public MAbstractTableModel
{
    Q_OBJECT
protected:
    Bdd * m_bdd;                                //!< Lien avec la base de donnée.
    Classe m_classe;                            //!< Classe associé à la liste.
    VectorPtr<Eleve> m_vectEleve;               //!< Vecteur des éléves présent dans la classe.
    VectorPtr<Controle> m_vectControle;         //!< Liste des controles dont les notes sont affichées
    QVector<MapPtr<Note>> m_dataN;           //! Ensemble des vecteurs de notes.

public:
    //! numero des colonnes
    enum indexColum {NomIndex = 0,
                    PrenomIndex = 1,
                    NbrDonneeEleve};

    //! Constructeur.
    ListeNoteModel(Bdd * bdd, const Classe &classe, QObject * parent = 0);

    //! Destructeur.
    ~ListeNoteModel()  {}

    //! Renvoie le nombre de colonnes.
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    //! Renvoie la donnée d'index et de role spécifié.
    QVariant data(const QModelIndex &index, int role) const;

    //! Renvoie les flags de l'index spécifié.
    Qt::ItemFlags flags(const QModelIndex &index) const;

    //! Renvoie le label des lignes et des colonnes.
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    //! Insert de nouvelles colonnes.
    bool insertColumn(const Controle &ctr);

    //! Renvoie le nombre de lignes.
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    //! Sauvegarde les données.
    void save();

    //! Modifie la donnée d'index et de role spécifié.
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
};

#endif // LISTENOTEMODEL_H
