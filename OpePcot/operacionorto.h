#ifndef OPERACIONORTO_H
#define OPERACIONORTO_H
#include "operacionpcot_global.h"
#include "operacion.h"
#include "proceso.h"
#include "cortemet.h"
#include "calculocortes.h"
#include "ccmet.h"
#include <QList>


/*!
 * @class OperacionOrto
 * @brief Crea las coordenadas y los ficheros de entrada y salida para cada proceso,
 * segun las coracteristicas del proyecto.
 * Los objetos IdentificadorCoordenadas y DataZoneProject, no son modificados en ningún momento por
 * calculoCortes.
 */

class OPERACIONPCOTSHARED_EXPORT OperacionOrto : public Operacion
{
    Q_OBJECT
public:
    /*!
     * Constructor recibe un puntero IdentificadorCoordenadas y puntero DataZoneProject.
     * Con los datos de IdentificadorCoordenadas y DataZoneProject calculo las coordenadas
     * y los ficheros de entrada y salida para los procesos.
     */
    explicit OperacionOrto(QObject *parent,IdentificadorCoordenadas *idCoor, DataZoneProject *dataZP);

    /*!
     * Muestra el path y el nombre del fichero *.cnp
     */
    virtual QString getFileCnpOrigen();

    /*!
     * Llama al metodo metodoOrto del objeto Proceso
     */
    virtual void aceptarProceso(Proceso *p);

    /*!
     * Muestra el path y el nombre del fichero de origen
     */
    virtual QString getFileOrigen();

    /*!
     * Muestra el path y el nombre del fichero de salida
     */
    virtual QString getFileDestino();

    /*!
     * Muestra la coordenada este
     */
    virtual double getEste();

    /*!
     * Muestra la coordenada oeste
     */
    virtual double getOeste();

    /*!
     * Muestra la coordenada norte
     */
    virtual double getNorte();

    /*!
     * Muestra la coordenada sur
     */
    virtual double getSur();


signals:

public slots:

private:

protected:

    QList <CorteMet *> listaCortes;           ///< Devuelve un listado de punteros a objetos CorteOrto.
    void recalcularTablaFPM();                ///< recalcula las coordenadas si la opción de FootprintMask esta activa.
    IdentificadorCoordenadas *_idCoorFPM;     ///< Identificador de Coordenadas con los que realizaremos los cortes.
    IdentificadorCoordenadas *_coordenadas;   ///< Identificador de Coordenadas con los que realizaremos los cortes.
    CalculoCortes *_cCortes;                 ///< Puntero a objeto CalculoCortes para añadir elementos a la lista listaCortes

};

#endif // OPERACIONORTO_H
