#ifndef ENTITYANNEE_H
#define ENTITYANNEE_H

#include "Entity.h"
#include "Annee.h"

class EntityAnnee : public Entity
{
public:
    static const entityId IdEntity = EntityAnneeId;
    static const int NbrValue = 0;

protected:
    Annee * m_annee;

public:
    enum position{AnneePos = -3};

    EntityAnnee(Annee * annee) {m_annee = annee;}
    EntityAnnee(Annee * annee, int id) : Entity(id) {m_annee = annee;}
    ~EntityAnnee()  {}
    virtual int idAnnee() const         {return m_annee->id();}
    //entityId idEntity() const   {return IdEntity;}
    virtual int nbrValue() const        {return NbrValue;}
};

#endif // ENTITYAN_H
