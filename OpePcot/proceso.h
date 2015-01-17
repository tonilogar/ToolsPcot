#ifndef PROCESO_H
#define PROCESO_H
#include "operacionpcot_global.h"
#include <QObject>
#include <QProcess>
#include <QTextStream>
#include <QDebug>


class Operacion;

class OPERACIONPCOTSHARED_EXPORT Proceso : public QObject
{
    Q_OBJECT
public:
    explicit Proceso(QObject *parent,QString pathProceso);
    virtual void metodoCnp(Operacion *Op)
    {}
    virtual void metodoMet(Operacion *Op)
    {}
    virtual void metodoOrto(Operacion *Op)
        {}
    bool isLibre();
    enum TipoMetodo{Cnp,Met,Orto,Desconocido
        };
signals:
    void procesoLibre();
    void procesoOcupado();

public slots:
    virtual void procesoIniciado();
    virtual void procesoTerminado(int fin);
    void kill();

protected:
    QProcess _proceso;
    QString _pathProceso;
    QTextStream _flujo;
    Operacion *_opeActual;
    bool _libre;

};

#endif // PROCESO_H
