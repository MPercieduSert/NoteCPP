#include "SpinBoxNote.h"

SpinBoxNote::SpinBoxNote(int decimale, int value, QWidget *parent) : QSpinBox(parent), m_decimale(decimale)
{
    setAlignment(Qt::AlignRight);
    setValue(value);
}

QString SpinBoxNote::textFromValue(int val) const
    {return QLocale(QLocale::French).toString((double) val / m_decimale);}

//QAbstractSpinBox::StepEnabled SpinBoxNote::stepEnabled() const
//    {return (StepUpEnabled| StepDownEnabled);}
QValidator::State SpinBoxNote::validate(QString &input, int &pos) const
{
    return QDoubleValidator().validate(input,pos);
}

int SpinBoxNote::valueFromText(const QString &text) const
{
    bool bb;
    double note = QLocale(QLocale::French).toDouble(text,&bb);
    if(bb)
        return note * m_decimale;
    else
        return value();
}
