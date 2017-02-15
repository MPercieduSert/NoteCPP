#include "TabListeEleve.h"

TabListeEleve::TabListeEleve(int idClasse, TabModule *parent) : TabAbstractClasse(idClasse,parent)
{
    if(m_classe.isValid())
    {
        m_delegate = new ListeEleveDelegate(m_annee,this);
        m_model = new ListeEleveModel(bdd(),m_classe,this);
        m_view = new QTableView();
        m_addColumnButton = new QPushButton(tr("Ajouter une nouvelle colonne au tableau"));
        m_saveButton = new QPushButton(tr("Sauvegarder"));

        m_view->setModel(m_model);
        m_view->setItemDelegate(m_delegate);
        m_view->setSelectionMode(QAbstractItemView::ExtendedSelection);
        connect(m_addColumnButton,&QPushButton::clicked,this,&TabListeEleve::addColumn);
        connect(m_saveButton,&QPushButton::clicked,this,&TabAbstractTableau::save);

        m_mainLayout->addWidget(m_view);
        m_mainLayout->addWidget(m_saveButton);
        m_mainLayout->addWidget(m_addColumnButton);
    }
}

void TabListeEleve::addColumn()
{
    Tree<Donnee> tree(bdd()->getArbre<Donnee>(1));
    SelectDonneeDialog dial(tree,this);
    dial.exec();
    Donnee dn(dial.result());
    if(bdd()->get(dn))
        ((ListeEleveModel *) m_model)->insertColumn(dn);
}

void TabListeEleve::becomeCurrent() const
{
    emit noyau()->collerPermis(true);
    emit noyau()->copierPermis(true);
    emit noyau()->couperPermis(true);
    emit noyau()->effacerPermis(true);
}
