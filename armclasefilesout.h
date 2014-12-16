#ifndef ARMCLASEFILESOUT_H
#define ARMCLASEFILESOUT_H

#include <QObject>
#include <QProcess>
#include <QList>
#include <QPair>
#include <QDebug>

/*!
 * @class ARMClaseFilesOut
 * @brief ARMClaseFilesOut
 * Implementació per generar la sortida de fitxer de canvi de formats att atp pix rf jpg.
 *
 */
class ARMClaseFilesOut : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor es necessari un punter nul.
     */
    explicit ARMClaseFilesOut(QObject *parent = 0);


signals:
    /*!
     * Canvia els valors de la barra de progres.
     * @param Nou valor de la barra de progres
     *
     */
    void setProgressRank(int min,int max);

    /*!
     * Actualitza la barra de progres.
     *
     */
    void actualizaAvance(int num);

    /*!
     * Senyal de sortida estendard del QProcess.
     *
     */
    void mensajeSalidaestandar(QString mensaje);

    /*!
     * Senyal de sortida d'error.
     *
     */
    void mensajeError(QString error);

public slots:

    /*!
     * Crear els fitxers att, atp, pix, rf, jpg.
     *
     */
   void createFilesAttPix(QList<QPair<QString,QString> > listaPares,QString folderatt,QString folderPix,QString radFile);
   /*!
    * Cancelar el progres de canvis de format.
    *
    */
    void cancelProgress();
private:

    //Mejora para intentar distintos procesos att-pix en paralelo
    QList<QProcess*> _listaProcesosAttPix;  ///< Llista de processos paral•lels.
    QStringList _argumentosAttPix;  ///< Llista d'arguments per els canvis de format.

    QList<QPair<QString,QString> > _listaAtt; ///< Llista dades att.
    int _posicionAtt;           ///< Index dels fitxers att.
    int _servidos;              ///< Processos entregats.
    QString _folderAtt;         ///< Directori de sortida fitxers att.
    QString _folderPix;         ///< Directori de sortida fitxers pix.
    QString _radFile;           ///< Nom fitxers *.rad.

    /*!
     * Generar el noms dels fitxers de sortida.
     *
     */
    QString nombreArchivoSalida(QString nombreSalida,QString directorioSalida);

    /*!
     * Generar el noms dels fitxers d'entrada.
     *
     */
    QString nombreArchivoEntrada(QString nombreEntrada,QString directorioEntrada);


private slots:

    /*!
     * Següent procés de la llista att.
     *
     */
    void nextAttPix(int exitCode);

    /*!
     * Iniciar per múltiples processos.
     *
     */
    void startMulti(int id);


};

#endif // ARMCLASEFILESOUT_H
