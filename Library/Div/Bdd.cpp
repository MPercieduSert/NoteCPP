#include "Bdd.h"

Bdd::Bdd(const QString & dbtype, const QString &fileName) : FileInterface(fileName,"Data Base files (*.db)"),
    m_bdd(QSqlDatabase::addDatabase(dbtype))
{
    m_bdd.setDatabaseName(fileName);

    m_managers[Entity::AttributArbreId] = &m_attributArbreManager(m_requete);
    m_managers[Entity::CoursArbreId] = &m_coursArbreManager(m_requete);
    m_managers[Entity::DonneeArbreId] = &m_donneeArbreManager(m_requete);
    m_managers[Entity::EnonceArbreId] = &m_enonceArbreManager(m_requete);
    m_managers[Entity::AnneeId] = &m_anneeManager(m_requete);

    /*
    m_managers[Entity::AppreciationId] = &m_appreciationManager;
    m_managers[Entity::AttributId] = &m_attributManager;
    m_managers[Entity::Attribut_baremeId] = &m_attribut_baremeManager;
    m_managers[Entity::Attribut_exerciceId] = &m_attribut_exerciceManager;
    m_managers[Entity::BaremeId] = &m_baremeManager;
    m_managers[Entity::ClasseId] = &m_classeManager;
    m_managers[Entity::CoefficientId] = &m_coefficientManager;
    m_managers[Entity::CommentaireId] = &m_commentaireManager;
    m_managers[Entity::ControleId] = &m_controleManager;
    m_managers[Entity::Controle_exerciceId] = &m_controle_exerciceManager;
    m_managers[Entity::EleveId] = &m_eleveManager;
    m_managers[Entity::Eleve_groupeId] = &m_eleve_groupeManager;
    m_managers[Entity::ExerciceId] = &m_exerciceManager;
    m_managers[Entity::GroupeId] = &m_groupeManager;
    m_managers[Entity::NoteId] = &m_noteManager;
    m_managers[Entity::NumControleId] = &m_numControleManager;
    m_managers[Entity::NiveauId] = &m_niveauManager;
    m_managers[Entity::PointId] = &m_pointManager;
    m_managers[Entity::SourceId] = &m_sourceManager;
    m_managers[Entity::TypeControleId] = &m_typeControleManager;
    m_managers[Entity::TypeGroupeId] = &m_typeGroupeManager;
    m_managers[Entity::TypeNiveauId] = &m_typeNiveauManager;
    */
}

Bdd::~Bdd()
{
    m_bdd.close();
    /*for(Manager **p = m_managers; p < m_managers+m_nbrEntity; p++)
    {
        if(*p != NULL){delete *p;}
    }*/
}

void Bdd::affError(const QSqlQuery & query) const
{
    QSqlError err = query.lastError();
    if(err.type() != QSqlError::NoError)
    {
        QMessageBox::critical(0,err.text(),err.text()+"\n"+err.nativeErrorCode()+"\n"+query.lastQuery());
    }
}

QString Bdd::afficheClasse(const Classe & classe);//, Niveau::affiche_alpha alpha)
{
    Niveau niveau(classe.niveau());
    get(niveau);
    QString string(niveau.nom());
    if(classe.num() != 0)
    {
        switch (alpha)
        {
        case Niveau::Sans:
            break;
        case Niveau::Numeric:
            string.append(QString::number(classe.num()));
            break;
        case Niveau::AlphabeticMaj:
            if(0 < classe.num() && classe.num() < 27)
            {
                string.append(QString("ABCDEFGHIJKLMOPQRSTUVWXYZ").at(classe.num()-1));
            }
            break;
        case Niveau::AlphabeticMin:
            if(0 < classe.num() && classe.num() < 27)
            {
                string.append(QString("abcdefghijklmopqrstuvwxyz").at(classe.num()-1));
            }
            break;
        }
    }
    return string;
}

QString Bdd::afficheClasse(int idClasse);//, Niveau::affiche_alpha alpha)
{
    Classe classe(idClasse);
    if(get(classe))
    {
        return afficheClasse(classe,alpha);
    }
    return QString("classe invalide identifiant:")+QString::number(idClasse);
}

