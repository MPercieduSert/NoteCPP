#ifndef TYPEGROUPE_H
#define TYPEGROUPE_H

#include "Entity.h"

class TypeGroupe : public Entity
{
public:
    static const entityId IdEntity = TypeGroupeId;
    static const int NbrValue = 4;
protected:
    int m_alpha;
    int m_classe;
    QString m_nom;
    int m_type;

public:
    enum position{AlphaPos = 0,
                  ClassePos = 1,
                  NomPos = 2,
                  TypePos = 3};

    TypeGroupe()    {}
    TypeGroupe(int id) : Entity(id) {}
    TypeGroupe(int alpha, int classe, const QString & nom, int type, int id = 0) : Entity(id)
    {
        setAlpha(alpha);
        setClasse(classe);
        setNom(nom);
        setType(type);
    }
    TypeGroupe(const Entity & entity) : Entity(entity.id())
    {
        const TypeGroupe & entityT = convert(entity);
        setAlpha(entityT.alpha());
        setClasse(entityT.classe());
        setNom(entityT.nom());
        setType(entityT.type());
    }
    ~TypeGroupe()   {}
    int alpha() const                       {return m_alpha;}
    int classe() const                      {return m_classe;}
     //entityId idEntity() const       {return IdEntity;}
     bool isValid() const
    {
        return Entity::isValid() && (m_alpha >= 0) && (m_classe > 0) && (!m_nom.isEmpty()) && (m_type > 0);
    }
     int nbrValue() const            {return NbrValue;}
    const QString & nom() const             {return m_nom;}
    void setAlpha(int alpha)
    {
        if(alpha >= 0)
        {
            m_alpha = alpha;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,AlphaPos));
        }
    }
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

        case AlphaPos:
            setAlpha(val.toInt());
            break;

        case ClassePos:
            setClasse(val.toInt());
            break;

        case NomPos:
            setNom(val.toString());
            break;

        case TypePos:
            setType(val.toInt());
            break;

        default:
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
    int type() const                        {return m_type;}
     QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
            break;

        case AlphaPos:
            return QVariant(alpha());
            break;

        case ClassePos:
            return QVariant(classe());
            break;

        case NomPos:
            return QVariant(nom());
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
        const TypeGroupe & entityT = convert(entity);
        setId(entity.id());
        setAlpha(entityT.alpha());
        setClasse(entityT.classe());
        setNom(entityT.nom());
        setType(entityT.type());
        // return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const TypeGroupe & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_alpha == entityT.alpha())
                 &&(m_classe == entityT.classe())
                 &&(m_nom == entityT.nom())
                 &&(m_type == entityT.type());
     }

     INCLUCE_METHODE(TypeGroupe)
protected:
    /*void setInt1(int kk)                    {setAlpha(kk);}
    void setInt2(int kk)                    {setClasse(kk);}
    void setString1(const QString & string) {setNom(string);}
    void setInt3(int kk)                    {setType(kk);}


    int valueInt1() const                   {return m_alpha;}
    int valueInt2() const                   {return m_classe;}
    const QString & valueString1() const    {return m_nom;}
    int valueInt3() const                   {return m_type;}*/
    /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
    const TypeGroupe & verif(const Entity & entity) const
    {
        if(verifEntity(entity))
        {
            return *((TypeGroupe*) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }*/
};

#endif // TYPEGROUPE_H
