/*Auteur: PERCIE DU SERT Maxime
 *Date: 15/07/2016
 */
#ifndef LISTEELEVEMODEL_H
#define LISTEELEVEMODEL_H

#include <QList>
#include <QMessageBox>
#include <QMimeData>
#include <QStringList>

#include "ListeElevesModel.h"
#include "../Div/Bdd.h"
#include "../Entities/Classe.h"
#include "../Entities/Eleve.h"
#include "../Div/VectorPtr.h"

/*! \ingroup groupeModel
 * \brief Model de la liste des éléves.
 */
class ListeEleveModel : public ListeElevesModel
{
    Q_OBJECT
protected:
    Classe m_classe;                            //!< Classe associé à la liste.
    QVector<MapPtr<CibleDonnee>> m_dataD;    //!< Ensemble des vecteurs de données sur les éléves.

public:
    //! Constructeur.
    ListeEleveModel(Bdd * bdd, const Classe &classe, QObject * parent = 0);

    //! Destructeur.
    ~ListeEleveModel()  {}

    //! Renvoie la donnée d'index et de role spécifié.
    QVariant dataPropre(const Indice &indice, int role) const;

    //! Insert de nouvelles colonnes.
    bool insertColumn(const Donnee & dn);

    //! Sauvegarde les données.
    void save();

    //! Modifie la donnée d'index et de role spécifié.
    bool setDataPropre(const Indice & indice, const QVariant & value, int role = Qt::EditRole);

    //! Tri les lignes suivant la colonne column.
    void sortPropre(int column, Qt::SortOrder order);
};

#endif // LISTEELEVEMODEL_H
