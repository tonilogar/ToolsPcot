#include "aprocnpmetortosection.h"

AProCnpMetOrtoSection::AProCnpMetOrtoSection(QObject *parent)
{
    _enable=false;
    _cnpEnable=false;
    _metEnable=false;
    _ortoEnable=false;
    _cnpFolderOut=QString();
}

AProCnpMetOrtoSection::~AProCnpMetOrtoSection()
{
    _enable=false;
    _cnpEnable=false;
    _metEnable=false;
    _ortoEnable=false;
    _cnpFolderOut=QString();
}

bool AProCnpMetOrtoSection::processSection(QJsonObject archivo)
{
    if(!archivo.contains("cnpMetOrto")) {
        _enable=false;
        _cnpEnable=false;
        _metEnable=false;
        _ortoEnable=false;
        _cnpFolderOut=QString();
        return true;
    }

    _enable=true;

    QJsonObject cnpMetOrtoConf=archivo.value("cnpMetOrto").toObject();

    if(!cnpMetOrtoConf.contains("cnpConfiguracion")) {
        _cnpEnable=false;
        _cnpFolderOut=QString();
    } else {
        //Leer configuracion de CNP
        QJsonObject cnpConf=cnpMetOrtoConf.value("cnpConfiguracion").toObject();
        if(!cnpConf.contains("isChecked")) {
            _cnpEnable=false;
            _cnpFolderOut=QString();
        } else {
            _cnpEnable=cnpConf.value("isChecked").toBool();
            _cnpFolderOut=cnpConf.value("folderOut").toString();
        }

    }
    //Leer la configuracion de MET
    if(!cnpMetOrtoConf.contains("metConfiguracion")) {
        _metEnable=false;
        //El resto de informacion de met a valor por defecto, es decir
        //DESACTIVADO
    } else {
        QJsonObject metConf=cnpMetOrtoConf.value("metConfiguracion").toObject();
        //Chequear los valores de configuracion de met
        if(!metConf.contains("isChecked")) {
            _metEnable=false;
        }
        else {
            _metEnable=metConf.value("isChecked").toBool();
            //Procesar el resto de informacion
        }
    }

    if(!cnpMetOrtoConf.contains("ortoConfiguracion")) {
        _ortoEnable=false;
        //El resto de informacion de met a valor por defecto, es decir
        //DESACTIVADO
    } else {
        QJsonObject ortoConf=cnpMetOrtoConf.value("ortoConfiguracion").toObject();
        //Chequear los valores de configuracion de orto
        if(!ortoConf.contains("isChecked")) {
            _ortoEnable=false;
        }
        else {
            _ortoEnable=ortoConf.value("isChecked").toBool();
            //Procesar el resto de informacion
        }
    }

    return true;
}

QJsonObject AProCnpMetOrtoSection::writeSection()
{
    //Lee la informacion y la convierte a formato JSON para poder guardarla
    QJsonObject resultadoSeccion;

    QJsonObject objCnp;
    objCnp.insert("isChecked",_cnpEnable);
    objCnp.insert("folderOut",_cnpFolderOut);

    resultadoSeccion.insert("cnpConfiguracion",objCnp);

    QJsonObject objMet;
    objMet.insert("isChecked",_metEnable);
    //Resto de informacion met

    resultadoSeccion.insert("metConfiguracion",objMet);

    QJsonObject objOrto;

    objOrto.insert("isChecked",_ortoEnable);
    //Resto de informacion orto
    resultadoSeccion.insert("ortoConfiguracion",objOrto);

    return resultadoSeccion;
}
