#ifndef OPERACIONMET_H
#define OPERACIONMET_H
#include "operacionpcot_global.h"
#include "operacion.h"
#include "proceso.h"
#include "cortemet.h"
#include "calculocortes.h"
#include "ccmet.h"
#include <QList>

/*!
 * @class OperacionMet
 * @brief Crea las coordenadas y los ficheros de entrada y salida para cada proceso,
 * segun las coracteristicas del proyecto.
 * Los objetos IdentificadorCoordenadas y DataZoneProject, no son modificados en ningún momento por
 * calculoCortes.
 */

class OPERACIONPCOTSHARED_EXPORT OperacionMet : public Operacion
{
    Q_OBJECT
public:
    /*!
     * Constructor recibe un puntero IdentificadorCoordenadas y puntero DataZoneProject.
     * Con los datos de IdentificadorCoordenadas y DataZoneProject calculo las coordenadas
     * y los ficheros de entrada y salida para los procesos.
     */
    explicit OperacionMet(QObject *parent,IdentificadorCoordenadas *idCoor, DataZoneProject *dataZP);

    virtual QString getFileCnpOrigen();
    virtual void aceptarProceso(Proceso *p);
    virtual QString getFileOrigen();
    virtual QString getFileDestino();

    virtual double getEste();
    virtual double getOeste();
    virtual double getNorte();
    virtual double getSur();


signals:

public slots:

private:

protected:

    QList <CorteMet *> listaCortes;
    void recalcularTablaFPM();
    IdentificadorCoordenadas *_idCoorFPM;
    IdentificadorCoordenadas *_coordenadas;
    CalculoCortes *_cCortes;


};

#endif // OPERACIONMET_H
