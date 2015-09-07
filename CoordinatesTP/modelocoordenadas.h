#ifndef MODELOCOORDENADAS_H
#define MODELOCOORDENADAS_H
#include "coordinatestp_global.h"
#include <QAbstractTableModel>
#include <QList>
#include <OpePcot/identificadorcoordenadas.h>
/*!
 * @class  ModeloCoordenadas
 * @brief  Classe per crea el model per tractar les dades del fitxers raw
 */
class COORDINATESTPSHARED_EXPORT ModeloCoordenadas : public QAbstractTableModel
{
    Q_OBJECT
public:
    /*!
     * Constructor explicit per defecte, necesita un punter nul i un llistat IdentificadorCoordenades.
     */
    explicit ModeloCoordenadas(QObject *parent = 0,QList<IdentificadorCoordenadas*> lista=QList<IdentificadorCoordenadas*>());

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
     * Borra les dades del model i de la llista de IdentificadorCoordenades.
     */
    void clear();
    /*!
     * Canvia els valors de la llista de IdentificadorCoordenades.
     */
    void setListaRegistro(QList<IdentificadorCoordenadas*> nuevaLista);
    /*!
     * retorna el llistat de IdentificadorCoordenades.
     */
    QList <IdentificadorCoordenadas*> getListaRegistro();
signals:
    
    void loadedModelo(bool);
    void modeloVacio();
    void cambioEnIdentificador();

public slots:
private:


    QList<IdentificadorCoordenadas*> _listaRegistros;///< Llista dels IdentificadorCoordenades seleccionats.
};

#endif // MODELOCOORDENADAS_H
