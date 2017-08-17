/*Auteur: PERCIE DU SERT Maxime
 *Date: 15/07/2016
 */
#ifndef LISTEELEVESMODEL_H
#define LISTEELEVESMODEL_H

#include <QList>
#include <QMessageBox>
#include <QMimeData>
#include <QStringList>

#include "MAbstractTableModel.h"
#include "../Div/Bdd.h"
#include "../Entities/Classe.h"
#include "../Entities/Eleve.h"
#include "../Div/MapPtr.h"
#include "../Div/VectorPtr.h"

/*! \ingroup groupeModel
 * \brief Classe mère des model contenant une liste d'éléves.
 */

class ListeElevesModel : public MAbstractTableModel
{
    Q_OBJECT
protected:
    Bdd * m_bdd;                //!< Lien avec la base de donnée.
    MapPtr<Eleve> m_eleve;      //!< Map des éléves à afficher.
    QMap<int,QString> m_header;       //!< Entêtes des colonnes.
    QVector<int> m_idCol;       //!< Coorespondance entre la colonne est l'identifiant de sa donnée.
    QVector<int> m_idRow;       //!< Coorespondance entre la ligne est l'identifiant de l'éléve.
    int m_nbrColEleve;          //!< Nombre de colonnes de donnée éléves.

    //! Prédicat premettant le tri des lignes suivant l'ordre aphabétique des nom, puis prénom et date de naissance
    template<int N> class sortEleve
    {
    protected:
        bool m_asc;   //!< trie dans le sans croissant si vrai et décroissant sinon.
        ListeElevesModel * m_model;

    public:
        //! Constructeur.
        sortEleve(ListeElevesModel * model, bool asc) : m_asc(asc), m_model(model) {}

        //! Opérateur () permet d'être utiliser commme prédicat.
        bool operator ()(int /*i*/, int /*j*/) const {return true;}
    };

public:
    enum tri {NomPrenomNaissance,PrenomNomNaissance,NaissanceNomPrenom};
    enum {Offset = Eleve::NbrAtt};
    using Indice = QPair<int,int>;

    //! Constructeur.
    ListeElevesModel(Bdd * bdd, const MapPtr<Eleve> &&mapEleve, QObject * parent = 0, const QList<int> & colonnes = QList<int>());

    //! Destructeur.
    ~ListeElevesModel()  {}

    //! Renvoie le nombre de colonnes.
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    //! Renvoie la donnée d'index et de role spécifié.
    QVariant data(const QModelIndex &index, int role) const;

    //! Renvoie la donnée d'indice et de role spécifié.
    QVariant data(const Indice &indice, int role) const;

    //! Renvoie la donnée d'index et de role spécifié.
    virtual QVariant dataPropre(const Indice &indice, int role) const = 0;

    //! Renvoie les flags de l'index spécifié.
    Qt::ItemFlags flags(const QModelIndex &index) const;

    //! Renvoie le label des lignes et des colonnes.
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    //! Fait la correspondance entre un index (QModelIndex) et un indice premettant l'accès au données.
    Indice indice(const QModelIndex &index) const
        {return Indice(m_idCol[index.column()],m_idRow[index.row()]);}

//    //! Insert de nouvelles lignes.
//    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());

//    //! Retire des lignes
//    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());

    //! Renvoie le nombre de lignes.
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    //! Sauvegarde les données.
    void save();

    //! Modifie la donnée d'index et de role spécifié.
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);

    //! Modifie la donnée d'index et de role spécifié.
    bool setData(const Indice & indice, const QVariant & value, int role = Qt::EditRole);

    //! Modifie la donnée d'index et de role spécifié.
    virtual bool setDataPropre(const Indice & indice, const QVariant & value, int role = Qt::EditRole) = 0;

    //! Tri les ligne suivant la i ème colonne.
    void sort(int column, Qt::SortOrder order);

    //! Tri les ligne suivant la i ème colonne.
    virtual void sortPropre(int /*column*/, Qt::SortOrder /*order*/) {}

protected:
    //! Ajoute un indice de colonne.
    void appendIdCol(int idCol)
        {m_idCol.append(idCol + Offset);}

    void headerInsert(int idCol, const QString & nom)
        {m_header.insert(idCol + Offset,nom);}
};

#endif // LISTEELEVESMODEL_H
