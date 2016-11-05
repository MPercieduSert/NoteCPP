/*Auteur: PERCIE DU SERT Maxime
 *Date: 18/05/2016
 */
#ifndef ABSTRACTBDD_H
#define ABSTRACTBDD_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <stdexcept>

#include "FileInterface.h"
#include "Managers.h"
#include "../Div/VectorPtr.h"

/*! \ingroup groupeFile
 *  \brief Classe mère du gestionnaire de base de donnée.
 *
 * Gestionnaire de la base donnée sous SQLite3. Cette classe fait le lien entre la base de donnée et les Entity grâce aux Manager.
 */
class AbstractBdd : public FileInterface
{
protected:
    QSqlDatabase m_bdd;                 //! Connexion à la base de donnée.
    Managers m_manager;                 //! Manager des entités.
    const int m_version;                //! Version de la base de donnée requis par le programme

public:
    //! Constructeur. Donner en argument le type ainsi que le chemin de la base de donnée.
    AbstractBdd(const QString & dbtype, const QString & fileName, int version);

    //! Destructeur. Referme la base de donnée.
    ~AbstractBdd();

    //! Vérifie si le fichier de chemin name existe et est un fichier de base de donnée valide, si c'est le cas,
    //! le fichier de la base de donnée est remplacé par une copie du fichier de chemin name.
    bool copy(const QString & name);

    //! Créer la base de donnée avec les tables et les entrées par défault.
    bool creer();

    //! Renvoie une réfrence sur la base de donnée.
    QSqlDatabase &db()
        {return m_bdd;}

    //! Teste si le fichier de base de donnée existe.
    bool exists() const
        {return QFile::exists(m_fileName);}

    //! Teste s'il existe une entité de même identifiant que entity en base de donnée.
    template<class Ent> bool exists(const Ent & entity);

    //! Teste s'il existe une entité vérifiant une condition.
    template<class Ent> bool exists(typename Ent::Position cle, const QVariant & value, bdd::Condition cond = bdd::Condition::Egal);

    //! Teste s'il existe une entité ayant les mêmes valeurs qu'un ensemble d'attributs uniques que entity en base de donnée.
    template<class Ent> bool existsUnique(Ent & entity);

    //! Teste s'il existe une entité ayant les mêmes valeurs qu'un ensemble d'attributs uniques que entity en base de donnée.
    template<class Ent> bool existsUnique(const Ent & entity);

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que entity en base de donnée.
    template<class Ent> bdd::ExisteUni existsUniqueEnsemble(Ent & entity);

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que entity en base de donnée.
    template<class Ent> bdd::ExisteUni existsUniqueEnsemble(const Ent & entity);

    //! Fonction d'agrega de valeur de type T sur l'attribut att appliquée à toutes les entités de la table.
    template<class Ent, class T> T fonctionAgrega(bdd::Agrega fonc, typename Ent::Position att);

    //! Fonction d'agrega de valeur de type T sur l'attribut att appliquée à toutes les entités vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value.
    template<class Ent, class T> T fonctionAgrega(bdd::Agrega fonc, typename Ent::Position att, typename Ent::Position cle, const QVariant & value,
                                                  bdd::Condition cond = bdd::Condition::Egal);

    //! Fonction d'agrega de valeur de type T sur l'attribut att appliquée à toutes les entités vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1 et valeur de la colonne d'identifiant cle2 = value2.
    template<class Ent, class T> T fonctionAgrega(bdd::Agrega fonc, typename Ent::Position att, typename Ent::Position cle1, const QVariant & value1,
                                                  typename Ent::Position cle2,  const QVariant & value2,
                                                  bdd::Condition cond1 = bdd::Condition::Egal, bdd::Condition cond2 = bdd::Condition::Egal);

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrées en base de donnée
    //! ayant le même identifiant que entity.
    //! Retourne True si l'opération s'est correctement déroulée.
    template<class Ent> bool get(Ent & entity);

    //! Renvoie l'arbre de racine d'identifiant id pour une entité de type arbre.
    template<class Ent> Tree<Ent> getArbre(int id);