bool Bdd::copy(const QString & name)
{
    Bdd file(name, m_bdd.driverName());
    if(file.exists() && file.isValid())
    {
        return file.m_fileName.copy(m_fileName);
    }
    else
    {
        return false;
    }
}

bool Bdd::creer()
{
    if(m_bdd.open())
    {
        QSqlQuery query;

        // Création des tables
        query.exec("CREATE TABLE typeNiveau ("
                   "id INTEGER PRIMARY KEY,"
                   "nom TEXT NOT NULL)"
                   );

        query.exec("CREATE TABLE niveau ("
                   "id INTEGER PRIMARY KEY,"
                   "colle INTEGER NOT NULL CHECK(colle IN (0, 1)),"
                   "nom TEXT NOT NULL,"
                   "type INTERGER NOT NULL REFERENCES typeNiveau,"
                   "UNIQUE(nom))"
                   );

        query.exec("CREATE TABLE annee ("
                   "id INTEGER PRIMARY KEY,"
                   "encours INTEGER NOT NULL CHECK(encours IN (0, 1)),"
                   "rentree INTERGER NOT NULL,"
                   "UNIQUE(rentree))");
        //,"
        //"CHECK((SELECT COUNT(*) FROM annee WHERE encours = 1) <= 1),"
        //);

        affError(query);

        query.exec("CREATE TABLE classe ("
                   "id INTEGER PRIMARY KEY,"
                   "annee INTEGER NOT NULL REFERENCES annee,"
                   "nbr_phase INTERGER NOT NULL CHECK(nbr_phase > 0),"
                   "niveau INTEGER NOT NULL REFERENCES niveau,"
                   "num INTERGER NOT NULL CHECK(num >= 0),"
                   "UNIQUE(annee, niveau, num))"
                   );

        query.exec("CREATE TABLE eleve ("
                   "id INTEGER PRIMARY KEY,"
                   "classe INTEGER NOT NULL REFERENCES classe,"
                   "fille INTEGER NOT NULL CHECK(fille IN (0, 1)),"
                   "naissance TEXT NOT NULL,"
                   "nom TEXT NOT NULL,"
                   "prenom TEXT NOT NULL,"
                   "abandon TEXT,"
                   "UNIQUE(nom,prenom,naissance))"
                   );

        query.exec("CREATE TABLE typeGroupe ("
                   "id INTEGER PRIMARY KEY,"
                   "alpha INTEGER NOT NULL CHECK(alpha >= 0),"
                   "classe INTEGER NOT NULL REFERENCES classe,"
                   "nom TEXT NOT NULL,"
                   "type INTEGER NOT NULL,"
                   "UNIQUE(classe,nom))"
                   );
        
        affError(query);

        query.exec("CREATE TABLE groupe ("
                   "id INTEGER PRIMARY KEY,"
                   "num INTERGER NOT NULL,"
                   "type INTEGER NOT NULL REFERENCES typeGroupe,"
                   "UNIQUE(type, num))"
                   );

        query.exec("CREATE TABLE eleve_groupe ("
                   "id INTEGER PRIMARY KEY,"
                   "eleve INTEGER NOT NULL REFERENCES eleve,"
                   "groupe INTEGER NOT NULL REFERENCES groupe,"
                   "UNIQUE(eleve, groupe))"
                   );

        query.exec("CREATE TABLE attribut ("
                   "id INTEGER PRIMARY KEY,"
                   "feuille INTEGER NOT NULL CHECK(feuille IN (0, 1)),"
                   "niveau INTERGER NOT NULL CHECK(niveau >= 0),"
                   "nom TEXT NOT NULL,"
                   "num INTERGER NOT NULL CHECK(niveau >= 0),"
                   "pere INTERGER NOT NULL CHECK(pere >= 0),"// CHECK(pere = 0 OR pere IN (SELECT id FROM attribut)),"
                   "nc TEXT,"
                   "UNIQUE(pere,num))"
                   );

        affError(query);

        query.exec("CREATE TABLE source ("
                   "id INTEGER PRIMARY KEY,"
                   "nom TEXT NOT NULL,"
                   "type INTEGER NOT NULL,"
                   "UNIQUE(nom,type))"
                   );

        affError(query);

        query.exec("CREATE TABLE exercice ("
                   "id INTEGER PRIMARY KEY,"
                   "enonce TEXT NOT NULL,"
                   "feuille INTEGER NOT NULL CHECK(feuille IN (0, 1)),"
                   "niveau INTERGER NOT NULL CHECK(niveau >= 0),"
                   "num INTERGER NOT NULL CHECK(num >= 0),"
                   "pere INTERGER NOT NULL CHECK(pere >= 0),"// OR pere IN (SELECT id FROM exercice)),"
                   "version INTERGER NOT NULL CHECK(version >= 0),"
                   "correction TEXT,"
                   "source INTERGER NOT NULL CHECK(source >= 0),"// OR pere IN (SELECT id FROM source)),"
                   "titre TEXT,"
                   "UNIQUE(pere, num, version))"
                   );

        affError(query);

        query.exec("CREATE TABLE attribut_exercice ("
                   "id INTEGER PRIMARY KEY,"
                   "attribut INTEGER NOT NULL REFERENCES attribut,"
                   "exercice INTEGER NOT NULL REFERENCES exercice,"
                   "UNIQUE(attribut, exercice))"
                   );

        query.exec("CREATE TABLE typeControle ("
                   "id INTEGER PRIMARY KEY,"
                   "appreciation INTEGER NOT NULL CHECK(appreciation IN (0, 1)),"
                   "decimale INTEGER NOT NULL CHECK(decimale > 0),"
                   "modifT INTEGER NOT NULL CHECK(modifT IN (0, 1)),"
                   "nc TEXT NOT NULL,"
                   "nom TEXT NOT NULL,"
                   "total INTEGER NOT NULL,"
                   "UNIQUE(nom))"
                   );

        query.exec("CREATE TABLE controle ("
                   "id INTEGER PRIMARY KEY,"
                   "classe INTERGER NOT NULL REFERENCES classe,"
                   "date TEXT NOT NULL,"
                   "decimale INTERGER NOT NULL CHECK(decimale > 0),"
                   "minima INTERGER NOT NULL CHECK(decimale >= 0),"
                   "nom TEXT NOT NULL,"
                   "saisie INTERGER NOT NULL CHECK(saisie IN (0, 1)),"
                   "total INTERGER NOT NULL CHECK(total > 0),"
                   "type INTEGER NOT NULL REFERENCES typeControle,"
                   "UNIQUE(classe,nom))"
                   );

        query.exec("CREATE TABLE numControle ("
                   "id INTEGER PRIMARY KEY,"
                   "classe INTERGER NOT NULL REFERENCES classe,"
                   "num INTEGER NOT NULL CHECK(num >= 0),"
                   "type INTEGER NOT NULL REFERENCES typeControle,"
                   "UNIQUE(classe,type))");

        query.exec("CREATE TABLE bareme ("
                   "id INTEGER PRIMARY KEY,"
                   "controle INTEGER NOT NULL REFERENCES controle,"
                   "exercice INTERGER NOT NULL REFERENCES exercice,"
                   "fraction INTERGER NOT NULL CHECK(fraction > 0 AND fraction <= valeur),"
                   "num INTEGER NOT NULL CHECK(num >= 0),"
                   "nom TEXT NOT NULL,"
                   "valeur INTERGER NOT NULL CHECK(valeur > 0),"
                   "UNIQUE(controle, exercice, num))"
                   );

        query.exec("CREATE TABLE attribut_bareme ("
                   "id INTEGER PRIMARY KEY,"
                   "attribut INTEGER NOT NULL REFERENCES attribut,"
                   "bareme INTEGER NOT NULL REFERENCES bareme,"
                   "UNIQUE(bareme,attribut))"
                   );

        query.exec("CREATE TABLE controle_exercice ("
                   "id INTEGER PRIMARY KEY,"
                   "controle INTEGER NOT NULL REFERENCES controle,"
                   "exercice INTERGER NOT NULL REFERENCES exercice,"
                   "num INTEGER NOT NULL CHECK(num >= 0),"
                   "UNIQUE(controle, exercice))"
                   );

        // Insertion par défault dans la table type_niveau
        query.exec("INSERT INTO type_niveau(id,nom) "
                   "VALUES(1,'Primaire'),"
                   "(2,'Collège'),"
                   "(3,'Lycée'),"
                   "(4,'Prépa')"
                   "(5,'Licence')");

        // Insertion par défault dans la table niveau
        query.exec("INSERT INTO niveau(nom,type,colle) "
                   "VALUES('CP',1,0),"
                   "('CE1',1,0),"
                   "('CE2',1,0),"
                   "('CM1',1,0),"
                   "('CM2',1,0)");

        query.exec("INSERT INTO niveau(nom,type,colle) "
                   "VALUES('6ème',2,0),"
                   "('5ème',2,0),"
                   "('4ème',2,0),"
                   "('3ème',2,0)");

        query.exec("INSERT INTO niveau(nom,type,colle) "
                   "VALUES('2nd',3,0),"
                   "('1er',3,0),"
                   "('Terminale',3,0)");

        query.exec("INSERT INTO niveau(nom,type,colle) "
                   "VALUES('BCPST-1',4,1),"
                   "('BCPST-2',4,1),"
                   "('MP',4,1),"
                   "('MPSI',4,1),"
                   "('PC',4,1),"
                   "('PCSI',4,1),"
                   "('PSI',4,1),"
                   "('PTSI',4,1),"
                   "('PT',4,1)");

        affError(query);
        return true;
    }
    else
    {
        throw std::runtime_error("la base de donnée n'est pas ouverte");
        return false;
    }
}

