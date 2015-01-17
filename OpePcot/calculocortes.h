#ifndef CALCULOCORTES_H
#define CALCULOCORTES_H
#include "operacionpcot_global.h"
#include <QObject>
#include "identificadorcoordenadas.h"
#include "datazoneproject.h"
#include "cortemet.h"

/*!
 * @class CalculoCortes
 * @brief Calcula las dimensiones de los cortes de met en caso que se seleccione la opción de corte booleana "_cutDtm".
 *
 */
class OPERACIONPCOTSHARED_EXPORT CalculoCortes : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor recibe un puntero IdentificadorCoordenadas y puntero DataZoneProject.
     * Con los datos de IdentificadorCoordenadas y DataZoneProject realizo las operaciones de corte.
     * Los objetos IdentificadorCoordenadas y DataZoneProject, no son modificados en ningún momento por
     * calculoCortes.
     * @note El objeto IdentificadorCoordenadas y DataZoneProject pueden estar compartido por multiples objetos tipo operación.
     */
    explicit CalculoCortes(QObject *parent = 0, IdentificadorCoordenadas *ideCoordenadas=0, DataZoneProject *dataZProject=0);
    /*!
     *Devuelve la lista de cortes, para el IdentificadorCoordenadas y el DataZoneProject.
     *@return Lista de cortes, o lista vacia si no es necesario realizar ningún corte.
     *@note No se modifican los objetos IdentificadorCoordenadas y DataZoneProject.
     */
    virtual QList <CorteMet*> generaListaCortes()=0;

signals:

public slots:


protected:
    IdentificadorCoordenadas *_ideCoordenadas;  ///< Identificador de Coordenadas con los que realizaremos los cortes.
    DataZoneProject *_dataZProject;             ///< Datos del proyecto.
};

#endif // CALCULOCORTES_H
