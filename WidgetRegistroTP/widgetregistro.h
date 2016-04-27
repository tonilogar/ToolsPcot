#ifndef WIDGETREGISTRO_H
#define WIDGETREGISTRO_H

#include "widgetregistrotp_global.h"

#include <QWidget>
#include <QState>
#include <QStateMachine>
#include <QFinalState>
#include <QAbstractTransition>
#include <QSignalTransition>
#include <QCheckBox>

#include <ProyectoTP/aprotpsection.h>

#include "booltransition.h"
#include "checktransition.h"
#include "inttransition.h"

enum CorreccionRegistro {
    Pasivo, ParcialCorrecto, Correcto
};
Q_ENUMS(CorreccionRegistro);

class WIDGETREGISTROTPSHARED_EXPORT WidgetRegistro : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool conectado READ estaConectado WRITE setConectado NOTIFY conectado)
    Q_PROPERTY(bool activo READ estaActivo WRITE setActivo NOTIFY activo)
    Q_PROPERTY(CorreccionRegistro correccion READ estaCorrecto WRITE setCorreccion NOTIFY correccion)

public:
    explicit WidgetRegistro(QWidget *parent = 0);

    //Getters
    bool estaConectado() const;
    bool estaActivo() const;


    CorreccionRegistro estaCorrecto() const;

    void setRegistro(AProTPSection *reg);

signals:

    void conectado(bool estado);
    void activo(bool estado);
    void correccion(CorreccionRegistro correc);

public slots:

    void conectarWidget(bool data);

protected slots:

    void setConectado(bool data);
    void setActivo(bool data);
    void activarWidget(int check);
    void setCorreccion(CorreccionRegistro correc);

    void cambiarCorreccion(CorreccionRegistro c);


protected:

    AProTPSection *_aproRegistro;
    bool _conectado;
    bool _activo;

    CorreccionRegistro _correccionActual;
    QStateMachine _mEstado;
    QStateMachine *_estadoConectado;
    QStateMachine *_estadoActivo;

    virtual void conectarInterface()=0;
    virtual void desconectarInterface()=0;

    virtual void activarInterface()=0;
    virtual void desactivarInterface()=0;

    virtual void checkEstadoCorreccion()=0;

    virtual void connectRegistro()=0;

};

#endif // WIDGETREGISTRO_H
