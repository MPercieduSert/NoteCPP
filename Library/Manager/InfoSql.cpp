#include "InfoSql.h"

// Annee
constexpr char InfoSql<Annee>::Table[] {"an"};
constexpr std::array<const char *, InfoSql<Annee>::NbrAtt> InfoSql<Annee>::Att{{"an","ID"}};
constexpr char InfoSql<Annee>::SqlCreate[] {"create table %1 "
                                   " (ID integer primary key,"
                                   "%2 integer not null,"
                                   "constraint UN%1 unique (%2))"};
constexpr std::array<int, InfoSql<Annee>::NbrAttUnique> InfoSql<Annee>::AttUnique {{0}};

// Arbre
constexpr char InfoSql<AttributArbre>::Table[] {"arbat"};
constexpr char InfoSql<CoursArbre>::Table[] {"arbcrs"};
constexpr char InfoSql<DonneeArbre>::Table[] {"arbdn"};
constexpr char InfoSql<EnonceArbre>::Table[] {"arben"};
constexpr char InfoSql<ExerciceArbre>::Table[] {"arbex"};

// Attribut
constexpr char InfoSql<Attribut>::Table[] {"at"};
constexpr std::array<const char *, InfoSql<Attribut>::NbrCleExt> InfoSql<Attribut>::CleExt {{InfoSql<AttributArbre>::Table}};
constexpr std::array<const char *, InfoSql<Attribut>::NbrAtt> InfoSql<Attribut>::Att {{"nm","prbr","prcm","prcrr","prcrs","prex","nc","ID"}};
constexpr char InfoSql<Attribut>::SqlCreate[] {"create table %1 "
    " (ID integer primary key,"
    "%2 text not null,"
    "%3 integer not null,"
    "%4 integer not null,"
    "%5 integer not null,"
    "%6 integer not null,"
    "%7 integer not null,"
    "%8 text,"
    "foreign key (ID) references %9)"};

// ClasseEleve
constexpr char InfoSql<ClasseEleve>::Table[] {"clel"};
constexpr std::array<const char *, InfoSql<ClasseEleve>::NbrCleExt> InfoSql<ClasseEleve>::CleExt {{InfoSql<Classe>::Table,InfoSql<Eleve>::Table}};
constexpr std::array<const char *, InfoSql<ClasseEleve>::NbrAtt> InfoSql<ClasseEleve>::Att {{"IDcl","IDel","ent","srt","ID"}};
constexpr char InfoSql<ClasseEleve>::SqlCreate[] {"create table %1 "
    " (ID integer primary key,"
    "%2 integer not null,"
    "%3 integer not null,"
    "%4 text,"
    "%5 text,"
    "constraint UN%1 unique (%2, %3),"
    "foreign key (%2) references %6,"
    "foreign key (%3) references %7)"};

// Classe
constexpr char InfoSql<Classe>::Table[] {"cl"};
constexpr std::array<const char *, InfoSql<Classe>::NbrCleExt> InfoSql<Classe>::CleExt {{InfoSql<Annee>::Table,InfoSql<Etablissement>::Table,InfoSql<Niveau>::Table}};
constexpr std::array<const char *, InfoSql<Classe>::NbrAtt> InfoSql<Classe>::Att {{"IDan","IDetab","IDniv","nm","ID"}};
constexpr char InfoSql<Classe>::SqlCreate[] {"create table %1 "
    " (ID integer primary key,"
    "%2 integer not null,"
    "%3 integer not null,"
    "%4 integer not null,"
    "%5 integer not null,"
    "constraint UN%1 unique (%2, %3, %4, %5),"
    "foreign key (%2) references %6,"
    "foreign key (%3) references %7,"
    "foreign key (%4) references %8)"};
constexpr std::array<int, InfoSql<Classe>::NbrAttUnique> InfoSql<Classe>::AttUnique {{0,1,2,3}};

// Commentaire
constexpr char InfoSql<Commentaire>::Table[] {"cm"};

// Donnee
constexpr char InfoSql<Donnee>::Table[] {"dn"};
constexpr std::array<const char *, InfoSql<Donnee>::NbrCleExt> InfoSql<Donnee>::CleExt {{InfoSql<DonneeArbre>::Table}};
constexpr std::array<const char *, InfoSql<Donnee>::NbrAtt> InfoSql<Donnee>::Att {{"cd","nm","sur","tp","tpvl"}};
constexpr char InfoSql<Donnee>::SqlCreate[] {"create table %1 "
    " (ID integer primary key,"
    "%2 integer not null,"
    "%3 text not null,"
    "%4 integer not null,"
    "%5 integer not null,"
    "%6 integer not null,"
    "foreign key (ID) references %7)"};

