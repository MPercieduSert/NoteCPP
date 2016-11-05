/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */

#ifndef MANAGERSQL_H
#define MANAGERSQL_H

#include "Manager.h"
#include "ReqSql.h"

// Macro pour manageur.
//! \ingroup groupeBaseManager
//! Coprs des deux methodes save.
#define SAVE if(entity.isValid()) \
    {if(entity.isNew()) \
        {if(existsUnique(entity) == bdd::Aucun) \
            add(entity); \
         else \
            throw std::invalid_argument(messageErreursUnique(entity).append("\n Erreur d'unicité : il existe déjà dans la base de donnée une entité ayant les mêmes valeurs d'attributs unique que cette nouvelle entité.").toStdString());} \
    else \
        {if(!sameInBdd(entity)) \
            {if(existsUnique(entity) <= bdd::Meme) \
                modify(entity); \
            else \
                throw std::invalid_argument(messageErreursUnique(entity).append("\n Erreur d'unicité :  il existe déjà dans la base de donnée une entité ayant les mêmes valeurs d'attributs unique que l'entité modifiée.").toStdString());}}} \
else \
    throw std::invalid_argument(messageErreurs(entity).append("\n Erreur de validité").toStdString());

/*! \ingroup groupeBaseManager
 * \brief Classe template mère des différents manageurs de type SQL.
 */
class AbstractManagerSql :  public Manager, public ReqSql
{
protected:
    static const QVector<QString> m_fonctionAgregaString;
    static const QVector<QString> m_conditionString;
    //static const std::array<const char *, bdd::Condition> m_fonctionConditionString;

public:
    //! Contructeur, transmettre en argument la connexion ouverte à le base de donnée.
    AbstractManagerSql()
        : ReqSql()
        {}

    //! Destructeur.
    ~AbstractManagerSql()  {}
};

/*! \ingroup groupeBaseManager
 * \brief Classe template mère des différents manageurs de type SQL.
 *
 * Classe template permettant d'instancier les différents manageurs.
 * Cette classe implémente les méthodes virtuelles pures de sa classe mère.
 * La classe Ent est la classe d'entité de programmation,
 * la classe Link est le lien avec les entités en base de donnée
 * et la classe Unique permet de faire les tests d'unicité.
 * La classe Link doit implémenter les membres suivantes :
 *  - const QString & attribut(int i) const-> Renvoie le nom en base de donnée du i-ème attribut.
 *  - void bindValues(const Ent & entity) -> Transmet à la requète préparée les valeurs des attributs de l'entité.
 *  - QString creer() const-> Renvoie la requète pour créer la table correspondant à l'entité dans la base de donnée.
 *  - void fromRequete(Ent & entity) -> Enregistre dans l'entité les valeurs des attributs de l'entité coorespond à la réquète de type SELECT prcédente.
 *  - NbrAtt -> Nombre d'attribut de la table.
 *  - Ent * newFromRequete() -> Crée dynamiquement une entité ayant les valeurs des attributs de l'entité coorespond à la réquète de type SELECT prcédente, puis renvoie un pointeur sur cette nouvelle entité.
 *  - void setId(const & Entity entity, int i = 0) -> Transmet à la requète préparée la valeur de l'identifiant de l'entité pour la position i.
 *  - const QString & table() const -> Renvoie le nom de la table.
 * La classe Unique doit implémenter les membres suivantes :
 *  - int attribut(int i) const -> Renvoie l'indice du i-ème attribut unique.
 *  - bdd::ExisteUni existeUnique(Ent & entity) -> Teste s'il y a des coorespondances entre les attributs uniques de l'entité et les entités enregistrées dans la base de donnée et modifie l'identifiant dans la cas Bdd::ExistUni::Tous.
 *  - bdd::ExisteUni existeUnique(const Ent &) -> Teste s'il y a des coorespondances entre les attributs uniques de l'entité et les entités enregistrées dans la base de donnée.
 *  - int nbrAttUnique() const -> Renvoie le nombre d'attributs uniques.
 */
