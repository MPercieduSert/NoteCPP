#include "TabAbstractClasse.h"

TabAbstractClasse::TabAbstractClasse(int idClasse, TabModule *parent) : TabAbstractTableau(idClasse, parent), m_classe(idClasse)
{
    if(!(bdd()->get(m_classe)))
    {
        QMessageBox::critical(this,"","Classe introuvable \n identifiant :"+QString::number(idClasse));
    }
    m_annee = Annee(m_classe.idAn());
    bdd()->get(m_annee);
}

