#ifndef LISTAPROCESOS_H
#define LISTAPROCESOS_H
#include "operacionpcot_global.h"
#include <QObject>
#include <QMap>
#include "datazoneproject.h"
#include "proceso.h"
#include "procesosubscene.h"
#include "procesocutfiles.h"
#include "procesoresize.h"
#include "procesofootprintmask.h"
#include "procesoextraction.h"
#include "procesogeotrans.h"
/*!
 * @class FactoryProcesos
 * Crea el listado de de punteros de objetos proceso, según los datos del objeto DataZoneProject.
 */
class  OPERACIONPCOTSHARED_EXPORT FactoryProcesos : public QObject
{
    Q_OBJECT
public:
    explicit FactoryProcesos(QObject *parent,  QMap <QString, QString> qMapEjecutables);
    QList <Proceso *> buildListaProcesosMet(DataZoneProject *dataZoPro);
    QList <Proceso *> buildListaProcesosOrto(DataZoneProject *dataZoPro);


signals:

public slots:

private:

    QMap <QString, QString> _qMapEjecutables;
};

#endif // LISTAPROCESOS_H
