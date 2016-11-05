#include "Bdd.h"

/*QString Bdd::afficheClasse(const Classe & classe, Classe::affichage alpha)
{
    Niveau niveau(classe.idNiv());
    get(niveau);
    QString string(niveau.nom());
    if(classe.num() != 0)
    {
        switch (alpha)
        {
        case Classe::Sans:
            break;
        case Classe::Numeric:
            string.append(QString::number(classe.num()));
            break;
        case Classe::AlphabeticMaj:
            if(0 < classe.num() && classe.num() < 27)
            {
                string.append(QString("ABCDEFGHIJKLMOPQRSTUVWXYZ").at(classe.num()-1));
            }
            break;
        case Classe::AlphabeticMin:
            if(0 < classe.num() && classe.num() < 27)
            {
                string.append(QString("abcdefghijklmopqrstuvwxyz").at(classe.num()-1));
            }
            break;
        }
    }
    return string;
}*/

void Bdd::listeMiseAJourBdd(int version)
{
    switch (version) {
    case bdd::miseAJourBdd::creationInitial:
    {
        m_manager.get<Annee>().creer();
        m_manager.get<Attribut>().creer();
        m_manager.get<AttributCommentaire>().creer();
        m_manager.get<Classe>().creer();
        m_manager.get<ClasseEleve>().creer();
        m_manager.get<Commentaire>().creer();
        m_manager.get<CommentaireClasse>().creer();
        m_manager.get<CommentaireEleve>().creer();
        m_manager.get<CommentaireGroupe>().creer();
        m_manager.get<Donnee>().creer();
        m_manager.get<DonneeClasse>().creer();
        m_manager.get<DonneeEleve>().creer();
        m_manager.get<DonneeEtablissement>().creer();
        m_manager.get<DonneeNiveau>().creer();
        m_manager.get<DonneeSource>().creer();
        m_manager.get<Eleve>().creer();
        m_manager.get<Etablissement>().creer();
        m_manager.get<EtablissementType>().creer();
        m_manager.get<EtablissementNiveau>().creer();
        m_manager.get<Groupe>().creer();
        m_manager.get<GroupeEleve>().creer();
        m_manager.get<Niveau>().creer();
        m_manager.get<NiveauPrecedent>().creer();
        m_manager.get<Source>().creer();
        m_manager.get<TypeEtablissement>().creer();
        m_manager.get<TypeNiveau>().creer();

        m_manager.saveVersion(bdd::miseAJourBdd::creationTable20160527);
        break;
    }
    case bdd::miseAJourBdd::creationTable20160527:
    {
        TypeEtablissement primaire(-7,-11,"Primaire");
        TypeEtablissement college(-3,-6,"Collège");
        TypeEtablissement lyceeGeneral(0,-2,"Lycée général");
        TypeEtablissement lyceePro(0,-2,"Lycée professionel");
        TypeEtablissement prepa(2,1,"Classe préparatoire");
        TypeEtablissement Universite(15,1,"Université");
        TypeEtablissement iut(2,1,"IUT");
        TypeEtablissement ecoleIng(8,1,"Ecole d'ingénieure");

        save(primaire);
        save(college);
        save(lyceeGeneral);
        save(lyceePro);
        save(Universite);
        save(iut);
        save(prepa);
        save(ecoleIng);

        TypeNiveau cp(-11,"CP");
        TypeNiveau ce1(-10,"CE1");
        TypeNiveau ce2(-9,"CE2");
        TypeNiveau cm1(-8,"CM1");
        TypeNiveau cm2(-7,"CM2");
        TypeNiveau six(-6,"Sixième");
        TypeNiveau cinq(-5,"Cinquième");
        TypeNiveau quatre(-4,"Quatrième");
        TypeNiveau trois(-3,"Troisième");
        TypeNiveau deux(-2,"Seconde");
        TypeNiveau un(-1,"Première");
        TypeNiveau ter(0,"Terminale");
        TypeNiveau l1(1,"Licence 1");
        TypeNiveau l2(2,"Licence 2");
        TypeNiveau l3(3,"Licence 3");
        TypeNiveau m1(4,"Master 1");
        TypeNiveau m2(5,"Master2");
        TypeNiveau these(8,"Doctorat");
        TypeNiveau sup(1,"Prépa Science sup");
        TypeNiveau spe(2,"Prépa Science spé");

        save(cp);
        save(ce1);
        save(ce2);
        save(cm1);
        save(cm2);
        save(six);
        save(cinq);
        save(quatre);
        save(trois);
        save(deux);
        save(un);
        save(ter);
        save(l1);
        save(l2);
        save(l3);
        save(m1);
        save(m2);
        save(these);
        save(sup);
        save(spe);

        Niveau Cp(cp.id(),primaire.id(),"CP","CP");
        Niveau Ce1(ce1.id(),primaire.id(),"CE1","CE1");
        Niveau Ce2(ce2.id(),primaire.id(),"CE2","CE2");
        Niveau Cm1(cm1.id(),primaire.id(),"CM1","CM1");
        Niveau Cm2(cm2.id(),primaire.id(),"CM2","CM2");
        Niveau Six(six.id(),college.id(),"6ème","Sixième");
        Niveau Cinq(cinq.id(),college.id(),"5ème","Cinquième");
        Niveau Quatre(quatre.id(),college.id(),"4ème","Quatrième");
        Niveau Trois(trois.id(),college.id(),"3ème","Troisième");
        Niveau deuxG(deux.id(),lyceeGeneral.id(),"2nd","Seconde Générale");
        Niveau unS(un.id(),lyceeGeneral.id(),"1er S","Première scientifique");
        Niveau unES(un.id(),lyceeGeneral.id(),"1er ES","Première économique et sociale");
        Niveau unL(un.id(),lyceeGeneral.id(),"1er L","Première littéraire");
        Niveau terS(ter.id(),lyceeGeneral.id(),"TS","Terminale scientifique");
        Niveau terES(ter.id(),lyceeGeneral.id(),"TS","Terminale économique et sociale");
        Niveau terL(ter.id(),lyceeGeneral.id(),"TL","Terminale littéraire");
        Niveau deuxPro(deux.id(),lyceePro.id(),"2nd","Seconde Professionelle");
        Niveau unPro(un.id(),lyceePro.id(),"1er","Première professionelle");
        Niveau terPro(ter.id(),lyceePro.id(),"T","Terminale professionelle");
        Niveau mpsi(sup.id(),prepa.id(),"MPSI","MPSI");
        Niveau pcsi(sup.id(),prepa.id(),"PCSI","PCSI");
        Niveau ptsi(sup.id(),prepa.id(),"PTSI","PTSI");
        Niveau bcpst1(sup.id(),prepa.id(),"BCPST1","BCPST1");
        Niveau mp(spe.id(),prepa.id(),"MP","MP");
        Niveau pc(spe.id(),prepa.id(),"PC","PC");
        Niveau psi(spe.id(),prepa.id(),"PSI","PSI");
        Niveau pt(spe.id(),prepa.id(),"PT","PT");
        Niveau bcpst2(spe.id(),prepa.id(),"BCPST2","BCPST2");

        save(Cp);
        save(Ce1);
        save(Ce2);
        save(Cm1);
        save(Cm2);
        save(Six);
        save(Cinq);
        save(Quatre);
        save(Trois);
        save(deuxG);
        save(unS);
        save(unES);
        save(unL);
        save(terS);
        save(terES);
        save(terL);
        save(deuxPro);
        save(unPro);
        save(terPro);
        save(mpsi);
        save(pcsi);
        save(ptsi);
        save(bcpst1);
        save(mp);
        save(pc);
        save(psi);
        save(pt);
        save(bcpst2);

        save(NiveauPrecedent(Cp.id(),Ce1.id()));
        save(NiveauPrecedent(Ce1.id(),Ce2.id()));
        save(NiveauPrecedent(Ce2.id(),Cm1.id()));
        save(NiveauPrecedent(Cm1.id(),Cm2.id()));
        save(NiveauPrecedent(Cm2.id(),Six.id()));
        save(NiveauPrecedent(Six.id(),Cinq.id()));
        save(NiveauPrecedent(Cinq.id(),Quatre.id()));
        save(NiveauPrecedent(Quatre.id(),Trois.id()));
        save(NiveauPrecedent(Trois.id(),deuxG.id()));
        save(NiveauPrecedent(deuxG.id(),unS.id()));
        save(NiveauPrecedent(deuxG.id(),unES.id()));
        save(NiveauPrecedent(deuxG.id(),unL.id()));
        save(NiveauPrecedent(unS.id(),terS.id()));
        save(NiveauPrecedent(unES.id(),terES.id()));
        save(NiveauPrecedent(unL.id(),terL.id()));
        save(NiveauPrecedent(Trois.id(),deuxPro.id()));
        save(NiveauPrecedent(deuxPro.id(),unPro.id()));
        save(NiveauPrecedent(unPro.id(),terPro.id()));
        save(NiveauPrecedent(terS.id(),mpsi.id()));
        save(NiveauPrecedent(terS.id(),pcsi.id()));
        save(NiveauPrecedent(terS.id(),ptsi.id()));
        save(NiveauPrecedent(terS.id(),bcpst1.id()));
        save(NiveauPrecedent(mpsi.id(),mp.id()));
        save(NiveauPrecedent(pcsi.id(),pc.id()));
        save(NiveauPrecedent(mpsi.id(),psi.id()));
        save(NiveauPrecedent(pcsi.id(),psi.id()));
        save(NiveauPrecedent(ptsi.id(),psi.id()));
        save(NiveauPrecedent(ptsi.id(),pt.id()));
        save(NiveauPrecedent(bcpst1.id(),bcpst2.id()));

        Tree<Donnee> arbre;
        arbre.root()->setData(Donnee(false,"Contact",Donnee::Perso,Donnee::NoDonnee,0,Donnee::prog::Contact));
        TreeItem<Donnee> * adr = arbre.root()->addChild(Donnee(false,"Adresse",Donnee::Perso,Donnee::NoDonnee,0,Donnee::prog::Adresse));
        adr->addChild(Donnee(false,"Numero de rue",Donnee::Perso,Donnee::String,0,Donnee::prog::NbrRue));
        adr->addChild(Donnee(false,"Rue",Donnee::Perso,Donnee::String,0,Donnee::prog::Rue));
        adr->addChild(Donnee(false,"Code Postal",Donnee::Perso,Donnee::String,0,Donnee::prog::CodePostal));
        adr->addChild(Donnee(false,"Ville",Donnee::Perso,Donnee::String,0,Donnee::prog::Ville));
        adr->addChild(Donnee(false,"Pays",Donnee::Perso,Donnee::String,0,Donnee::prog::Pays));
        arbre.root()->addChild(Donnee(false,"Teléphone",Donnee::Perso,Donnee::String,0,Donnee::prog::Tel));
        arbre.root()->addChild(Donnee(false,"Mail",Donnee::Perso,Donnee::String,0,Donnee::prog::Mail));
        save(arbre, bdd::TreeSave::AddLeaf);

        m_manager.saveVersion(bdd::miseAJourBdd::Donnees20160527);
        break;
    }
    default:
        throw std::invalid_argument(QString("Aucune mise à jour ne correspond à la version :").append(QString::number(version)).toStdString());
        break;
    }
}
