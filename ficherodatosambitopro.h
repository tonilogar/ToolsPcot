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

class FicheroDatosAmbitoPro : public QObject
{
    Q_OBJECT
public:
    explicit FicheroDatosAmbitoPro(QObject *parent = 0, QString nFichero=QString());
    void setNombreFichero(QString nFichero);
    QString getNombreFichero();
    bool fileExist();
    QStandardItemModel*  obtenerModelo();

signals:
    
public slots:


private:
QString nombreFichero;


    
};

#endif // FICHERODATOSAMBITOPRO_H