/*
bool Bdd::creerAnnee(Annee & annee)
{
    if(m_bdd.isOpen())
    {
        save(annee);
        QSqlQuery query;

        // Création des tables
        QString sql("CREATE TABLE note_%1 "
                    "(id INTERGER PRIMARY KEY,"
                    "appreciation INTERGER NOT NULL CHECK(appreciation IN (0, 1)),"
                    "controle INTERGER NOT NULL REFERENCES controle,"
                    "date TEXT NOT NULL,"
                    "eleve INTERGER NOT NULL REFERENCES eleve,"
                    "saisie INTERGER NOT NULL CHECK(saisie IN (0, 1)),"
                    "valeur INTERGER CHECK(valeur ISNULL OR valeur >= 0),"
                    "UNIQUE(controle, eleve))");

        query.exec(sql.arg(annee.id()));
        affError(query);

        sql = "CREATE TABLE coefficient_%1 "
              "(id INTERGER PRIMARY KEY,"
              "controle INTERGER NOT NULL REFERENCES controle,"
              "indice INTERGER NOT NULL CHECK(indice >= 0),"
              "valeur REAL NOT NULL,"
              "UNIQUE(controle, indice))";

        query.exec(sql.arg(annee.id()));
        affError(query);

        sql = "CREATE TABLE appreciation_%1 "
              "(id INTERGER PRIMARY KEY,"
              "date TEXT NOT NULL,"
              "note INTERGER NOT NULL REFERENCES note,"
              "saisie INTERGER NOT NULL CHECK(saisie IN (0, 1)),"
              "texte TEXT,"
              "UNIQUE(note))";

        query.exec(sql.arg(annee.id()));
        affError(query);

        sql = "CREATE TABLE point_%1 "
              "(id INTERGER PRIMARY KEY,"
              "bareme INTERGER NOT NULL REFERENCES bareme,"
              "commentaire INTERGER NOT NULL REFERENCES commentaire,"
              "date TEXT NOT NULL,"
              "note INTERGER NOT NULL REFERENCES note,"
              "saisie INTERGER NOT NULL CHECK(saisie IN (0, 1)),"
              "valeur INTERGER,"
              "UNIQUE(note, bareme))";

        query.exec(sql.arg(annee.id()));

        affError(query);

        sql = "CREATE TABLE commentaire_%1 "
              "(id INTERGER PRIMARY KEY,"
              "texte TEXT NOT NULL,"
              "type INTERGER NOT NULL,"
              "UNIQUE(texte))";

        query.exec(sql.arg(annee.id()));

        affError(query);
        return true;
    }
    else
    {
        throw std::runtime_error("la base de donnée n'est pas ouverte");
        return false;
    }
}
*/

