/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/02/2016
 */

#ifndef EXERCICELINKSQL_H
#define EXERCICELINKSQL_H

#include "LinkSqlUniqueSimple.h"
#include "ArbreLinkSql.h"
#include "../Entities/Exercice.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entitée Annee de programation et sa représentation en base de donnée.
 */

class ExerciceLinkSql : public LinkSqlUniqueSimple<Exercice>
{
    USING_LINKSQL(Exercice)

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    ExerciceLinkSql(QSqlQuery & requete)
        : LinkSqlUniqueSimple(requete,writeStringUnique())
        {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Exercice & exo)
    {
        m_requete.bindValue(Exercice::IdArbExPos,exo.idArbEx());
        m_requete.bindValue(Exercice::DatePos,exo.date());
        m_requete.bindValue(Exercice::TypePos,exo.type());
        m_requete.bindValue(Exercice::VersionPos,exo.version());
        m_requete.bindValue(Exercice::ResumePos,exo.resume());
        m_requete.bindValue(Exercice::TextePos,exo.texte());
        m_requete.bindValue(Exercice::TitrePos,exo.titre());
    }

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    void creer();

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(Exercice & exo)
    {
        exo.setIdArbEx(m_requete.value(Exercice::IdArbExPos).toInt());
        exo.setDate(m_requete.value(Exercice::DatePos).toDate());
        exo.setType(m_requete.value(Exercice::TypePos).toInt());
        exo.setVersion(m_requete.value(Exercice::VersionPos).toInt());
        exo.setResume(m_requete.value(Exercice::ResumePos).toString());
        exo.setTexte(m_requete.value(Exercice::TextePos).toString());
        exo.setTitre(m_requete.value(Exercice::TitrePos).toString());
    }

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    Exercice * newFromRequete()
    {
        return new Exercice(m_requete.value(Exercice::IdArbExPos).toInt(),
                            m_requete.value(Exercice::DatePos).toDate(),
                            m_requete.value(Exercice::TypePos).toInt(),
                            m_requete.value(Exercice::VersionPos).toInt(),
                            m_requete.value(Exercice::IdPos).toInt(),
                            m_requete.value(Exercice::ResumePos).toString(),
                            m_requete.value(Exercice::TextePos).toString(),
                            m_requete.value(Exercice::TitrePos).toString());
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Exercice & exo)
    {
        m_requete.bindValue(0,exo.idArbEx());
        m_requete.bindValue(0,exo.version());
    }

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne.
    QString writeStringUnique() const;
};

#endif // EXERCICELINKSQL_H
