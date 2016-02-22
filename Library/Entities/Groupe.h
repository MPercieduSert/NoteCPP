#ifndef GROUPE_H
#define GROUPE_H

#include "Entity.h"

class Groupe : public Entity
{
public:
    static const entityId IdEntity = GroupeId;
    static const int NbrValue = 2;
protected:
    int m_num;
    int m_type;

public:
    enum position{NumPos = 0,
                  TypePos = 1};

    Groupe() {}
    Groupe(int id) : Entity(id)     {}
    Groupe(int num, int type, int id = 0) : Entity(id)
    {
        setNum(num);
        setType(type);
    }
    Groupe(const Entity & entity) : Entity(entity.id())
    {
        const Groupe & entityT = convert(entity);
        setNum(entityT.num());
        setType(entityT.type());
    }
    ~Groupe()   {}
     //entityId idEntity() const   {return IdEntity;}
     bool isValid() const        {return Entity::isValid() && (m_num > 0) && (m_type > 0);}
     int nbrValue() const        {return NbrValue;}
    int num() const                     {return m_num;}
    void setNum(int num)
    {
        if(num > 0)
        {
            m_num = num;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,NumPos));
        }
    }
    void setType(int type)
    {
        if(type > 0)
        {
            m_type = type;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,TypePos));
        }
    }
     void setValue(int pos, const QVariant & val)
    {
        switch (pos)
        {
        case IdPos:
            setId(val.toInt());
            break;

        case NumPos:
            setNum(val.toInt());
            break;

        case TypePos:
            setType(val.toInt());
            break;

        default:
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
    int type() const                    {return m_type;}
     QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
            break;

        case NumPos:
            return QVariant(num());
            break;

        case TypePos:
            return QVariant(type());
            break;

        default:
            return QVariant();
        }
    }
     void operator << (const Entity & entity)
    {
        const Groupe & entityT = convert(entity);
        setId(entity.id());
        setNum(entityT.num());
        setType(entityT.type());
        // return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Groupe & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_num == entityT.num())
                 &&(m_type == entityT.type());
     }

     INCLUCE_METHODE(Groupe)
protected:
    /*void setInt1(int kk)        {setNum(kk);}
    void setInt2(int kk)        {setType(kk);}

    int valueInt1() const       {return m_num;}
    int valueInt2() const       {return m_type;}*/
    /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
    const Groupe & verif(const Entity & entity) const
    {
        if(verifEntity(entity))
        {
            return *((Groupe*) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }*/
};

#endif // GROUPE_H