/*
Manager * Bdd::newManager(Entity::entityId idEntity)
{
    switch (idEntity)
    {
    case Entity::AnneeId:
        return new AnneeManager(m_bdd);
        break;

    case Entity::AppreciationId:
        return new AppreciationManager(m_bdd, m_annee);
        break;

    case Entity::AttributId:
        return new AttributManager(m_bdd);
        break;

    case Entity::Attribut_baremeId:
        return new Attribut_baremeManager(m_bdd);
        break;

    case Entity::Attribut_exerciceId:
        return new Attribut_exerciceManager(m_bdd);
        break;

    case Entity::BaremeId:
        return new BaremeManager(m_bdd);
        break;

    case Entity::ClasseId:
        return new ClasseManager(m_bdd);
        break;

    case Entity::CommentaireId:
        return new CommentaireManager(m_bdd, m_annee);
        break;

    case Entity::CoefficientId:
        return new CoefficientManager(m_bdd, m_annee);
        break;

    case Entity::ControleId:
        return new ControleManager(m_bdd);
        break;

    case Entity::Controle_exerciceId:
        return new Controle_exerciceManager(m_bdd);
        break;

    case Entity::EleveId:
        return new EleveManager(m_bdd);
        break;

    case Entity::Eleve_groupeId:
        return new Eleve_groupeManager(m_bdd);
        break;

    case Entity::ExerciceId:
        return new ExerciceManager(m_bdd);
        break;

    case Entity::GroupeId:
        return new GroupeManager(m_bdd);
        break;

    case Entity::NoteId:
        return new NoteManager(m_bdd, m_annee);
        break;

    case Entity::NumControleId:
        return new NumControleManager(m_bdd);
        break;

    case Entity::NiveauId:
        return new NiveauManager(m_bdd);
        break;

    case Entity::PointId:
        return new PointManager(m_bdd, m_annee);
        break;

    case Entity::SourceId:
        return new SourceManager(m_bdd);
        break;

    case Entity::TypeControleId:
        return new TypeControleManager(m_bdd);
        break;

    case Entity::TypeGroupeId:
        return new TypeGroupeManager(m_bdd);
        break;

    case Entity::TypeNiveauId:
        return new TypeNiveauManager(m_bdd);
        break;
    default:
        return NULL;
        break;
    }
}
*/
/*
void Bdd::setAnnee(const Annee & annee)
{
    m_annee = annee;
    m_appreciationManager.setAnnee(annee);
    m_coefficientManager.setAnnee(annee);
    m_commentaireManager.setAnnee(annee);
    m_noteManager.setAnnee(annee);
    m_pointManager.setAnnee(annee);
}
*/

