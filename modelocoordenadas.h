#ifndef MODELOCOORDENADAS_H
#define MODELOCOORDENADAS_H

#include <QAbstractTableModel>
#include <QList>
#include "registrocoordenadas.h"

class ModeloCoordenadas : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModeloCoordenadas(QObject *parent = 0,QList<RegistroCoordenadas*> lista=QList<RegistroCoordenadas*>());

    //Devuelve el numero de filas del modelo
    int rowCount(const QModelIndex &parent=QModelIndex()) const;

    //Devuelve el numero de columnas del modelo
    int columnCount(const QModelIndex &parent=QModelIndex()) const;

    //Tenemos que definir las banderas de estado
    Qt::ItemFlags flags(const QModelIndex &index) const;

    //Metodo que nos devuelve el valor almacenado en una posicion
    QVariant data(const QModelIndex &index, int role) const;

    //Metodo que permite establecer el valor desde la vista
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    //Metodo que devuelve las cabeceras a la vista
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    //Metodos propios
    void clear();
    void setListaRegistro(QList<RegistroCoordenadas*> nuevaLista);
signals:
    
public slots:
private:

    //Atributos del modelo
    QList<RegistroCoordenadas*> _listaRegistros;
};

#endif // MODELOCOORDENADAS_H
