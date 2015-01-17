#ifndef CCMET_H
#define CCMET_H
#include "operacionpcot_global.h"
#include "calculocortes.h"
#include <QDebug>
#include "math.h"

/*!
 * @class CCMet
 * @brief CCMet necesarios para realizar qualquier proceso con el met
 * La clase hereda de CalculoCortes
 */
class OPERACIONPCOTSHARED_EXPORT CCMet : public CalculoCortes
{
    Q_OBJECT
public:

    /*!
     * Constructor son necesarios 3 punteros: puntero a la clase de la que hereda, puntero IdentificadorCoordenadas y puntero DataZoneProject
     *
     */
    explicit CCMet(QObject *parent = 0, IdentificadorCoordenadas *ideCoordenadas=0, DataZoneProject *dataZProject=0);
    /*!
     * metodo virtual
     * Muestra un listado con los datos necesarios
     * para realizar los cortes del met.
     */
    virtual QList <CorteMet*> generaListaCortes();
signals:

public slots:

};

#endif // CCMET_H
