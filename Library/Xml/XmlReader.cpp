#include "XmlReader.h"

bool XmlReader::exists(const QString & nameVar, const QMap<QString,QString> & atts)
{
    int n = nameVar.indexOf('/');

    if (n<0)
    {
        QMap<QString,QString>::const_iterator i;
        bool controle=false;
        while(readNextStartElement() && !controle)
        {
           if(name() == nameVar)
           {
               if(!atts.isEmpty())
               {
                    QXmlStreamAttributes attribs = attributes();
                    i = atts.constBegin();
                    while(i != atts.constEnd() && attribs.hasAttribute(i.key()) && attribs.value(i.key()) == i.value()) ++i;
                    controle = (i == atts.constEnd());
               }
               else
               {
                   controle = true;
               }
           }
            skipCurrentElement();
        }
        return controle;
    }
    else
    {
        QString dirVar = nameVar.left(n);
        QString pathVar = nameVar.right(nameVar.size()-n-1);

        while(readNextStartElement() && name() != dirVar) skipCurrentElement();
        if(name() == dirVar)
        {
            return exists(pathVar, atts);
        }
        else
        {
            return false;
        }
    }
}

void XmlReader::getVarsRec(const QString & nameVar, const QMap<QString,QString> & atts, QStringList & strList)
{
    int n = nameVar.indexOf('/');

    if (n<0)
    {
        QMap<QString,QString>::const_iterator i;
        while(readNextStartElement())
        {
            if(name() == nameVar)
            {
               if(!atts.isEmpty())
               {
                    QXmlStreamAttributes attribs = attributes();
                    i = atts.constBegin();
                    while(i != atts.constEnd() && attribs.hasAttribute(i.key()) && attribs.value(i.key()) == i.value()) ++i;
                    if(i == atts.constEnd())
                    {
                       strList.append(readElementText());
                    }
                    else
                    {
                        skipCurrentElement();
                    }
               }
               else
               {
                   strList.append(readElementText());
               }
            }
            else
            {
                skipCurrentElement();
            }
        }
    }
    else
    {
        QString dirVar = nameVar.left(n);
        QString pathVar = nameVar.right(nameVar.size()-n-1);

        while(readNextStartElement() && name() != dirVar) skipCurrentElement();
        if(name() == dirVar)
        {
           getVarsRec(pathVar, atts, strList);
        }
    }
}

void XmlReader::getVarsAttsRec(const QString & nameVar, const QMap<QString,QString> & atts, QVector<varAtts> & varsAtts)
{
    int n = nameVar.indexOf('/');

    if (n<0)
    {
        QMap<QString,QString>::const_iterator i;
        bool addVarAtts;
        while(readNextStartElement())
        {
            if(name() == nameVar)
            {
               if(!atts.isEmpty())
               {
                    QXmlStreamAttributes attribs = attributes();
                    i = atts.constBegin();
                    while(i != atts.constEnd() && attribs.hasAttribute(i.key()) && attribs.value(i.key()) == i.value()) ++i;
                    addVarAtts = i == atts.constEnd();
               }
               else
               {
                   addVarAtts = true;
               }

            }
            else
            {
                addVarAtts = false;

            }
            if(addVarAtts)
            {
                varAtts var;
                QXmlStreamAttributes atts = attributes();
                for(QXmlStreamAttributes::const_iterator j = atts.constBegin(); j != atts.constEnd(); ++j)
                    var.second.insert(j->name().toString(),j->value().toString());
                var.first = readElementText();
                varsAtts.append(var);

            }
            else
            {
                skipCurrentElement();
            }

        }
    }
    else
    {
        QString dirVar = nameVar.left(n);
        QString pathVar = nameVar.right(nameVar.size()-n-1);

        while(readNextStartElement() && name() != dirVar) skipCurrentElement();
        if(name() == dirVar)
        {
           getVarsAttsRec(pathVar, atts, varsAtts);
        }
    }
}

void XmlReader::readIn(XmlDoc & doc)
{
    doc.clear();
    while(!atEnd())
    {
        switch (readNext())
        {
        case QXmlStreamReader::StartElement:
            doc.addChild(readElement());
            break;
        case QXmlStreamReader::EndElement:
            doc.toParent();
            break;
        case QXmlStreamReader::Characters:
            doc.setText(text().toString());
            break;
        }
    }
}

XmlDoc XmlReader::read()
{
    XmlDoc doc;
    while(!atEnd())
    {
        switch (readNext())
        {
        case QXmlStreamReader::StartElement:
            doc.addChild(readElement());
            break;
        case QXmlStreamReader::EndElement:
            doc.toParent();
            break;
        case QXmlStreamReader::Characters:
            doc.setText(text().toString());
            break;
        }
    }
    return doc;
}
