#ifndef OMETDATOSEJECUCION_H
#define OMETDATOSEJECUCION_H

#include <QObject>

class OmetDatosEjecucion : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     */
    explicit OmetDatosEjecucion(QObject *parent = 0);
//Geters
    /*!
     * Mostrar path del executable SubScene.
     */
    QString getFileSubScene();
    /*!
     * Mostrar path del executable Opegeo.
     */
    QString getFileOpegeo();
    /*!
     * Mostrar path del executable FootPrintMask.
     */
    QString getFileFootPrintMask();
    /*!
     * Mostrar path del executableExtraction.
     */
    QString getFileExtraction();
    /*!
     * Mostrar path del executable Resize.
     */
    QString getFileResize();
    /*!
     * Mostrar path del executable FileCutDtm.
     */
    QString getFileCutDtm();

signals:

public slots:

    //seters
    /*!
     * Canvia el path del executable SubScene.
     * @param Nou valor del executable SubScene.
     */
    void setFileSubScene(QString fSubScene);
    /*!
     * Canvia el path del executable Opegeo.
     * @param Nou valor del executable Opegeo.
     */
    void setFileOpegeo(QString fOpegeo);
    /*!
     * Canvia el path del executable FootPrintMask.
     * @param Nou valor del executable FootPrintMask.
     */
    void setFileFootPrintMask(QString fFootPrintMask);
    /*!
     * Canvia el path del executable Extraction.
     * @param Nou valor del executable Extraction.
     */
    void setFileExtraction(QString fExtraction);
    /*!
     * Canvia el path del executable Resize.
     * @param Nou valor del executable Resize.
     */
    void setFileResize(QString fResize);
    /*!
     * Canvia el path del executable CutDtm.
     * @param Nou valor del executable CutDtm.
     */
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
