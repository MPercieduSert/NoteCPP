/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */

#ifndef SOURCE_H
#define SOURCE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Source.
 */
class Source : public TypeNomEntity, public EntityTemp<IdentifiantEntity::SourceId,3,Source>
{
public:
    POS_2_ATT(Nom,Type)

    //! Constructeur par defaut.
    Source(int id = 0)
        :TypeNomEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    Source(const QString & nom, int type = 0, int id=0)
        : TypeNomEntity(nom,type,id)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Source(const QString & nom)
        : TypeNomEntity(nom)
    {}

    //! Constructeur de recopie.
    Source(const Source & entity)
        : TypeNomEntity(entity)
    {}

    //! Destructeur.
    ~Source()
    {}
};

#endif // SOURCE_H
