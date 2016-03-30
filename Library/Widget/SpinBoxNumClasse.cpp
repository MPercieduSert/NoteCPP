#include "SpinBoxNumClasse.h"

SpinBoxNumClasse::SpinBoxNumClasse(const QList<int> & liste, Classe::affichage alpha = Classe::Numeric, QWidget *parent) : QAbstractSpinBox(parent),m_alpha(alpha), m_liste(liste), m_value(-1)
{
    setReadOnly(true);
    setAlignment(Qt::AlignHCenter);
    stepBy(1);
    printValue();
}

void SpinBoxNumClasse::printValue()
{
    if(m_value == 0)
    {
        lineEdit()->setText(QString());
    }
    else
    {
        switch (m_alpha) {
        case Classe::Numeric:
            lineEdit()->setText(QString::number(m_value));
            break;
        case Classe::AlphabeticMaj:
            lineEdit()->setText(QString("ABCDEFGHIJKLMNOPQRSTUVWXYZ").at(m_value));
            break;
        case Classe::AlphabeticMin:
            lineEdit()->setText(QString("abcdefghijklmnopqrstuvwxyz").at(m_value));
            break;
        }
    }
}

void SpinBoxNumClasse::setListe(const QList<int> &liste)
{
    m_liste = liste;
    m_value = -1;
    stepBy(1);
    printValue();
}

void SpinBoxNumClasse::stepBy(int steps)
{
    if(steps > 0)
    {
        m_value += steps;
        while(m_liste.contains(m_value))
        {
            ++m_value;
            if(m_value >= 26 && (m_alpha == Classe::AlphabeticMaj || m_alpha == Classe::AlphabeticMin))
            {
                m_value = 0;
            }
        }
        printValue();
    }
    else if(steps < 0)
    {
        int value = m_value;
        value += steps;
        while(value >=0 && m_liste.contains(value))
        {
            --value;
        }
        if(value >= 0)
        {
            m_value = value;
            printValue();
        }
    }
}

QAbstractSpinBox::StepEnabled SpinBoxNumClasse::stepEnabled() const
{
    return (StepUpEnabled| StepDownEnabled);
}
