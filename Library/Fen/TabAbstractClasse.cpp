#include "TabAbstractClasse.h"

TabAbstractClasse::TabAbstractClasse(int idClasse, TabModule *parent) : TabAbstractTableau(idClasse, parent), m_classe(idClasse)
{
    if(!(m_bdd->get(m_classe)))
    {
        QMessageBox::critical(this,"","Classe introuvable \n identifiant :"+QString::number(idClasse));
    }
    m_annee = Annee(m_classe.idAn());
    m_bdd->get(m_annee);
}

