#ifndef REGISTROCNPS_H
#define REGISTROCNPS_H

#include <QObject>
#include <OperacionPcot/datazoneproject.h>
/*!
 * @class  RegistroOrto
 * @brief  Classe amb les dades necessàries per fer els processos de cnp.
 */
class RegistroCnps : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     */
    explicit RegistroCnps(QObject *parent = 0);
    /*!
     * El constructor necessita un punter this i la variable del directori de sortida.
     */
 RegistroCnps(QObject *parent,QString folderOut);


    //Getters
 /*!
 * Mostrar el valors del directori de sortida.
 */
    QString getFolderOut();
 /*!
  * Crear l'objecte DataZoneProject.
  */
    void buildDataZoneProject(DataZoneProject *dataZP);
signals:

public slots:
    //setters
    /*!
     * Canvia el nom del directori de sortida.
     * @param nou valor del fitxer de sortida.
     */
        void setFolderOut(QString folderOut);
private:

    QString _folderOut;  ///< Nom del directori de sortida.


};

#endif // REGISTROCNPS_H
