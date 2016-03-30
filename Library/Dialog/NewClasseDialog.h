#ifndef NEWCLASSEDIALOG_H
#define NEWCLASSEDIALOG_H

#include <QCheckBox>
#include <QComboBox>
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QMap>
#include <QMessageBox>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <stdexcept>

#include "../Entities/Annee.h"
#include "../Entities/Classe.h"
#include "../Entities/ListEntities.h"
#include "../Entities/Niveau.h"
#include "../Widget/SpinBoxAnnee.h"
#include "../Widget/SpinBoxNumClasse.h"

class NewClasseDialog : public QDialog
{
    Q_OBJECT
    struct dialogResult {
        Classe classe;
        int nbrEleve;
    };

protected:
    Annee m_annee;
    QVector<Classe> m_classe;

    QLabel *m_anneeLabel;
    QLabel *m_nbrEleveLabel;
    QLabel *m_nbrPhaseLabel;
    QLabel *m_niveauLabel;
    QLabel *m_numLabel;
    //QLabel *m_colleLabel;

    QCheckBox *m_colleCheckBox;
    QSpinBox *m_nbrEleveSpinBox;
    QSpinBox * m_nbrPhaseSpinBox;
    QComboBox *m_niveauComboBox;
    SpinBoxNumClasse *m_numSpinBox;

    QPushButton *m_cancelBouton;
    QPushButton *m_creerBouton;

    QHBoxLayout *m_hLayoutButton;
    QHBoxLayout *m_hLayoutNbrEleve;
    QHBoxLayout *m_hLayoutNbrPhase;
    QHBoxLayout *m_hLayoutNum;
    QVBoxLayout *m_vLayout;

public:
    explicit NewClasseDialog(QVector<Niveau> niveaux, const Annee &annee, QVector<Classe> classe, Classe::affichage alpha, QWidget *parent = 0);
    ~NewClasseDialog()  {}
    dialogResult value() const;
signals:

public slots:
    void niveauChangeNum(int);
};

#endif // NEWCLASSEDIALOG_H
