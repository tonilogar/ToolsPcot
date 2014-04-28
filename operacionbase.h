#ifndef OPERACIONBASE_H
#define OPERACIONBASE_H
#include <QObject>
#include <QVariantMap>
#include <QTextStream>
#include <QProcess>
#include"operacionprogresdialog.h"
#include <QDateTime>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
class OperacionBase : public QObject
{
    Q_OBJECT
public:
    explicit OperacionBase(QObject *parent = 0);
    QVariantMap getDatosRegistro();
signals:
    void actualizarProgreso(int paso);
    void inicioProgreso(int min, int max);
    void errorProgreso(QString ultimoMensaje);
    void finProgreso();
    void inicioIccImaOpeGeo();


public slots:
    void setDatosRegistro(QVariantMap datos);
    virtual void inicio()=0;//metodo virtual para que los hijos puedan cambiar el metodo
    void datosSalida();
    virtual void fin(int end)=0;
    void resetOperacion();
    virtual void startOperacion()=0;
    virtual void cancelarOperacion()=0;

protected:
    QVariantMap registro;
    int contador;
    QTextStream flujo;
    QProcess proceso;
    void obStartOperacion();
    operacionProgresdialog *_tablaproceso;
};

#endif // OPERACIONBASE_H
