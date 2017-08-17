#include "Noyau.h"
#include "../Fen/TabModule.h"
#include "../Fen/TabAbstractModule.h"

Noyau::Noyau(const QString & path, QWidget *parent = 0) :
    QObject(parent),
    m_bdd("QSQLITE"),
    m_config(path+"/confFile.xml"),
    m_parent(parent)
{
    //! + Ouverture du fichier de configuration.
    FenFoundFile fenConfig(&m_config,m_parent);
    fenConfig.exists();
    fenConfig.isValid();

    //!  + Ouverture de la base de donnée.
    m_bdd.setFileName(m_config.getVars(DEFAULT_DIRECTORY));
    FenFoundFile fenBdd(&m_bdd,m_parent);
    fenBdd.openInConf(config(),DATA_BASE);
    //m_bdd.miseAJour();

    //! + Selection de l'année courante
    QString strDiagAn;
    Annee annee;
    if(m_config.varExists(DEFAULT_ANNEE))
    {
        annee.setAn(m_config.getVars(DEFAULT_ANNEE).toInt());
        if(annee.an() != 0 && !m_bdd.getUnique(annee))
        {
            strDiagAn = tr("L'année par défaut enregistrée dans le fichier de configuration n'existe pas. "
                           "Vous devez selectionner une année par défaut ou en créer une.");
        }
    }
    else
    {
        strDiagAn = tr("Aucune année par défaut n'est enregistrée dans le fichier de configuration. "
                       "Vous devez selectionner une année par défaut ou en créer une.");
    }
    if(!strDiagAn.isEmpty())
    {
        QMessageBox::critical(m_parent,tr("Année par défaut invalide"),strDiagAn);
        annee = selectAnnee(parent,Annee(0,0), false, true, true);
        m_config.add(DEFAULT_ANNEE,QString::number(annee.an()));
    }

    setAnnee(annee);

    m_tabModule = new TabModule(parent,this);
}

TabAbstractModule * Noyau::activeTab() const
{
    return qobject_cast<TabAbstractModule *>(m_tabModule->currentWidget());
}

QWidget * Noyau::centralZone()
    {return m_tabModule;}

void Noyau::coller()
    {activeTab()->coller();}

void Noyau::couper()
    {activeTab()->couper();}

void Noyau::copier()
    {activeTab()->copier();}

void Noyau::creerAnnee(QWidget * parent)
{
    NewAnneeDialog diag(parent);
    diag.exec();
    int n = diag.result();
    if(n > 0)
    {
        Annee annee(n,0);
        if(m_bdd.existsUnique(annee))
        {
            QMessageBox::critical(parent,"Erreur année","L'année "+annee.affiche()+" existe déjà.");
        }
        else
        {
            m_bdd.save(annee);
        }
    }
}

void Noyau::creerClasse(QWidget *parent)
{
    NewClasseDialog dial(m_anneeDefaut,
                         m_bdd.getVector<Etablissement>(),
                         m_bdd.getVector<EtablissementNiveau>(),
                         m_bdd.getVector<Niveau>(),
                         m_bdd.getVector<Classe>(),
                         parent);
    if(dial.exec() == QDialog::Accepted)
    {
        NewClasseDialog::dialogResult value = dial.value();
        if(value.classe.id() == NewClasseDialog::dialogResult::CreerEtab)
        {
            creerEtablissement(parent);
            creerClasse(parent);
        }
        else
        {
            Classe classe(dial.value().classe);
            m_bdd.save(classe);
            for(int i = 0; i != dial.value().nbrEleve; ++i)
            {
                Eleve eleve(true,
                      QDate(2000,1,1),
                      QString::number(i)+"nom_classe"+QString::number(classe.id()),
                      QString::number(i)+"prenom_classe"+QString::number(classe.id()));
                m_bdd.save(eleve);
                m_bdd.save(ClasseEleve(classe.id(),eleve.id(),value.entree));
            }
        }
    }
}

