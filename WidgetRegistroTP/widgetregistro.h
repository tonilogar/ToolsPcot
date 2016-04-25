#ifndef WIDGETREGISTRO_H
#define WIDGETREGISTRO_H

#include "widgetregistrotp_global.h"

#include <QWidget>
#include <QState>
#include <QStateMachine>
#include <QAbstractTransition>
#include <QSignalTransition>

#include <ProyectoTP/aprotpsection.h>

#include "booltransition.h"


class WIDGETREGISTROTPSHARED_EXPORT WidgetRegistro : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool conectado READ estaConectado WRITE setConectado NOTIFY conectado)

public:
    explicit WidgetRegistro(QWidget *parent = 0);

    //Getters
    bool estaConectado() const;

    enum CorreccionRegistro {
        Inoperativo, Incorrecto, Correcto
    };
    Q_ENUMS(CorreccionRegistro)

    CorreccionRegistro getEstadoCorreccion() const;

    void setRegistro(AProTPSection *reg);

signals:

    void conectado(bool estado);
    void cambioEstadoCorreccion(CorreccionRegistro estado);

public slots:

    void conectarWidget(bool data);

protected slots:

    void setConectado(bool data);


protected:

    AProTPSection *_aproRegistro;
    bool _conectado;

    CorreccionRegistro _correccionActual;
    QStateMachine _mEstado;

    virtual void conectarInterface()=0;
    virtual void desconectarInterface()=0;

    virtual void checkEstadoCorreccion()=0;

    virtual void connectRegistro()=0;

};

#endif // WIDGETREGISTRO_H
