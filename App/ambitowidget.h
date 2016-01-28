#ifndef AMBITOWIDGET_H
#define AMBITOWIDGET_H

#include <QWidget>

#include <AmbitoTP/ambito.h>

#include <AmbitoTP/ambevaluador.h>
#include <AmbitoTP/ambevaluatest.h>
#include <AmbitoTP/ambevrangoutmtest.h>
#include <QFileDialog>


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
    void cambioUtm(int index);
    void seleccionarImagenReferencia();
    void changeToFileInfo(QString file);

private:
    Ui::AmbitoWidget *ui;
    Ambito *_ambito;

    AmbEvaluador *_evaluador;
};

#endif // AMBITOWIDGET_H
