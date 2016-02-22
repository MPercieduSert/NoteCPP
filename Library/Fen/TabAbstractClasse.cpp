#include "TabAbstractClasse.h"

TabAbstractClasse::TabAbstractClasse(int idClasse, Bdd *bdd, TabModule *parent) : TabAbstractTableau(bdd, parent), m_classe(idClasse)
{
    if(!(m_classeIsValid = m_bdd->get(m_classe)))
    {
        QMessageBox::critical(this,"","Classe introuvable \n identifiant :"+QString::number(idClasse));
    }
}

