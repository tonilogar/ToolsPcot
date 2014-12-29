#ifndef READERCOORDINATESBASICO_H
#define READERCOORDINATESBASICO_H
#include "readercoordinates.h"
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
/*!
 * @class ReaderCoordinates
 * @brief Interface per llegir fitxers de coordenades basic.
 *
 * Aquesta clase penja de la clase readercoordinates.
 */
class ReaderCoordinatesBasico : public ReaderCoordinates
{
    Q_OBJECT
public:
    explicit ReaderCoordinatesBasico(QObject *parent = 0);   
    virtual bool canRead(QString pathFile);
    virtual bool tryRead(QString pathFile);


signals:

public slots:

};

#endif // READERCOORDINATESBASICO_H
