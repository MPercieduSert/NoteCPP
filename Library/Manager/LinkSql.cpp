#include "LinkSql.h"

template<> const std::array<const char*, LinkSql<AttributArbre>::NbrAtt> LinkSql<AttributArbre>::Att{{"fl","nv","nm","pr","ID"}};
template<> const std::array<const char*, LinkSql<CoursArbre>::NbrAtt> LinkSql<CoursArbre>::Att{{"fl","nv","nm","pr","ID"}};
template<> const std::array<const char*, LinkSql<DonneeArbre>::NbrAtt> LinkSql<DonneeArbre>::Att{{"fl","nv","nm","pr","ID"}};
template<> const std::array<const char*, LinkSql<EnonceArbre>::NbrAtt> LinkSql<EnonceArbre>::Att{{"fl","nv","nm","pr","ID"}};
template<> const std::array<const char*, LinkSql<ExerciceArbre>::NbrAtt> LinkSql<ExerciceArbre>::Att{{"fl","nv","nm","pr","ID"}};
template<> const char LinkSql<AttributArbre>::Table[] = "arbat";
template<> const char LinkSql<CoursArbre>::Table[] = "arbcrs";
template<> const char LinkSql<DonneeArbre>::Table[] = "arbdn";
template<> const char LinkSql<EnonceArbre>::Table[] = "arben";
template<> const char LinkSql<ExerciceArbre>::Table[] = "arbex";

template<> const std::array<const char*,  LinkSql<Annee>::NbrAtt> LinkSql<Annee>::Att{{"an","ID"}};
template<> const char LinkSql<Annee>::Table[] = "an";

template<> const std::array<const char*,  LinkSql<Classe>::NbrAtt> LinkSql<Classe>::Att{{"IDcl","IDan","IDetab","IDniv","nm","ID"}};
template<> const char LinkSql<Classe>::Table[] = "ex";

template<> const std::array<const char*,  LinkSql<Donnee>::NbrAtt> LinkSql<Donnee>::Att{{"cd","nm","sur","tp","tp_vl","ID"}};
template<> const char LinkSql<Donnee>::Table[] = "dn";

template<> const std::array<const char*,  LinkSql<Eleve>::NbrAtt> LinkSql<Eleve>::Att{{"fl","ne","nm","pnm","ID"}};
template<> const char LinkSql<Eleve>::Table[] = "el";

template<> const std::array<const char*,  LinkSql<Etablissement>::NbrAtt> LinkSql<Etablissement>::Att{{"nc","nm","td","ID"}};
template<> const char LinkSql<Etablissement>::Table[] = "etab";

template<> const std::array<const char*,  LinkSql<Exercice>::NbrAtt> LinkSql<Exercice>::Att{{"IDarbex","dt","tp","vr","rs","txt","tr","ID"}};
template<> const char LinkSql<Exercice>::Table[] = "ex";

template<> const std::array<const char*,  LinkSql<Niveau>::NbrAtt> LinkSql<Niveau>::Att{{"IDtp","nc","nm","ID"}};
template<> const char LinkSql<Niveau>::Table[] = "niv";

template<> const std::array<const char*,  LinkSql<TypeNiveau>::NbrAtt> LinkSql<TypeNiveau>::Att{{"nm","ID"}};
template<> const char LinkSql<TypeNiveau>::Table[] = "tpniv";
