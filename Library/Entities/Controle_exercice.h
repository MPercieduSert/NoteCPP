#ifndef CONTROLE_EXERCICE_H
#define CONTROLE_EXERCICE_H

#include "Entity.h"

class Controle_exercice : public Entity
{
public:
    static const entityId IdEntity = Controle_exerciceId;
    static const int NbrValue = 3;
protected:
    int m_controle;
    int m_exercice;
    int m_num;

public:
    enum position{ControlePos = 0,
                  ExercicePos = 1,
                  NumPos = 2};

    Controle_exercice() {}
    Controle_exercice(int id) : Entity(id)  {}
    Controle_exercice(int controle, int exercice, int num, int id = 0) : Entity(id)
    {
        setControle(controle);
        setExercice(exercice);
        setNum(num);
    }
    Controle_exercice(const Entity & entity) : Entity(entity.id())
    {
        const Controle_exercice & entityT = convert(entity);
        setControle(entityT.controle());
        setExercice(entityT.exercice());
        setNum(entityT.num());
    }
    ~Controle_exercice()    {}
    int controle() const                    {return m_controle;}
    int exercice() const                    {return m_exercice;}
     //entityId idEntity() const       {return IdEntity;}
     bool isValid() const            {return Entity::isValid() && (m_controle > 0) && (m_exercice > 0) && (m_num >= 0);}
     int nbrValue() const            {return NbrValue;}
    int num() const                         {return m_num;}
    void setControle(int controle)
    {
        if(controle > 0)
        {
            m_controle = controle;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,ControlePos));
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
     void setValue(int pos, const QVariant & val)
    {
        switch (pos)
        {
        case IdPos:
            setId(val.toInt());
            break;

        case ControlePos:
            setControle(val.toInt());
            break;

        case ExercicePos:
            setExercice(val.toInt());
            break;

        case NumPos:
            setNum(val.toInt());
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
            return QVariant(m_id);
            break;

        case ControlePos:
            return QVariant(m_controle);
            break;

        case NumPos:
            return QVariant(m_num);
            break;

        default:
            return QVariant();
        }
    }
     void operator << (const Entity & entity)
    {
        const Controle_exercice & entityT = convert(entity);
        setId(entity.id());
        setControle(entityT.controle());
        setExercice(entityT.exercice());
        setNum(entityT.num());
        // return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Controle_exercice & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_controle == entityT.controle())
                 &&(m_exercice == entityT.exercice())
                 &&(m_num == entityT.num());
     }

     INCLUCE_METHODE(Controle_exercice)
protected:
    /*void setInt1(int kk)                    {setControle(kk);}
    void setInt2(int kk)                    {setExercice(kk);}
    void setInt3(int kk)                    {setNum(kk);}

    int valueInt1() const                   {return m_controle;}
    int valueInt2() const                   {return m_exercice;}
    int valueInt3() const                   {return m_num;}*/
    /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
    const Controle_exercice & verif(const Entity & entity) const
    {
        if(verifEntity(entity))
        {
            return *((Controle_exercice*) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }*/
};

#endif // CONTROLE_EXERCICE_H
