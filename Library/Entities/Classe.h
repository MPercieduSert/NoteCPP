/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */
#ifndef CLASSE_H
#define CLASSE_H

#include "AttributEntity.h"
#include "EntityNom.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Bareme.
 */
class Classe : public NomEntity
{
    ATTRIBUT_ENTITY_ID(An)
    ATTRIBUT_ENTITY_ID(Etab)
    ATTRIBUT_ENTITY_ID(Niv)
    ATTRIBUT_ENTITY_INT_SUP(Num,num,0)
public:
    using NomEntity::NomEntity;
    BASE_ENTITY(Classe,InfoEntity::ClasseId)

    //! Constructeur à partir des valeurs attributs.
    Classe(int idAn, int idEtab, int idNiv, const QString & nom, int num, int id =0)
        : NomEntity(nom,id),
          m_idAn(idAn),
          m_idEtab(idEtab),
          m_idNiv(idNiv),
          m_num(num)
    {}

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    Classe(int idAn, int idEtab, int idNiv, int num)
        : m_idAn(idAn),
          m_idEtab(idEtab),
          m_idNiv(idNiv),
          m_num(num)
    {}

  MEMBRE_ATT_4(Classe,NomEntity,IdAn,idAn,IdEtab,idEtab,IdNiv,idNiv,Num,num)
};

#endif // CLASSE_H