    //! Renvoie la liste des entités de la table des entités Ent ordonnée suivant la colonne d'identifiant ordre.
    template<class Ent> ListPtr<Ent> getList(typename Ent::Position ordre = Ent::Id, bool croissant = true);

    //! Renvoie la liste des entités de la table des entités Ent vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant la colonne d'identifiant ordre.
    template<class Ent> ListPtr<Ent> getList(typename Ent::Position cle, const QVariant & value, typename Ent::Position ordre = Ent::Id, bdd::Condition cond = bdd::Condition::Egal, bool crois = true);

    //! Renvoie la liste des entités de la table des entités Ent vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant les colonnes d'identifiant ordre1 puis ordre2.
    template<class Ent> ListPtr<Ent> getList(typename Ent::Position cle, const QVariant & value, typename Ent::Position order1, typename Ent::Position order2, bdd::Condition cond = bdd::Condition::Egal, bool croissant1 = true, bool croissant2 = true);

    //! Renvoie la liste des entités de la table des entités Ent vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant les colonnes d'identifiant ordre1, ordre2 puis ordre3.
    template<class Ent> ListPtr<Ent> getList(typename Ent::Position cle, const QVariant & value, typename Ent::Position ordre1, typename Ent::Position ordre2, typename Ent::Position ordre3,
                                             bdd::Condition cond = bdd::Condition::Egal,
                                             bool crois1 = true, bool crois2 = true, bool crois3 = true);

    //! Renvoie la liste des entités de la table des entités Ent vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1 et valeur de la colonne d'identifiant cle2 = value2,
    //! ordonnée suivant la colonne d'identifiant ordre.
    template<class Ent> ListPtr<Ent> getList(typename Ent::Position cle1, const QVariant & value1, typename Ent::Position cle2, const QVariant & value2,
                                             typename Ent::Position ordre = Ent::Id,
                                             bdd::Condition cond1 = bdd::Condition::Egal, bdd::Condition cond2 = bdd::Condition::Egal,
                                             bool crois = true);

    //! Renvoie la liste des entités de la table des entités Ent vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1, valeur de la colonne d'identifiant cle2 = value2,
    //! et valeur de la colonne d'identifiant cle3 = value3,
    //! ordonnée suivant la colonne d'identifiant ordre.
    template<class Ent> ListPtr<Ent> getList(typename Ent::Position cle1, const QVariant & value1,
                                             typename Ent::Position cle2, const QVariant & value2,
                                             typename Ent::Position cle3, const QVariant & value3,
                                             typename Ent::Position ordre = Ent::Id,
                                             bdd::Condition cond1 = bdd::Condition::Egal, bdd::Condition cond2 = bdd::Condition::Egal,
                                             bdd::Condition cond3 = bdd::Condition::Egal,
                                             bool crois = true);

    //! Renvoie la liste des entités de la table vérifiant une condition sur une jointure (colonneTable = colonneJoin),
    //! valeur des colonnes de la table Ent d'identifiant key = value de QMap whereMapTable,
    //! valeur des colonnes de la table Join d'identifiant key = value de QMap whereMapJoin,
    //! ordonnée suivant les colonnes de la table Ent d'identifiants key et d'ordre value de QMap orderMapTable (true -> croissant, false -> décroissant).
    template<class Ent, class Join> ListPtr<Ent> getList(typename Ent::Position colonneTable,
                                                   typename Join::Position colonneJoin,
                                                   const QMap<int,QVariant> & whereMapTable,
                                                   const QMap<int,QVariant> & whereMapJoin,
                                                   const QMap<int,bool> & orderMapTable);

    //! Renvoie la liste des entités de la table vérifiant une condition sur une jointure,
    //! valeur de la colonne de la jointure d'identifiant cleWhere = valueWhere,
    //! ordonnée suivant la colonne de l'entité d'identifiant ordre.
    template<class Ent, class Join> ListPtr<Ent> getList(typename Ent::Position cleJoin, typename Join::Position cleWhere, const QVariant & valueWhere, typename Ent::Position ordre = Ent::Id, bdd::Condition cond = bdd::Condition::Egal, bool crois = true);

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrées en base de donnée
    //! ayant les mêmes valeurs uniques.
    //! Retourne True si l'opération s'est correctement déroulée.
    template<class Ent> bool getUnique(Ent & entity);

