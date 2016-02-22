#include "NewAnneeDialog.h"

NewAnneeDialog::NewAnneeDialog(QWidget *parent): QDialog(parent)
{
    m_label = new QLabel(tr("Choix de l'année à creer"));
    m_box = new SpinBoxAnnee();
    m_check = new QCheckBox("Nouvelle année de travail");
    m_check->setChecked(true);
    m_creerBouton = new QPushButton(tr("Créer"));
    m_cancelBouton = new QPushButton(tr("Annuler"));
    m_hLayout = new QHBoxLayout();
    m_hLayout->addWidget(m_creerBouton);
    m_hLayout->addWidget(m_cancelBouton);
    m_vLayout = new QVBoxLayout(this);
    m_vLayout->addWidget(m_label);
    m_vLayout->addWidget(m_box);
    m_vLayout->addWidget(m_check);
    m_vLayout->addLayout(m_hLayout);

    connect(m_creerBouton,&QPushButton::clicked,this,&NewAnneeDialog::accept);
    connect(m_cancelBouton,&QPushButton::clicked,this,&NewAnneeDialog::reject);
}

void NewAnneeDialog::accept()
{
    QDialog::accept();
    setResult(m_box->value());
}

bool NewAnneeDialog::isChecked() const
{
    return m_check->isChecked();
}
