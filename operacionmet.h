#ifndef OPERACIONMET_H
#define OPERACIONMET_H
#include"operacionbase.h"
#include"registrocreatemet.h"
#include"createmet.h"
#include"cortemet.h"
#include"ometdatosejecucion.h"
#include <QVariantMap>
#include <QList>
#include <QVariant>
#include <math.h>
class OperacionMet : public OperacionBase
{
    Q_OBJECT
public:
    explicit OperacionMet(QObject *parent = 0);

signals:

public slots:
    virtual void inicio();//virtual
    virtual void fin(int end);//virtual
    virtual void startOperacion();//virtual
    virtual void cancelarOperacion();

protected:
    QString zProyecto;
    QString aProyecto;
    QString exeSScene;
    QString exeImaOpeGeo;
    QString exeFootPrintMask;
    int utmDefecto;
    QString fOut;
    double pixel;
    int utm;
    int sCut;
    int nCanals;
    int aPasada;
    int oPasada;
    QVariantList tabla;
    bool controlOperacion;
    int contadorFilas;
    int totalPasos;
    int procesoQueToca;
    bool footPrintMask;
    bool cutDtm;
    QList <QList<CorteMet *> > resDef;
    QList <OmetDatosEjecucion*> datosEjecucion;
    //metodos
    void recalcularTablaFPM();
    QList <QList<CorteMet *> > calculoCorte();
    QList <CorteMet*> calculaCorteFila(QString ident,int este,int oeste,int norte,int sur,OmetDatosEjecucion* datosEje);
};

#endif // OPERACIONMET_H
