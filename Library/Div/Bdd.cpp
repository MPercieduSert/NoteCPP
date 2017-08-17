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

 int Bdd::idDonnee(typename Donnee::prog idP)
 {
     Donnee dn(idP,0);
     getUnique(dn);
     return dn.id();
 }

void Bdd::listeMiseAJourBdd(int version)
{
    switch (version) {
    case bdd::miseAJourBdd::creationInitial:
    {
        // création des tables
        m_manager.get<Annee>().creer();
        m_manager.get<CibleCommentaire>().creer();
        m_manager.get<CibleDonnee>().creer();
        m_manager.get<CibleMotCle>().creer();
        m_manager.get<Classe>().creer();
        m_manager.get<ClasseEleve>().creer();
        m_manager.get<Coefficient>().creer();
        m_manager.get<Commentaire>().creer();
        m_manager.get<Controle>().creer();
        m_manager.get<Donnee>().creer();
        m_manager.get<DonneeCard>().creer();
        m_manager.get<Eleve>().creer();
        m_manager.get<Etablissement>().creer();
        m_manager.get<EtablissementNiveau>().creer();
        m_manager.get<EtablissementType>().creer();
        m_manager.get<Groupe>().creer();
        m_manager.get<GroupeEleve>().creer();
        m_manager.get<MotCle>().creer();
        m_manager.get<MotClePermission>().creer();
        m_manager.get<Niveau>().creer();
        m_manager.get<NiveauPrecedent>().creer();
        m_manager.get<Note>().creer();
        m_manager.get<RestrictionModification>().creer();
        m_manager.get<Source>().creer();
        m_manager.get<TypeControle>().creer();
        m_manager.get<TypeEtablissement>().creer();
        m_manager.get<TypeNiveau>().creer();

        // Types d'établissement
        TypeEtablissement primaire(-7,-11,"Primaire");
        TypeEtablissement college(-3,-6,"Collège");
        TypeEtablissement lyceeGeneral(0,-2,"Lycée général");
        TypeEtablissement lyceePro(0,-2,"Lycée professionel");
        TypeEtablissement prepa(2,1,"Classe préparatoire");
        TypeEtablissement Universite(15,1,"Université");
        TypeEtablissement iut(2,1,"IUT");
        TypeEtablissement ecoleIng(8,1,"Ecole d'ingénieure");

        QList<bdd::Autorisation> rien({bdd::Modif,bdd::Suppr});
        save(primaire,rien);
        save(college,rien);
        save(lyceeGeneral,rien);
        save(lyceePro,rien);
        save(Universite,rien);
        save(iut,rien);
        save(prepa,rien);
        save(ecoleIng,rien);

        // Types de Niveau
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

        save(cp,rien);
        save(ce1,rien);
        save(ce2,rien);
        save(cm1,rien);
        save(cm2,rien);
        save(six,rien);
        save(cinq,rien);
        save(quatre,rien);
        save(trois,rien);
        save(deux,rien);
        save(un,rien);
        save(ter,rien);
        save(l1,rien);
        save(l2,rien);
        save(l3,rien);
        save(m1,rien);
        save(m2,rien);
        save(these,rien);
        save(sup,rien);
        save(spe,rien);

        // Niveaux
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

        save(Cp,rien);
        save(Ce1,rien);
        save(Ce2,rien);
        save(Cm1,rien);
        save(Cm2,rien);
        save(Six,rien);
        save(Cinq,rien);
        save(Quatre,rien);
        save(Trois,rien);
        save(deuxG,rien);
        save(unS,rien);
        save(unES,rien);
        save(unL,rien);
        save(terS,rien);
        save(terES,rien);
        save(terL,rien);
        save(deuxPro,rien);
        save(unPro,rien);
        save(terPro,rien);
        save(mpsi,rien);
        save(pcsi,rien);
        save(ptsi,rien);
        save(bcpst1,rien);
        save(mp,rien);
        save(pc,rien);
        save(psi,rien);
        save(pt,rien);
        save(bcpst2,rien);

        // Liens entre les niveaux
        save(NiveauPrecedent(Cp.id(),Ce1.id()),rien);
        save(NiveauPrecedent(Ce1.id(),Ce2.id()),rien);
        save(NiveauPrecedent(Ce2.id(),Cm1.id()),rien);
        save(NiveauPrecedent(Cm1.id(),Cm2.id()),rien);
        save(NiveauPrecedent(Cm2.id(),Six.id()),rien);
        save(NiveauPrecedent(Six.id(),Cinq.id()),rien);
        save(NiveauPrecedent(Cinq.id(),Quatre.id()),rien);
        save(NiveauPrecedent(Quatre.id(),Trois.id()),rien);
        save(NiveauPrecedent(Trois.id(),deuxG.id()),rien);
        save(NiveauPrecedent(deuxG.id(),unS.id()),rien);
        save(NiveauPrecedent(deuxG.id(),unES.id()),rien);
        save(NiveauPrecedent(deuxG.id(),unL.id()),rien);
        save(NiveauPrecedent(unS.id(),terS.id()),rien);
        save(NiveauPrecedent(unES.id(),terES.id()),rien);
        save(NiveauPrecedent(unL.id(),terL.id()),rien);
        save(NiveauPrecedent(Trois.id(),deuxPro.id()),rien);
        save(NiveauPrecedent(deuxPro.id(),unPro.id()),rien);
        save(NiveauPrecedent(unPro.id(),terPro.id()),rien);
        save(NiveauPrecedent(terS.id(),mpsi.id()),rien);
        save(NiveauPrecedent(terS.id(),pcsi.id()),rien);
        save(NiveauPrecedent(terS.id(),ptsi.id()),rien);
        save(NiveauPrecedent(terS.id(),bcpst1.id()),rien);
        save(NiveauPrecedent(mpsi.id(),mp.id()),rien);
        save(NiveauPrecedent(pcsi.id(),pc.id()),rien);
        save(NiveauPrecedent(mpsi.id(),psi.id()),rien);
        save(NiveauPrecedent(pcsi.id(),psi.id()),rien);
        save(NiveauPrecedent(ptsi.id(),psi.id()),rien);
        save(NiveauPrecedent(ptsi.id(),pt.id()),rien);
        save(NiveauPrecedent(bcpst1.id(),bcpst2.id()),rien);

        // Donnée de contacts
        Tree<Donnee> arbre;
        arbre.root()->setData(Donnee("Contact",Donnee::Perso,Donnee::NoDonnee,Donnee::prog::Contact));
        TreeItem<Donnee> * adr = arbre.root()->addChild(Donnee("Adresse",Donnee::Perso,Donnee::NoDonnee,Donnee::prog::Adresse));
        TreeItem<Donnee> * adrNuRue = adr->addChild(Donnee("Numero de rue",Donnee::Perso,Donnee::String,Donnee::prog::NumRue));
        TreeItem<Donnee> * adrRue = adr->addChild(Donnee("Rue",Donnee::Perso,Donnee::String,Donnee::prog::Rue));
        TreeItem<Donnee> * adrCP = adr->addChild(Donnee("Code Postal",Donnee::Perso,Donnee::Int,Donnee::prog::CodePostal));
        TreeItem<Donnee> * adrVille =adr->addChild(Donnee("Ville",Donnee::Perso,Donnee::String,Donnee::prog::Ville));
        TreeItem<Donnee> * adrPays =adr->addChild(Donnee("Pays",Donnee::Perso,Donnee::String,Donnee::prog::Pays));
        TreeItem<Donnee> * tel = arbre.root()->addChild(Donnee("Teléphone",Donnee::Perso,Donnee::String,Donnee::prog::Tel));
        TreeItem<Donnee> * mail = arbre.root()->addChild(Donnee("Mail",Donnee::Perso,Donnee::String,Donnee::prog::Mail));
        save(arbre, bdd::TreeSave::AddLeaf);
        setRestriction(arbre,rien);

        save(DonneeCard(adrNuRue->data().id(),DonneeCard::cardinal::Infini,false,bdd::cible::EleveCb),rien);
        save(DonneeCard(adrRue->data().id(),DonneeCard::cardinal::Infini,false,bdd::cible::EleveCb),rien);
        save(DonneeCard(adrCP->data().id(),DonneeCard::cardinal::Infini,false,bdd::cible::EleveCb),rien);
        save(DonneeCard(adrVille->data().id(),DonneeCard::cardinal::Infini,false,bdd::cible::EleveCb),rien);
        save(DonneeCard(adrPays->data().id(),DonneeCard::cardinal::Infini,false,bdd::cible::EleveCb),rien);
        save(DonneeCard(tel->data().id(),DonneeCard::cardinal::Infini,false,bdd::cible::EleveCb),rien);
        save(DonneeCard(mail->data().id(),DonneeCard::cardinal::Infini,false,bdd::cible::EleveCb),rien);

        save(DonneeCard(adrNuRue->data().id(),1,true,bdd::cible::EtablissementCb),rien);
        save(DonneeCard(adrRue->data().id(),1,true,bdd::cible::EtablissementCb),rien);
        save(DonneeCard(adrCP->data().id(),1,true,bdd::cible::EtablissementCb),rien);
        save(DonneeCard(adrVille->data().id(),1,true,bdd::cible::EtablissementCb),rien);
        save(DonneeCard(adrPays->data().id(),1,true,bdd::cible::EtablissementCb),rien);
        save(DonneeCard(tel->data().id(),DonneeCard::cardinal::Infini,false,bdd::cible::EtablissementCb),rien);
        save(DonneeCard(mail->data().id(),DonneeCard::cardinal::Infini,false,bdd::cible::EtablissementCb),rien);

        // Types de controle
        save(TypeControle(true,10,false,"DS","Devoir surveillé",20),rien);
        save(TypeControle(false,1,false,"Colle","Khôle",20),rien);
        save(TypeControle(false,4,true,"Interro","Interrogation",5),rien);

        // MotClé
        //Difficulté
        Tree<MotCle> arbreDiff;
        arbreDiff.root()->setData(MotCle("Diff","Difficultés",MotCle::prog::ArbreDiff));
        arbreDiff.root()->addChild(MotCle("QC","Question de Cours",MotCle::prog::QuestionCoursDiff));
        arbreDiff.root()->addChild(MotCle("ExC","Exercice de Cours",MotCle::prog::ExerciceCoursDiff));
        arbreDiff.root()->addChild(MotCle("Int","Intermédiaire",MotCle::prog::IntermediaireDiff));
        arbreDiff.root()->addChild(MotCle("Diff","Difficile",MotCle::prog::DifficileDiff));
        arbreDiff.root()->addChild(MotCle("TD","Trés Difficile",MotCle::prog::TresDifficileDiff));
        arbreDiff.root()->addChild(MotCle("Imp","Impossible",MotCle::prog::ImposibleDiff));
        save(arbreDiff,bdd::TreeSave::AddLeaf);
        setRestriction(arbreDiff,rien);

        for(TreeItem<MotCle>::iterator i = arbreDiff.begin() + 1; i != arbreDiff.end(); i++)
            save(MotClePermission((*i)->data().id(),Cible<Controle>::value,bdd::motClePermissionNum::VisibleAttNum),rien);

        //Compétence
        Tree<MotCle> arbreComp;
        arbreComp.root()->setData(MotCle("Comp","Compétences",MotCle::prog::ArbreComp));
        TreeItem<MotCle> * mathComp = arbreComp.root()->addChild(MotCle("Math Comp","Compétences Mathématiques",MotCle::prog::MathComp));
        mathComp->addChild(MotCle("An","Analyser",MotCle::prog::AnalyserComp));
        mathComp->addChild(MotCle("Mod(M)","Modéliser (Math)",MotCle::prog::ModeliserMathComp));
        mathComp->addChild(MotCle("Rep","Représenter",MotCle::prog::RepresenterComp));
        mathComp->addChild(MotCle("Arg","Argumenter",MotCle::prog::ArgumenterComp));
        mathComp->addChild(MotCle("Cal","Calculer",MotCle::prog::CalculerComp));
        mathComp->addChild(MotCle("Com(M)","Communiquer (Math)",MotCle::prog::CommuniquerMathComp));
        TreeItem<MotCle> * infoComp = arbreComp.root()->addChild(MotCle("Info Comp","Compétences Informatiques",MotCle::prog::InfoComp));
        infoComp->addChild(MotCle("Mod(I)","Modéliser (Info)",MotCle::prog::ModeliserInfoComp));
        infoComp->addChild(MotCle("Img","Imaginer",MotCle::prog::ImaginerComp));
        infoComp->addChild(MotCle("Trad","Traduire",MotCle::prog::TraduireComp));
        infoComp->addChild(MotCle("Eval","Evaluer",MotCle::prog::EvaluerComp));
        infoComp->addChild(MotCle("Spé","Spécifier",MotCle::prog::SpecifierComp));
        infoComp->addChild(MotCle("Com(I)","Communiquer (Info)",MotCle::prog::CommuniquerInfoComp));
        save(arbreComp,bdd::TreeSave::AddLeaf);
        setRestriction(arbreComp,rien);

        for(TreeItem<MotCle>::iterator i = arbreComp.begin() + 1; i != arbreComp.end(); i++)
            save(MotClePermission((*i)->data().id(),Cible<Controle>::value,bdd::motClePermissionNum::VisibleAttNum),rien);

        //!Savoir
        Tree<MotCle> arbreSav;
        arbreSav.root()->setData(MotCle("Savoir","Savoir et savoir-faire",MotCle::prog::SavoirArbre));
        TreeItem<MotCle> * mathSav = arbreSav.root()->addChild(MotCle("Math Sav","Savoir et savoir-faire Mathématiques",MotCle::prog::MathSav));
        mathSav->addChild(MotCle("Logi","Logique",MotCle::prog::LogiqueSav));
        mathSav->addChild(MotCle("Alg","Algèbre",MotCle::prog::AlgebreSav));
        mathSav->addChild(MotCle("An","Analyse",MotCle::prog::AnalyseSav));
        mathSav->addChild(MotCle("Prob","Probabilité",MotCle::prog::ProbaSav));
        /*TreeItem<MotCle> * infoSav =*/ arbreSav.root()->addChild(MotCle("Info Sav","Savoir et savoir-faire Informatique",MotCle::prog::InfoSav));
        save(arbreSav,bdd::TreeSave::AddLeaf);
        setRestriction(arbreSav,rien);

        //!Programme
        Tree<MotCle> arbreProg;
        arbreProg.root()->setData(MotCle("Prog","Programmes",MotCle::prog::ArbreProg));
        /*TreeItem<MotCle> * mathProg =*/ arbreProg.root()->addChild(MotCle("Prog Math","Programme de Mathématiques",MotCle::prog::MathProg));
        /*TreeItem<MotCle> * InfoProg =*/ arbreProg.root()->addChild(MotCle("Prog Info","Programme d'informatique",MotCle::prog::InfoProg));
        save(arbreProg,bdd::TreeSave::AddLeaf);
        setRestriction(arbreProg,rien);

        m_manager.saveVersion(bdd::miseAJourBdd::Donnees20170816);
        break;
    }
    default:
        throw std::invalid_argument(QString("Aucune mise à jour ne correspond à la version :").append(QString::number(version)).toStdString());
        break;
    }
}