template<class Ent, class Link, class Unique> class ManagerSql : public AbstractManagerSql
{
protected:
    Link m_link;            //!< Lien.
    Unique m_unique;        //! Condition d'unicité.
    // Requête sql
    QString m_sqlAdd;       //!< Requéte sql d'insertion d'une ligne.
    QString m_sqlDelete;    //!< Requéte sql de suppression d'une ligne
    QString m_sqlExists;    //!< Requéte sql d'existence d'une ligne d'identifiant donné.
    QString m_sqlExistsWhere;    //!< Requéte sql d'existense d'une ligne vérifiant une condition.
    QString m_sqlFonctionAgrega;    //!< Requéte sql appliquant une fonction d'agrega à toutes les lignes de la table.
    QString m_sqlFonctionAgregaWhere1;      //!< Requéte sql appliquant une fonction d'agrega aux lignes de la table vérifiant une condition.
    QString m_sqlFonctionAgregaWhere2;      //!< Requéte sql appliquant une fonction d'agrega aux lignes de la table vérifiant deux conditions.
    QString m_sqlGet;       //!< Requéte sql de lecture d'une ligne d'identifiant donné.
    QString m_sqlGetList;   //!< Requéte sql de lecture de toutes les lignes de la table triées suivant une colonne.
    QString m_sqlGetListWhere;      //!< Requéte sql de lecture des lignes de la table vérifiant une condition.
    QString m_sqlGetList1Where1;    //!< Requéte sql de lecture des lignes de la table vérifiant une condition triées suivant une colonne.
    QString m_sqlGetList1Where2;    //!< Requéte sql de lecture des lignes de la table vérifiant une condition triées suivant deux colonnes.
    QString m_sqlGetList1Where3;    //!< Requéte sql de lecture des lignes de la table vérifiant une condition triées suivant trois colonnes.
    QString m_sqlGetList2Where1;    //!< Requéte sql de lecture des lignes de la table vérifiant deux conditions triées suivant une colonne.
    QString m_sqlGetList3Where1;    //!< Requéte sql de lecture des lignes de la table vérifiant deux conditions triées suivant une colonne.
    QString m_sqlGetListJoin;        //!< Requéte sql de lecture des lignes de la table vérifiant une condition avec une jointure triées jusqu'à trois colonnes.
    QString m_sqlGetListJoin1Where1;        //!< Requéte sql de lecture des lignes de la table vérifiant une condition avec une jointure triées suivant une colonne.
    QString m_sqllastId;    //!< Requéte sql de lecture de l'identifiant de la dernière ligne insérée dans la table.
    QString m_sqlModify;    //!< Requéte sql de mis à jour d'une ligne de la table.

    using AbstractManagerSql::value;

public:
    //! Contructeur, avec les noms des attributs de la table.
    ManagerSql(const QString & table, const QMap<int,QString> & att, const QVector<QMap<int,int>> & attUnique);

    //! Destructeur.
    ~ManagerSql()  {}

    //! Renvoie le nom en base de donnée du i-ème attribut.
    const QString & attribut(int pos) const
        {return m_link.attribut(pos);}

    /*//! Renvoie le nom en base de donnée du i-ème attribut unique.
    const QString & attributUnique(int i) const
        {return m_link.attribut(m_unique.attributUnique(i));}*/

    //! Teste s'il existe une entité de même identifiant que entity en base de donnée.
    bool exists(const Entity & entity)
    {
        if(Ent::verifEntity(entity))
        {
            prepare(m_sqlExists);
            m_link.setId(entity);
            exec();
            bool bb = next();
            finish();
            return bb;
        }
        else
            {throw std::runtime_error("Mauvaise correspondance des Entity");}
    }

    //! Teste s'il existe une entité de même identifiant que entity en base de donnée.
    bool exists(const Ent & entity)
    {
        prepare(m_sqlExists);
        m_link.setId(entity);
        exec();
        bool bb = next();
        finish();
        return bb;
    }

    //! Teste s'il existe une entité vérifiant une condition.
    bool exists(typename Ent::Position cle, const QVariant & value, bdd::Condition cond = bdd::Condition::Egal)
    {
        prepare(m_sqlExistsWhere.arg(QString(attribut(cle)).append(m_conditionString[cond]).append("?")));
        bindValue(0,value);
        exec();
        bool bb = next();
        finish();
        return bb;
    }

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    bdd::ExisteUni existsUnique(Ent & entity)
        {return m_unique.existsUnique(entity);}

    //! Idem bdd::ExisteUni existsUnique(Ent & entity) avec une conversion de référence.
    bdd::ExisteUni existsUnique(Entity & entity)
        {return existsUnique(Ent::convert(entity));}

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que entity en base de donnée.
    bdd::ExisteUni existsUnique(const Ent & entity)
        {return m_unique.existsUnique(entity);}

    //! Idem bdd::ExisteUni existsUnique(const Ent & entity) avec une conversion de référence.
    bdd::ExisteUni existsUnique(const Entity & entity)
        {return existsUnique(Ent::convert(entity));}

    //! Fonction d'agrega de valeur de type T sur l'attribut att appliquée à toutes les entités de la table.
    template<class T> T fonctionAgrega(bdd::Agrega fonc, typename Ent::Position att)
    {
        exec(m_sqlFonctionAgrega.arg(m_fonctionAgregaString[fonc],
                                     attribut(att)));
        next();
        return value<T>();
    }

    //! Fonction d'agrega de valeur de type T sur l'attribut att appliquée à toutes les entités vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value.
    template<class T> T fonctionAgrega(bdd::Agrega fonc, typename Ent::Position att, typename Ent::Position cle, const QVariant & value,
                                       bdd::Condition cond = bdd::Condition::Egal)
    {
        prepare(m_sqlFonctionAgregaWhere1.arg(m_fonctionAgregaString[fonc],
                                              attribut(att),
                                              attribut(cle),
                                              m_conditionString[cond]));
        bindValue(0,value);
        exec();
        next();
        return AbstractManagerSql::template value<T>();
    }

    //! Fonction d'agrega de valeur de type T sur l'attribut att appliquée à toutes les entités vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1 et valeur de la colonne d'identifiant cle2 = value2.
    template<class T> T fonctionAgrega(bdd::Agrega fonc, typename Ent::Position att, typename Ent::Position cle1, const QVariant & value1, typename Ent::Position cle2, const QVariant & value2, bdd::Condition cond1 = bdd::Condition::Egal, bdd::Condition cond2 = bdd::Condition::Egal)
    {
        prepare(m_sqlFonctionAgregaWhere2.arg(m_fonctionAgregaString[fonc],
                                              attribut(att),
                                              attribut(cle1),
                                              m_conditionString[cond1],
                                              attribut(cle2),
                                              m_conditionString[cond2]));
        bindValue(0,value1);
        bindValue(1,value2);
        exec();
        next();
        return value<T>();
    }

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrée en base de donnée
    //! ayant le même identifiant que entity.
    //! Retourne True si l'opération s'est correctement déroulée.
    bool get(Entity & entity)
        {return get(Ent::convert(entity));}

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrée en base de donnée
    //! ayant le même identifiant que entity.
    //! Retourne True si l'opération s'est correctement déroulée.
    bool get(Ent & entity)
    {
        prepare(m_sqlGet);
        m_link.setId(entity);
        exec();
        if(next())
        {
            m_link.fromRequete(entity);
            finish();
            return true;
        }
        else
        {
            finish();
            return false;
        }
    }

    //! Renvoie la liste des entités de la table vérifiant la condition.
    ListPtr<Ent> getList(const QString & condition)
    {
        prepare(m_sqlGetListWhere.arg(condition));
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table ordonnée suivant la colonne d'identifiant ordre.
    ListPtr<Ent> getList(typename Ent::Position ordre = Ent::Id, bool crois = true)
    {
        prepare(m_sqlGetList.arg(attribut(ordre),croissant(crois)));
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant la colonne d'identifiant ordre.
    ListPtr<Ent> getList(typename Ent::Position cle, const QVariant & value, typename Ent::Position ordre = Ent::Id, bdd::Condition cond = bdd::Condition::Egal, bool crois = true)
    {
        prepare(m_sqlGetList1Where1.arg(attribut(cle), m_conditionString[cond],
                                        attribut(ordre), croissant(crois)));
        bindValue(0,value);
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant les colonnes d'identifiant ordre1 puis ordre2.
    ListPtr<Ent> getList(typename Ent::Position cle, const QVariant & value, typename Ent::Position ordre1, typename Ent::Position ordre2, bdd::Condition cond = bdd::Condition::Egal, bool crois1 = true, bool crois2 = true)
    {
        prepare(m_sqlGetList1Where2.arg(attribut(cle), m_conditionString[cond],
                                        attribut(ordre1), croissant(crois1),
                                        attribut(ordre2), croissant(crois2)));
        bindValue(0,value);
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant les colonnes d'identifiant ordre1, ordre2 puis ordre3.
    ListPtr<Ent> getList(typename Ent::Position cle, const QVariant & value, typename Ent::Position ordre1, typename Ent::Position ordre2, typename Ent::Position ordre3,
                         bdd::Condition cond = bdd::Condition::Egal,
                         bool crois1 = true, bool crois2 = true, bool crois3 = true)
    {
        prepare(m_sqlGetList1Where3.arg(attribut(cle), m_conditionString[cond],
                                        attribut(ordre1), croissant(crois1),
                                        attribut(ordre2), croissant(crois2),
                                        attribut(ordre3), croissant(crois3)));
        bindValue(0,value);
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1 et valeur de la colonne d'identifiant cle2 = value2,
    //! ordonnée suivant la colonne d'identifiant ordre.
    ListPtr<Ent> getList(typename Ent::Position cle1, const QVariant & value1, typename Ent::Position cle2,  const QVariant & value2,
                         typename Ent::Position ordre = Ent::Id, bdd::Condition cond1 = bdd::Condition::Egal, bdd::Condition cond2 = bdd::Condition::Egal, bool crois = true)
    {
        prepare(m_sqlGetList2Where1.arg(attribut(cle1), m_conditionString[cond1],
                                        attribut(cle2), m_conditionString[cond2],
                                        attribut(ordre), croissant(crois)));
        bindValue(0,value1);
        bindValue(1,value2);
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1, valeur de la colonne d'identifiant cle2 = value2
    //! et valeur de la colonne d'identifiant cle3 = value3,
    //! ordonnée suivant la colonne d'identifiant ordre.
    ListPtr<Ent> getList(typename Ent::Position cle1, const QVariant & value1,
                         typename Ent::Position cle2, const QVariant & value2,
                         typename Ent::Position cle3, const QVariant & value3,
                         typename Ent::Position ordre = Ent::Id,
                         bdd::Condition cond1 = bdd::Condition::Egal, bdd::Condition cond2 = bdd::Condition::Egal,
                         bdd::Condition cond3 = bdd::Condition::Egal,
                         bool crois = true)
    {
        prepare(m_sqlGetList3Where1.arg(attribut(cle1), m_conditionString[cond1],
                                        attribut(cle2), m_conditionString[cond2],
                                        attribut(cle3), m_conditionString[cond3],
                                        attribut(ordre), croissant(crois)));
        bindValue(0,value1);
        bindValue(1,value2);
        bindValue(1,value3);
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table vérifiant une condition sur une jointure (colonneTable = colonneJoin),
    //! valeur des colonnes de la table Ent d'identifiant key = value de QMap whereMapTable,
    //! valeur des colonnes de la table Join key = value de QMap whereMapJoin,
    //! ordonnée suivant les colonnes de la table Ent d'identifiants key et d'ordre value de QMap orderMapTable (true -> croissant, false -> décroissant).
    ListPtr<Ent> getListJoin(const QString & tableJoin, int colonneTable,
                                                   const QString & colonneJoin,
                                                   const QMap<int,QVariant> & whereMapTable,
                                                   const QMap<QString,QVariant> & whereMapJoin,
                                                   const QMap<int,bool> & orderMapTable)
    {
        QString sqlWhere;
        for(QMap<int,QVariant>::const_iterator i = whereMapTable.cbegin(); i != whereMapTable.cend(); ++i)
            sqlWhere.append("T.").append(attribut(i.key())).append("=? AND ");
        for(QMap<QString,QVariant>::const_iterator i = whereMapJoin.cbegin(); i != whereMapJoin.cend(); ++i)
            sqlWhere.append("J.").append(i.key()).append("=? AND ");
        sqlWhere.chop(5);
        QString sqlOrder;
        for(QMap<int,bool>::const_iterator i = orderMapTable.cbegin(); i != orderMapTable.cend(); ++i)
            sqlOrder.append(" T.").append(attribut(i.key())).append(croissant(i.value())).append(",");
        sqlOrder.chop(1);
        prepare(m_sqlGetListJoin.arg(tableJoin,
                                     attribut(colonneTable),
                                     colonneJoin,
                                     sqlWhere,
                                     sqlOrder));
        int j = 0;
        for(QMap<int,QVariant>::const_iterator i = whereMapTable.cbegin(); i != whereMapTable.cend(); ++i, ++j)
            bindValue(j,i.value());
        for(QMap<QString,QVariant>::const_iterator i = whereMapJoin.cbegin(); i != whereMapJoin.cend(); ++i, ++j)
            bindValue(j,i.value());
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table vérifiant une condition sur une jointure (table.ID = join.colonneJoin),
    //! valeur de la colonne de la jointure d'identifiant cleWhere = valueWhere,
    //! ordonnée suivant la colonne de l'entité d'identifiant ordre.
    template<class Join> ListPtr<Ent> getListJoin(const QString & tableJoin,
                                                       const QString & colonneJoin,
                                                       const QString & whereJoin,
                                                       const QVariant & valueWhere,
                                                       typename Ent::Position ordre = Ent::Id, bdd::Condition cond = bdd::Condition::Egal, bool crois = true)
    {
        prepare(m_sqlGetListJoin1Where1.arg(tableJoin,
                                            colonneJoin,
                                            whereJoin, cond,
                                            attribut(ordre), croissant(crois)));
        bindValue(0,valueWhere);
        return listFormRequete();
    }

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrée en base de donnée
    //! ayant les mêmes valeurs pour les attributs uniques.
    //! Retourne True si l'opération s'est correctement déroulée.
    bool getUnique(Entity & entity)
        {return getUnique(Ent::convert(entity));}

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrée en base de donnée
    //! ayant les mêmes valeurs pour les attributs uniques.
    //! Retourne True si l'opération s'est correctement déroulée.
    bool getUnique(Ent & entity)
    {
        if(existsUnique(entity) == bdd::Tous)
        {
            return get(entity);
        }
        else
        {
            return false;
        }
    }

    //! Teste s'il y a dans la base de donnée une entité ayant exactement les mêmes attributs (identifiant compris).
    bool sameInBdd(const Entity &entity)
        {return sameInBdd(Ent::convert(entity));}

    //! Teste s'il y a dans la base de donnée une entité ayant exactement les mêmes attributs (identifiant compris).
    bool sameInBdd(const Ent &entity)
    {
        Ent entityT(entity.id());
        if(get(entityT))
            return entityT == entity;
        else
            return false;
    }

    //! Enregistre l'entité entity en base de donnée et assigne l'identifiant de l'entité insérée en base de donnée à entity.
    void save(Entity & entity)
        {save(Ent::convert(entity));}

    //! Enregistre l'entité entity en base de donnée.
    void save(const Entity & entity)
        {save(Ent::convert(entity));}

    //! Enregistre l'entité entity en base de donnée et assigne l'identifiant de l'entité insérée en base de donnée à entity.
    void save(Ent & entity)
        {SAVE}

    //! Enregistre l'entité entity en base de donnée.
    void save(const Ent & entity)
        {SAVE}

    //! Renvoie le nom de la table de l'entité dans la base de donnée.
    const QString & table() const
        {return m_link.table();}

protected:
    //! Insert la nouvelle entité entity dans la base de donnée
    //! et assigne l'identifiant de l'entité insérée en base de donnée à entity.
    virtual void add(Ent & entity)
    {
        prepare(m_sqlAdd);
        m_link.bindValues(entity);
        exec();
        exec(m_sqllastId);
        next();
        entity.setId(value<int>());
        finish();
    }

    //! Insert la nouvelle entité entity dans la base de donnée.
    virtual void add(const Ent & entity)
    {
        prepare(m_sqlAdd);
        m_link.bindValues(entity);
        execFinish();
    }

    //! Crée dans la base de donnée la table associée l'entité du manageur.
    void creerSql(const QMap<int,QPair<bdd::createSql,bool>>& attCaract,
               const QVector<QMap<int,int>> & attUnique = QVector<QMap<int,int>>(),
               const QMap<int,QString> & foreignKey = QMap<int,QString>());

    //! Renvoit la chaine de caractères "ACS" ou "DESC"
    QString croissant(bool crois)
        {return crois ? QString(): " DESC";}

    //! Supprime de la table en base de donnée l'entité d'identifiant id.
    void del(int id)
    {
        prepare(m_sqlDelete);
        bindValue(0,id);
        execFinish();
    }

    //! Construit la liste des entités correspondant une requète de type sqlGetList.
    ListPtr<Ent> listFormRequete()
    {
        exec();
        ListPtr<Ent> liste;
        while(next())
        {
            liste.append(m_link.newFromRequete());
        }
        finish();
        return liste;
    }

    //! Message d'erreurs si l'entité entity n'est pas valide.
    QString messageErreurs(const Entity & entity) const;

    //! Message d'erreurs s'il existe déjà en base de donnée une entité ayant les mêmes valeurs d'attributs uniques que entity.
    QString messageErreursUnique(const Entity & entity) const;

    //! Met à jour l'entité entity en base de donnée.
    virtual void modify(const Ent & entity)
    {
        prepare(m_sqlModify);
        m_link.bindValues(entity);
        m_link.setId(entity,m_link.nbrAtt()-1);
        execFinish();
    }

    //! Transforme QVector<QMap<int,int>> en QVector<QMap<int,QString>> avec les noms des attributs
    QVector<QMap<int,QString>> uniqueInit(const QVector<QMap<int,int>> & attsInt);

    //! Ecrit les chaines des requètes sql.
    void writeStringSql();
};

template<class Ent, class Link, class Unique> ManagerSql<Ent,Link,Unique>::ManagerSql(const QString &table, const QMap<int, QString> &att, const QVector<QMap<int, int>>  & attUnique)
    : m_link(table,att),
      m_unique(table,uniqueInit(attUnique))
    {writeStringSql();}

template<class Ent, class Link, class Unique> void ManagerSql<Ent,Link,Unique>::creerSql(const QMap<int,QPair<bdd::createSql,bool>>& attCaract,
                                                                                      const QVector<QMap<int, int> > & attUnique,
                                                                                      const QMap<int,QString> & foreignKey)
{
    QString sql(m_link.creer(attCaract,foreignKey));
    sql.append(m_unique.creer(table(),uniqueInit(attUnique)));
    sql.append(")");
    exec(sql);
}

template<class Ent, class Link, class Unique> QString ManagerSql<Ent,Link,Unique>::messageErreurs(const Entity & entity) const
{
    QString message("Entité invalide:");
    message.append(Ent::Name()).append(" d'identifiant:").append(QString::number(entity.id())).append("\n")
            .append(entity.toString());
    return message;
}

template<class Ent, class Link, class Unique> QString ManagerSql<Ent,Link,Unique>::messageErreursUnique(const Entity & entity) const
{
    QString message("Entité ayant les même valeurs d'attributs unique déjà présente dans la base de donnée.\n");
    message.append(Ent::Name()).append(" d'identifiant:").append(QString::number(entity.id())).append("\n");
    message.append(entity.toString());
    /*if(m_unique.nbrAttUnique() != 0)
    {
        message.append("Valeurs Uniques:\n");
        for(int i = 0; i != m_unique.nbrAttUnique(); ++i)
            message.append(attributUnique(i)).append("\n");
    }*/
    return message;
}

template<class Ent, class Link, class Unique> QVector<QMap<int,QString>> ManagerSql<Ent,Link,Unique>::uniqueInit(const QVector<QMap<int,int>> & attsInt)
{
    QVector<QMap<int,QString>> attsString(attsInt.size());
    for(int i = 0; i!= attsInt.size(); ++i)
    {
        for(QMap<int,int>::const_iterator j = attsInt.at(i).cbegin(); j != attsInt.at(i).cend(); ++j)
            attsString[i].insert(j.key(), m_link.attribut(j.value()));
    }
    return attsString;
}

template<class Ent, class Link, class Unique> void ManagerSql<Ent,Link,Unique>::writeStringSql()
{
    // Liste des colonnes.
    QString colonnesId;
    for(int i = 0; i != m_link.nbrAtt(); ++i)
        colonnesId.append(attribut(i)).append(",");
    colonnesId.chop(1);

    QString colonnes;
    for(int i = 1; i != m_link.nbrAtt(); ++i)
        colonnes.append(attribut(i)).append(",");
    colonnes.chop(1);

    QString idEgal(attribut(Ent::Id));
    idEgal.append("=?");

    // Select where
    m_sqlGetListWhere.append("SELECT ");
    m_sqlGetListWhere.append(colonnesId).append(" FROM ").append(table()).append(" WHERE %1");
    m_sqlGetListWhere.squeeze();

    // Select Join
    QString selectJoin("SELECT ");
    for(int i = 0; i != m_link.nbrAtt(); ++i)
        selectJoin.append("T.").append(attribut(i)).append(",");
    selectJoin.chop(1);
    selectJoin.append(" FROM ").append(table()).append(" T JOIN %1 J ON ");

    // Add
    m_sqlAdd.append("INSERT INTO ");
    m_sqlAdd.append(table()).append("(").append(colonnes).append(") VALUES(");
    for(int i = 1; i != m_link.nbrAtt(); ++i)
        m_sqlAdd.append("?,");
    m_sqlAdd.chop(1);
    m_sqlAdd.append(")");
    m_sqlAdd.squeeze();

    // Delete
    m_sqlDelete.append("DELETE FROM ");
    m_sqlDelete.append(table()).append(" WHERE ").append(idEgal);
    m_sqlDelete.squeeze();

    // ExisteWhere
    m_sqlExistsWhere.append("SELECT 1 FROM ");
    m_sqlExistsWhere.append(table()).append(" WHERE %1 LIMIT 1");
    m_sqlExists.squeeze();

    // Existe
    m_sqlExists.append(m_sqlExistsWhere.arg(idEgal));
    m_sqlExists.squeeze();

    // Agrega
    m_sqlFonctionAgrega.append("SELECT %1(%2) FROM ");
    m_sqlFonctionAgrega.append(table());
    m_sqlFonctionAgrega.squeeze();

    // Agrega where 1
    m_sqlFonctionAgregaWhere1.append(m_sqlFonctionAgrega);
    m_sqlFonctionAgregaWhere1.append(" WHERE %3%4?");
    m_sqlFonctionAgregaWhere1.squeeze();

    // Agrega where 2
    m_sqlFonctionAgregaWhere2.append(m_sqlFonctionAgregaWhere1);
    m_sqlFonctionAgregaWhere2.append(" AND %5%6?");
    m_sqlFonctionAgregaWhere2.squeeze();

    // Get
    m_sqlGet.append(m_sqlGetListWhere.arg(idEgal));
    m_sqlGet.squeeze();

    // Get list
    m_sqlGetList.append("SELECT ");
    m_sqlGetList.append(colonnesId).append(" FROM ").append(table()).append(" ORDER BY %1%2");
    m_sqlGetList.squeeze();

    // Get list 1 where 1 ordre
    m_sqlGetList1Where1.append(m_sqlGetListWhere.arg("%1%2? ORDER BY %3%4"));
    m_sqlGetList1Where1.squeeze();

    // Get list 1 where 2 ordre
    m_sqlGetList1Where2.append(m_sqlGetList1Where1);
    m_sqlGetList1Where2.append(",%5%6");
    m_sqlGetList1Where2.squeeze();

    // Get list 1 where 3 ordre
    m_sqlGetList1Where3.append(m_sqlGetList1Where2);
    m_sqlGetList1Where3.append(",%7%8");
    m_sqlGetList1Where3.squeeze();

    // Get list 2 where 1 ordre
    m_sqlGetList2Where1.append(m_sqlGetListWhere.arg("%1%2? AND %3%4? ORDER BY %5%6"));
    m_sqlGetList2Where1.squeeze();

    // Get list 3 where 1 ordre
    m_sqlGetList2Where1.append(m_sqlGetListWhere.arg("%1%2? AND %3%4? AND %5%6? ORDER BY %7%8"));
    m_sqlGetList2Where1.squeeze();

    // Get list join
    m_sqlGetListJoin.append(selectJoin);
    m_sqlGetListJoin.append("T.%2=J.%3 WHERE %4 ORDER BY%5");
    m_sqlGetListJoin.squeeze();

    // Get list join 1 where 1
    m_sqlGetListJoin1Where1.append(selectJoin);
    m_sqlGetListJoin1Where1.append("T.ID=J.%2 WHERE %3%4? ORDER BY %5%6");
    m_sqlGetListJoin1Where1.squeeze();

    // Id last query
    m_sqllastId.append("SELECT last_insert_rowid() FROM ");
    m_sqllastId.append(table());
    m_sqllastId.squeeze();

    // Modify
    m_sqlModify.append("UPDATE ");
    m_sqlModify.append(table()).append(" SET ");
    for(int i = 1; i != m_link.nbrAtt(); ++i)
        m_sqlModify.append(attribut(i)).append("=?,");
    m_sqlModify.chop(1);
    m_sqlModify.append("WHERE ").append(idEgal);
    m_sqlModify.squeeze();
}

#endif // MANAGERSQL_H
