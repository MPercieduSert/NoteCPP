/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/02/2016
 */

#ifndef TYPE_NIVEAU_H
#define TYPE_NIVEAU_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée TypeNiveau.
 */

class TypeNiveau : public Entity
{
public:
    //! Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.
    enum position {NomPos = 0,
                  IdPos = 1};

    //! Numéro des types de niveaux.
    enum num {Primaire = 1,
              College = 2,
              Lycee = 3,
              Prepa = 4,
              Licence =5};

    static const entityId IdEntity = TypeNiveauId;   //!< Identifiant du type des entitées Annee.
    static constexpr char Name[] = "TypeNiveau";     //!< Nom de l'entitée.
    static const int NbrAtt = 2;                //!< Nombre d'attributs des entitées Annee.
    static constexpr std::array<const char*,NbrAtt> Att {{"nom", "ID"}};  //!< Tableau des attributs des entitées Annee.

protected:
    QString m_nom;

public:
    INCLUCE_METHODE(TypeNiveau)

    //! Constructeur à partir des valeurs attributs.
    TypeNiveau(const QString & nom, int id = 0)
        : Entity(id)
        {setNom(nom);}

    GET_SET_TEXTE_NOT_NULL(nom,Nom)

    //! Teste si l'entitée est valide.
    bool isValid() const
        {return Entity::isValid() && (!m_nom.isEmpty());}

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const TypeNiveau & entity) const
    {
        return Entity::egal(entity)
                && (m_nom == entity.m_nom);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const TypeNiveau & entity)
    {
        setNom(entity.nom());
    }
};

#endif // TYPE_NIVEAU_H
