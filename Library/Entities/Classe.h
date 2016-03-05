/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */

#ifndef CLASSE_H
#define CLASSE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Bareme.
 */

class Classe : public Entity
{
public:
    //! Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.
    enum position {IdAnPos = 0,
                   IdEtabPos = 1,
                   IdNivPos = 2,
                   NumPos = 3,
                   IdPos = 4};

    static const entityId IdEntity = ClasseId;   //!< Identifiant du type de l'entitée.
    static constexpr char Name[] = "Classe";     //!< Nom de l'entitée.
    static const int NbrAtt = 6;                //!< Nombre d'attributs de l'entitée.
    static constexpr std::array<const char*,NbrAtt> Att {{"idAn", "idEtab", "idNiv", "num", "ID"}};  //!< Tableau des attributs de l'entitée.

protected:
    int m_idAn;     //!< Clé: Annee.
    int m_idEtab;   //!< Clé: Etablissement.
    int m_idNiv;    //!< Clé: Niveau.
    int m_num;      //!< Attribut: numéro  de la classe.

public:
    INCLUCE_METHODE(Classe)

    //! Constructeur à partir des valeurs attributs.
    Classe(int idAn, int idEtab, int idNiv, int num, int id =0)
        : Entity(id)
    {
        setIdAn(idAn);
        setIdEtab(idEtab);
        setIdNiv(idNiv);
        setNum(num);
    }

    GET_SET_ID(An)
    GET_SET_ID(Etab)
    GET_SET_ID(Niv)
    GET_SET_INT_SUP(num,Num,0)

     bool isValid() const
    {
        return Entity::isValid() && (m_idAn > 0) && (m_idEtab > 0) && (m_idNiv > 0) && (m_num >= 0);
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Classe & entity) const
    {
        return Entity::egal(entity)
                &&(m_idAn == entity.m_idAn)
                &&(m_idEtab == entity.m_idEtab)
                &&(m_idNiv == entity.m_idNiv)
                &&(m_num == entity.m_num);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Classe & entity)
    {
        setIdAn(entity.m_idAn);
        setIdEtab(entity.m_idEtab);
        setIdNiv(entity.m_idNiv);
        setNum(entity.m_num);
    }
};

#endif // CLASSE_H
