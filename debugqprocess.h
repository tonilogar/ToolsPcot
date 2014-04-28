#ifndef DEBUGQPROCESS_H
#define DEBUGQPROCESS_H

#include <QObject>
#include <QDebug>
#include <QIODevice>
#include <QTextStream>

class DebugQprocess : public QObject
{
    Q_OBJECT
public:
    explicit DebugQprocess(QObject *parent = 0, QIODevice *dis=0);
    
signals:
    
public slots:

private slots:

    void mensageListo();


private:
 QIODevice *dispositivo;
 QTextStream *stream;


    
};

#endif // DEBUGQPROCESS_H
