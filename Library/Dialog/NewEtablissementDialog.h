/*Auteur: PERCIE DU SERT Maxime
 *Date: 02/06/2016
 */
#ifndef NEWETABLISSEMENTDIALOG_H
#define NEWETABLISSEMENTDIALOG_H

#include <QCheckBox>
#include <QDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSignalMapper>
#include <QVBoxLayout>

#include "../Entities/EntityOfDefaultType.h"
#include "../Entities/Niveau.h"
#include "../Entities/TypeEtablissement.h"
#include "../Div/VectorPtr.h"
#include "../Widget/SelectInListBox.h"


class NewEtablissementDialog : public QDialog
{
    Q_OBJECT
public:
    struct dialogResult {
        Etablissement etab;
        QVector<int> niveaux;
        QVector<int> types;
    };

protected:
    const int NbrChoixLine = 4;

    // Donnée
    VectorPtr<TypeEtablissement> m_vectTpEtab;     //! Liste des types d'établissements
    VectorPtr<Niveau> m_vectNiveau;                //! Liste des Niveaux

    // Widget

    QLabel *m_labelNc;              //! Nom Abrégé de l'établissement
    QLabel *m_labelNom;             //! Nom de l'établissement
    QLineEdit *m_lineNc;            //! Demande du nom abrégé de l'établissement
    QLineEdit *m_lineNom;          //! Demande du nom de l'établissement
    QPushButton *m_buttonCancel;    //! Bouton pour Annuler
    QPushButton *m_buttonCreer;     //! Bouton pour créer l'établissement
    SelectInListBox *m_selectListeClasse;  //! Selection des classe présente dans l'établisement

    QSignalMapper *m_signalChoixType;

    //Layout
    QGroupBox *m_groupChoixType;       //! Regroupe les choix des types de classe
    QVBoxLayout *m_layoutBouton;       //! Bouton créer et annuler
    QGridLayout *m_layoutChoixType;
    QHBoxLayout *m_layoutHaut;
    QVBoxLayout *m_layoutMain;
    QVBoxLayout *m_layoutNom;

public:
    //! Constructeur.
    explicit NewEtablissementDialog(const VectorPtr<TypeEtablissement> & vectTpEtab, const VectorPtr<Niveau> & vectNiveau, const QString & nc = QString(), const QString & nom = QString(), QWidget *parent = 0);

    //! Reourne le resultat de la fenêtre de dialogue.
    dialogResult value() const;

public slots:
    //! Ajoute à la liste de gauche les niveaux vérifiant idTpEtab == n.
    void boxCheckChange(int n);

};

#endif // NEWETABLISSEMENTDIALOG_H
