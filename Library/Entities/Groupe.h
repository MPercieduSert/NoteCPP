/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */
#ifndef GROUPE_H
#define GROUPE_H

#include "AttributEntityAlias.h"
#include "EntityNom.h"
#include "InfoEntity.h"

/*! \ingroup groupeInfoEntity
 * \brief Information sur l'entité Groupe.
 */
struct GroupeInfo
{
    static const int ID = InfoEntity::GroupeId;
    static constexpr char Name[] {"Groupe"};
    ATTRIBUT_5(IdAn,IdCl,Alpha,Nom,Type)
};

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Groupe.
 */
class Groupe : public TypeNomEntity<Groupe,GroupeInfo>, public IdAnNullAttribut, public IdClNullAttribut, public AlphaAttribut
{
public:
    enum grPour {GrAnnee = 0,
                 GrClasse =1};

    //! Constructeur par defaut.
    Groupe(int id = 0)
        :TypeNomEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    Groupe(int idAn, int idCl, int alpha, const QString & nom, int type, int id = 0)
        : TypeNomEntity(nom,type,id),
          IdAnNullAttribut(idAn),
          IdClNullAttribut(idCl),
          AlphaAttribut(alpha)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Groupe(int cle, const QString & nom, grPour pr)
        : TypeNomEntity(nom)
    {
        if(pr == GrClasse)
            {setIdCl(cle);}
        else
            {setIdAn(cle);}
    }

    //! Teste si l'entité est valide.
    bool isValid() const
    {return TypeNomEntity::isValid()
                && IdAnNullAttribut::valide()
                && IdClNullAttribut::valide()
                && AlphaAttribut::valide()
                && ((idAn() > 0 && idCl() == 0) || (idAn() == 0 && idCl() > 0));}

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Groupe & entity) const
    {
        return TypeNomEntity::egal(entity)
                && (idAn() == entity.idAn())
                && (idCl() == entity.idCl())
                && (alpha() == entity.alpha());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Groupe & entity)
    {
        TypeNomEntity::set(entity);
        setIdAn(entity.idAn());
        setIdCl(entity.idCl());
        setAlpha(entity.alpha());
    }
};

#endif // GROUPE_H
