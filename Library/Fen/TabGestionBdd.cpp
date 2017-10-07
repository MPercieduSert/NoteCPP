#include "TabGestionBdd.h"

TabGestionBdd::TabGestionBdd(QSqlDatabase & bdd,int index, TabModule *parent) : TabAbstractModule(index,parent)
{
    m_listName = new QListWidget();
    m_stack = new QStackedWidget();
    //m_stack = new QStackedLayout();
    QMap<int,QString> nomAttributsBdd;
    DECL_TABLE_ENTITY(Annee)
    DECL_TABLE_ENTITY(CibleCommentaire)
    DECL_TABLE_ENTITY(CibleDonnee)
    DECL_TABLE_ENTITY(CibleMotCle)
    DECL_TABLE_ENTITY(CibleTexte)
    DECL_TABLE_ENTITY(Classe)
    DECL_TABLE_ENTITY(ClasseEleve)
    DECL_TABLE_ENTITY(Coefficient)
    DECL_TABLE_ENTITY(Commentaire)
    DECL_TABLE_ENTITY(Controle)
    DECL_TABLE_ENTITY(Cours)
    DECL_TABLE_ENTITY(Donnee)
    DECL_TABLE_ENTITY(DonneeCard)
    DECL_TABLE_ENTITY(Eleve)
    DECL_TABLE_ENTITY_NAME(Etablissement)
    DECL_TABLE_ENTITY(EtablissementNiveau)
    DECL_TABLE_ENTITY(EtablissementType)
    DECL_TABLE_ENTITY(Exercice)
    DECL_TABLE_ENTITY(Forme)
    DECL_TABLE_ENTITY(Groupe)
    DECL_TABLE_ENTITY(GroupeEleve)
    DECL_TABLE_ENTITY(MotCle)
    DECL_TABLE_ENTITY(MotClePermission)
    DECL_TABLE_ENTITY(Niveau)
    DECL_TABLE_ENTITY(NiveauPrecedent)
    DECL_TABLE_ENTITY(Note)
    DECL_TABLE_ENTITY_NAME(RestrictionModification)
    DECL_TABLE_ENTITY_NAME(Source)
    DECL_TABLE_ENTITY_NAME(Texte)
    DECL_TABLE_ENTITY(TexteSource)
    DECL_TABLE_ENTITY(TypeControle)
    DECL_TABLE_ENTITY(TypeCours)
    DECL_TABLE_ENTITY(TypeEtablissement)
    DECL_TABLE_ENTITY_NAME(TypeExercice)
    DECL_TABLE_ENTITY(TypeNiveau)
    DECL_TABLE_ENTITY_NAME(TypeUtilisation)
    DECL_TABLE_ENTITY(Utilisation)
    QStringList nomArbreAttributs;
    nomArbreAttributs<<"Id"<<"Parent"<<"Feuille"<<"Num";
    m_tables[ArbreCoursId].nom = "ArbreCours";
    m_tables[ArbreCoursId].nomBdd = InfoBdd<Cours>::tableArbre();
    m_tables[ArbreCoursId].nomAttributs = nomArbreAttributs;
    m_tables[ArbreDonneeId].nom = "ArbreDonnee";
    m_tables[ArbreDonneeId].nomBdd = InfoBdd<Donnee>::tableArbre();
    m_tables[ArbreDonneeId].nomAttributs = nomArbreAttributs;
    m_tables[ArbreExerciceId].nom = "ArbreExercice";
    m_tables[ArbreExerciceId].nomBdd = InfoBdd<Exercice>::tableArbre();
    m_tables[ArbreExerciceId].nomAttributs = nomArbreAttributs;
    m_tables[ArbreMotCleId].nom = "ArbreMotCle";
    m_tables[ArbreMotCleId].nomBdd = InfoBdd<MotCle>::tableArbre();
    m_tables[ArbreMotCleId].nomAttributs = nomArbreAttributs;
    for(Tables::iterator i = m_tables.begin(); i != m_tables.end(); ++i)
    {
        (*i).model = new QSqlTableModel(this,bdd);
        (*i).model->setTable((*i).nomBdd);
        (*i).model->setEditStrategy(QSqlTableModel::OnRowChange);
        (*i).model->select();
        for(int j = 0; j != (*i).nomAttributs.count(); ++j)
            (*i).model->setHeaderData(j,Qt::Horizontal,(*i).nomAttributs.at(j));
        (*i).view = new QTableView();
        (*i).view->setModel((*i).model);
        m_listName->addItem((*i).nom);
        //m_stack->addWidget((*i).view);
        QPushButton * insertButton = new QPushButton("Ajouter");
        QPushButton * supprButton = new QPushButton("Supprimer");
        connect(insertButton,&QPushButton::clicked,[i](){(*i).model->insertRow((*i).model->rowCount());});
        connect(supprButton,&QPushButton::clicked,[i]()
            {
                QModelIndexList indexList = (*i).view->selectionModel()->selectedRows();
                for(QModelIndexList::const_iterator j = indexList.cbegin(); j != indexList.cend(); ++j)
                    (*i).model->removeRow((*j).row());
            });
        QWidget * wdgt = new QWidget();
        QVBoxLayout * vLayout = new QVBoxLayout(wdgt);
        vLayout->addWidget((*i).view);
        vLayout->addWidget(insertButton);
        vLayout->addWidget(supprButton);
        vLayout->setContentsMargins(0,0,0,0);
        m_stack->addWidget(wdgt);
    }
    connect(m_listName,SIGNAL(currentRowChanged(int)),m_stack,SLOT(setCurrentIndex(int)));
    m_splitter = new QSplitter();
    m_splitter->addWidget(m_listName);
    m_splitter->addWidget(m_stack);
    //m_splitter->addWidget(m_stack);
    /*m_secondLayout = new QHBoxLayout();
    m_secondLayout->addWidget(m_listName);
    m_secondLayout->addWidget(m_stack);*/
    m_mainLayout->addWidget(m_splitter);
}
