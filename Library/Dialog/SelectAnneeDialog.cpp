#include "SelectAnneeDialog.h"

SelectAnneeDialog::SelectAnneeDialog(const VectorPtr<Annee> &listeAnnee, QWidget *parent, int idDefault, bool AnnuleButton, bool creerAnnee) : QDialog(parent)
{
    m_label = new QLabel();
    m_creerBouton = new QPushButton(tr("Créer une nouvelle année"));
    m_cancelBouton = new QPushButton(tr("Annuler"));
    m_hLayout = new QHBoxLayout();
    m_vLayout = new QVBoxLayout(this);
    m_vLayout->addWidget(m_label);

    bool listeAnneeEmpty = listeAnnee.isEmpty();
    if(listeAnneeEmpty)
    {
        m_label->setText(tr("Aucune Annee disponible"));
        if(creerAnnee)
            {m_hLayout->addWidget(m_creerBouton);}
        if(AnnuleButton)
            {m_hLayout->addWidget(m_cancelBouton);}
        m_vLayout->addLayout(m_hLayout);
    }
    else
    {
        m_listBox = new QComboBox();
        m_okBouton = new QPushButton(tr("OK"));
        m_vLayout->addWidget(m_listBox);
        m_label->setText(tr("Choisir une anneé:"));

        int index = 0;
        int indexDefault = -1;
        for(VectorPtr<Annee>::iterator i = listeAnnee.cbegin(); i != listeAnnee.cend(); ++i, ++index)
        {
            m_listBox->addItem((*i).affiche(),QVariant((*i).id()));
            if((*i).id() == idDefault)
                {indexDefault = index;}
        }
        if(indexDefault < 0)
            {m_listBox->setCurrentIndex(m_listBox->count()-1);}
        else
            {m_listBox->setCurrentIndex(indexDefault);}

        m_hLayout->addWidget(m_okBouton);
        if(creerAnnee)
            {m_hLayout->addWidget(m_creerBouton);}
        if(AnnuleButton)
            {m_hLayout->addWidget(m_cancelBouton);}
        m_vLayout->addLayout(m_hLayout);
        connect(m_okBouton,&QPushButton::clicked,this,&QDialog::accept);
    }
    if(creerAnnee)
        {connect(m_creerBouton,&QPushButton::clicked,this,&SelectAnneeDialog::creerClick);}
    if(AnnuleButton)
        {connect(m_cancelBouton,&QPushButton::clicked,this,&SelectAnneeDialog::reject);}
}

void SelectAnneeDialog::accept()
{
    QDialog::accept();
    setResult(m_listBox->currentData().toInt());

}

void SelectAnneeDialog::creerClick()
{
    QDialog::reject();
    setResult(Creer);
}

void SelectAnneeDialog::reject()
{
    QDialog::reject();
    setResult(Annuler);
}
