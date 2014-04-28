#ifndef ARMCLASEFILESOUT_H
#define ARMCLASEFILESOUT_H

#include <QObject>
#include <QProcess>
#include <QList>
#include <QPair>
#include <QDebug>

/*!
  Mi implementacion para generar las salidas de archivos
  */

class ARMClaseFilesOut : public QObject
{
    Q_OBJECT
public:
    explicit ARMClaseFilesOut(QObject *parent = 0);


signals:

    /*!
      Establece el rango de barra de progreso
      */

    void setProgressRank(int min,int max);

    /*!
      Actualiza el avance de la barra de progreso
      */

    void actualizaAvance(int num);


    void mensajeSalidaestandar(QString mensaje);


    void mensajeError(QString error);

public slots:

    /*!
      Crear archivos att y PIX
      */

   void createFilesAttPix(QList<QPair<QString,QString> > listaPares,QString folderatt,QString folderPix,QString radFile);

    void cancelProgress();
private:

    //Mejora para intentar distintos procesos att-pix en paralelo
    QList<QProcess*> _listaProcesosAttPix;  ///< Lista de procesos paralelos
    QStringList _argumentosAttPix;  ///< Lista de argumentos para el programa att-pix

    QList<QPair<QString,QString> > _listaAtt; ///< Lista de datos att
    int _posicionAtt;           ///< Marcador de la lista
    int _servidos;              ///< Procesos servidos
    QString _folderAtt;
    QString _folderPix;
    QString _radFile;

    /*!
      Generar los nombres de archivos de salida
      */
    QString nombreArchivoSalida(QString nombreSalida,QString directorioSalida);

    /*!
      Generar nombre de archivo de entrada
      */
    QString nombreArchivoEntrada(QString nombreEntrada,QString directorioEntrada);


private slots:

    /*!
      Siguiente proceso de la lista att-pix
      */

    void nextAttPix(int exitCode);

    /*!
      Iniciar para multiples procesos
      */

    void startMulti(int id);


};

#endif // ARMCLASEFILESOUT_H
