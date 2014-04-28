#ifndef OMETDATOSEJECUCION_H
#define OMETDATOSEJECUCION_H

#include <QObject>

class OmetDatosEjecucion : public QObject
{
    Q_OBJECT
public:
    explicit OmetDatosEjecucion(QObject *parent = 0);
//Geters
    QString getFileSubScene();
    QString getFileOpegeo();
    QString getFileFootPrintMask();
    QString getFileExtraction();
    QString getFileResize();
    QString getFileCutDtm();

signals:

public slots:

    //seters
    void setFileSubScene(QString fSubScene);
    void setFileOpegeo(QString fOpegeo);
    void setFileFootPrintMask(QString fFootPrintMask);
    void setFileExtraction(QString fExtraction);
    void setFileResize(QString fResize);
    void setFileCutDtm(QString datos);

private:
    QString fileSubScene;
    QString fileOpegeo;
    QString fileFootPrintMask;
    QString fileExtraction;
    QString fileResize;
    QString fileCutDtm;

};

#endif // OMETDATOSEJECUCION_H
