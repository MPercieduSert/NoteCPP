#include "XmlWriter.h"

void XmlWriter::write(const XmlDoc & doc)
{
    setAutoFormatting(true);
    doc.begin();
    writeStartDocument();
    while(doc.suivant())
    {
        if(doc.sens())
        {
            XmlElement elt = doc.data();
            writeStartElement(elt.name());        
            if(elt.hasAttributes())
            {
                for(QMap<QString,QString>::const_iterator i = elt.attributes().cbegin(); i != elt.attributes().cend(); ++i)
                {
                    writeAttribute(i.key(),i.value());
                }
            }
            if(elt.hasText())
            {
                writeCharacters(elt.text());
            }
        }
        else
        {
            writeEndElement();
        }
    }
    writeEndDocument();
}
