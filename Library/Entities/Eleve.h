/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/02/2016
 */
#ifndef ELEVE_H
#define ELEVE_H

#include "AttributEntity.h"
#include "EntityNom.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Eleve.
 */
class Eleve : public NomEntity
{
    ATTRIBUT_ENTITY_BOOL(Fille,fille)
    ATTRIBUT_ENTITY_DATE_VALIDE(Naissance,naissance)
    ATTRIBUT_ENTITY_STR_NOT_EMPTY(Prenom,prenom)
public:
    BASE_ENTITY(Eleve,InfoEntity::EleveId)

    //! Constructeur par defaut.
    Eleve(int id)
        : NomEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    Eleve(bool fille, const QDate & naissance, const QString &nom, const QString &prenom, int id = 0)
        : NomEntity(nom, id),
          m_fille(fille),
          m_naissance(naissance),
          m_prenom(prenom)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Eleve(const QDate & naissance, const QString &nom, const QString &prenom)
        : NomEntity(nom),
          m_naissance(naissance),
          m_prenom(prenom)
    {}

    //! Renvoie F si l'éléve est une fille et M sinon.
    QChar afficheFille() const                      {return fille() ? QChar('F'): QChar('M');}

    MEMBRE_ATT_3(Eleve,NomEntity,Fille,fille,Naissance,naissance,Prenom,prenom)
};

#endif // ELEVE_H
