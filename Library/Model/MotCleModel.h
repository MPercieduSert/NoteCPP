/*Auteur: PERCIE DU SERT Maxime
 *Date: 17/09/2017
 */
#ifndef MOTCLEMODEL_H
#define MOTCLEMODEL_H

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
    Bdd * m_bdd;        //!< Pointeur vers la base de donnée.
    const int m_cible;  //!< Numero de cible du type d'entité pour les quels on souhaite gérer les mots clés.
    QList<int> m_idEntityList;           //!< Identifiant de l'entité dont les mots clés sont affichés.
    QMap<int,int> m_idMotCleComp;  //!< Liste des identifiants des mots clés associés l'entité d'identifiant m_id.

public:
    //! Constructeur.
    MotCleModel(Bdd *bd, int cible, QObject * parent);

    //! Renvoie la liste des mots clés associés à l'entité d'identifiant m_id.
    QString dataListeNomMotCle() const;

    //! Mes à jour l'arbre des mots clès.
    void setTreeMotCle();

signals:
    void changedIdEntityList(QList<int> IdList);

public slots:
    //!< Mutateur de m_idEntityList, l'identifiant de l'entité pour laquelle sont affiché les mots clés.
    void setIdEntityList(const QList<int> & idEntityList);

};

#endif // MOTCLEMODEL_H
