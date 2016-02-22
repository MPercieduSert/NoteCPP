#ifndef ELEVE_GROUPE_H
#define ELEVE_GROUPE_H

#include "Entity.h"

class Eleve_groupe : public Entity
{
public:
    static const entityId IdEntity = Eleve_groupeId;
    static const int NbrValue = 2;
protected:
    int m_eleve;
    int m_groupe;

public:
    enum position{ElevePos = 0,
                  GroupePos = 1};

    Eleve_groupe()  {}
    Eleve_groupe(int id) : Entity(id)  {}
    Eleve_groupe(int eleve, int groupe, int id = 0) : Entity(id)
    {
        setEleve(eleve);
        setGroupe(groupe);
    }
    Eleve_groupe(const Entity & entity) : Entity(entity.id())
    {
        const Eleve_groupe & entityT = convert(entity);
        setEleve(entityT.eleve());
        setGroupe(entityT.groupe());
    }
    ~Eleve_groupe()     {}
    int eleve() const                       {return m_eleve;}
    int groupe() const                      {return m_groupe;}
     //entityId idEntity() const       {return IdEntity;}
     bool isValid() const            {return Entity::isValid() && (m_groupe > 0) && (m_eleve > 0);}
     int nbrValue() const            {return NbrValue;}
    void setEleve(int eleve)
    {
        if(eleve > 0)
        {
            m_eleve = eleve;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,ElevePos));
        }
    }
    void setGroupe(int groupe)
    {
        if(groupe > 0)
        {
            m_groupe = groupe;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,GroupePos));
        }
    }
     void setValue(int pos, const QVariant & val)
    {
        switch (pos)
        {
        case IdPos:
            setId(val.toInt());
            break;

        case ElevePos:
            setEleve(val.toInt());
            break;

        case GroupePos:
            setGroupe(val.toInt());
            break;

        default:
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
     QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
            break;

        case ElevePos:
            return QVariant(eleve());
            break;

        case GroupePos:
            return QVariant(groupe());
            break;

        default:
            return QVariant();
        }
    }
     void operator << (const Entity & entity)
    {
        const Eleve_groupe & entityT = convert(entity);
        setId(entity.id());
        setEleve(entityT.eleve());
        setGroupe(entityT.groupe());
        // return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Eleve_groupe & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_eleve == entityT.eleve())
                 &&(m_groupe == entityT.groupe());
     }

     INCLUCE_METHODE(Eleve_groupe)
protected:
   /*void setInt1(int kk)         {setEleve(kk);}
   void setInt2(int kk)         {setGroupe(kk);}

   int valueInt1() const        {return m_eleve;}
   int valueInt2() const        {return m_groupe;}*/
   /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
   const Eleve_groupe & verif(const Entity & entity) const
   {
       if(verifEntity(entity))
       {
           return *((Eleve_groupe*) &entity);
       }
       else
       {
           throw std::runtime_error("Mauvaise correspondance des Entity");
       }
   }*/
};

#endif // ELEVE_GROUPE_H
