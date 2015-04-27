#ifndef APROCNPMETORTOSECTION_H
#define APROCNPMETORTOSECTION_H

#include "proyectotp_global.h"
#include "aprotpsection.h"

#include <QObject>

class PROYECTOTPSHARED_EXPORT AProCnpMetOrtoSection : public AProTPSection
{
    Q_OBJECT
public:
    explicit AProCnpMetOrtoSection(QObject *parent=0);
    ~AProCnpMetOrtoSection();

    virtual bool processSection(QJsonObject archivo);
    virtual QJsonObject writeSection();

    /*!
      Indica si la seccion existe o no existe
      */

    bool virtual isEnabled() const {
        return _enable;
    }

    bool virtual isCnpEnabled() const {
        return _cnpEnable;
    }

    bool virtual isMetEnabled() const {
        return _metEnable;
    }
    bool virtual isOrtoEnabled() const {
        return _ortoEnable;
    }

    QString virtual cnpFolderOut() const {
        return _cnpFolderOut;
    }

    void virtual setCnpFolderOut(QString f) {
        _cnpFolderOut=f;
    }

    void virtual enableCNP(bool v) {
        _cnpEnable=v;
    }

    void virtual enableMet(bool v) {
        _metEnable=v;
    }

    void virtual enableOrto(bool v) {
        _ortoEnable=v;
    }

private:

    bool _enable;       ///< Flag de activacion
    bool _cnpEnable;    ///< Flag de cnp activo
    bool _metEnable;    ///< Flag de met activo
    bool _ortoEnable;   ///< Flag de orto activo

    //Seccion CNP
    QString _cnpFolderOut;  ///< Directorio de salida para cnp
};

#endif // APROCNPMETORTOSECTION_H
