#ifndef READERCOORDINATES_H
#define READERCOORDINATES_H

#include <QObject>
#include <OperacionPcot/identificadorcoordenadas.h>
class ReaderCoordinates : public QObject
{
    Q_OBJECT
public:
    explicit ReaderCoordinates(QObject *parent = 0);
    virtual bool canRead(QString pathFile)=0;
    virtual bool tryRead(QString pathFile)=0;
    virtual QList < IdentificadorCoordenadas *> getListCoordinates()=0;
    virtual QString lastError()=0;
signals:

public slots:

        private:

};

#endif // READERCOORDINATES_H