    //! Renvoie le vector des entités de la table des entités Ent ordonnée suivant la colonne d'identifiant ordre.
    template<class Ent> VectorPtr<Ent> getVector(typename Ent::Position ordre = Ent::Id, bool croissant = true);

    //! Renvoie le vector des entités de la table des entités Ent vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant la colonne d'identifiant ordre.
    template<class Ent> VectorPtr<Ent> getVector(typename Ent::Position cle, const QVariant & value, typename Ent::Position ordre = Ent::Id, bdd::Condition cond = bdd::Condition::Egal, bool crois = true);

    //! Renvoie le vector des entités de la table des entités Ent vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant les colonnes d'identifiant ordre1 puis ordre2.
    template<class Ent> VectorPtr<Ent> getVector(typename Ent::Position cle, const QVariant & value, typename Ent::Position ordre1, typename Ent::Position ordre2, bdd::Condition cond = bdd::Condition::Egal, bool crois1 = true, bool crois2 = true);

    //! Renvoie le vector des entités de la table des entités Ent vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant les colonnes d'identifiant ordre1, ordre2 puis ordre3.
    template<class Ent> VectorPtr<Ent> getVector(typename Ent::Position cle, const QVariant & value, typename Ent::Position ordre1, typename Ent::Position ordre2, typename Ent::Position ordre3,
                                                 bdd::Condition cond = bdd::Condition::Egal,
                                                 bool crois1 = true, bool crois2 = true, bool crois3 = true);

    //! Renvoie le vector des entités de la table des entités Ent vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1 et valeur de la colonne d'identifiant cle2 = value2,
    //! ordonnée suivant la colonne d'identifiant ordre.
    template<class Ent> VectorPtr<Ent> getVector(typename Ent::Position cle1, const QVariant & value1,
                                                 typename Ent::Position cle2, const QVariant & value2,
                                                 typename Ent::Position ordre = Ent::Id,
                                                 bdd::Condition cond1 = bdd::Condition::Egal, bdd::Condition cond2 = bdd::Condition::Egal,
                                                 bool crois = true);

    //! Renvoie le vector des entités de la table des entités Ent vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1, valeur de la colonne d'identifiant cle2 = value2,
    //! et valeur de la colonne d'identifiant cle3 = value3,
    //! ordonnée suivant la colonne d'identifiant ordre.
    template<class Ent> VectorPtr<Ent> getVector(typename Ent::Position cle1, const QVariant & value1,
                                                 typename Ent::Position cle2, const QVariant & value2,
                                                 typename Ent::Position cle3, const QVariant & value3,
                                                 typename Ent::Position ordre = Ent::Id,
                                                 bdd::Condition cond1 = bdd::Condition::Egal, bdd::Condition cond2 = bdd::Condition::Egal,
                                                 bdd::Condition cond3 = bdd::Condition::Egal,
                                                 bool crois = true);

    //! Renvoie le vector des entités de la table vérifiant une condition sur une jointure (colonneTable = colonneJoin),
    //! valeur des colonnes de la table Ent d'identifiant key = value de QMap whereMapTable,
    //! valeur des colonnes de la table Join d'identifiant key = value de QMap whereMapJoin,
    //! ordonnée suivant les colonnes de la table Ent d'identifiants key et d'ordre value de QMap orderMapTable (true -> croissant, false -> décroissant).
    template<class Ent, class Join> VectorPtr<Ent> getVector(typename Ent::Position colonneTable,
                                                   typename Join::Position colonneJoin,
                                                   const QMap<int,QVariant> & whereMapTable,
                                                   const QMap<int,QVariant> & whereMapJoin,
                                                   const QMap<int,bool> & orderMapTable);

