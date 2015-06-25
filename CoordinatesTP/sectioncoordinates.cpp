#include "sectioncoordinates.h"

SectionCoordinates::SectionCoordinates(QObject *parent)
    : AProTPSection(parent)
{
    _stateChanged=true;
    _modeloCoordenadas=0;
}

SectionCoordinates::~SectionCoordinates()
{

}


QString SectionCoordinates::getNombreSection() const
{
    return QString("Coordenadas");
}

bool SectionCoordinates::processSection(QJsonObject archivo)
{
    if(!archivo.contains(getNombreSection()))
        return false;

    QJsonObject coordenadas=archivo.value(getNombreSection()).toObject();

    if(!coordenadas.contains("listado"))
        return false;

    QJsonArray listaCoordenadas=coordenadas.value("listado").toArray();
    QJsonArray::iterator it;
    for(it=listaCoordenadas.begin();it!=listaCoordenadas.end();it++) {
        QJsonObject identificadorCoordenadas=(*it).toObject();
        if(identificadorCoordenadas.contains("Id"))
            qDebug() <<"Id: " <<identificadorCoordenadas.value("Id").toString();
        if(identificadorCoordenadas.contains("Xa"))
            qDebug() <<"Xa: "<<identificadorCoordenadas.value("Xa").toDouble();
        if(identificadorCoordenadas.contains("Xb"))
            qDebug() << "Xb: "<<identificadorCoordenadas.value("Xb").toDouble();
        if(identificadorCoordenadas.contains("Ya"))
            qDebug() << "Ya: "<<identificadorCoordenadas.value("Ya").toDouble();
        if(identificadorCoordenadas.contains("Yb"))
            qDebug() << "Yb: "<<identificadorCoordenadas.value("Yb").toDouble();
        qDebug() << "----------------------------------";
    }
    _stateChanged=true;
    emit this->estaActualizado(_stateChanged);
}

QJsonObject SectionCoordinates::writeSection()
{
    if(!_modeloCoordenadas)
        return QJsonObject();

    QJsonObject resultado;
    QJsonArray listado;

    QList<IdentificadorCoordenadas*> lIdentificadores=_modeloCoordenadas->getListaRegistro();

    foreach(IdentificadorCoordenadas *item,lIdentificadores) {
        QJsonObject identJson;
        identJson.insert("Id",item->getIdentificador());
        identJson.insert("Xa",item->getXa());
        identJson.insert("Xb",item->getXb());
        identJson.insert("Ya",item->getYa());
        identJson.insert("Yb",item->getYb());
        listado.append(identJson);
    }
    resultado.insert("listado",listado);

    _stateChanged=true;
    emit this->estaActualizado(_stateChanged);
    return resultado;
}

void SectionCoordinates::resetSection()
{
    if(_modeloCoordenadas) {
        this->disconnect(_modeloCoordenadas);
        _modeloCoordenadas->clear();
        connect(_modeloCoordenadas,SIGNAL(modelReset()),this,SLOT(modeloResetado()));
        _stateChanged=true;
        emit this->estaActualizado(_stateChanged);
    }
}

void SectionCoordinates::modeloResetado()
{
    _stateChanged=false;
    emit this->estaActualizado(_stateChanged);
}

void SectionCoordinates::setModeloCoordenadas(ModeloCoordenadas *m)
{
    if(_modeloCoordenadas)
        this->disconnect(_modeloCoordenadas);
    _modeloCoordenadas=m;
    connect(_modeloCoordenadas,SIGNAL(modelReset()),this,SLOT(modeloResetado()));
}

ModeloCoordenadas *SectionCoordinates::getModeloCoordenadas()
{
    return _modeloCoordenadas;
}