// Eleve
constexpr char InfoSql<Eleve>::Table[] {"el"};
constexpr std::array<const char *, InfoSql<Eleve>::NbrAtt> InfoSql<Eleve>::Att {{"fl","ne","nm","pnm","ID"}};
constexpr char InfoSql<Eleve>::SqlCreate[] {"create table %1 "
    " (ID integer primary key,"
    "%2 integer not null,"
    "%3 text not null,"
    "%4 text not null,"
    "%5 text not null,"
    "constraint UN%1 unique (%3, %4, %5))"};
constexpr std::array<int, InfoSql<Eleve>::NbrAttUnique> InfoSql<Eleve>::AttUnique {{1,2,3}};

// Etablissement
constexpr char InfoSql<Etablissement>::Table[] {"etab"};

// Groupe
constexpr char InfoSql<Groupe>::Table[] {"gr"};
constexpr std::array<const char *, InfoSql<Groupe>::NbrCleExt> InfoSql<Groupe>::CleExt {{InfoSql<Annee>::Table,InfoSql<Classe>::Table}};
constexpr std::array<const char *, InfoSql<Groupe>::NbrAtt> InfoSql<Groupe>::Att {{"IDan","IDCl","alp","nm","tp","ID"}};
constexpr char InfoSql<Groupe>::SqlCreate[] {"create table %1 "
    " (ID integer primary key,"
    "%2 integer,"
    "%3 integer,"
    "%4 interger not null,"
    "%5 text not null,"
    "%6 interger not null,"
    "constraint UNa%1 unique (%2,%5),"
    "constraint UNb%1 unique (%3,%5),"
    "foreign key (%2) references %7,"
    "foreign key (%3) references %8)"};
constexpr std::array<const int, InfoSql<Groupe>::NbrAttUnique1> InfoSql<Groupe>::AttUnique1{{0,3}};
constexpr std::array<const int, InfoSql<Groupe>::NbrAttUnique2> InfoSql<Groupe>::AttUnique2{{1,3}};
constexpr std::array<int, InfoSql<Groupe>::NbrAttUnique> InfoSql<Groupe>::AttUnique {{0,3,1,3}};

// Niveau
constexpr char InfoSql<Niveau>::Table[] {"niv"};
constexpr std::array<const char *, InfoSql<Niveau>::NbrCleExt> InfoSql<Niveau>::CleExt {{InfoSql<TypeNiveau>::Table}};
constexpr std::array<const char *, InfoSql<Niveau>::NbrAtt> InfoSql<Niveau>::Att {{"IDtp","nc","nm","ID"}};
constexpr char InfoSql<Niveau>::SqlCreate[] {"create table %1 "
    " (ID integer primary key,"
    "%2 integer not null,"
    "%3 text not null,"
    "%4 text not null,"
    "constraint UN%1 unique (%4),"
    "foreign key (%2) references %5)"};
const std::array<int, InfoSql<Niveau>::NbrAttUnique> InfoSql<Niveau>::AttUnique {{2}};

// DateRelation
constexpr char InfoSql<CommentaireClasse>::Table[] {"cmcl"};
constexpr std::array<const char *,InfoSql<CommentaireClasse>::NbrAtt> InfoSql<CommentaireClasse>::Att {{"IDcm","IDcl","dt","ID"}};
constexpr std::array<const char *, InfoSql<CommentaireClasse>::NbrCleExt> InfoSql<CommentaireClasse>::CleExt {{InfoSql<Commentaire>::Table,InfoSql<Classe>::Table}};

constexpr char InfoSql<CommentaireEleve>::Table[] {"cmel"};
constexpr std::array<const char *,InfoSql<CommentaireEleve>::NbrAtt> InfoSql<CommentaireEleve>::Att {{"IDcm","IDel","dt","ID"}};
constexpr std::array<const char *, InfoSql<CommentaireEleve>::NbrCleExt> InfoSql<CommentaireEleve>::CleExt {{InfoSql<Commentaire>::Table,InfoSql<Eleve>::Table}};

constexpr char InfoSql<CommentaireGroupe>::Table[] {"cmgr"};
constexpr std::array<const char *,InfoSql<CommentaireGroupe>::NbrAtt> InfoSql<CommentaireGroupe>::Att {{"IDcm","IDgr","dt","ID"}};
constexpr std::array<const char *, InfoSql<CommentaireGroupe>::NbrCleExt> InfoSql<CommentaireGroupe>::CleExt {{InfoSql<Commentaire>::Table,InfoSql<Groupe>::Table}};

