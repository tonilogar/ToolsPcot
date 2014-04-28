#ifndef REGISTROCOORDENADAS_H
#define REGISTROCOORDENADAS_H

#include <QObject>

class RegistroCoordenadas : public QObject
{
    Q_OBJECT
public:
    explicit RegistroCoordenadas(QObject *parent = 0);

    RegistroCoordenadas(QObject *parent,QString id,double xA,double yA,double xB,double yB);
    
    //Getter
    QString getIdentificador() const
    { return _identificador; }

    double getXA()
    { return _xA; }

    double getYA()
    { return _yA; }

    double getXB()
    { return _xB; }

    double getYB()
    { return _yB; }

    //Setters
    void setIdentificador(QString id)
    { _identificador=id; }

    void setXA(double valor)
    { _xA=valor; }

    void setYA(double valor)
    { _yA=valor; }

    void setXB(double valor)
    { _xB=valor; }

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
