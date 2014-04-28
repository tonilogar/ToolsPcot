#ifndef CORTEMET_H
#define CORTEMET_H

#include <QObject>

class CorteMet : public QObject
{
    Q_OBJECT
public:
    explicit CorteMet(QObject *parent = 0, QString nFileIn=QString(), QString nFileOut=QString(), int fSup=0, int fInf=0,
                      int cIz=0, int cDer=0);
//Getter
    QString getNombreFileIn();
    QString getNombreFileOut();
    int getFilaSup();
    int getFilaInf();
    int getColumnIz();
    int getColumnDer();
signals:

public slots:
 //setters
    void setNombreFileIn(QString);
    void setNombreFileOut(QString);
    void setFilaSup(int);
    void setFilaInf(int);
    void setColumnIz(int);
    void setColumnDer(int);



private:
QString nombreFileIn;
int filaSup;
int filaInf;
int columnIz;
int columnDer;
QString nombreFileOut;


};

#endif // CORTEMET_H
