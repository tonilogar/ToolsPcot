#ifndef WORKCOORDINATES_H
#define WORKCOORDINATES_H
#include "operacionpcot_global.h"
#include <QObject>
#include "identificadorcoordenadas.h"

class OPERACIONPCOTSHARED_EXPORT WorkCoordinates : public QObject
{
    Q_OBJECT
public:
    explicit WorkCoordinates(QObject *parent,IdentificadorCoordenadas *idecoo);
    //Getter
    double getOeste()
    { return oeste; }

    double getEste()
    { return este; }

    double getNorte()
    { return norte; }

    double getSur()
    { return sur; }

    IdentificadorCoordenadas* getIdentificadorCoordenadas()
    {return _idecoo;}



signals:

public slots:

    void setIdentificadorCoordenadas(IdentificadorCoordenadas *idecoo);
 //setters
private:
    double getCoordenadasEste(IdentificadorCoordenadas *coordenadas);
    double getCoordenadasOeste(IdentificadorCoordenadas *coordenadas);
    double getCoordenadasNorte(IdentificadorCoordenadas *coordenadas);
    double getCoordenadasSur(IdentificadorCoordenadas *coordenadas);


    double oeste;
    double este;
    double norte;
    double sur;
    IdentificadorCoordenadas *_idecoo;
};

#endif // WORKCOORDINATES_H