void Noyau::creerEtablissement(QWidget * parent, const QString & nc, const QString & nom)
{
    NewEtablissementDialog dial(m_bdd.getVector<TypeEtablissement>(), m_bdd.getVector<Niveau>(),nc,nom,parent);
    if(dial.exec() == QDialog::Accepted)
    {
        NewEtablissementDialog::dialogResult result = dial.value();
        if(!result.etab.isValid())
        {
            QMessageBox::critical(parent,tr("Entrée invalide"),tr("Le nom et le nom abrégé de l'établissement doivent être entrés"));
            creerEtablissement(parent,result.etab.nc(),result.etab.nom());
        }
        else if(m_bdd.existsUnique(result.etab))
        {
            QMessageBox::critical(parent,tr("Entrée invalide"),tr("Un établissement de même non existe déjà dans la base de donnée"));
            creerEtablissement(parent,result.etab.nc(),result.etab.nom());
        }
        else
        {
            m_bdd.save(result.etab);
            for(QVector<int>::iterator i = result.types.begin(); i != result.types.end(); ++i)
                m_bdd.save(EtablissementType(result.etab.id(),*i));
            for(QVector<int>::iterator i = result.niveaux.begin(); i != result.niveaux.end(); ++i)
                m_bdd.save(EtablissementNiveau(result.etab.id(),*i));
            m_bdd.save(CibleDonnee(m_bdd.idDonnee(Donnee::prog::CodePostal),result.etab.id(),bdd::cible::EtablissementCb,
                                   0,QVariant(result.donnee.at(NewEtablissementDialog::CodePostalInd))));
            m_bdd.save(CibleDonnee(m_bdd.idDonnee(Donnee::prog::NumRue),result.etab.id(),bdd::cible::EtablissementCb,
                                   0,QVariant(result.donnee.at(NewEtablissementDialog::NumRueInd))));
            m_bdd.save(CibleDonnee(m_bdd.idDonnee(Donnee::prog::Pays),result.etab.id(),bdd::cible::EtablissementCb,
                                   0,QVariant(result.donnee.at(NewEtablissementDialog::PaysInd))));
            m_bdd.save(CibleDonnee(m_bdd.idDonnee(Donnee::prog::Rue),result.etab.id(),bdd::cible::EtablissementCb,
                                   0,QVariant(result.donnee.at(NewEtablissementDialog::RueInd))));
            m_bdd.save(CibleDonnee(m_bdd.idDonnee(Donnee::prog::Ville),result.etab.id(),bdd::cible::EtablissementCb,
                                   0,QVariant(result.donnee.at(NewEtablissementDialog::VilleInd))));
        }
    }
}

void Noyau::effacer()
    {activeTab()->effacer();}

void Noyau::save()
    {activeTab()->save();}

Annee Noyau::selectAnnee(QWidget *parent, Annee preSelect, bool annule, bool creer, bool vide)
{
    VectorPtr<Annee> vecAnnee(m_bdd.getList<Annee>(Annee::An));
    if(vide)
    {
        vecAnnee.append(Annee(0,0));
    }
    SelectAnneeDialog diag(vecAnnee,parent,preSelect.id(),annule,creer);
    diag.exec();
    if(diag.result() > 0)
    {
        Annee an(diag.result());
        m_bdd.get(an);
        return an;
    }
    if(diag.result() == 0)
        {return Annee(0,0);}
    if(creer && diag.result() == SelectAnneeDialog::Creer)
    {
        NewAnneeDialog diagNew(parent);
        diagNew.exec();
        if(diagNew.result() > 0)
        {
            Annee an(diagNew.result(),0);
            if(!m_bdd.existsUnique(an))
                m_bdd.save(an);
            else
                m_bdd.getUnique(an);
            return selectAnnee(parent,an, annule, creer, vide);
        }
        else
        {return selectAnnee(parent,preSelect, annule, creer, vide);}
    }
    else
        {return Annee(-1);}
}


void Noyau::selectDefaultAnnee(QWidget * parent)
{
    Annee an(selectAnnee(parent,m_anneeDefaut,true,true,true));
    if(an.id() >= 0)
    {
        setAnnee(an);
        m_config.modify(DEFAULT_ANNEE,QString::number(m_anneeDefaut.an()));
    }
}

void Noyau::setAnnee(const Annee & an)
{
    if(an.an() == 0)
    {
        m_anneeDefaut = an;
        emit creerClassePermis(false);
    }
    else if(an.isValid())
    {
        m_anneeDefaut = an;
        emit creerClassePermis(true);
    }
}