    //! Renvoie la liste des entités de la table vérifiant une condition sur une jointure,
    //! valeur de la colonne de la jointure d'identifiant cleWhere = valueWhere,
    //! ordonnée suivant la colonne de l'entité d'identifiant ordre.
    template<class Ent, class Join> VectorPtr<Ent> getVector(typename Ent::Position cleJoin, typename Join::Position cleWhere, const QVariant & valueWhere, typename Ent::Position ordre = Ent::Id, bdd::Condition cond = bdd::Condition::Egal, bool crois = true);

    //! Teste si la base de donnée est valide.
    bool isValid()
        {return true;}

    //! Ouvre la base de donnée.
    bool open();

    //! Enregistre l'entity dans la base de donnée.
    template<class Ent> void save(Ent & entity);

    //! Enregistre l'entity dans la base de donnée.
    template<class Ent> void save(const Ent && entity);

    //! Enregistre l'arbre d'entités dans la base de donnée.
    template<class Ent> void save(Tree<Ent> & arbre, bdd::TreeSave n = bdd::TreeSave::ExternalChange);

    //! Enregistre les entités de vector dans la base de donnée.
    template<class Ent> void save(VectorPtr<Ent> & vector);

    //! Transmet la connexion à la base de donnée aux managers.
    void setBdd();

    //! Modifie le chemin de la base de donnée.
    void setFileName(const QString & fileName);

protected:
    //! Mise à jour de la base de donnée.
    virtual void listeMiseAJourBdd(int /*version*/)
        {}

    //! Mise à jour de la base de donnée.
    void miseAJourBdd();

    //! Ouverture de la base de donnée.
    bool openBdd();
};

template<class Ent> bool AbstractBdd::exists(const Ent & entity)
{
    if(entity.isNew())
    {
        return false;
    }
    else
    {
        return m_manager.get<Ent>().exists(entity);
    }
}

template<class Ent> bool AbstractBdd::exists(typename Ent::Position cle, const QVariant & value, bdd::Condition cond)
    { return m_manager.get<Ent>().exists(cle,value,cond);}

template<class Ent> bool AbstractBdd::existsUnique(Ent & entity)
    { return m_manager.get<Ent>().existsUnique(entity) != bdd::Aucun;}

template<class Ent> bool AbstractBdd::existsUnique(const Ent & entity)
    { return m_manager.get<Ent>().existsUnique(entity) != bdd::Aucun;}

template<class Ent> bdd::ExisteUni AbstractBdd::existsUniqueEnsemble(Ent & entity)
    { return m_manager.get<Ent>().existsUnique(entity);}

template<class Ent> bdd::ExisteUni AbstractBdd::existsUniqueEnsemble(const Ent & entity)
    { return m_manager.get<Ent>().existsUnique(entity);}

template<class Ent, class T> T AbstractBdd::fonctionAgrega(bdd::Agrega fonc, typename Ent::Position att)
    {return m_manager.get<Ent>().fonctionAgrega(fonc, att);}

template<class Ent, class T> T AbstractBdd::fonctionAgrega(bdd::Agrega fonc, typename Ent::Position att, typename Ent::Position cle, const QVariant & value, bdd::Condition cond)
    {return m_manager.get<Ent>().fonctionAgrega(fonc, att, cle, value, cond);}

template<class Ent, class T> T AbstractBdd::fonctionAgrega(bdd::Agrega fonc, typename Ent::Position att, typename Ent::Position cle1, const QVariant & value1, typename Ent::Position cle2, const QVariant & value2, bdd::Condition cond1, bdd::Condition cond2)
    {return m_manager.get<Ent>().fonctionAgrega(fonc, att, cle1, value1, cle2, value2, cond1, cond2);}

template<class Ent> bool AbstractBdd::get(Ent & entity)
    {return m_manager.get<Ent>().get(entity);}

template<class Ent> Tree<Ent> AbstractBdd::getArbre(int id)
    {return m_manager.get<Ent>().getArbre(id);}

