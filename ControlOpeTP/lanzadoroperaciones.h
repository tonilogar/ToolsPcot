#ifndef LANZADOROPERACIONES_H
#define LANZADOROPERACIONES_H
#include "controlopetp_global.h"
#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFileInfo>
#include <QProcess>
#include <QMessageBox>
#include <QDebug>
#include <CoordinatesTP/modelocoordenadas.h>
#include <RegistroTP/registrocnp.h>
#include <RegistroTP/registromet.h>
#include <RegistroTP/registroorto.h>
#include <QProgressDialog>
#include <QTextStream>
#include <QApplication>
#include <OpePcot/datazoneproject.h>
#include <OpePcot/identificadorcoordenadas.h>
//Codigo nuevo
#include <OpePcot/workcoordinates.h>
#include <OpePcot/operacioncnp.h>
#include <OpePcot/pocesocnp.h>
#include <OpePcot/procesosubscene.h>
#include <OpePcot/procesocutfiles.h>
#include <OpePcot/procesoresize.h>
#include <OpePcot/procesofootprintmask.h>
#include <OpePcot/procesoextraction.h>
#include <OpePcot/procesogeotrans.h>
#include <OpePcot/operacionmet.h>
#include <OpePcot/operacionorto.h>
#include <OpePcot/worker.h>
#include <OpePcot/workermet.h>
#include <OpePcot/workerorto.h>
#include <OpePcot/factoryprocesos.h>
#include <QFileInfo>
#include <QFile>
#include "controlworker.h"
class  CONTROLOPETPSHARED_EXPORT LanzadorOperaciones : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor explicit per defecte, necesita un punter nul,tres punters de RegistroCreateCnps,RegistroCreateMet, RegistroCreateOrto
     *i TableViewCoordinates.
     */
    explicit LanzadorOperaciones(QObject *parent = 0, RegistroCnp *_regCnp=0, RegistroMet  *_regMet=0,
                                 RegistroOrto *_regOrto=0, ModeloCoordenadas *_modeloCoor=0);
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
    ControlWorker *getControlCnp();
    ControlWorker *getControlMet();
    ControlWorker *getControlOrto();
signals:
    void inicioOperaciones();

    public slots:
    /*!
     * Canvia el valor del objecte RegistroCreateCnps.
     * @param Nou valor del objecte RegistroCreateCnps.
     */
 void setObjetoRegistroCnp(RegistroCnp *_regCnp);
 /*!
  * Canvia el valor del objecte RegistroCreateMet.
  * @param Nou valor del objecte RegistroCreateMet.
  */
 void setObjetoRegistroMet(RegistroMet *_regMet);
 /*!
  * Canvia el valor del objecte RegistroCreateOrto.
  * @param Nou valor del objecte RegistroCreateOrto.
  */
 void setObjetoRegistroOrto(RegistroOrto *_regOrto);
 /*!
  * Canvia el valor del objecte TableViewCoordinates.
  * @param Nou valor del objecte TableViewCoordinates.
  */
 void setObjetoModeloCoordenadas(ModeloCoordenadas *_mCoor);
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
 RegistroCnp *_registroCnp;  ///< Valor del objecte RegistroCreateCnps.
 RegistroMet  *_registroMet;  ///< Valor del objecte RegistroCreateMet.
 RegistroOrto *_registroOrto; ///< Valor del objecte RegistroCreateOrto.
 ModeloCoordenadas *_modeloCoordenadas; ///< Valor del objecte TableViewCoordinates.
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
