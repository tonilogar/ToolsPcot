#ifndef CONTROLWORKER_H
#define CONTROLWORKER_H
#include <QList>
#include <OperacionPcot/operacion.h>
#include <OperacionPcot/worker.h>
#include <OperacionPcot/workermet.h>
#include <OperacionPcot/workermetcat.h>
#include <QObject>

class ControlWorker : public QObject
{
    Q_OBJECT
public:
    explicit ControlWorker(QObject *parent = 0);
    Worker * getWorker();
    WorkerMet * getWorkerMet();
    WorkerMetCat * getWorkerMetCat();
    QList <Operacion *> getListaOperaciones();

signals:
    void rangoOperaciones(int min, int max);
    void actualizarPaso(int paso);
    void enviarError(QString error);
    void operacionesTerminadas(bool end);
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
