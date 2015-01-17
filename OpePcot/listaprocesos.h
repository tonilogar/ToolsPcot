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
 * @class ListaProcesos
 * Crea el listado de de punteros de objetos proceso, según los datos del objeto DataZoneProject.
 */
class  OPERACIONPCOTSHARED_EXPORT ListaProcesos : public QObject
{
    Q_OBJECT
public:
    explicit ListaProcesos(QObject *parent,  QMap <QString, QString> qMapEjecutables);
    QList <Proceso *> getListaProcesosMet(DataZoneProject *dataZoPro);
    QList <Proceso *> getListaProcesosOrto(DataZoneProject *dataZoPro);


signals:

public slots:

private:

    QMap <QString, QString> _qMapEjecutables;
};

#endif // LISTAPROCESOS_H
