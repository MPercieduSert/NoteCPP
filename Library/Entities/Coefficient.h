#ifndef COEFFICIENT_H
#define COEFFICIENT_H

#include "Entity.h"

class Coefficient : public Entity
{
public:
    static const entityId IdEntity = CoefficientId;
    static const int NbrValue = 3;
protected:
    int m_controle;
    int m_indice;
    double m_valeur;

public:
    enum position {ControlePos = 0,
                   IndicePos = 1,
                   ValeurPos = 2};

    Coefficient() {}
    Coefficient(int id) : Entity(id) {}
    Coefficient(int controle, int indice, double valeur, int id = 0) : Entity(id)
    {
        setControle(controle);
        setIndice(indice);
        setValeur(valeur);
    }
    Coefficient(const Entity & entity):Entity(entity.id())
    {
        const Coefficient & entityT = convert(entity);
        setControle(entityT.controle());
        setIndice(entityT.indice());
        setValeur(entityT.valeur());
    }
    ~Coefficient()  {}
    int controle() const                {return m_controle;}
     //entityId idEntity() const   {return IdEntity;}
     bool isValid() const        {return Entity::isValid() && (m_controle > 0) && (m_indice >= 0);}
    int indice() const                  {return m_indice;}
     int nbrValue() const        {return NbrValue;}
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
    void setIndice(int indice)
    {
        if(indice >= 0)
        {
            m_indice = indice;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,IndicePos));
        }
    }
    void setValeur(double valeur)       {m_valeur = valeur;}
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

        case IndicePos:
            setIndice(val.toInt());
            break;

        case ValeurPos:
            setValeur(val.toDouble());
            break;

        default:
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
    float valeur() const                {return m_valeur;}
     QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
            break;

        case ControlePos:
            return QVariant(controle());
            break;

        case IndicePos:
            return QVariant(indice());
            break;

        case ValeurPos:
            return QVariant(valeur());
            break;

        default:
            return QVariant();
        }
    }
     void operator << (const Entity & entity)
    {
        const Coefficient & entityT = convert(entity);
        setId(entity.id());
        setControle(entityT.controle());
        setIndice(entityT.indice());
        setValeur(entityT.valeur());
        //return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Coefficient & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_controle == entityT.controle())
                 &&(m_indice == entityT.indice())
                 &&(m_valeur == entityT.valeur());
     }

     INCLUCE_METHODE(Coefficient)
     /*const Coefficient & verif(const Entity & entity) const
     {
         if(verifEntity(entity))
         {
             return *((Coefficient*) &entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     const Coefficient & verif(const Entity & entity) const
     {
         if(verifEntity(entity))
         {
             return *((Coefficient*) &entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
protected:
     /*void setInt1(int kk)               {setControle(kk);}
     void setInt2(int kk)               {setIndice(kk);}
     void setDouble(double dd)          {setValeur(dd);}

     int valueInt1() const              {return m_controle;}
     int valueInt2() const              {return m_indice;}
     double valueDouble() const         {return m_valeur;}*/
};

#endif // COEFFICIENT_H
