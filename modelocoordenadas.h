#ifndef MODELOCOORDENADAS_H
#define MODELOCOORDENADAS_H

#include <QAbstractTableModel>
#include <QList>
#include "registrocoordenadas.h"

class ModeloCoordenadas : public QAbstractTableModel
{
    Q_OBJECT
public:
    /*!
     * Constructor explicit per defecte, necesita un punter nul i un llistat de registre de coordenades.
     */
    explicit ModeloCoordenadas(QObject *parent = 0,QList<RegistroCoordenadas*> lista=QList<RegistroCoordenadas*>());

    /*!
     * Mostrar el número de files del model.
     */
    int rowCount(const QModelIndex &parent=QModelIndex()) const;

    /*!
     * Mostrar el número de columnes del model.
     */
    int columnCount(const QModelIndex &parent=QModelIndex()) const;
    /*!
     * Definir les banderes d'estat.
     */
    Qt::ItemFlags flags(const QModelIndex &index) const;
    /*!
     * Mostra el index del valor al model.
     */
    QVariant data(const QModelIndex &index, int role) const;
    /*!
     * Canvia el valor a la finestra grafica.
     */
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    /*!
     * Retorna les capçaleres a la finestra gràfica.
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    //Metodos propios
    /*!
     * Borra les dades del model i de la llista de registres.
     */
    void clear();
    /*!
     * Canvia els valors de la llista de registres.
     */
    void setListaRegistro(QList<RegistroCoordenadas*> nuevaLista);
signals:
    
public slots:
private:


    QList<RegistroCoordenadas*> _listaRegistros;///< Llista dels registres seleccionats.
};

#endif // MODELOCOORDENADAS_H
