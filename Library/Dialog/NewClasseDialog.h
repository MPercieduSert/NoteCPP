#ifndef NEWCLASSEDIALOG_H
#define NEWCLASSEDIALOG_H

#include <QCheckBox>
#include <QComboBox>
#include <QDialog>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMap>
#include <QMessageBox>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <stdexcept>

#include "../Entities/Annee.h"
#include "../Entities/Classe.h"
#include "../Entities/InfoEntity.h"
#include "../Entities/Niveau.h"
#include "../Entities/EntityOfDefaultType.h"
#include "../Entities/VectorEntities.h"
#include "../Widget/SpinBoxAnnee.h"
#include "../Widget/SpinBoxNumClasse.h"

class NewClasseDialog : public QDialog
{
    Q_OBJECT
public:
    struct dialogResult {
        enum button {creerEtab = -1};
        Classe classe;
        int nbrEleve;
    };

protected:
    // Donnée
    Annee m_annee;
    VectorEntities<Classe> m_classes;
    bool m_creerEtab;
    VectorEntities<Etablissement> m_etabs;
    VectorEntities<EtablissementNiveau> m_etabNiveaux;
    VectorEntities<Niveau> m_niveaux;

    // Label
    QLabel *m_anneeLabel;
    QLabel *m_nameLabel;
    QLabel *m_nbrEleveLabel;
    //QLabel *m_nbrPhaseLabel;
    QLabel *m_niveauLabel;
    QLabel *m_numLabel;
    //QLabel *m_colleLabel;

    QLineEdit *m_nameLine;
    //QCheckBox *m_colleCheckBox;
    QSpinBox *m_nbrEleveSpinBox;
    //QSpinBox * m_nbrPhaseSpinBox;
    QComboBox *m_etabComboBox;
    QComboBox *m_niveauComboBox;
    SpinBoxNumClasse *m_numSpinBox;

    // Bouton
    QPushButton *m_cancelBouton;
    QPushButton *m_creerBouton;
    QPushButton *m_creerEtabBouton;

    // Layout
    QGroupBox *m_groupePara;
    QGroupBox *m_groupeEtab;
    QHBoxLayout *m_hLayoutButton;
    QHBoxLayout *m_hLayoutEtab;
    QGridLayout *m_gridLayout;
    QVBoxLayout *m_vLayout;

public:
    explicit NewClasseDialog(const Annee &annee, VectorEntities<Etablissement> etabs, VectorEntities<EtablissementNiveau> etabNiveaux, VectorEntities<Niveau> niveaux,  VectorEntities<Classe> classes, QWidget *parent = 0);
    ~NewClasseDialog()  {}
    dialogResult value() const;
signals:

public slots:
    void creerEtab();
    void etabChange(int n);
    void nameUpdate(int num);
    void niveauChange(int n);
};

#endif // NEWCLASSEDIALOG_H
