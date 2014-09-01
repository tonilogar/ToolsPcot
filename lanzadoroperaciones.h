#ifndef LANZADOROPERACIONES_H
#define LANZADOROPERACIONES_H
#include <QObject>
#include <QFileInfo>
#include <QProcess>
#include <QMessageBox>
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
#include"operacioncnp.h"
#include"operacionorto.h"
#include <QApplication>
#include <OperacionPcot/datazoneproject.h>
#include <OperacionPcot/identificadorcoordenadas.h>
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

signals:
    
public slots:

 void setObjetoRegistroCnp(RegistroCreateCnps *_regCnp);
 void setObjetoRegistroMet(RegistroCreateMet *_regMet);
 void setObjetoRegistroOrto(RegistroCreateOrto *_regOrto);
 void setObjetotableCoordinates(TableViewCoordinates *_tableCoor);

private:
 RegistroCreateCnps *_registroCnp;
 RegistroCreateMet  *_registroMet;
 RegistroCreateOrto *_registroOrto;
 TableViewCoordinates *_tableCoordinates;
 operacionProgresdialog *_tablaproceso;
 OperacionCnp *_opeCnp;
 OperacionMet *_opeMet;
 OperacionOrto *_opeOrto;
 DataZoneProject *_dataZone;
 QList <IdentificadorCoordenadas *> IdeCor;
 QList <IdentificadorCoordenadas *> createIDC();
};

#endif // LANZADOROPERACIONES_H
