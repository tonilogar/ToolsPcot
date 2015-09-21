#ifndef REGISTROCNP_H
#define REGISTROCNP_H

#include "registrotp_global.h"
#include <QObject>
#include <OpePcot/datazoneproject.h>
#include <ProyectoTP/aprotpsection.h>


class REGISTROTP_EXPORT RegistroCnp : public AProTPSection
{
    Q_OBJECT
public:

    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     */
    explicit RegistroCnp(QObject *parent = 0);
    /*!
     * El constructor necessita un punter this i la variable del directori de sortida.
     */
 RegistroCnp(QObject *parent,QString folderOut);


    //Getters
 /*!
   Devuelve si la seccion esta o no activada
   */
 bool getCnpsEnabled() const;
 /*!
 * Mostrar el valors del directori de sortida.
 */
    QString getFolderOut();
 /*!
  * Crear l'objecte DataZoneProject.
  */
    void buildDataZoneProject(DataZoneProject *dataZP);

    //Metodos de interfaz AProTPSection

    virtual QString getNombreSection() const;
    virtual bool processSection(QJsonObject archivo);
    virtual QJsonObject writeSection();
    virtual void resetSection();

signals:

public slots:
    //setters
    /*!
     * Canvia el nom del directori de sortida.
     * @param nou valor del fitxer de sortida.
     */
        void setFolderOut(QString folderOut);

        void setCnpsEnabled(bool enabled);
private:

    QString _folderOut;  ///< Nom del directori de sortida.
    bool _cnpsEnabled;  ///< Seccion CNPS activada

};
#endif // REGISTROCREATECNPS_H





