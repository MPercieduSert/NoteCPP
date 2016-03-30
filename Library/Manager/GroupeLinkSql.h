/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/03/2016
 */
#ifndef GROUPELINKSQL
#define GROUPELINKSQL

#include "AttributsLinkSql.h"
#include "LinkSqlNom.h"
#include "LinkSqlUnique.h"
#include "GroupeInfoSql.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité Groupe de programation et sa représentation en base de donnée.
 */
class GroupeLinkSql : public LinkSqlUniqueDouble<TypeNomLinkSql<Groupe,GroupeInfoSql> >, public IdAnAttributSqlNullToZero<Groupe>, public IdClAttributSqlNullToZero<Groupe>, public AlphaAttributSql<Groupe>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    GroupeLinkSql(QSqlQuery & requete)
        : ReqSql(requete)
        {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Groupe & entity)
    {
        LinkSqlUniqueDouble::bindValues(entity);
        setIdAn(entity);
        setIdCl(entity);
        setAlpha(entity);
    }

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a exactement deux ensembles de valeurs uniques.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    Manager::ExisteUni existsUnique(Groupe & entity)
    {
        if(entity.idAn() != 0 && entity.idCl() == 0)
        {
            prepare(m_unique_1);
            bindValuesUnique_1(entity);
            exec();
            if(next())
            {
                entity.setId(toInt());
                finish();
                return Manager::Tous;
            }
            else
            {
                finish();
                return Manager::Aucun;
            }
        }

        if(entity.idAn() == 0 && entity.idCl() != 0)
        {
            prepare(m_unique_2);
            bindValuesUnique_2(entity);
            exec();
            if(next())
            {
                entity.setId(toInt());
                finish();
                return Manager::Tous;
            }
            else
            {
                finish();
                return Manager::Aucun;
            }
        }

        return Manager::Conflit;
    }

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a exactement deux ensembles de valeurs uniques.
    Manager::ExisteUni existsUnique(const Ent & entity)
    {
        if(entity.idAn() != 0 && entity.idCl() == 0)
        {
            prepare(m_unique_1);
            bindValuesUnique_1(entity);
            exec();
            if(next())
            {
                finish();
                return Manager::Tous;
            }
            else
            {
                finish();
                return Manager::Aucun;
            }
        }

        if(entity.idAn() == 0 && entity.idCl() != 0)
        {
            prepare(m_unique_2);
            bindValuesUnique_2(entity);
            exec();
            if(next())
            {
                finish();
                return Manager::Tous;
            }
            else
            {
                finish();
                return Manager::Aucun;
            }
        }

        return Manager::Conflit;
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Groupe & entity) const
    {
        LinkSqlUniqueDouble::fromRequete(entity);
        entity.setIdAn(idAn());
        entity.setIdCl(idCl());
        entity.setAlpha(alpha());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Groupe * newFromRequete() const
    {
        return new Groupe(idAn(),idCl(),alpha(),nom(),type());
    }

protected:
    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne 1.
    void bindValuesUnique_1(const Groupe &entity)
    {
        setIdAn(entity,GroupeInfoSql::IdUnique);
        setNom(entity,GroupeInfoSql::NomUnique);
    }

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne 2.
    void bindValuesUnique_2(const Groupe &entity)
    {
        setIdCl(entity,GroupeInfoSql::IdUnique);
        setNom(entity,GroupeInfoSql::NomUnique);
    }
};

#endif // GROUPELINKSQL
