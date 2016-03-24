#ifndef WIDGETREGISTRO_H
#define WIDGETREGISTRO_H

#include "widgetregistrotp_global.h"
#include <QWidget>
#include <ProyectoTP/aprotpsection.h>


class WIDGETREGISTROTPSHARED_EXPORT WidgetRegistro : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetRegistro(QWidget *parent = 0);

    //Getters
    bool getEstadoInterface();
    enum CorreccionRegistro {
        Inoperativo, Incorrecto, Correcto
    };
    Q_ENUMS(CorreccionRegistro)
signals:

public slots:

    void setEstadoInterface(bool data);

 protected:

    AProTPSection *_aproRegistro;
    bool estadoInterface;
    virtual void activarInterface();
    virtual void desactivarInterface();




};

#endif // WIDGETREGISTRO_H
