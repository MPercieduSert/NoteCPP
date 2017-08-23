/*Auteur: PERCIE DU SERT Maxime
*Date: 22/08/2017
*/
#ifndef FORME_H
#define FORME_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntity.h"

SINGLE_ATTRIBUT(AlignHAttribut,AttributIntSup,AttributIntSup<0>,AlignH,alignH,int)
SINGLE_ATTRIBUT(AlignVAttribut,AttributIntSup,AttributIntSup<0>,AlignV,alignV,int)
SINGLE_ATTRIBUT(CapitalAttribut,AttributIntSup,AttributIntSup<0>,Capital,capital,int)
SINGLE_ATTRIBUT(FormatAttribut,AttributIntSup,AttributIntSup<0>,Format,format,int)
SINGLE_ATTRIBUT(GrasAttribut,AttributIntSup,AttributIntSup<0>,Gras,gras,int)
SINGLE_ATTRIBUT(ItalicAttribut,AttributIntSup,AttributIntSup<0>,Italic,italic,int)
SINGLE_ATTRIBUT(IndentAttribut,AttributIntSup,AttributIntSup<0>,Indent,indent,int)
SINGLE_ATTRIBUT(LigneAttribut,AttributIntSup,AttributIntSup<0>,Ligne,ligne,int)
SINGLE_ATTRIBUT(MargeAttribut,AttributInt,AttributInt,Marge,marge,int)
SINGLE_ATTRIBUT(PoliceAttribut,AttributStringNotEmpty,AttributStringNotEmpty,Police,police,QString)
SINGLE_ATTRIBUT(TailleAttribut,AttributIntSup,AttributIntSup<0>,Taille,taille,int)

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Forme.
 */
class Forme : public EntityAttributsID<Attributs<AlignHAttribut,
                                                AlignVAttribut,
                                                CapitalAttribut,
                                                FormatAttribut,
                                                GrasAttribut,
                                                ItalicAttribut,
                                                IndentAttribut,
                                                LigneAttribut,
                                                MargeAttribut,
                                                NomAttribut,
                                                PoliceAttribut,
                                                TailleAttribut>,InfoEntity::FormeId>

{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,Forme>::Position,
                   AlignH = PositionEnum<AlignHAttribut,Forme>::Position,
                   AlignV = PositionEnum<AlignVAttribut,Forme>::Position,
                   Capital = PositionEnum<CapitalAttribut,Forme>::Position,
                   Format = PositionEnum<FormatAttribut,Forme>::Position,
                   Gras = PositionEnum<GrasAttribut,Forme>::Position,
                   Italic = PositionEnum<ItalicAttribut,Forme>::Position,
                   Indent = PositionEnum<IndentAttribut,Forme>::Position,
                   Ligne = PositionEnum<LigneAttribut,Forme>::Position,
                   Marge = PositionEnum<MargeAttribut,Forme>::Position,
                   Nom = PositionEnum<NomAttribut,Forme>::Position,
                   Police = PositionEnum<PoliceAttribut,Forme>::Position,
                   Taille = PositionEnum<TailleAttribut,Forme>::Position,
                   NbrAtt};

    using EAID = EntityAttributsID<Attributs<AlignHAttribut,AlignVAttribut,CapitalAttribut,FormatAttribut,GrasAttribut,ItalicAttribut,IndentAttribut,LigneAttribut,MargeAttribut,NomAttribut,PoliceAttribut,TailleAttribut>,InfoEntity::FormeId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(Forme)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    Forme(const QString & nom, int id = 0)
        : EAID(id)
    {setNom(nom);}

    //! Constructeur à partir des valeurs attributs.
    Forme(int alignH, int alignV, int capital, int format, int gras, int italic, int indent, int ligne, int marge, const QString & nom, const QString & police, int taille, int id = 0)
        : Forme(nom,id)
    {
        setAlignH(alignH);
        setAlignV(alignV);
        setCapital(capital);
        setFormat(format);
        setGras(gras);
        setItalic(italic);
        setIndent(indent);
        setLigne(ligne);
        setMarge(marge);
        setPolice(police);
        setTaille(taille);
    }
};

#endif // FORME_H
