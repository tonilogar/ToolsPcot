#ifndef AMBJSONEVALUADOR_H
#define AMBJSONEVALUADOR_H

#include <QObject>
#include <QList>

#include "ambitotp_global.h"

class AmbitJson;
class AmbJsonEvaluaTest;

class AMBITOTPSHARED_EXPORT AmbJsonEvaluador : public QObject
{
    Q_OBJECT
public:
    explicit AmbJsonEvaluador(QObject *parent = 0, AmbitJson *ambJson=0);

    void addTest(AmbJsonEvaluaTest *test);
    void removeTest(AmbJsonEvaluaTest *test);

    AmbitJson *getAmbitJson() const;

    void setAmbitJson(AmbitJson *ambJson);

    bool checkAmbitJson(AmbitJson *ambJson);

    bool isCorrect() const;

    QList<AmbJsonEvaluaTest*> failedTest();

signals:

public slots:

protected:

    AmbitJson *_ambitJson;
    QList<AmbJsonEvaluaTest*> _testList;
    bool _isCorrect;
};

#endif // AMBJSONEVALUADOR_H
