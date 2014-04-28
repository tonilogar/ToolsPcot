#ifndef OPERACIONCNP_H
#define OPERACIONCNP_H
#include"operacionbase.h"

class OperacionCnp : public OperacionBase
{
    Q_OBJECT
public:
    explicit OperacionCnp(QObject *parent = 0);

public slots:
    void inicio();//virtual
    void fin(int end);//virtual
    void startOperacion();//virtual
    void cancelarOperacion();
private:
    QString fOut;
    QVariantList tabla;
    bool controlOperacion;
};

#endif // OPERACIONCNP_H
