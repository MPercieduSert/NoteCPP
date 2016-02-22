#ifndef CLASSE_H
#define CLASSE_H

#include <QStringList>
#include "Entity.h"

class Classe : public Entity
{
public:
    static const entityId IdEntity = ClasseId;
    static const int NbrValue = 4;
protected:
    int m_annee;
    int m_nbr_phase;
    int m_niveau;
    int m_num;
public:
    enum position {AnneePos = 0,
                   Nbr_phasePos = 1,
                   NiveauPos = 2,
                   NumPos = 3};

    Classe()    {}
    Classe(int id) : Entity(id) {}
    Classe(int annee, int nbr_phase, int niveau,  int num, int id =0) : Entity(id)
    {
        setAnnee(annee);
        setNbr_phase(nbr_phase);
        setNiveau(niveau);
        setNum(num);
    }
    Classe(const Entity & entity) : Entity(entity.id())
    {
        const Classe & entityT = convert(entity);
        setAnnee(entityT.annee());
        setNbr_phase(entityT.nbr_phase());
        setNiveau(entityT.niveau());
        setNum(entityT.num());
    }
    ~Classe()   {}
    int annee() const                   {return m_annee;}
     //entityId idEntity() const   {return IdEntity;}
     bool isValid() const
    {
        return Entity::isValid() && (m_niveau > 0) && (m_annee > 0) && (m_nbr_phase > 0) && (m_num >= 0);
    }

    int nbr_phase() const               {return m_nbr_phase;}
    int niveau() const                  {return m_niveau;}
    int num() const                     {return m_num;}
    void setAnnee(int annee)
    {
        if(annee > 0)
        {
            m_annee = annee;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,AnneePos));
        }
    }
    void setNbr_phase(int nbr_phase)
    {
        if(nbr_phase > 0)
        {
            m_nbr_phase = nbr_phase;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,Nbr_phasePos));
        }
    }
    void setNiveau(int niveau)
    {
        if(niveau > 0)
        {
            m_niveau = niveau;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,NiveauPos));
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

        case AnneePos:
            setAnnee(val.toInt());
            break;

        case Nbr_phasePos:
            setNbr_phase(val.toInt());
            break;

        case NiveauPos:
            setNiveau(val.toInt());
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
            return QVariant(id());
            break;

        case AnneePos:
            return QVariant(annee());
            break;

        case Nbr_phasePos:
            return QVariant(nbr_phase());
            break;

        case NiveauPos:
            return QVariant(niveau());
            break;

        case NumPos:
            return QVariant(num());
            break;
        default:
            return QVariant();
        }
    }
     void operator << (const Entity & entity)
    {
        const Classe & entityT = convert(entity);
        setId(entity.id());
        setAnnee(entityT.annee());
        setNbr_phase(entityT.nbr_phase());
        setNiveau(entityT.niveau());
        setNum(entityT.num());
        //return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Classe & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_annee == entityT.annee())
                 &&(m_nbr_phase == entityT.nbr_phase())
                 &&(m_niveau == entityT.niveau())
                 &&(m_num == entityT.num());
     }

     INCLUCE_METHODE(Classe)

     /*const Classe & verif(const Entity & entity) const
     {
         if(verifEntity(entity))
         {
             return *((Classe*) &entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     const Classe & verif(const Entity & entity) const
     {
         if(verifEntity(entity))
         {
             return *((Classe*) &entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
protected:
     /*void setInt1(int kk)                       {setAnnee(kk);}
     void setInt2(int kk)                       {setNbr_phase(kk);}
     void setInt3(int kk)                       {setNiveau(kk);}
     void setInt4(int kk)                       {setNum(kk);}

     int valueInt1() const                      {return m_annee;}
     int valueInt2() const                      {return m_nbr_phase;}
     int valueInt3() const                      {return m_niveau;}
     int valueInt4() const                      {return m_num;}*/
};

#endif // CLASSE_H
