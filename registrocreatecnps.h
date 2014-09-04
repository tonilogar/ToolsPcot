#ifndef REGISTROCREATECNPS_H
#define REGISTROCREATECNPS_H

#include <QObject>
#include <OperacionPcot/datazoneproject.h>

class RegistroCreateCnps : public QObject
{
    Q_OBJECT
public:
    explicit RegistroCreateCnps(QObject *parent = 0);

 RegistroCreateCnps(QObject *parent,QString folderOut);


    //Getter
    QString getFolderOut();
    void buildDataZoneProject(DataZoneProject *dataZP);
signals:

public slots:
    //setters
        void setFolderOut(QString folderOut);
private:

    QString _folderOut;


};

#endif // REGISTROCREATECNPS_H
