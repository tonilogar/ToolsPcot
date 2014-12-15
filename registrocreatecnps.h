#ifndef REGISTROCREATECNPS_H
#define REGISTROCREATECNPS_H

#include <QObject>
#include <OperacionPcot/datazoneproject.h>

class RegistroCreateCnps : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     */
    explicit RegistroCreateCnps(QObject *parent = 0);
    /*!
     * El constructor necessita un punter this i la variable del directori de sortida.
     */
 RegistroCreateCnps(QObject *parent,QString folderOut);


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

#endif // REGISTROCREATECNPS_H
