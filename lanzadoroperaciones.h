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
#include"registrocnps.h"
#include"registromet.h"
#include"registroorto.h"
#include"tableviewcoordinates.h"
#include <QProgressDialog>
#include <QTextStream>
#include"dialogprogresoope.h"
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
    /*!
     * Constructor explicit per defecte, necesita un punter nul,tres punters de RegistroCnps,RegistroMet, RegistroOrto
     *i TableViewCoordinates.
     */
    explicit LanzadorOperaciones(QObject *parent = 0, RegistroCnps *_regCnp=0,RegistroMet  *_regMet=0,
                                 RegistroOrto *_regOrto=0,TableViewCoordinates *_tableCoor=0);
    /*!
     * Mostra el valor del boolea del proces cnp.
     */
    bool getCnpActivo();
    /*!
     * Mostra el valor del boolea del proces met
     */
    bool getMetActivo();
    /*!
     * Mostra el valor del boolea del proces orto.
     */
    bool getOrtoActivo();
    /*!
     * Identifica les operacions seleccionades i les llença.
     */
    void launch();
signals:

    public slots:
    /*!
     * Canvia el valor del objecte RegistroCnps.
     * @param Nou valor del objecte RegistroCnps.
     */
 void setObjetoRegistroCnp(RegistroCnps *_regCnp);
 /*!
  * Canvia el valor del objecte RegistroMet.
  * @param Nou valor del objecte RegistroMet.
  */
 void setObjetoRegistroMet(RegistroMet *_regMet);
 /*!
  * Canvia el valor del objecte RegistroOrto.
  * @param Nou valor del objecte RegistroOrto.
  */
 void setObjetoRegistroOrto(RegistroOrto *_regOrto);
 /*!
  * Canvia el valor del objecte TableViewCoordinates.
  * @param Nou valor del objecte TableViewCoordinates.
  */
 void setObjetotableCoordinates(TableViewCoordinates *_tableCoor);
 /*!
  * Canvia el valor del boolea del proces cnp.
  * @param Nou valor del boolea del proces cnp.
  */
 void setCnpActivo(bool cnpActivo);
 /*!
  * Canvia el valor del boolea del proces met.
  * @param Nou valor del boolea del proces met.
  */
 void setMetActivo(bool metActivo);
 /*!
  * Canvia el valor del boolea del proces orto.
  * @param Nou valor del boolea del proces orto.
  */
 void setOrtoActivo(bool ortoActivo);


private:
 RegistroCnps *_registroCnp;  ///< Valor del objecte RegistroCnps.
 RegistroMet  *_registroMet;  ///< Valor del objecte RegistroMet.
 RegistroOrto *_registroOrto; ///< Valor del objecte RegistroOrto.
 TableViewCoordinates *_tableCoordinates; ///< Valor del objecte TableViewCoordinates.
 DialogProgresoOpe *_dialogoProgreso; ///< Valor del objecte DialogProgresoOpe.
 DataZoneProject *_dataZoneCnp; ///< Valor del objecte DataZoneProject cnp.
 DataZoneProject *_dataZoneMet; ///< Valor del objecte DataZoneProject met.
 DataZoneProject *_dataZoneOrto; ///< Valor del objecte DataZoneProject orto.
 QList <IdentificadorCoordenadas *> _listaIdentificadores; ///< Valor del llistat de IdentificadorCoordenadas.


 //codigo nuevo
 QList <Operacion *> _listadoOperacionCnp;///< Valor del llistat per les operacions cnp.
 QList <Operacion *> _listadoOperacionMet;///< Valor del llistat per les operacions met.
 QList <Operacion *> _listadoOperacionOrto;///< Valor del llistat per les operacions orto.
 Worker *_Wcnp;    ///< Valor per al  worker de les operacions cnp.
 Worker *_WMet;    ///< Valor per al  worker de les operacions cnp.
 Worker *_WOrto;   ///< Valor per al  worker de les operacions cnp.
 bool _cnpActivo;  ///< Valor boolea per les operacions cnp.
 bool _metActivo;  ///< Valor boolea per les operacions met.
 bool _ortoActivo; ///< Valor boolea per les operacions orto.
 bool _cnpClose;   ///< Valor boolea cnp per el boto close.
 bool _metClose;   ///< Valor boolea met per el boto close.
 bool _ortoClose;  ///< Valor boolea orto per el boto close.
 ControlWorker *_controlCnp;  ///< Valor del objecte ControlWorker per les operacions cnp.
 ControlWorker *_controlMet;  ///< Valor del objecte ControlWorker per les operacions met.
 ControlWorker *_controlOrto; ///< Valor del objecte ControlWorker per les operacions orto.
 void borrarListadoOperacion(QList <Operacion *> &lista);
 /*!
  * Borra el llistat de les operacions cnp.
  */
 void createListadoOperacionCnp();
 /*!
  * Borra el llistat de les operacions met.
  */
 void createListadoOperacionMet();
 /*!
  * Borra el llistat de les operacions orto.
  */
 void createListadoOperacionOrto();
 /*!
  * Crea la llista de identificadors i coordenades.
  */
 void crearListaIdentificadores();

};

#endif // LANZADOROPERACIONES_H
