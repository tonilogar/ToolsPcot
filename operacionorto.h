#ifndef OPERACIONORTO_H
#define OPERACIONORTO_H
#include"operacionbase.h"
#include"registrocreateorto.h"

class OperacionOrto : public OperacionBase
{
    Q_OBJECT
public:
    explicit OperacionOrto(QObject *parent = 0);

signals:

public slots:
    void inicio();//virtual
    void fin(int end);//virtual
    void startOperacion();//virtual
    void cancelarOperacion();
private:
    QString aProyecto;
    QString exeSScene;
    QString fOut;
    QVariantList tabla;
    bool controlOperacion;
};

#endif // OPERACIONORTO_H
