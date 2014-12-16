#ifndef CONTROLWORKER_H
#define CONTROLWORKER_H
#include <QList>
#include <OperacionPcot/operacion.h>
#include <OperacionPcot/worker.h>
#include <OperacionPcot/workermet.h>
#include <OperacionPcot/workerorto.h>
#include <QObject>
/*!
 * @class ControlWorker
 * @brief ControlWorker
 * Utilitza les dades dels objectes worker i les llistes de operacions per controlar
 * els processos i els passos actualitzacions de la barra de progres
 *
 */
class ControlWorker : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor explicit reb un punter nul.
     */
    explicit ControlWorker(QObject *parent = 0);
    /*!
     * Crear objecte worker.
     */
    Worker * getWorker();
    /*!
     * Mostra  el contingut del llistat d'operacions.
     */
    QList <Operacion *> getListaOperaciones();

signals:
    /*!
     * Valors per el minin màxim de barra de progrés.
     */
    void rangoOperaciones(int min, int max);
    /*!
     * Actualitzar pas de la barra de progres.
     */
    void actualizarPaso(int paso);
    /*!
     * Enviar l'error generat per el Qproces.
     */
    void enviarError(QString error);
    /*!
     * Enviar senyal d’operacions acabades.
     */
    void operacionesTerminadas(bool end);
    /*!
     * Crear objecte worker.
     */
    void nuevoWorker(Worker *w);
public slots:
    /*!
     * Canvia el valor del objecte worker.
     * @param Nou valor del objecte worker.
     *
     */
    void setWorker(Worker *worker);
    /*!
     * Canvia el valor del llistat d'operacions.
     * @param Nou valor del llistat d'operacions.
     *
     */
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