// ValeurDateRelation
constexpr char InfoSql<DonneeClasse>::Table[] {"dncl"};
constexpr std::array<const char *,InfoSql<DonneeClasse>::NbrAtt> InfoSql<DonneeClasse>::Att {{"IDdn","IDcl","dt","vl","ID"}};
constexpr std::array<const char *, InfoSql<DonneeClasse>::NbrCleExt> InfoSql<DonneeClasse>::CleExt {{InfoSql<Donnee>::Table,InfoSql<Classe>::Table}};

constexpr char InfoSql<DonneeEleve>::Table[] {"dnel"};
constexpr std::array<const char *,InfoSql<DonneeEleve>::NbrAtt> InfoSql<DonneeEleve>::Att {{"IDdn","IDel","dt","vl","ID"}};
constexpr std::array<const char *, InfoSql<DonneeEleve>::NbrCleExt> InfoSql<DonneeEleve>::CleExt {{InfoSql<Donnee>::Table,InfoSql<Eleve>::Table}};

constexpr char InfoSql<DonneeEtablissement>::Table[] {"dnetab"};
constexpr std::array<const char *,InfoSql<DonneeEtablissement>::NbrAtt> InfoSql<DonneeEtablissement>::Att {{"IDdn","IDetab","dt","vl","ID"}};
constexpr std::array<const char *, InfoSql<DonneeEtablissement>::NbrCleExt> InfoSql<DonneeEtablissement>::CleExt {{InfoSql<Donnee>::Table,InfoSql<Etablissement>::Table}};

constexpr char InfoSql<DonneeNiveau>::Table[] {"dnniv"};
constexpr std::array<const char *,InfoSql<DonneeNiveau>::NbrAtt> InfoSql<DonneeNiveau>::Att {{"IDdn","IDniv","dt","vl","ID"}};
constexpr std::array<const char *, InfoSql<DonneeNiveau>::NbrCleExt> InfoSql<DonneeNiveau>::CleExt {{InfoSql<Donnee>::Table,InfoSql<Niveau>::Table}};

constexpr char InfoSql<DonneeSource>::Table[] {"dnsr"};
constexpr std::array<const char *,InfoSql<DonneeSource>::NbrAtt> InfoSql<DonneeSource>::Att {{"IDdn","IDsr","dt","vl","ID"}};
constexpr std::array<const char *, InfoSql<DonneeSource>::NbrCleExt> InfoSql<DonneeSource>::CleExt {{InfoSql<Donnee>::Table,InfoSql<Source>::Table}};

// NumRelation
constexpr char InfoSql<GroupeEleve>::Table[] {"grel"};
constexpr std::array<const char *,InfoSql<GroupeEleve>::NbrAtt> InfoSql<GroupeEleve>::Att {{"IDgr","IDel","nm","ID"}};
constexpr std::array<const char *, InfoSql<GroupeEleve>::NbrCleExt> InfoSql<GroupeEleve>::CleExt {{InfoSql<Groupe>::Table,InfoSql<Eleve>::Table}};

// RelationSimple
constexpr char InfoSql<AttributCommentaire>::Table[] {"atcm"};
constexpr std::array<const char *,InfoSql<AttributCommentaire>::NbrAtt> InfoSql<AttributCommentaire>::Att {{"IDat","IDcm","ID"}};
constexpr std::array<const char *, InfoSql<AttributCommentaire>::NbrCleExt> InfoSql<AttributCommentaire>::CleExt {{InfoSql<Attribut>::Table,InfoSql<Commentaire>::Table}};

constexpr char InfoSql<NiveauPrecedent>::Table[] {"nivpre"};
constexpr std::array<const char *,InfoSql<NiveauPrecedent>::NbrAtt> InfoSql<NiveauPrecedent>::Att {{"IDpr","IDsv","ID"}};
constexpr std::array<const char *, InfoSql<NiveauPrecedent>::NbrCleExt> InfoSql<NiveauPrecedent>::CleExt {{InfoSql<Niveau>::Table,InfoSql<Niveau>::Table}};

constexpr char InfoSql<EtablissementNiveau>::Table[] {"etabniv"};
constexpr std::array<const char *,InfoSql<EtablissementNiveau>::NbrAtt> InfoSql<EtablissementNiveau>::Att {{"IDetab","IDniv","ID"}};
constexpr std::array<const char *, InfoSql<EtablissementNiveau>::NbrCleExt> InfoSql<EtablissementNiveau>::CleExt {{InfoSql<Etablissement>::Table,InfoSql<Niveau>::Table}};

// Source
constexpr char InfoSql<Source>::Table[] {"sr"};

// TypeNiveau
constexpr char InfoSql<TypeNiveau>::Table[] {"tpniv"};
