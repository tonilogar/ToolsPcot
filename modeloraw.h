#ifndef MODELORAW_H
#define MODELORAW_H

#include <QAbstractTableModel>
#include <QList>
#include "registroraw.h"
class ModeloRaw : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModeloRaw(QObject *parent = 0,QList<RegistroRaw*> lista=QList<RegistroRaw*>());

    //Devuelve el numero de filas del modelo
    int rowCount(const QModelIndex &parent) const;

    //Devuelve el numero de columnas del modelo
    int columnCount(const QModelIndex &parent) const;

    //Tenemos que definir las banderas de estado
    Qt::ItemFlags flags(const QModelIndex &index) const;

    //Metodo que nos devuelve el valor almacenado en una posicion
    QVariant data(const QModelIndex &index, int role) const;

    //Metodo que permite establecer el valor desde la vista
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    //Metodo que devuelve las cabeceras a la vista
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QList< QPair< QString,QString> > getPares();
    //Metodos propios
    void clear();
    void setListaRegistro(QList<RegistroRaw*> nuevaLista);
    QList<RegistroRaw*> getListaRegistro();

    QString getFicheroRad();
    QString getFicheroRadCorr();
    QString getFicheroAttsync();
    QString getDatosRadCorr();
    QString getDatosAttsync();

    bool comprobarEstadoRaw();
signals:
    void cambioEstado(bool state);

public slots:
    void setPrefix(QString prefijo);
    void setNomAvio(QString nomAvio);
    void setNumeroVol(QString numeroVol);
    void setCodiSensor(QString codiSensor);
    void setRangoPasada(QString rangoPasada);
    void setOberturaPasada(QString oberturaPasada);
    void setFicheroRad(QString ficheroRad);

    void setDatosRadCorr(QString datosRadCorr);
    void setDatosAttsync(QString datosAttsync);

    void setFicheroRadCorr(QString ficheroRadCorr);
    void setFicheroAttsync(QString ficheroAttsync);
private:

    //Atributos del modelo
    QList<RegistroRaw*> _listaRegistros;
    QString _prefix;
    QString _nomAvio;
    QString _numeroVol;
    QString _codiSensor;
    QString _rangoPasada;
    QString _oberturaPasada;
    QString _ficheroRad;
    QString _ficheroRadCorr;
    QString _ficheroAttsync;
    QString _datosRadCorr;
    QString _datosAttsync;

    bool _flagStripNumber;
    bool _flagFilenumber;
    bool _flagSignoPasada;
    bool _flagCanalRed;
    bool _flagCanalGreen;
    bool _flagCanalBlue;


private slots:
    /*!evaluar columna de strip number
      */
    bool evaluaColumnaStripNunber();
    bool evaluaColumnaSignoPasada();
    bool evaluaColumnaFileNumber();
    bool evaluaColumnaCanalRed();
    bool evaluaColumnaCanalGreen();
    bool evaluaColumnaCanalBlue();
    bool evaluacionGeneral();

};

#endif // MODELORAW_H
