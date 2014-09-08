#ifndef LANZADOROPERACIONES_H
#define LANZADOROPERACIONES_H
#include <QObject>
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
#include"operacionbase.h"
#include"operacionmet.h"
#include"operacionorto.h"
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
#include <OperacionPcot/worker.h>
#include <OperacionPcot/workermet.h>
#include <OperacionPcot/workermetcat.h>
#include <QFileInfo>
#include <QFile>
class LanzadorOperaciones : public QObject
{
    Q_OBJECT
public:
    explicit LanzadorOperaciones(QObject *parent = 0, RegistroCreateCnps *_regCnp=0,RegistroCreateMet  *_regMet=0,
                                 RegistroCreateOrto *_regOrto=0,TableViewCoordinates *_tableCoor=0);
    void operacionCnps();
    void operacionMet();
    void operacionOrto();
    QVariantList obtenerDatosModelo(ModeloCoordenadas *_modeloC);
    bool getCnpActivo();
    bool getMetActivo();
    bool getOrtoActivo();
    void launch();
signals:

    void pasoCnpActual(int);
    void sendError(QString error);
public slots:

 void setObjetoRegistroCnp(RegistroCreateCnps *_regCnp);
 void setObjetoRegistroMet(RegistroCreateMet *_regMet);
 void setObjetoRegistroOrto(RegistroCreateOrto *_regOrto);
 void setObjetotableCoordinates(TableViewCoordinates *_tableCoor);
 void pasoCnp(int paso);
 void errorCnp(QString error, int paso);

 void setCnpActivo(bool cnpActivo);
 void setMetActivo(bool metActivo);
 void setOrtoActivo(bool ortoActivo);
 void siguienteOperacionCnp();
private:
 RegistroCreateCnps *_registroCnp;
 RegistroCreateMet  *_registroMet;
 RegistroCreateOrto *_registroOrto;
 TableViewCoordinates *_tableCoordinates;
 operacionProgresdialog *_tablaproceso;
 OperacionMet *_opeMet;
 OperacionOrto *_opeOrto;
 DataZoneProject *_dataZoneCnp;
 DataZoneProject *_dataZoneMet;
 DataZoneProject *_dataZoneOrto;
 QList <IdentificadorCoordenadas *> IdeCor;
 QList <IdentificadorCoordenadas *> createIDC();

 //codigo nuevo
 QList <Operacion *> _listadoOperacionCnp;
 Worker *_Wcnp;
 Worker *_WMet;
 Worker *_WOrto;
 bool _cnpActivo;
 bool _metActivo;
 bool _ortoActivo;
 int contadorCnp;
 QList <Operacion *> createListadoOperacion();
 QList <Operacion *> createListadoOperacionCnp();
 void siguienteProceso();
 QList <Proceso *> createListadoProcesos();
 QList <Proceso *> listaProcesos;

};

#endif // LANZADOROPERACIONES_H
