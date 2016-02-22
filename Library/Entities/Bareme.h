#ifndef BAREME_H
#define BAREME_H

#include "Entity.h"

class Bareme : public Entity
{
public:
    static const entityId IdEntity = BaremeId;
    static const int NbrValue = 6;
protected:
    int m_controle;
    int m_exercice;
    int m_fraction;
    int m_num;
    QString m_nom;
    int m_valeur;

public:
    enum position{ControlePos = 0,
                  ExercicePos = 1,
                  FractionPos = 2,
                  NumPos = 3,
                  NomPos = 4,
                  ValeurPos = 5};

    Bareme()    {}
    Bareme(int id) : Entity(id) {}
    Bareme(int controle, int exercice, int fraction, int num, const QString &nom, int valeur, int id = 0) : Entity(id)
    {
        setControle(controle);
        setExercice(exercice);
        setValeur(valeur);
        setFraction(fraction);
        setNum(num);
        setNom(nom);
    }
    Bareme(const Entity & entity) : Entity(entity.id())
    {
        const Bareme & entityT = convert(entity);
        setControle(entityT.controle());
        setExercice(entityT.exercice());
        setFraction(entityT.fraction());
        setNom(entityT.nom());
        setNum(entityT.num());
        setValeur(entityT.valeur());
    }
    ~Bareme() {}
    int controle() const                        {return m_controle;}
    int exercice() const                        {return m_exercice;}
    int fraction() const                        {return m_fraction;}
     //entityId idEntity() const           {return IdEntity;}
     bool isValid() const
    {
        return Entity::isValid() && (m_controle > 0) && (m_exercice > 0) && (m_valeur > 0) && (0 < m_fraction) &&(m_fraction <= m_valeur) && (m_num >= 0) && (!m_nom.isEmpty());
    }
     int nbrValue() const                {return NbrValue;}
    int num() const                             {return m_num;}
    const QString & nom() const                 {return m_nom;}
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
    void setFraction(int fraction)
    {
        if((0 < fraction) && (fraction <= m_valeur))
        {
            m_fraction = fraction;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,FractionPos));
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
    void setNom(const QString & nom)
    {
        if(!nom.isEmpty())
        {
            m_nom = nom;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,NomPos));
        }
    }
    void setValeur(int valeur)
    {
        if(valeur > 0)
        {
            m_valeur = valeur;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,ValeurPos));
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

        case FractionPos:
            setFraction(val.toInt());
            break;

        case NumPos:
            setNum(val.toInt());
            break;

        case NomPos:
            setNom(val.toString());
            break;

        case ValeurPos:
            setValeur(val.toInt());
            break;

        default:
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
    int valeur() const                          {return m_valeur;}
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

        case ExercicePos:
            return QVariant(exercice());
            break;

        case FractionPos:
            return QVariant(fraction());
            break;

        case NumPos:
            return QVariant(num());
            break;

        case NomPos:
            return QVariant(nom());
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
        const Bareme & entityT = convert(entity);
        setId(entity.id());
        setControle(entityT.controle());
        setExercice(entityT.exercice());
        setFraction(entityT.fraction());
        setNom(entityT.nom());
        setNum(entityT.num());
        setValeur(entityT.valeur());
        //return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Bareme & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_controle == entityT.controle())
                 &&(m_exercice == entityT.exercice())
                 &&(m_fraction == entityT.fraction())
                 &&(m_nom == entityT.nom())
                 &&(m_num == entityT.num())
                 &&(m_valeur == entityT.valeur());
     }

     INCLUCE_METHODE(Bareme)
     /*const Bareme & verif(const Entity & entity)
     {
         if(verifEntity(entity))
         {
             return *((Bareme*) &entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     const Bareme & verif(Entity * entity)
     {
         if(verifEntity(*entity))
         {
             return (Bareme*) entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
    bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
protected:
     /*void setInt1(int kk)                   {setControle(kk);}
     void setInt2(int kk)                   {setExercice(kk);}
     void setInt3(int kk)                   {setFraction(kk);}
     void setString1(const QString & string){setNom(string);}
     void setInt4(int kk)                   {setNum(kk);}
     void setInt5(int kk)                   {setValeur(kk);}

     int valueInt1() const                  {return m_controle;}
     int valueInt2() const                  {return m_exercice;}
     int valueInt3() const                  {return m_fraction;}
     const QString & valueString1() const   {return m_nom;}
     int valueInt4() const                  {return m_num;}
     int valueInt5() const                  {return m_valeur;}*/
};

#endif // BAREME_H
