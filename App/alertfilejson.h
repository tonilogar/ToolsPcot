#ifndef ALERTFILEJSON_H
#define ALERTFILEJSON_H

#include <QDialog>
#include <QDebug>
#include <QFileDialog>
#include <QSettings>
#include "dialogpre.h"
#include <AmbitoTP/ambitjson.h>
#include <AmbitoTP/ambito.h>

/*!
 * @class AlertFileJson
 * @brief AlertFileJson
 * Finestra d'alerta para seleccionar o crear ficher de preferencies Json.
 *
 */
namespace Ui {
class AlertFileJson;
}

class AlertFileJson : public QDialog
{
    Q_OBJECT

public:

    enum ModoAlerta
    { FaltaArchivo, ArchivoNoValido, Desconocido };

    //Q_ENUM(ModoAlerta)

public:
    /*!
     * Constructor es necessari un punter nul.
     */
    explicit AlertFileJson(QWidget *parent = 0,AmbitJson *archivoAmb=0);
    /*!
     * Destructor  per defecte.
     */
    ~AlertFileJson();

    void setModo(ModoAlerta m);

    ModoAlerta getModo() const
    { return _modoActual; }

private:
    Ui::AlertFileJson *ui;
    AmbitJson *_ambitoFile;
    ModoAlerta _modoActual;
private slots:
    /*!
     * Lanza una ventana para seleccionar el fichero Json de preferencias.
     */
    void selectJson();
    void createJson();
    void cancel();
};

#endif // ALERTFILEJSON_H
