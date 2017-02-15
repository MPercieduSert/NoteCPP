#include "TabListeNote.h"

TabListeNote::TabListeNote(int idClasse, TabModule *parent) : TabAbstractClasse(idClasse,parent)
{
    if(m_classe.isValid())
    {
        m_delegate = new ListeNoteDelegate(this);
        m_model = new ListeNoteModel(bdd(),m_classe,this);
        m_view = new QTableView();
        m_addColumnButton = new QPushButton(tr("Ajouter une nouvelle note"));
        m_saveButton = new QPushButton(tr("Sauvegarder"));

        m_view->setModel(m_model);
        m_view->setItemDelegate(m_delegate);
        m_view->setSelectionMode(QAbstractItemView::ExtendedSelection);
        connect(m_addColumnButton,&QPushButton::clicked,this,&TabListeNote::addColumn);
        connect(m_saveButton,&QPushButton::clicked,this,&TabAbstractTableau::save);

        m_mainLayout->addWidget(m_view);
        m_mainLayout->addWidget(m_saveButton);
        m_mainLayout->addWidget(m_addColumnButton);
    }
}

void TabListeNote::addColumn()
{

}

void TabListeNote::becomeCurrent() const
{
    emit noyau()->collerPermis(true);
    emit noyau()->copierPermis(true);
    emit noyau()->couperPermis(true);
    emit noyau()->effacerPermis(true);
}
