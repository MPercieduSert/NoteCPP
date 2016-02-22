#include "SelectAnneeDialog.h"

SelectAnneeDialog::SelectAnneeDialog(QVector<Annee> listeAnnee, QWidget *parent, bool creerAnnee) : QDialog(parent)
{
    m_label = new QLabel();
    m_creerBouton = new QPushButton(tr("Créer une nouvelle anneé"));
    m_cancelBouton = new QPushButton(tr("Annuler"));
    m_hLayout = new QHBoxLayout();
    m_vLayout = new QVBoxLayout(this);
    m_vLayout->addWidget(m_label);

    bool listeAnneeEmpty = listeAnnee.isEmpty();
    if(listeAnneeEmpty)
    {
        m_label->setText(tr("Aucune Annee disponible"));
        if(creerAnnee)
        {
            m_hLayout->addWidget(m_creerBouton);
        }
        m_hLayout->addWidget(m_cancelBouton);
        m_vLayout->addLayout(m_hLayout);
    }
    else
    {
        m_listBox = new QComboBox();
        m_okBouton = new QPushButton(tr("OK"));
        m_vLayout->addWidget(m_listBox);
        m_label->setText(tr("Choisir une anneé:"));
        for(QVector<Annee>::const_iterator i = listeAnnee.cbegin(); i != listeAnnee.cend(); ++i)
        {
            m_listBox->addItem((*i).affiche(),QVariant((*i).id()));;
        }
        m_listBox->setCurrentIndex(m_listBox->count()-1);
        m_hLayout->addWidget(m_okBouton);
        if(creerAnnee)
        {
            m_hLayout->addWidget(m_creerBouton);

        }
        m_hLayout->addWidget(m_cancelBouton);
        m_vLayout->addLayout(m_hLayout);
        connect(m_okBouton,&QPushButton::clicked,this,&QDialog::accept);
    }
    if(creerAnnee)
    {
        connect(m_creerBouton,&QPushButton::clicked,this,&SelectAnneeDialog::creerAnnee);
    }
    connect(m_cancelBouton,&QPushButton::clicked,this,&QDialog::reject);
}

int SelectAnneeDialog::value() const
{
    return m_listBox->currentData().toInt();
}

void SelectAnneeDialog::creerAnnee()
{
    reject();
    setResult(Creer);
}
