#ifndef CORTEMET_H
#define CORTEMET_H
#include "operacionpcot_global.h"
#include <QObject>

/*!
 * @class CorteMet
 * @brief CorteMet
 * Datos necesarios para Calcular los cortes del met.
 *
 */
class OPERACIONPCOTSHARED_EXPORT CorteMet : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor son necesarios un puntero nulo, dos valores QString y 5 enteros
     * puntero IdentificadorCoordenadas y puntero DataZoneProject.
     */
    explicit CorteMet(QObject *parent = 0, QString nFileIn=QString(), QString nFileOut=QString(), int fSup=0, int fInf=0,
                      int cIz=0, int cDer=0, int ind=0);
//Getter
    /*!
     * Muestra el nombre del fichero de entrada.
     *
     */
    QString getNombreFileIn();

    /*!
     * Muestra el nombre del fichero de salida.
     *
     */
    QString getNombreFileOut();

    /*!
     * Muestra el numero de fila superior.
     *
     */
    int getFilaSup();

    /*!
     * Muestra el numero de fila inferior.
     *
     */
    int getFilaInf();

    /*!
     * Muestra el numero de columna izquierda.
     *
     */
    int getColumnIz();

    /*!
     * Muestra el numero de columna derecha.
     *
     */
    int getColumnDer();

    /*!
     * Muestra el numero del corte
     *
     */
    int getIndice();
signals:

public slots:
 //setters
    /*!
     * Cambia el nombre del fichero de entrada.
     * @param nombreFileIn nuevo valor del fichero de entrada.
     *
     */
    void setNombreFileIn(QString);

    /*!
     * Cambia el nombre del fichero de salida.
     * @param nombreFileOut nuevo valor del fichero de salida.
     *
     */
    void setNombreFileOut(QString);

    /*!
     * Cambia el valor de la fila superior.
     * @param filaSup nuevo valor de la fila superior.
     *
     */
    void setFilaSup(int);

    /*!
     * Cambia el valor de la fila inferior.
     * @param filaInf nuevo valor de la fila inferior.
     *
     */
    void setFilaInf(int);
    /*!
     * Cambia el valor de la columna izquierda.
     * @param columnIz nuevo valor de la columna izquierda.
     *
     */
    void setColumnIz(int);

    /*!
     * Cambia el valor de la columna derecha.
     * @param columnDer nuevo valor de la columna derecha.
     *
     */
    void setColumnDer(int);

    /*!
     * Cambia el valor del indice de corte.
     * @param indice nuevo valor del indice de corte.
     *
     */
    void setIndice(int);



private:
QString nombreFileIn;   ///< Nombre de fichero de entrada.
int filaSup;            ///< Valor de la fila superior.
int filaInf;            ///< Valor de la fila inferior.
int columnIz;           ///< Valor de la columna izquierda.
int columnDer;          ///< Valor de la columna derecha.
int indice;             ///< Valor de indice de corte.
QString nombreFileOut;  ///< Nombre de fichero de salida.


};

#endif // CORTEMET_H