void Bdd::setBdd()
{
    m_requete = QSqlQuery(m_bdd);
    /*
    m_anneeManager.setBdd(m_bdd);
    m_appreciationManager.setBdd(m_bdd);
    m_attributManager.setBdd(m_bdd);
    m_attribut_baremeManager.setBdd(m_bdd);
    m_attribut_exerciceManager.setBdd(m_bdd);
    m_baremeManager.setBdd(m_bdd);
    m_classeManager.setBdd(m_bdd);
    m_coefficientManager.setBdd(m_bdd);
    m_commentaireManager.setBdd(m_bdd);
    m_controleManager.setBdd(m_bdd);
    m_controle_exerciceManager.setBdd(m_bdd);
    m_eleveManager.setBdd(m_bdd);
    m_eleve_groupeManager.setBdd(m_bdd);
    m_exerciceManager.setBdd(m_bdd);
    m_groupeManager.setBdd(m_bdd);
    m_noteManager.setBdd(m_bdd);
    m_numControleManager.setBdd(m_bdd);
    m_niveauManager.setBdd(m_bdd);
    m_pointManager.setBdd(m_bdd);
    m_sourceManager.setBdd(m_bdd);
    m_typeControleManager.setBdd(m_bdd);
    m_typeGroupeManager.setBdd(m_bdd);
    m_typeNiveauManager.setBdd(m_bdd);
    */
}

void Bdd::setFileName(const QString & fileName)
{
    FileInterface::setFileName(fileName);
    if(m_bdd.isOpen())
    {
        m_bdd.close();
    }
    m_bdd.setDatabaseName(fileName);
}
