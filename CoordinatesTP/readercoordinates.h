#ifndef READERCOORDINATES_H
#define READERCOORDINATES_H

#include <QObject>
#include <OperacionPcot/identificadorcoordenadas.h>
/*!
 * @class ReaderCoordinates
 * @brief Interface per llegir fitxers de coordenades.
 *
 * Aquesta es la clase pare de la gerarquia per llegir fitxers.
 */
class ReaderCoordinates : public QObject
{
    Q_OBJECT
public:
    explicit ReaderCoordinates(QObject *parent = 0);
    /*!
     *Comproba si es pot llegir el fitxer.
     */
    virtual bool canRead(QString pathFile)=0;
    /*!
     *Intenta llegir el fitxer.
     */
    virtual bool tryRead(QString pathFile)=0;
    /*!
     *Retorna el llistat de coordenades, llegit del fitxer de coordenades.
     */
    virtual QList < IdentificadorCoordenadas *> getListCoordinates()
    {
        return _listCoordinates;
    }
    /*!
     *Retorna l'ultim error.
     */
    virtual QString lastError()
    {
        return _error;
    }

signals:

public slots:

protected:
    QString _error;
    QList <IdentificadorCoordenadas *> _listCoordinates;

};

#endif // READERCOORDINATES_H
