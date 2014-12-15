#ifndef REGISTROCOORDENADAS_H
#define REGISTROCOORDENADAS_H

#include <QObject>

class RegistroCoordenadas : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     */
    explicit RegistroCoordenadas(QObject *parent = 0);
    /*!
     * El constructor necessita un punter this, un identificador QString i quatre coordenades double.
     */
    RegistroCoordenadas(QObject *parent,QString id,double xA,double yA,double xB,double yB);
    
    //Getter
    /*!
     * Mostrar el valor de l'identificador.
     */
    QString getIdentificador() const
    { return _identificador; }
    /*!
     * Mostrar el valor de la coordenada xa.
     */
    double getXA()
    { return _xA; }
    /*!
     * Mostrar el valor de la coordenada ya.
     */
    double getYA()
    { return _yA; }
    /*!
     * Mostrar el valor de la coordenada xb.
     */
    double getXB()
    { return _xB; }
    /*!
     * Mostrar el valor de la coordenada yb.
     */
    double getYB()
    { return _yB; }

    //Setters
    /*!
     * Canvia el nom del identificador.
     * @param nou valor del identificador.
     */
    void setIdentificador(QString id)
    { _identificador=id; }
    /*!
     * Canvia el valor de la coordenada xa.
     * @param nou valor de la coordenada xa.
     */
    void setXA(double valor)
    { _xA=valor; }
    /*!
     * Canvia el valor de la coordenada ya.
     * @param nou valor de la coordenada ya.
     */
    void setYA(double valor)
    { _yA=valor; }
    /*!
     * Canvia el valor de la coordenada xb.
     * @param nou valor de la coordenada xb.
     */
    void setXB(double valor)
    { _xB=valor; }
    /*!
     * Canvia el valor de la coordenada yb.
     * @param nou valor de la coordenada yb.
     */
    void setYB(double valor)
    { _yB=valor; }

    void ordenarCoordenadas();

signals:
    
public slots:

private:

    QString _identificador; ///< Identificador del registro de coordenadas
    double _xA;             ///< Coordenada xA
    double _yA;             ///< Coordenada yA
    double _xB;             ///< Coordenada xB
    double _yB;             ///< Coordenada yB
    
};

#endif // REGISTROCOORDENADAS_H
