/*Auteur: PERCIE DU SERT Maxime
 *Date: 31/01/2016
 */
/*! \defgroup groupeXML XML
 *
 * \brief Ensemble de classes utiliser pour la manipulation de fichiers XML.
 */

/*! \ingroup groupeXML
 * \brief  Cette classe est un arbre de XmlElement permettant de manipuler un document XML.
 *
 * Le document XML est répresenté par la classe XmlDoc sous la forme un arbre de XmlElement.
 * La navigation dans l'arbre s'effectue à l'aide d'un noeud courant tel un curseur.
 * Voir la classe Tree pour connaitre la manière de parcourir l'arbre, de modifier ou de créer des noeuds dans l'arbre.
 *  - Un XmlDoc peut-être obtenu à partir d'un fichier XML grâce à XmlReader.
 *  - Un XmlDoc peut-être écrit dans un fichier XML grâce à XmlWriter.
 * \sa Tree, XmlElement, XmlReader, XmlWriter
 */

#ifndef XMLDOC_H
#define XMLDOC_H

#include <QList>
#include <QString>
#include <QStringList>
#include <QMap>
#include "../Div/Tree.h"
#include "XmlElement.h"


class XmlDoc : public Tree<XmlElement>
{
protected :

public:
    //! Constructeur.
    XmlDoc()
        {}

    //! Renvoie les attributs du noeud courant sous la forme d'un QMap<clé,valeur>.
    const QMap<QString, QString> & attributes() const
        {return (*m_i)->data().attributes();}

    //! Renvoie le nom du noeud courant.
    const QString & name() const
        {return (*m_i)->data().name();}

    //! Renvoie le texte du noeud courant.
    const QString & text() const
        {return (*m_i)->data().text();}

    //! Déplace le noeud courant de navigation au noeud indiqué.
    /*! Le noeud courant de la navigation devient l'élément correspond au chemin indiqué dont les différents noeuds sont
     * séparés par un /. Par défaut, si les noeuds du chemin n'existent pas il sont créés, prendre newElt=false pour modifier ce
     * comportement. Par défaut, le chemin commence à la racine de l'arbre, prendre root=false pour modifier ce
     * comportement.
     */
    XmlDoc & seek(const QString & chemin, bool newElt = true, bool root = true);

    //! Remplace les attributs du noeud courant par ceux donnés en argument sous la forme d'un QMap<clé,valeur>.
    void setAttributes(const QMap<QString, QString> & atts)
        {(*m_i)->modifData().setAttributes(atts);}

    //! Modifie le nom du noeud courant.
    void setName(const QString & name)
        {(*m_i)->modifData().setName(name);}

    //! Modifie le texte du noeud courant.
    void setText(const QString & text)
        {(*m_i)->modifData().setText(text);}
};

#endif // XMLDOC_H
