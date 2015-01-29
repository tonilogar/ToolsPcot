#ifndef CONTROLWORKER_H
#define CONTROLWORKER_H
#include "controlopetp_global.h"
#include <QList>
#include <OpePcot/operacion.h>
#include <OpePcot/worker.h>
#include <OpePcot/workermet.h>
#include <OpePcot/workerorto.h>
#include <QObject>

class CONTROLOPETPSHARED_EXPORT ControlWorker : public QObject
{
    Q_OBJECT
public:
    explicit ControlWorker(QObject *parent = 0);
    Worker * getWorker();
    QList <Operacion *> getListaOperaciones();

signals:
    void rangoOperaciones(int min, int max);
    void actualizarPaso(int paso);
    void enviarError(QString error);
    void operacionesTerminadas(bool end);
    void nuevoWorker(Worker *w);
public slots:
    void setWorker(Worker *worker);
    void setListaOperaciones(QList <Operacion *> listaOperaciones);
    void start();
private slots:
    void siguienteOperacion();
    void pasoActualizado(int paso);
    void errorOperacion(QString error, int pasos);
private:
    Worker *_worker;
    QList <Operacion *> _listaOperaciones;
    int _contadorOperacion;
    int _contadorPasos;

};

#endif // CONTROLWORKER_H
