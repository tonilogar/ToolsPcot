#ifndef FICHERODATOSAMBITOPRO_H
#define FICHERODATOSAMBITOPRO_H
#include "cnpmetortotp_global.h"
#include <QObject>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
class CNPMETORTOTPSHARED_EXPORT FicheroDatosAmbitoPro : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor explicit, necesita un punter nul i un Qstring del nom del fitxer
     *de coordenades.
     */
    explicit FicheroDatosAmbitoPro(QObject *parent = 0, QString nFichero=QString());
    /*!
     * Canvia el nom del fitxer de coordenades.
     */
    void setNombreFichero(QString nFichero);
    /*!
     * Mostra el nom del fitxer de coordenades.
     */
    QString getNombreFichero();
    /*!
     * El valor indica si el fitxer de coordenades existeix o no.
     */
    bool fileExist();
    /*!
     * Genera el model després de llegir el fitxer Json.
     */
    QStandardItemModel*  obtenerModelo();
    /*!
     * Genera un fitxer Json per defecte de les dades met.
     */
    void CreateJsonMetDefecto();
    /*!
     * Genera un fitxer Json per defecte de les dades orto.
     */
    void CreateJsonOrtoDefecto();
    //Getter
    /*!
     * Mostra la imatge origen del met de Catalunya.
     */
    QString getPathImageMetCat();
    /*!
     * Mostra la imatge origen del met de Espanya.
     */
    QString getPathImageMetEsp();
    /*!
     * Mostra la imatge origen del met de França.
     */
    QString getPathImageMetFran();
    /*!
     * Mostra el path del executable SubScene.
     */
    QString getExeSubScene();
    /*!
     * Mostra el path del executable ImaOpeGeo.
     */
    QString getExeImaOpeGeo();
    /*!
     * Mostra el path del executable FootPrintMask.
     */
    QString getExeFootPrintMask();
    /*!
     * Mostra el path del executable Extraction.
     */
    QString getExeExtraction();
    /*!
     * Mostra el path del executable ExeResize.
     */
    QString getExeResize();

signals:

public slots:
    //setters
    /*!
     * Canvia la imatge origen del met de Catalunya.
     */
    void setPathImageMetCat(QString pathImageMetCat);
    /*!
     * Canvia la imatge origen del met de Espanya.
     */
    void setPathImageMetEsp(QString pathImageMetEsp);
    /*!
     * Canvia la imatge origen del met de França.
     */
    void setPathImageMetFran(QString pathImageMetFran);
    /*!
     * Canvia el path del executable SubScene.
     */
    void setExeSubScene(QString exeSubScene);
    /*!
     * Canvia el path del executable ImaOpeGeo.
     */
    void setExeImaOpeGeo(QString exeImaOpeGeo);
    /*!
     * Canvia el path del executable FootPrintMask.
     */
    void setExeFootPrintMask(QString exeFootPrintMask);
    /*!
     * Canvia el path del executable Extraction.
     */
    void setExeExtraction(QString exeExtraction);
    /*!
     * Canvia el path del executable Resize.
     */
    void setExeResize(QString exeResize);

private:
    QString nombreFichero;///< Nom del nom de fitxer de coordenades.
    QString _pathImageMetCat; ///< Path de la imatge original del met de Catalunya.
    QString _pathImageMetEsp; ///< Path de la imatge original del met de Espanya.
    QString _pathImageMetFran;///< Path de la imatge original del met de França.
    QString _exeSubScene; ///< Path del executable SubScene.
    QString _exeImaOpeGeo;///< Path del executable ImaOpeGeo.
    QString _exeFootPrintMask;///< Path del executable FootPrintMask.
    QString _exeExtraction;///< Path del executable Extraction.
    QString _exeResize;///< Path del executable Resize.



};

#endif // FICHERODATOSAMBITOPRO_H
