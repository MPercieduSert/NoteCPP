#ifndef ATTRIBUT_EXERCICE_H
#define ATTRIBUT_EXERCICE_H

#include "Entity.h"

class Attribut_exercice : public Entity
{
public:
    static const entityId IdEntity = Attribut_exerciceId;
    static const int NbrValue = 2;
protected:
    int m_attribut;
    int m_exercice;

public:
    enum position{AttributPos = 0,
                  ExercicePos = 1};

    Attribut_exercice()     {}
    Attribut_exercice(int id) : Entity(id)  {}
    Attribut_exercice(int attribut, int exercice, int id = 0): Entity(id)
    {
        setAttribut(attribut);
        setExercice(exercice);
    }
    Attribut_exercice(const Entity & entity) :Entity(entity.id())
    {
        const Attribut_exercice & entityT = convert(entity);
        setAttribut(entityT.attribut());
        setExercice(entityT.exercice());
    }
    ~Attribut_exercice() {}
    int attribut() const                    {return m_attribut;}
    int exercice() const                    {return m_exercice;}
     //entityId idEntity() const       {return IdEntity;}
     bool isValid() const            {return Entity::isValid() && (m_attribut > 0) && (m_exercice > 0);}
     int nbrValue() const            {return NbrValue;}
    void setAttribut(int attribut)
    {
        if(attribut > 0)
        {
            m_attribut = attribut;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,AttributPos));
        }
    }
    void setExercice(int exercice)
    {
        if(exercice > 0)
        {
            m_exercice = exercice;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,ExercicePos));
        }
    }
     void setValue(int pos, const QVariant & val)
    {
        switch (pos)
        {
        case IdPos:
            setId(val.toInt());
            break;

        case AttributPos:
            setAttribut(val.toInt());
            break;

        case ExercicePos:
            setExercice(val.toInt());
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

        case AttributPos:
            return QVariant(attribut());
            break;

        case ExercicePos:
            return QVariant(exercice());
            break;

        default:
            return QVariant();
        }
    }
     void operator << (const Entity & entity)
    {
        const Attribut_exercice & entityT = convert(entity);
        setId(entity.id());
        setAttribut(entityT.attribut());
        setExercice(entityT.exercice());
        //return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Attribut_exercice & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_attribut == entityT.attribut())
                 &&(m_exercice == entityT.exercice());
     }

     INCLUCE_METHODE(Attribut_exercice)
     /*const Attribut_exercice & verif(const Entity & entity) const
     {
         if(verifEntity(entity))
         {
             return *((Attribut_exercice*) &entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     const Attribut_exercice & verif(Entity * entity) const
     {
         if(verifEntity(*entity))
         {
             return (Attribut_exercice*) entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
protected:
    /*void setInt1(int kk)                {setAttribut(kk);}
    void setInt2(int kk)                {setExercice(kk);}

    int valueInt1() const               {return m_attribut;}
    int valueInt2() const               {return m_exercice;}*/
};

#endif // ATTRIBUT_EXERCICE_H
