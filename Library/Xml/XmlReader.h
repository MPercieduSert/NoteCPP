/*Auteur: PERCIE DU SERT Maxime
 *Date: 01/02/2016
 */
/*! \ingroup groupeXML
 */

#ifndef XMLREADER_H
#define XMLREADER_H

#include <QXmlStreamReader>
#include <QMap>
#include "XmlDoc.h"
#include "XmlElement.h"

/*! \var typedef QPair<QString,QMap<QString,QString> > varAtts;
 * \brief Couple (Valeur,Attribut sous forme liste<clé,valeur>) d'un noeud
 */
typedef QPair<QString,QMap<QString,QString> > varAtts;


/*! \ingroup groupeXML
 * \brief Cette classe permet de lire un document XML.
*
* Cette classe donne accés en lecture aux noeuds d'un document XML ou permet d'obtenir l'arbre des noeuds sous la forme d'un XmlDoc.
* Tous les chemins sont relatifs.
* \sa XmlElement, XmlDoc, XmlReader
*/
class XmlReader : public QXmlStreamReader
{
public:
    //! Constructeur
    XmlReader():QXmlStreamReader()
        {}

    //! Constructeur
    XmlReader(QIODevice *device):QXmlStreamReader(device)
        {}

    //! Test si le noeuds dont le chemin est donné par name et possédant l'attribut attName de valeur attValue existe.
    bool exists(const QString & name, const QString & attName, const QString & attValue)
    {
        QMap<QString,QString> atts;
        atts.insert(attName,attValue);
        return exists(name, atts);
    }

    //! Test si le noeuds dont le chemin est donné par name et possédant les attributs atts donné sous forme d'un QMap<clé,valeur> existe.
    bool exists(const QString & name, const QMap<QString,QString> & atts = QMap<QString,QString>());

    //! Retourne la liste des valeurs des noeuds dont le chemin est donné par name et possédant l'attribut attName de valeur attValue.
    QStringList getVars(const QString & name, const QString & attName, const QString & attValue)
    {
        QMap<QString,QString> atts;
        atts.insert(attName,attValue);
        return getVars(name, atts);
    }

    //! Retourne la liste des valeurs des noeuds dont le chemin est donné par name et possédant les attributs atts donné sous forme d'un QMap<clé,valeur>.
    QStringList getVars(const QString & name, const QMap<QString,QString> & atts = QMap<QString,QString>())
    {
        QStringList strList;
        getVarsRec(name, atts, strList);
        return strList;
    }

    //! Retourne un vecteur de pairs (valeur,attributs) associés aux noeuds dont le chemin est donné par name et possédant l'attribut attName de valeur attValue.
    QVector<varAtts> getVarsAtts(const QString & name, const QString & attName, const QString & attValue)
    {
        QMap<QString,QString> atts;
        atts.insert(attName,attValue);
        return getVarsAtts(name, atts);
    }

    //! Retourne un vecteur de pairs (valeur,attributs) associés aux noeuds dont le chemin est donné par name et possédant les attributs atts donné sous forme d'un QMap<clé,valeur>.
    QVector<varAtts> getVarsAtts(const QString & name, const QMap<QString,QString> & atts = QMap<QString,QString>())
    {
        QVector<varAtts> varsAtts;
        getVarsAttsRec(name, atts, varsAtts);
        return varsAtts;
    }

    //! Lit entièrement le fichier Xml et stoke dans l'arbre XmlDoc transmis en argument.
    void readIn(XmlDoc & doc);

    //! Lit entièrement le fichier Xml puis renvoie un arbre XmlDoc.
    XmlDoc read();

    //! Lit le noeud courant du flux QXmlStreamReader puis retourne un XmlElement contenant les informations du noeud.
    XmlElement readElement()
    {XmlElement element;
        element.setName(name().toString());
        QMap<QString,QString> map;
        QXmlStreamAttributes atts = attributes();
        for(QXmlStreamAttributes::const_iterator j = atts.constBegin(); j != atts.constEnd(); ++j)
            map.insert(j->name().toString(),j->value().toString());
        element.setAttributes(map);
        return element;
    }

protected:
    //! fonction récurrsive à la base de la fonction getVars
    void getVarsRec(const QString & name, const QMap<QString,QString> & atts, QStringList & strList);

    //! fonction récurrsive à la base de la fonction getVarsAtts
    void getVarsAttsRec(const QString & name, const QMap<QString,QString> & atts, QVector<varAtts> & varsAtts);

};

#endif // XMLREADER_H
