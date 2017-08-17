#include "TabListeNote.h"

TabListeNote::TabListeNote(int idClasse, TabModule *parent) : TabAbstractClasse(idClasse,parent)
{
    if(m_classe.isValid())
    {
        m_delegate = new ListeNoteDelegate(this);
        m_model = new ListeNoteModel(bdd(),m_classe,this);
        m_view = new QTableView();
        m_header = new HeaderView(Qt::Horizontal);
        m_addColumnButton = new QPushButton(tr("Ajouter une nouvelle note"));
        m_saveButton = new QPushButton(tr("Sauvegarder"));

        m_header->setSectionsClickable(true);
        connect(m_header,SIGNAL(mouseClikedRight(int)),this,SLOT(openControleGraph(int)));
        m_view->setModel(m_model);
        m_view->setItemDelegate(m_delegate);
        m_view->setHorizontalHeader(m_header);
        m_view->setSelectionMode(QAbstractItemView::ExtendedSelection);
        m_view->setSortingEnabled(true);
        m_view->sortByColumn(0,Qt::AscendingOrder);
        connect(m_addColumnButton,&QPushButton::clicked,this,&TabListeNote::addColumn);
        connect(m_saveButton,&QPushButton::clicked,this,&TabAbstractTableau::save);

        m_mainLayout->addWidget(m_view);
        m_mainLayout->addWidget(m_saveButton);
        m_mainLayout->addWidget(m_addColumnButton);
    }
}

void TabListeNote::addColumn()
{
    Tree<TypeControleNum> tree(bdd()->getArbre<TypeControle>());
    for(TreeItem<TypeControleNum>::iterator i = tree.begin(); i != tree.end(); ++i)
    {
        int num = bdd()->fonctionAgrega<Controle, int>(bdd::Agrega::Max,Controle::Num,Controle::IdCl,m_classe.id(),Controle::IdTp,(*i)->data().id());
        (*i)->modifData().setNum(num);
    }
    NewControleDialog diag(tree,this);
    if(diag.exec())
    {
        NewControleDialog::dialogResult value = diag.value();
        if(value.creerType)
        {
            NewTypeControleDialog diagType(bdd()->getArbre<TypeControle>(),this);
            if(diagType.exec())
                bdd()->save(diagType.value());
            addColumn();
        }
        else
        {
            value.controle.setIdCl(m_classe.id());
            bdd()->save(value.controle);
            ListPtr<ClasseEleve> eleves = bdd()->getList<ClasseEleve>(ClasseEleve::IdCl,m_classe.id());
            for(ListPtr<ClasseEleve>::iterator i = eleves.begin(); i != eleves.end(); ++i)
            {
                Note note(value.controle.id(),(*i).idEl());
                bdd()->save(note);
                if(value.appreciation)
                    bdd()->save(CibleCommentaire(0,note.id(),bdd::cible::NoteCb,bdd::commentaireNum::AppreciationNum));
            }
            ((ListeNoteModel *) m_model)->insertColumn(value.controle);
        }
    }
}

void TabListeNote::becomeCurrent() const
{
    emit noyau()->collerPermis(true);
    emit noyau()->copierPermis(true);
    emit noyau()->couperPermis(true);
    emit noyau()->effacerPermis(true);
}

void TabListeNote::openControleGraph(int section)
{
    ControleGraphDialog diag(((ListeNoteModel *) m_model)->controle(section), ((ListeNoteModel *) m_model)->vectNotes(section), this);
    diag.exec();
}
