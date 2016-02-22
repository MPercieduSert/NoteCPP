#ifndef SELECTANNEEDIALOG_H
#define SELECTANNEEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../Entities/Annee.h"
#include "../Entities/ListEntities.h"


class SelectAnneeDialog : public QDialog
{
    Q_OBJECT
public:
    enum DialogCode {Creer = -1};

protected:
    QLabel *m_label;
    QPushButton *m_okBouton;
    QPushButton *m_creerBouton;
    QPushButton *m_cancelBouton;
    QComboBox *m_listBox;
    QVBoxLayout *m_vLayout;
    QHBoxLayout *m_hLayout;

public:
    SelectAnneeDialog(QVector<Annee> listeAnnee, QWidget *parent=0, bool creerAnnee = false);
    int value() const;
public slots:
    void creerAnnee();



};

#endif // SELECTANNEEDIALOG_H
