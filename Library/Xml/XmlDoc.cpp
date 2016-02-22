#include "XmlDoc.h"

XmlDoc & XmlDoc::seek(const QString & chemin, bool newElt, bool root)
{
    if(root) begin();
    bool controle = true;
    QList<QString> list(chemin.split("/"));
    for(QList<QString>::const_iterator i = list.cbegin(); controle && i != list.cend(); ++i)
    {
        QList< TreeItem<XmlElement> *>::const_iterator j = childs().cbegin();
        while(j != childs().cend() && (*j)->data().name() != *i) ++j;
        if(j == childs().cend())
        {
            controle = false;
            if(newElt)
            {
                XmlElement elt;
                for(; i != list.cend(); ++i)
                {
                    elt.setName(*i);
                    addChild(elt);
                }
            }
            else
            {
                m_i = m_root;
            }
        }
        else
        {
            m_i = *j;
        }
    }
    return *this;
}
