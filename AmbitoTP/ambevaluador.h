#ifndef AMBEVALUADOR_H
#define AMBEVALUADOR_H

#include "ambitotp_global.h"

#include <QObject>
#include <QList>

#include "ambito.h"
#include "ambevaluatest.h"

class AMBITOTPSHARED_EXPORT AmbEvaluador : public QObject
{
    Q_OBJECT
public:
    explicit AmbEvaluador(QObject *parent = 0,Ambito *amb=0);

    void addTest(AmbEvaluaTest *test);
    void removeTest(AmbEvaluaTest *test);

    QList<AmbEvaluaTest*> getTestList() const
    { return _listaTests; }

    Ambito *getAmbito() const
    { return _ambito; }

    void check(Ambito *amb=0);

    bool isReadyToCheck() const;

signals:

public slots:

private:

    QList<AmbEvaluaTest*> _listaTests;
    Ambito *_ambito;
};

#endif // AMBEVALUADOR_H
