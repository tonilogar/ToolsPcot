#ifndef IDENTIFICADORCOORDENADAS_H
#define IDENTIFICADORCOORDENADAS_H
#include "operacionpcot_global.h"
#include <QObject>

/*!
 * @class IdentificadorCoordenadas
 * @brief IdentificadorCoordenadas
 * Datos necesarios para darle un identificador y localizar el lugar del corte.
 *
 */
class OPERACIONPCOTSHARED_EXPORT IdentificadorCoordenadas : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor explicito por defecto, necesita un puntero nulo
     */
    explicit IdentificadorCoordenadas(QObject *parent = 0);
    /*!
     * Constructor son necesarios un puntero nulo, un valore QString y 4 enteros
     */
    IdentificadorCoordenadas(QObject *parent, QString identificador,double xa, double ya,
                             double xb, double yb);
    //Getter
    /*!
     * Muestra el nombre de la imagen del corte.
     *
     */
    QString getIdentificador();

    /*!
     * Muestra el valor x de la primera coordenada.
     *
     */
    double getXa();

    /*!
     * Muestra el valor y de la primera coordenada.
     *
     */
    double getYa();

    /*!
     * Muestra el valor x de la segunda coordenada.
     *
     */
    double getXb();

    /*!
     * Muestra el valor y de la segunda coordenada.
     *
     */
    double getYb();


signals:

public slots:
    //setters
    /*!
     * Cambia el nombre de la imagen del corte.
     * @param identificador nuevo nombre de la imagen del corte.
     *
     */
    void setIdentificador(QString identificador);

    /*!
     * Cambia el valor x de la primera coordenada.
     * @param xa nuevo valor x de la primera coordenada.
     *
     */
    void setXa(double xa);

    /*!
     * Cambia el valor x de la primera coordenada.
     * @param xa nuevo valor y de la primera coordenada.
     *
     */
    void setYa(double ya);

    /*!
     * Cambia el valor x de la primera coordenada.
     * @param xa nuevo valor x de la segunda coordenada.
     *
     */
    void setXb(double xb);

    /*!
     * Cambia el valor x de la primera coordenada.
     * @param xa nuevo valor y de la segunda coordenada.
     *
     */
    void setYb(double yb);



private:
    QString _identificador;     ///< Nombre del corte de la imagen.
    double _xa, _xb, _ya, _yb;  ///< valores de las coordenadas.

};

#endif // IDENTIFICADORCOORDENADAS_H
