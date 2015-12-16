#ifndef AMBITOWIDGET_H
#define AMBITOWIDGET_H

#include <QWidget>

#include <AmbitoTP/ambito.h>

#include <AmbitoTP/ambevaluador.h>
#include <AmbitoTP/ambevaluatest.h>
#include <AmbitoTP/ambevrangoutmtest.h>

namespace Ui {
class AmbitoWidget;
}

class AmbitoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AmbitoWidget(QWidget *parent = 0,Ambito *amb=0);
    ~AmbitoWidget();

private slots:

    void depuracionSalidaEvaluador(bool);

private:
    Ui::AmbitoWidget *ui;
    Ambito *_ambito;

    AmbEvaluador *_evaluador;
};

#endif // AMBITOWIDGET_H
