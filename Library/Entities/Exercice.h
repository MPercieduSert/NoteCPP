/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/02/2016
 */


#ifndef EXERCICE_H
#define EXERCICE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Exercice.
 */

class Exercice : public Entity
{
public:
    //! Différents types des parties d'exercices.
    enum typeEx {ExerciceTp = 0,
              QuestionTp = 1,
              };

    //! Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.
    enum position{IdArbExPos = 0,
                  DatePos = 1,
                  TypePos = 2,
                  VersionPos = 3,
                  ResumePos = 4,
                  TextePos = 5,
                  TitrePos = 6,
                  IdPos = 7
                  };

    static const entityId IdEntity = ExerciceId;    //!< Identifiant du type de l'entitée.
    static constexpr char Name[] = "Exercice";      //!< Nom de l'entitée.
    static const int NbrAtt = 8;                    //!< Nombre d'attributs de l'entitée.
    static constexpr std::array<const char*, NbrAtt> Att {{"IDArbEx","date","type","version","resume","texte","titre","ID"}}; //!< Tableau des attributs de l'entitée.

protected:    
    int m_idArbEx;      //!< Clé: Référence sur l'arbre des exercices.
    QDate m_date;       //!< Attribut: Date de la dernière modification.
    int m_type;         //!< Attribut: Type de la partie d'exercice.
    int m_version;      //!< Attribut: Version de la partie d'exercice.    
    QString m_resume;   //!< Attribut optionel: Résumé de l'exercice.
    QString m_texte;   //!< Attribut: Texte de la partie d'exercice.
    QString m_titre;    //!< Attribut optionel: Titre de l'exercice.


public:
    INCLUCE_METHODE(Exercice)

    //! Constructeur à partir des valeurs attributs.
    Exercice(int idArbrEx, const QDate & date, int type, int version,
             int id = 0, const QString & resume = QString(), const QString & texte = QString(), const QString & titre = QString())
        : Entity(id)
    {
        setIdArbEx(idArbrEx);
        setDate(date);
        setType(type);
        setVersion(version);       
        setResume(resume);
        setTexte(texte);
        setTitre(titre);
    }

    GET_SET_ID(ArbEx)
    GET_SET_DATE_VALIDE(date,Date)
    GET_SET_INT(type,Type)
    GET_SET_INT_SUP(version,Version,0)
    GET_SET_TEXTE_NULL(resume,Resume)
    GET_SET_TEXTE_NULL(texte,Texte)
    GET_SET_TEXTE_NULL(titre,Titre)

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return Entity::isValid() && (m_idArbEx > 0) && (!m_date.isValid()) && (m_version >= 0);
    }

protected:
     //! Test d'égalité entre cette entitée et celle transmise en argument.
     bool egal(const Exercice & exo) const
     {
         return Entity::egal(exo)
                 && (m_idArbEx == exo.m_idArbEx)
                 && (m_date == exo.m_date)
                 && (m_type == exo.m_type)
                 && (m_version == exo.m_version)
                 && (m_resume == exo.m_resume)
                 && (m_texte == exo.m_texte)
                 && (m_titre == exo.m_titre);
     }

     //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
     void set(const Exercice & exo)
     {
         setIdArbEx(exo.idArbEx());
         setDate(exo.date());
         setType(exo.type());
         setVersion(exo.version());
         setResume(exo.resume());
         setTexte(exo.texte());
         setTitre(exo.titre());
     }
};

#endif // EXERCICE_H
