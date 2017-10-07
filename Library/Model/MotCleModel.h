/*Auteur: PERCIE DU SERT Maxime
 *Date: 17/09/2017
 */
#ifndef MOTCLEMODEL_H
#define MOTCLEMODEL_H

#include <QSet>
#include "TreeModelReadTemp.h"
#include "../Div/Bdd.h"
#include "../Entities/MotCle.h"

/*! \ingroup groupeModel
 * \brief Model de gestion des motcle.
 */
class MotCleModel : public TreeModelReadTemp<MotCle>
{
    Q_OBJECT
protected:
    enum {PasTous,TousJusquaPresent,Tous};
    Bdd * m_bdd;        //!< Pointeur vers la base de donnée.
    const int m_cible;  //!< Numero de cible du type d'entité pour les quels on souhaite gérer les mots clés.
    QSet<int> m_idSet;           //!< Ensemble des identifiants des entités dont les mots clés sont affichés.
    QMap<int,bool> m_idMotCle;  //!< Map dont les clés sont les identifiants des mots clés associés aux entités d'identifiant contenus dans m_idSet et de valeur true si le mot clé est associé à toutes les entités dont les identifiants sont contenus dans m_idSet et false sinon..

public:
    //! Constructeur.
    MotCleModel(Bdd *bd, int cible, QObject * parent);

    //! Renvoie la liste des mots clés associés aux entités dont d'identifiant est contenu dans m_idSet.
    QString dataListeNomMotCle() const;

    //! Mes à jour l'arbre des mots clès.
    void setTreeMotCle();

signals:
    void changedIdSet(QSet<int> IdSet);

public slots:
    //!< Mutateur de m_idEntityList, l'identifiant de l'entité pour laquelle sont affiché les mots clés.
    void setIdSet(const QSet<int> & idSet);

};

#endif // MOTCLEMODEL_H
