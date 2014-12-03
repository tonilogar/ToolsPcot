#ifndef LANZADOROPERACIONES_H
#define LANZADOROPERACIONES_H
#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFileInfo>
#include <QProcess>
#include <QMessageBox>
#include <QDebug>
#include"modelocoordenadas.h"
#include"registrocreatecnps.h"
#include"registrocreatemet.h"
#include"registrocreateorto.h"
#include"tableviewcoordinates.h"
#include"debugqprocess.h"
#include <QProgressDialog>
#include <QTextStream>
#include"operacionprogresdialog.h"
#include <QApplication>
#include <OperacionPcot/datazoneproject.h>
#include <OperacionPcot/identificadorcoordenadas.h>
//Codigo nuevo
#include <OperacionPcot/workcoordinates.h>
#include <OperacionPcot/operacioncnp.h>
#include <OperacionPcot/pocesocnp.h>
#include <OperacionPcot/procesosubscene.h>
#include <OperacionPcot/procesocutfiles.h>
#include <OperacionPcot/procesoresize.h>
#include <OperacionPcot/procesofootprintmask.h>
#include <OperacionPcot/procesoextraction.h>
#include <OperacionPcot/procesogeotrans.h>
#include <OperacionPcot/operacionmet.h>
#include <OperacionPcot/operacionorto.h>
#include <OperacionPcot/worker.h>
#include <OperacionPcot/workermet.h>
#include <OperacionPcot/workerorto.h>
#include <OperacionPcot/listaprocesos.h>
#include <QFileInfo>
#include <QFile>
#include "controlworker.h"
class LanzadorOperaciones : public QObject
{
    Q_OBJECT
public:
    explicit LanzadorOperaciones(QObject *parent = 0, RegistroCreateCnps *_regCnp=0,RegistroCreateMet  *_regMet=0,
                                 RegistroCreateOrto *_regOrto=0,TableViewCoordinates *_tableCoor=0);

    bool getCnpActivo();
    bool getMetActivo();
    bool getOrtoActivo();
    void launch();
signals:

    public slots:

 void setObjetoRegistroCnp(RegistroCreateCnps *_regCnp);
 void setObjetoRegistroMet(RegistroCreateMet *_regMet);
 void setObjetoRegistroOrto(RegistroCreateOrto *_regOrto);
 void setObjetotableCoordinates(TableViewCoordinates *_tableCoor);
 void setCnpActivo(bool cnpActivo);
 void setMetActivo(bool metActivo);
 void setOrtoActivo(bool ortoActivo);


private:
 RegistroCreateCnps *_registroCnp;
 RegistroCreateMet  *_registroMet;
 RegistroCreateOrto *_registroOrto;
 TableViewCoordinates *_tableCoordinates;
 operacionProgresdialog *_dialogoProgreso;
 DataZoneProject *_dataZoneCnp;
 DataZoneProject *_dataZoneMet;
 DataZoneProject *_dataZoneOrto;
 QList <IdentificadorCoordenadas *> _listaIdentificadores;


 //codigo nuevo
 QList <Operacion *> _listadoOperacionCnp;
 QList <Operacion *> _listadoOperacionMet;
 QList <Operacion *> _listadoOperacionOrto;
 Worker *_Wcnp;
 Worker *_WMet;
 Worker *_WOrto;
 bool _cnpActivo;
 bool _metActivo;
 bool _ortoActivo;
 ControlWorker *_controlCnp;
 ControlWorker *_controlMet;
 ControlWorker *_controlOrto;
 void borrarListadoOperacion(QList <Operacion *> lista);
 void createListadoOperacionCnp();
 void createListadoOperacionMet();
 void createListadoOperacionOrto();
 void crearListaIdentificadores();
 int contadorOperaciones;
};

#endif // LANZADOROPERACIONES_H
