/*Auteur: PERCIE DU SERT Maxime
 *Date: 02/02/2016
 */
/*! \ingroup groupeXML
 * \brief Cette classe permet d'écrire un document XML à partir d'un arbre XmlDoc.
 */

#ifndef XMLWRITER_H
#define XMLWRITER_H

#include <QXmlStreamWriter>
#include "XmlDoc.h"

class XmlWriter : public QXmlStreamWriter
{
public:
    //! Constructeur.
    XmlWriter():QXmlStreamWriter()
        {}

    //!Constructeur.
    XmlWriter(QIODevice *device):QXmlStreamWriter(device)
        {}

    //! Fonction écrit l'arbre XmlDoc transmis en argument dans le fichier attaché au flux QXmlStreamWriter.
    void write(const XmlDoc & doc);
};

#endif // XMLWRITER_H
