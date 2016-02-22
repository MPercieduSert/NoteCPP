#ifndef ANNEE_H
#define ANNEE_H

#include "Entity.h"

class Annee : public Entity
{
public:
    static const entityId IdEntity = AnneeId;
    static const int NbrValue = 2;
protected:
    bool m_encours;
    int m_rentree;

public:
    enum position {EncoursPos = 0,
                   RentreePos = 1};

    Annee() {}
    Annee(int id) : Entity(id) {}
    Annee(bool encours, int rentree, int id = 0) : Entity(id)
    {
        setEncours(encours);
        setRentree(rentree);
    }
    Annee(const Entity & entity) : Entity(entity.id())
    {
        const Annee & entityT = convert(entity);
        setEncours(entityT.encours());
        setRentree(entityT.rentree());
    }
    ~Annee() {}
    QString affiche() const                             {return QString::number(m_rentree)+"-"+QString::number(m_rentree+1);}
    bool encours() const                                {return m_encours;}
    ////entityId idEntity() const                           {return IdEntity;}
    bool isValid() const                                {return Entity::isValid() && (m_rentree > 0);}
    int nbrValue() const                                {return NbrValue;}
    int rentree() const                                 {return m_rentree;}
    void setEncours(bool encours)                       {m_encours = encours;}
    void setRentree(int rentree)
    {
        if(rentree > 0)
        {
            m_rentree = rentree;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,RentreePos));
        }
    }
    void setValue(int pos, const QVariant & val)
    {
        switch (pos)
        {
        case IdPos:
            setId(val.toInt());
            break;
            
        case EncoursPos:
            setEncours(val.toBool());
            break;

        case RentreePos:
            setRentree(val.toInt());
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
            
        case EncoursPos:
            return QVariant(encours());
            break;
            
        case RentreePos:
            return QVariant(rentree());
            break;
            
        default:
            return QVariant();
        }
    }
    void operator << (const Entity & entity)
    {
        const Annee & entityT = convert(entity);
        setId(entity.id());
        setEncours(entityT.encours());
        setRentree(entityT.rentree());
        //return *this;
    }
    bool operator == (const Entity & entity) const
    {
        const Annee & entityT = convert(entity);
        return (m_id == entityT.id())
                &&(m_encours == entityT.encours())
                &&(m_rentree == entityT.rentree());
    }

    bool operator < (const Annee & annee) const
    {
        if(m_encours == annee.encours())
        {
            return m_rentree < annee.rentree();
        }
        else
        {
            return m_encours < annee.encours();
        }
    }

    INCLUCE_METHODE(Annee)
    /*static Annee & convert(const Entity & entity)
    {
        if(verifEntity(entity))
        {
            return *((Annee*) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }
    static Annee * convert(Entity *entity)
    {
        if(verifEntity(*entity))
        {
            return (Annee*) entity;
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }
    static bool verifEntity(const Entity & entity)              {return IdEntity == entity.idEntity();}
protected:
    /*void setBool1(bool encours)                         {setEncours(encours);}
    void setInt1(int rentree)                           {setRentree(rentree);}
    bool valueBool1() const                             {return m_encours;}
    int valueInt1() const                               {return m_rentree;}*/
};

#endif // ANNEE_H
