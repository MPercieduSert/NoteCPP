#include "TypeNiveauManager.h"

TypeNiveauManager::TypeNiveauManager(QSqlQuery &req)
    :ManagerSql(req)
{

}

void TypeNiveauManager::creer()
{
    ManagerSql::creer();
    save(TypeNiveau("Primaire",TypeNiveau::Primaire));
    save(TypeNiveau("Collège",TypeNiveau::College));
    save(TypeNiveau("Lycée",TypeNiveau::Lycee));
    save(TypeNiveau("Classe Préparatoire",TypeNiveau::Prepa));
    save(TypeNiveau("Licence",TypeNiveau::Licence));
}