template<class Ent> ListPtr<Ent> AbstractBdd::getList(typename Ent::Position ordre, bool croissant)
    {return m_manager.get<Ent>().getList(ordre, croissant);}

template<class Ent> ListPtr<Ent> AbstractBdd::getList(typename Ent::Position cle, const QVariant & value, typename Ent::Position ordre, Condition cond, bool crois)
    {return m_manager.get<Ent>().getList(cle, value, ordre, cond, crois);}

template<class Ent> ListPtr<Ent> AbstractBdd::getList(typename Ent::Position cle, const QVariant & value, typename Ent::Position order1, typename Ent::Position order2, bdd::Condition cond, bool croissant1, bool croissant2)
    {return m_manager.get<Ent>().getList(cle, value, order1, order2, cond, croissant1, croissant2);}

template<class Ent> ListPtr<Ent> AbstractBdd::getList(typename Ent::Position cle, const QVariant & value, typename Ent::Position order1, typename Ent::Position order2, typename Ent::Position ordre3, bdd::Condition cond, bool croissant1, bool croissant2, bool croissant3)
    {return m_manager.get<Ent>().getList(cle, value, order1, order2, ordre3, cond, croissant1, croissant2, croissant3);}

template<class Ent> ListPtr<Ent> AbstractBdd::getList(typename Ent::Position cle1, const QVariant & value1, typename Ent::Position cle2, const QVariant & value2, typename Ent::Position order, bdd::Condition cond1, bdd::Condition cond2, bool croissant)
    { return m_manager.get<Ent>().getList(cle1, value1, cle2, value2, order, cond1, cond2, croissant);}

template<class Ent> ListPtr<Ent> AbstractBdd::getList(typename Ent::Position cle1, const QVariant & value1, typename Ent::Position cle2, const QVariant & value2, typename Ent::Position cle3, const QVariant & value3, typename Ent::Position order, bdd::Condition cond1, bdd::Condition cond2, bdd::Condition cond3, bool croissant)
    {return m_manager.get<Ent>().getList(cle1, value1, cle2, value2, cle3, value3, order, cond1, cond2, cond3, croissant);}

template<class Ent, class Join> ListPtr<Ent> AbstractBdd::getList(typename Ent::Position colonneTable, typename Join::Position colonneJoin,
                                               const QMap<int,QVariant> & whereMapTable, const QMap<int,QVariant> & whereMapJoin,
                                               const QMap<int,bool> & orderMapTable)
{
    QMap<QString,QVariant> whereMapJoinString;
    for(QMap<int,QVariant>::const_iterator i = whereMapJoin.cbegin(); i != whereMapJoin.cend(); i++)
        whereMapJoinString.insert(m_manager.get<Join>().attribut(i.key()),i.value());
    return m_manager.get<Ent>().getListJoin(m_manager.get<Join>().table(),colonneTable, m_manager.get<Join>().attribut(colonneJoin),
                                                      whereMapTable, whereMapJoinString, orderMapTable);
}

template<class Ent, class Join> ListPtr<Ent> AbstractBdd::getList(typename Ent::Position cleJoin, typename Join::Position cleWhere, const QVariant & valueWhere, typename Ent::Position ordre, bdd::Condition cond, bool crois)
{
    return m_manager.get<Ent>().getListJoin(m_manager.get<Join>().table(),m_manager.get<Join>().attribut(cleJoin), get<Join>().attribut(cleWhere),
                                                      valueWhere, ordre, cond, crois);
}

template<class Ent> bool AbstractBdd::getUnique(Ent & entity)
    {return m_manager.get<Ent>().getUnique(entity);}

template<class Ent> VectorPtr<Ent> AbstractBdd::getVector(typename Ent::Position ordre, bool croissant)
    {return VectorPtr<Ent>(m_manager.get<Ent>().getList(ordre, croissant));}

template<class Ent> VectorPtr<Ent> AbstractBdd::getVector(typename Ent::Position cle, const QVariant & value, typename Ent::Position ordre, Condition cond, bool crois)
    {return VectorPtr<Ent>(m_manager.get<Ent>().getList(cle, value, ordre, cond, crois));}

