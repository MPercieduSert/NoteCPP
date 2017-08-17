/*Auteur: PERCIE DU SERT Maxime
 *Date: 09/03/2017
 */
#ifndef SPINBOXNOTE_H
#define SPINBOXNOTE_H

#include <QSpinBox>
#include <QDoubleValidator>

/*! \ingroup groupeWidget
 * \brief Spin Box pour les notes.
 */
class SpinBoxNote : public QSpinBox
{
    Q_OBJECT
protected:
    int m_decimale;     //! Decimale
     //int m_value;        //! Valeur (note = valeur / decimale )
public:
    SpinBoxNote(int decimale = 1, int value = 0, QWidget * parent = 0);

protected:
    //! Affiche la note.
    QString textFromValue(int val) const;

    //! Return la validité du text en double.
    QValidator::State validate(QString &input, int &pos) const;

    //! Modifie la valeur.
    int valueFromText(const QString &text) const;


};

#endif // SPINBOXNOTE_H
