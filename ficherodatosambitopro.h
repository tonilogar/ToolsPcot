#ifndef FICHERODATOSAMBITOPRO_H
#define FICHERODATOSAMBITOPRO_H

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
class FicheroDatosAmbitoPro : public QObject
{
    Q_OBJECT
public:
    explicit FicheroDatosAmbitoPro(QObject *parent = 0, QString nFichero=QString());
    void setNombreFichero(QString nFichero);
    QString getNombreFichero();
    bool fileExist();
    QStandardItemModel*  obtenerModelo();
    QJsonObject CreateJsonDefecto();
    //Getter
    QString getPathImageMetCat();
    QString getPathImageMetEsp();
    QString getPathImageMetFran();
    QString getExeSubScene();
    QString getExeImaOpeGeo();
    QString getExeFootPrintMask();
    QString getExeExtraction();
    QString getExeResize();

signals:

public slots:
    //setters
    void setPathImageMetCat(QString pathImageMetCat);
    void setPathImageMetEsp(QString pathImageMetEsp);
    void setPathImageMetFran(QString pathImageMetFran);
    void setExeSubScene(QString exeSubScene);
    void setExeImaOpeGeo(QString exeImaOpeGeo);
    void setExeFootPrintMask(QString exeFootPrintMask);
    void setExeExtraction(QString exeExtraction);
    void setExeResize(QString exeResize);

private:
    QString nombreFichero;

    QString _pathImageMetCat;
    QString _pathImageMetEsp;
    QString _pathImageMetFran;
    QString _exeSubScene;
    QString _exeImaOpeGeo;
    QString _exeFootPrintMask;
    QString _exeExtraction;
    QString _exeResize;



};

#endif // FICHERODATOSAMBITOPRO_H