template<class Ent> VectorPtr<Ent> AbstractBdd::getVector(typename Ent::Position cle, const QVariant & value, typename Ent::Position ordre1, typename Ent::Position ordre2, Condition cond, bool crois1, bool crois2)
    {return VectorPtr<Ent>(m_manager.get<Ent>().getList(cle, value, ordre1, ordre2, cond, crois1, crois2));}

template<class Ent> VectorPtr<Ent> AbstractBdd::getVector(typename Ent::Position cle, const QVariant & value, typename Ent::Position ordre1, typename Ent::Position ordre2, typename Ent::Position ordre3, bdd::Condition cond, bool crois1, bool crois2, bool crois3)
    {return VectorPtr<Ent>(m_manager.get<Ent>().getList(cle, value, ordre1, ordre2, ordre3, cond, crois1, crois2, crois3));}

template<class Ent> VectorPtr<Ent> AbstractBdd::getVector(typename Ent::Position cle1, const QVariant & value1, typename Ent::Position cle2, const QVariant & value2, typename Ent::Position order, bdd::Condition cond1, bdd::Condition cond2, bool croissant)
    {return VectorPtr<Ent>(m_manager.get<Ent>().getList(cle1, value1, cle2, value2, order, cond1, cond2, croissant));}

template<class Ent> VectorPtr<Ent> AbstractBdd::getVector(typename Ent::Position cle1, const QVariant & value1, typename Ent::Position cle2, const QVariant & value2, typename Ent::Position cle3, const QVariant & value3, typename Ent::Position order, bdd::Condition cond1, bdd::Condition cond2, bdd::Condition cond3, bool croissant)
    {return VectorPtr<Ent>(m_manager.get<Ent>().getList(cle1, value1, cle2, value2, cle3, value3, order, cond1, cond2, cond3, croissant));}

template<class Ent, class Join> VectorPtr<Ent> AbstractBdd::getVector(typename Ent::Position colonneTable, typename Join::Position colonneJoin,
                                               const QMap<int,QVariant> & whereMapTable, const QMap<int,QVariant> & whereMapJoin,
                                               const QMap<int,bool> & orderMapTable)
{
    QMap<QString,QVariant> whereMapJoinString;
    for(QMap<int,QVariant>::const_iterator i = whereMapJoin.cbegin(); i != whereMapJoin.cend(); i++)
        whereMapJoinString.insert(m_manager.get<Join>().attribut(i.key()),i.value());
    return VectorPtr<Ent>(m_manager.get<Ent>().getListJoin(m_manager.get<Join>().table(),
                                                                          colonneTable, m_manager.get<Join>().attribut(colonneJoin),
                                                                          whereMapTable, whereMapJoinString, orderMapTable));

}

template<class Ent, class Join> VectorPtr<Ent> AbstractBdd::getVector(typename Ent::Position cleJoin, typename Join::Position cleWhere, const QVariant & valueWhere, typename Ent::Position ordre, bdd::Condition cond, bool crois)
    {return VectorPtr<Ent>(m_manager.get<Ent>().getListJoin(m_manager.get<Join>().table(),m_manager.get<Join>().attribut(cleJoin),
                                                                           get<Join>().attribut(cleWhere),
                                                                           valueWhere, ordre, cond, crois));}

template<class Ent> void AbstractBdd::save(Ent & entity)
    {m_manager.get<Ent>().save(entity);}

template<class Ent> void AbstractBdd::save(const Ent &&entity)
    {m_manager.get<Ent>().save(entity);}

template<class Ent> void AbstractBdd::save(Tree<Ent> & arbre, bdd::TreeSave n)
    {m_manager.get<Ent>().save(arbre,n);}

template<class Ent> void AbstractBdd::save(VectorPtr<Ent> & vector)
{
   for(typename VectorPtr<Ent>::iterator i = vector.begin(); i != vector.end(); ++i)
       m_manager.get<Ent>().save(*i);
}

#endif // ABSTRACTBDD_H
