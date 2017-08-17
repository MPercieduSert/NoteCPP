/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/01/2017
 */
#ifndef LISTENOTEMODEL_H
#define LISTENOTEMODEL_H

#include <QStringList>

#include "ListeElevesModel.h"
#include "../Div/Bdd.h"
#include "../Entities/Classe.h"
#include "../Entities/Eleve.h"
#include "../Div/VectorPtr.h"

/*! \ingroup groupeModel
 * \brief Model de la liste des notes d'une classe.
 */
class ListeNoteModel: public ListeElevesModel
{
    Q_OBJECT
protected:
    Classe m_classe;                            //!< Classe associé à la liste.
    VectorPtr<Controle> m_vectControle;         //!< Liste des controles dont les notes sont affichées
    QVector<MapPtr<Note>> m_dataN;              //! Ensemble des vecteurs de notes.

    //! Prédicat premettant le tri des lignes suivant l'ordre des notes.
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
    //! Constructeur.
    ListeNoteModel(Bdd * bdd, const Classe &classe, QObject * parent = 0);

    //! Destructeur.
    ~ListeNoteModel()  {}

    //! Renvoie la donnée d'index et de role spécifié.
    QVariant dataPropre(const Indice &indice, int role) const;

    //! Renvoie le controle correspondant à la colonne de section.
    Controle controle(int section) const
    {
        int pos = m_idCol[section] - Offset;
        return 0 <= pos && pos < m_vectControle.count() + Offset ? m_vectControle[pos] : Controle();
    }

    //! Renvoie la liste des notes du controle d'indice pos.
    QVector<double> vectNotes(int section) const;

    //! Insert de nouvelles colonnes.
    bool insertColumn(const Controle &ctr);

    //! Insert de nouvelles colonnes.
    bool insertColumn(const ListPtr<Controle> &ctrs);

    //! Sauvegarde les données.
    void save();

    //! Modifie la donnée d'index et de role spécifié.
    bool setDataPropre(const Indice & indice, const QVariant & value, int role = Qt::EditRole);

    //! Tri les lignes suivant la colonne column.
    void sortPropre(int column, Qt::SortOrder order);
};

#endif // LISTENOTEMODEL_H
