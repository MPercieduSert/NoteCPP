#include "ControleGraphDialog.h"

ControleGraphDialog::ControleGraphDialog(const Controle & controle, const QVector<double> &notes, QWidget *parent)
    : QDialog(parent), m_controle(controle)
{
    int i = 0;
    QVector<double> intervalle(m_controle.total() / largeurBar() + 1);
    std::generate(intervalle.begin(), intervalle.end(), [this,&i]() -> double {return i++ * largeurBar();});

    i = 0;
    QVector<QBrush> aspet(m_controle.total() / largeurBar() + 1);
    std::generate(aspet.begin(), aspet.end(), [this,&i,&intervalle]() -> QBrush {
                      return intervalle[i++] * m_controle.decimale() < m_controle.minima() ? QBrush(Qt::red) : QBrush(Qt::blue);});

    m_plotter = new Histogramme(intervalle, aspet, notes);
    m_plotter->setAxesAuto();
//    Plotter::Axes axes;
//    axes.setXOrigine(0);
//    axes.setXMin(-1);
//    axes.setXMax(1);
//    axes.setXGraduation(0.3);
//    axes.setYOrigine(0);
//    axes.setYMin(-1);
//    axes.setYMax(1);
//    axes.setYGraduation(0.3);
//    m_plotter = new Plotter;
//    m_plotter->setAxes(axes);
    m_plotter->setMarge(50);



    // Bouton
    m_buttonAccepter = new QPushButton(tr("Ok"));
    connect(m_buttonAccepter,&QPushButton::clicked,this,&ControleGraphDialog::accept);

    m_buttonAnnuler = new QPushButton(tr("Annuler"));
    connect(m_buttonAnnuler,&QPushButton::clicked,this,&ControleGraphDialog::reject);

    m_layoutButton = new QHBoxLayout();
    m_layoutButton->addWidget(m_buttonAnnuler);
    m_layoutButton->addWidget(m_buttonAccepter);

    // Main layout
    m_LayoutMain = new QVBoxLayout(this);
    m_LayoutMain->addWidget(m_plotter);
    m_LayoutMain->addLayout(m_layoutButton);
}
