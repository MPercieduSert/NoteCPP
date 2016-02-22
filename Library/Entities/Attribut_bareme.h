#ifndef ATTRIBUT_BAREME_H
#define ATTRIBUT_BAREME_H

#include "Entity.h"

class Attribut_bareme : public Entity
{
public:
    static const entityId IdEntity = Attribut_baremeId;
    static const int NbrValue = 2;
protected:
    int m_attribut;
    int m_bareme;

public:
    enum position{AttributPos = 0,
                  BaremePos = 1};

    Attribut_bareme()   {}
    Attribut_bareme(int id) : Entity(id)    {}
    Attribut_bareme(int attribut, int bareme, int id = 0) : Entity(id)
    {
        setAttribut(attribut);
        setBareme(bareme);
    }
    Attribut_bareme(const Entity & entity) : Entity(entity.id())
    {
        const Attribut_bareme & entityT = convert(entity);
        setAttribut(entityT.attribut());
        setBareme(entityT.bareme());
    }
    ~Attribut_bareme() {}
    int attribut() const                            {return m_attribut;}
    int bareme() const                              {return m_bareme;}
     //entityId idEntity() const               {return IdEntity;}
     bool isValid() const                    {return Entity::isValid() && (m_attribut > 0) && (m_bareme > 0);}
     int nbrValue() const                    {return NbrValue;}
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
    void setBareme(int bareme)
    {
        if(bareme > 0)
        {
            m_bareme = bareme;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,BaremePos));
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

        case BaremePos:
            setBareme(val.toInt());
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

        case BaremePos:
            return QVariant(bareme());
            break;

        default:
            return QVariant();
        }
    }
     void operator << (const Entity & entity)
    {
        const Attribut_bareme & entityT = convert(entity);
        setId(entity.id());
        setAttribut(entityT.attribut());
        setBareme(entityT.bareme());
        //return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Attribut_bareme & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_attribut == entityT.attribut())
                 &&(m_bareme == entityT.bareme());
     }

     INCLUCE_METHODE(Attribut_bareme)
     /*const Attribut_bareme & verif(const Entity & entity) const
     {
         if(verifEntity(entity))
         {
             return *((Attribut_bareme*) &entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     const Attribut_bareme & verif(Entity *entity) const
     {
         if(verifEntity(*entity))
         {
             return (Attribut_bareme*) entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
protected:
    /*void setInt1(int kk)                {setAttribut(kk);}
    void setInt2(int kk)                {setBareme(kk);}

    int valueInt1() const               {return m_attribut;}
    int valueInt2() const               {return m_bareme;}*/
};

#endif // ATTRIBUT_BAREME_H
