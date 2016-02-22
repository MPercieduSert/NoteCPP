#ifndef COMMENTAIRE_H
#define COMMENTAIRE_H

#include "Entity.h"

class CommentaireManager;

class Commentaire : public Entity
{
    friend class CommentaireManager;

public:
    static const entityId IdEntity = CommentaireId;
    static const int NbrValue = 2;
protected:
    QString m_texte;
    int m_type;

public:
    enum position{TextePos = 0,
                  TypePos = 1};

    Commentaire() {}
    Commentaire(int id) : Entity(id) {}
    Commentaire(const QString & texte, int type, int id) : Entity(id)
    {
        setTexte(texte);
        setType(type);
    }
    Commentaire(const Entity & entity): Entity(entity.id())
    {
        const Commentaire & entityT = convert(entity);
        setTexte(entityT.texte());
        setType(entityT.type());
    }
    ~Commentaire()  {}
     //entityId idEntity() const               {return IdEntity;}
     bool isValid() const                    {return Entity::isValid() && (m_texte.isEmpty()) && (m_type >= 0);}
     int nbrValue() const                    {return NbrValue;}
    void setTexte(const QString & texte)
    {
        if(texte.isEmpty())
        {
            m_texte = texte;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,TextePos));
        }
    }
    void setType(int type)
    {
        if(type >= 0)
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

        case TextePos:
            setTexte(val.toString());
            break;

        case TypePos:
            setType(val.toInt());
            break;

        default:
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
    const QString & texte() const                   {return m_texte;}
    int type() const                                {return m_type;}
     QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
            break;

        case TextePos:
            return QVariant(texte());
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
        const Commentaire & entityT = convert(entity);
        setId(entity.id());
        setTexte(entityT.texte());
        setType(entityT.type());
        //return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Commentaire & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_texte == entityT.texte())
                 &&(m_type == entityT.type());
     }

     INCLUCE_METHODE(Commentaire)
     /*const Commentaire & verif(const Entity & entity) const
     {
         if(verifEntity(entity))
         {
             return *((Commentaire*) &entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     const Commentaire & verif(const Entity & entity) const
     {
         if(verifEntity(entity))
         {
             return *((Commentaire*) &entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
protected:
     /*void setString1(const QString & string)    {setTexte(string);}
     void setInt1(int kk)                       {setType(kk);}

     const QString & valueString1() const       {return m_texte;}
     int valueInt1() const                      {return m_type;}*/
};

#endif // COMMENTAIRE_H
