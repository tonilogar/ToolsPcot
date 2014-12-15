#ifndef MODELORAW_H
#define MODELORAW_H

#include <QAbstractTableModel>
#include <QList>
#include "registroraw.h"
class ModeloRaw : public QAbstractTableModel
{
    Q_OBJECT
public:
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     */
    explicit ModeloRaw(QObject *parent = 0,QList<RegistroRaw*> lista=QList<RegistroRaw*>());
    /*!
     * Mostrar el número de files del model.
     */
    int rowCount(const QModelIndex &parent) const;
    /*!
     * Mostrar el número de columnes del model.
     */
    int columnCount(const QModelIndex &parent) const;
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

    QList< QPair< QString,QString> > getPares();
    //Metodos propios
    /*!
     * Borra les dades del model i de la llista de registres.
     */
    void clear();
    /*!
     * Canvia els valors de la llista de registres.
     */
    void setListaRegistro(QList<RegistroRaw*> nuevaLista);
    /*!
     * Mostra la llista de registres.
     */
    QList<RegistroRaw*> getListaRegistro();
    /*!
     * Mostra el path del fitxer rad.
     */
    QString getFicheroRad();
    /*!
     * Mostra el path del fitxer radCorr.
     */
    QString getFicheroRadCorr();
    /*!
     * Mostra el path del fitxer Attsync.
     */
    QString getFicheroAttsync();
    /*!
     * Mostra les dades necessàries per què el fitxer radcoor treballi.
     */
    QString getDatosRadCorr();
    /*!
     * Mostra les dades necessàries per què el fitxer Attsync treballi.
     */
    QString getDatosAttsync();
    /*!
     * Comprovar l'estat de atributs booleans:
     *
     */
    bool comprobarEstadoRaw();
signals:
    /*!
     * Canvia l'estat de atributs booleans:
     *
     */
    void cambioEstado(bool state);

public slots:
    /*!
     * Canvia el valor prefix.
     * @param nou valor de prefix.
     */
    void setPrefix(QString prefijo);
    /*!
     * Canvia el valor nomAvio.
     * @param nou valor de nomAvio.
     */
    void setNomAvio(QString nomAvio);
    /*!
     * Canvia el valor numeroVol.
     * @param nou valor de numeroVol.
     */
    void setNumeroVol(QString numeroVol);
    /*!
     * Canvia el valor codiSensor.
     * @param nou valor de codiSensor.
     */
    void setCodiSensor(QString codiSensor);
    /*!
     * Canvia el valor rangoPasada.
     * @param nou valor de rangoPasada.
     */
    void setRangoPasada(QString rangoPasada);
    /*!
     * Canvia el valor oberturaPasada.
     * @param nou valor de oberturaPasada.
     */
    void setOberturaPasada(QString oberturaPasada);
    /*!
     * Canvia el valor del path del fitxer rad.
     * @param nou valor del path del fitxer rad.
     */
    void setFicheroRad(QString ficheroRad);
    /*!
     * Canvia el valor de les dades que necessita per treballar el fitxer rad.
     * @param nou valor de les dades que necessita per treballar el fitxer rad.
     */
    void setDatosRadCorr(QString datosRadCorr);
    /*!
     * Canvia el valor de les dades que necessita per treballar el fitxer Attsync.
     * @param nou valor de les dades que necessita per treballar el fitxer Attsync.
     */
    void setDatosAttsync(QString datosAttsync);
    /*!
     * Canvia el valor del path del fitxer RadCorr.
     * @param nou valor del path del fitxer RadCorr.
     */
    void setFicheroRadCorr(QString ficheroRadCorr);
    /*!
     * Canvia el valor del path del fitxer Attsync.
     * @param nou valor del path del fitxer Attsync.
     */
    void setFicheroAttsync(QString ficheroAttsync);
private:

    //Atributos del modelo
    QList<RegistroRaw*> _listaRegistros; ///< Llista de fitxers .raw seleccionats.
    QString _prefix;           ///< Valor del prefix.
    QString _nomAvio;          ///< Valor nom de l`avio.
    QString _numeroVol;        ///< Valor número de vol.
    QString _codiSensor;       ///< Valor codi de sensor.
    QString _rangoPasada;      ///< Valor rang de passada.
    QString _oberturaPasada;   ///< Valor obertura de passada.
    QString _ficheroRad;       ///< Valor path fitxer rad.
    QString _ficheroRadCorr;   ///< Valor path fitxer RadCorr.
    QString _ficheroAttsync;   ///< Valor path fitxer Attsync.
    QString _datosRadCorr;     ///< Valor parametres per el fitxer RadCorr.
    QString _datosAttsync;     ///< Valor parametres per el fitxer Attsync.

    bool _flagStripNumber;     ///< Valor boolea per el número de passada.
    bool _flagFilenumber;      ///< Valor boolea per el número de fitxer.
    bool _flagSignoPasada;     ///< Valor boolea per el signe de passada.
    bool _flagCanalRed;        ///< Valor boolea per el número canal red.
    bool _flagCanalGreen;      ///< Valor boolea per el número canal green.
    bool _flagCanalBlue;       ///< Valor boolea per el número canal blue.


private slots:
    /*!evaluar columna de strip number
      */
    bool evaluaColumnaStripNunber();
    /*!evaluar columna de SignoPasada
      */
    bool evaluaColumnaSignoPasada();
    /*!evaluar columna de FileNumber
      */
    bool evaluaColumnaFileNumber();
    /*!evaluar columna de CanalRed
      */
    bool evaluaColumnaCanalRed();
    /*!evaluar columna de CanalGreen
      */
    bool evaluaColumnaCanalGreen();
    /*!evaluar columna de CanalBlue
      */
    bool evaluaColumnaCanalBlue();
    /*!evaluar todas las columnas
      */
    bool evaluacionGeneral();

};

#endif // MODELORAW_H
