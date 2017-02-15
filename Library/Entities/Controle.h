/*Auteur: PERCIE DU SERT Maxime
 *Date: 06/12/2016
 */
#ifndef CONTROLE_H
#define CONTROLE_H

#include "AttributEntity.h"
#include "EntityRelation.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Controle.
 */
class Controle : public NumRelationEntity
{
    ATTRIBUT_ENTITY_BOOL(Bareme,bareme)
    ATTRIBUT_ENTITY_DATE_VALIDE(Date,date)
    ATTRIBUT_ENTITY_INT_SUP(Decimale,decimale,1)
    ATTRIBUT_ENTITY_BOOL(Enonce,enonce)
    ATTRIBUT_ENTITY_INT_SUP(Minima,minima,0)
    ATTRIBUT_ENTITY_STR_NOT_EMPTY(Nom,nom)
    ATTRIBUT_ENTITY_BOOL(Saisie,saisie)
    ATTRIBUT_ENTITY_INT_SUP(Total,total,1)

public:
    //! Positions des attributs.
    enum Position {Id = NumRelationEntity::Id,
                   IdCl = NumRelationEntity::Id1,
                   IdTp = NumRelationEntity::Id2,
                   Num = NumRelationEntity::Num,
                   Bareme = NumRelationEntity::NbrAtt,
                   Date,
                   Decimale,
                   Enonce,
                   Minima,
                   Nom,
                   Saisie,
                   Total,
                   NbrAtt};

    using NumRelationEntity::NumRelationEntity;
    BASE_ENTITY(Controle,InfoEntity::ControleId)
    RELATION_ALIAS_2_CLE(Cl,Tp)


    //! Constructeur à partir des valeurs attributs.
    Controle(int idCl, int idTp, bool bareme, const QDate &date, int decimale, bool enonce, int minima, const QString &nom, int num, bool saisie, int total, int id = 0)
        : NumRelationEntity(idCl,idTp,num,id), m_bareme(bareme), m_date(date), m_decimale(decimale), m_enonce(enonce), m_minima(minima), m_nom(nom), m_saisie(saisie), m_total(total)
        {}

    MEMBRE_ATT_8(Controle,NumRelationEntity,Bareme,bareme,Date,date,Decimale,decimale,Enonce,enonce,Minima,minima,Nom,nom,Saisie,saisie,Total,total)
};

#endif // CONTROLE_H
