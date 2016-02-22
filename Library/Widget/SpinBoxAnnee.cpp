#include "SpinBoxAnnee.h"

SpinBoxAnnee::SpinBoxAnnee(int value, QWidget *parent): QAbstractSpinBox(parent), m_value(value)
{
    setReadOnly(true);
    setAlignment(Qt::AlignHCenter);
    printValue();
}

void SpinBoxAnnee::printValue()
{
    lineEdit()->setText(QString::number(m_value)+"-"+QString::number(m_value+1));
}

void SpinBoxAnnee::stepBy(int steps)
{
    m_value += steps;
    printValue();
}

QAbstractSpinBox::StepEnabled SpinBoxAnnee::stepEnabled() const
{
    return (StepUpEnabled| StepDownEnabled);
}
