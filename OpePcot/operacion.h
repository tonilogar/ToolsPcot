#ifndef OPERACION_H
#define OPERACION_H
#include "operacionpcot_global.h"
#include <QObject>
#include <QDebug>
#include "identificadorcoordenadas.h"
#include "datazoneproject.h"
#include "workcoordinates.h"


class Proceso;
/*!
 * @class Operacion
 * @brief Operacion
 * Datos necesarios para Calcular los cortes del met utilizando un objeto IdentificadorCoordenadas
 * y un objeto DataZoneProject.
 *
 */
class OPERACIONPCOTSHARED_EXPORT Operacion : public QObject
{
    Q_OBJECT
public:

    /*!
     * Constructor explicito son necesarios 3 punteros: puntero nulo a QObject, puntero IdentificadorCoordenadas y puntero DataZoneProject
     *
     */
    explicit Operacion(QObject *parent,IdentificadorCoordenadas *idCoor, DataZoneProject *dataZP);

    /*!
     * metodo virtual
     *
     */
    virtual void aceptarProceso(Proceso *p)
    {}


    //Getter
    virtual QString getFileCnpOrigen();
    virtual QString getIdentificador();
    virtual IdentificadorCoordenadas* getidenCoor();
    virtual double getEste();
    virtual double getOeste();
    virtual double getNorte();
    virtual double getSur();
    virtual QString getFileOrigen();
    virtual QString getFileDestino();
    virtual DataZoneProject * getDataZoneProyect(){
        return _dataZP;
    }

    void incrementarPasos();
    int totalPasos();
    int pasoActual();
    void setFallida(QString error);
    bool isFallida();
    bool isCompleta();
    void resetOperation();

signals:
    void pasoActualizado(int paso);
    void operacionFallida(QString error, int contadorpasos);
    void operacionCompleta();
public slots:


protected:
  IdentificadorCoordenadas *_idCoor;
  DataZoneProject *_dataZP;
  WorkCoordinates *_wCoor;
  int contadorpasos;
  int _totalPasos;
  QString _error;
  bool fallida;
  bool completo;
  int _numberPixelsSensor;


};

#endif // OPERACION_H
