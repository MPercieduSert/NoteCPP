/*Auteur: PERCIE DU SERT Maxime
 *Date: 31/01/2016
 */
/*! \ingroup groupeXML
 * \brief Cette classe est un noeud d'un document XML.
 *
 * Cette classe est un noeud d'arbre permettant de manipuler un document XML avec la classe XmlDoc.
 * \sa XmlDoc
 */
#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#include <QString>
#include <QMap>

class XmlElement
{
protected:
    QString m_name; //!< Nom du noeuds XML.
    QString m_text; //!< Texte contenue entre les deux balises du noeuds XML.
    QMap<QString,QString> m_attributes; //!< Attributs XML sous la forme <clé,valeur> attachés au noeud.

public:
    //! Constructeur.
    XmlElement()
        {}

    //! Constructeur.
    XmlElement(const QString & name)
        {m_name = name;}

    //! Renvoie le nom de du noeud.
    const QString & name() const
        {return m_name;}

    //! Renvoie le texte du noeud.
    const QString & text() const
        {return m_text;}

    //! Renvoie les attributs du noeud sous la forme d'un QMap<clé,valeur>.
    const QMap<QString,QString> & attributes() const
        {return m_attributes;}

    //! Test si le noeud posséde des attributs.
    bool hasAttributes() const
        {return !m_attributes.isEmpty();}

    //! Test si le noeud contient du texte.
    bool hasText() const
        {return !m_text.isEmpty();}

    //! Modifie le nom du noeud.
    void setName(const QString & name)
        {m_name = name;}

    //! Modifie le texte du noeud courant.
    void setText(const QString & text)
        {m_text = text;}

    //! Remplace les attributs du noeud par ceux donnés en argument sous la forme d'un QMap<clé,valeur>.
    void setAttributes(const QMap<QString,QString> & map)
        {m_attributes = map;}
};

#endif // XMLELEMENT_H
