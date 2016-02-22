#ifndef NUMCONTROLE_H
#define NUMCONTROLE_H

#include "Entity.h"
class NumControle : public Entity
{
public:
    static const entityId IdEntity = NumControleId;
    static const int NbrValue = 3;
protected:
    int m_classe;
    int m_num;
    int m_type;

public:
    enum position{ClassePos = 0,
                  NumPos = 1,
                  TypePos = 2};

    NumControle() {}
    NumControle(int id) : Entity(id)    {}
    NumControle(int classe, int num, int type, int id = 0) : Entity(id)
    {
        setClasse(classe);
        setNum(num);
        setType(type);
    }
    NumControle(const Entity & entity): Entity(entity.id())
    {
        const NumControle & entityT = convert(entity);
        setClasse(entityT.classe());
        setNum(entityT.num());
        setType(entityT.type());
    }

    ~NumControle()  {}
    int classe() const                      {return m_classe;}
     //entityId idEntity() const       {return IdEntity;}
     bool isValid() const            {return Entity::isValid() && (m_classe > 0) && (m_num >= 0) && (m_type > 0);}
     int nbrValue() const            {return NbrValue;}
    int num() const                         {return m_num;}
    void setClasse(int classe)
    {
        if(classe > 0)
        {
            m_classe = classe;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,ClassePos));
        }
    }
    void setNum(int num)
    {
        if(num >= 0)
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
    int type() const                        {return m_type;}
     void setValue(int pos, const QVariant & val)
    {
        switch (pos)
        {
        case IdPos:
            setId(val.toInt());
            break;

        case ClassePos:
            setClasse(val.toInt());
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
     QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
            break;

        case ClassePos:
            return QVariant(classe());
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
        const NumControle & entityT = convert(entity);
        setId(entity.id());
        setClasse(entityT.classe());
        setNum(entityT.num());
        setType(entityT.type());
        // return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const NumControle & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_classe == entityT.classe())
                 &&(m_num == entityT.num())
                 &&(m_type == entityT.type());
     }

     INCLUCE_METHODE(NumControle)
protected:
    /*void setInt1(int kk)        {setClasse(kk);}
    void setInt2(int kk)        {setNum(kk);}
    void setInt3(int kk)        {setType(kk);}

    int valueInt1() const       {return m_classe;}
    int valueInt2() const       {return m_num;}
    int valueInt3() const       {return m_type;}*/
    /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
    const NumControle & verif(const Entity & entity) const
    {
        if(verifEntity(entity))
        {
            return *((NumControle*) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }*/
};

#endif // NUMCONTROLE_H
