#include "factoryprocesos.h"

FactoryProcesos::FactoryProcesos(QObject *parent, QMap <QString, QString> qMapEjecutables) :
    QObject(parent)
{
    _qMapEjecutables=qMapEjecutables;
}
QList <Proceso *> FactoryProcesos::buildListaProcesosMet(DataZoneProject *dataZoPro)
{
    QList <Proceso *> listaProcesos;
    if(dataZoPro->getCoordinateSystem()==DataZoneProject::Etrs89)
    {
        if(dataZoPro->getAmbitoOperacion()==DataZoneProject::Catalunya)
        {
            listaProcesos.append(new ProcesoExtraction(this,_qMapEjecutables.value("exeExtraction")));
            listaProcesos.append(new ProcesoGeoTrans(this,_qMapEjecutables.value("exeGeoTransform")));
            listaProcesos.append(new ProcesoFootPrintMask(this,_qMapEjecutables.value("exeFootPrintMask")));
            listaProcesos.append(new ProcesoCutFiles(this,_qMapEjecutables.value("exeSubScene")));
        }
        if(dataZoPro->getAmbitoOperacion()==DataZoneProject::Espanya)
        {
            listaProcesos.append(new ProcesoSubScene(this,_qMapEjecutables.value("exeSubScene")));
            listaProcesos.append(new ProcesoResize(this,_qMapEjecutables.value("exeResize")));
            listaProcesos.append(new ProcesoFootPrintMask(this,_qMapEjecutables.value("exeFootPrintMask")));
            listaProcesos.append(new ProcesoCutFiles(this,_qMapEjecutables.value("exeSubScene")));
        }
    }
    if(dataZoPro->getCoordinateSystem()==DataZoneProject::Ed50)
    {
        if(dataZoPro->getAmbitoOperacion()==DataZoneProject::Catalunya)
        {
            if(dataZoPro->getFootPrintMask())
            {
                listaProcesos.append(new ProcesoExtraction(this,_qMapEjecutables.value("exeExtraction")));
                listaProcesos.append(new ProcesoFootPrintMask(this,_qMapEjecutables.value("exeFootPrintMask")));
                listaProcesos.append(new ProcesoGeoTrans(this,_qMapEjecutables.value("exeGeoTransform")));
                listaProcesos.append(new ProcesoCutFiles(this,_qMapEjecutables.value("exeSubScene")));
            }
            else
            {
                listaProcesos.append(new ProcesoExtraction(this,_qMapEjecutables.value("exeExtraction")));
                listaProcesos.append(new ProcesoGeoTrans(this,_qMapEjecutables.value("exeGeoTransform")));
                listaProcesos.append(new ProcesoFootPrintMask(this,_qMapEjecutables.value("exeFootPrintMask")));
                listaProcesos.append(new ProcesoCutFiles(this,_qMapEjecutables.value("exeSubScene")));
            }
        }
        if(dataZoPro->getAmbitoOperacion()==DataZoneProject::Espanya)
        {
            if(dataZoPro->getFootPrintMask())
            {
                listaProcesos.append(new ProcesoSubScene(this,_qMapEjecutables.value("exeSubScene")));
                listaProcesos.append(new ProcesoFootPrintMask(this,_qMapEjecutables.value("exeFootPrintMask")));
                listaProcesos.append(new ProcesoGeoTrans(this,_qMapEjecutables.value("exeGeoTransform")));
                listaProcesos.append(new ProcesoCutFiles(this,_qMapEjecutables.value("exeSubScene")));
            }
            else
            {
                listaProcesos.append(new ProcesoSubScene(this,_qMapEjecutables.value("exeSubScene")));
                listaProcesos.append(new ProcesoGeoTrans(this,_qMapEjecutables.value("exeGeoTransform")));
                listaProcesos.append(new ProcesoFootPrintMask(this,_qMapEjecutables.value("exeFootPrintMask")));
                listaProcesos.append(new ProcesoCutFiles(this,_qMapEjecutables.value("exeSubScene")));
            }
        }
    }
    if( dataZoPro->getCoordinateSystem()==DataZoneProject::Ntf)
    {
        listaProcesos.append(new ProcesoSubScene(this,_qMapEjecutables.value("exeSubScene")));
        listaProcesos.append(new ProcesoResize(this,_qMapEjecutables.value("exeResize")));
        listaProcesos.append(new ProcesoFootPrintMask(this,_qMapEjecutables.value("exeFootPrintMask")));
        listaProcesos.append(new ProcesoCutFiles(this,_qMapEjecutables.value("exeSubScene")));
    }
    return listaProcesos;
}

QList <Proceso *> FactoryProcesos::buildListaProcesosOrto(DataZoneProject *dataZoPro)
{
    QList <Proceso *> listaProcesos;
    if(dataZoPro->getCoordinateSystem()==DataZoneProject::Ed50)
    {
        if(dataZoPro->getFootPrintMask()==false && dataZoPro->getCutDtm()==false)
        {
                listaProcesos.append(new ProcesoSubScene(this,_qMapEjecutables.value("exeSubScene")));
        }
        if(dataZoPro->getFootPrintMask() && dataZoPro->getCutDtm())
        {
            listaProcesos.append(new ProcesoSubScene(this,_qMapEjecutables.value("exeSubScene")));
            listaProcesos.append(new ProcesoFootPrintMask(this,_qMapEjecutables.value("exeFootPrintMask")));
            listaProcesos.append(new ProcesoGeoTrans(this,_qMapEjecutables.value("exeGeoTransform")));
            listaProcesos.append(new ProcesoResize(this,_qMapEjecutables.value("exeResize")));
            listaProcesos.append(new ProcesoCutFiles(this,_qMapEjecutables.value("exeSubScene")));
        }
        if(dataZoPro->getFootPrintMask()==false && dataZoPro->getCutDtm())
        {
            listaProcesos.append(new ProcesoSubScene(this,_qMapEjecutables.value("exeSubScene")));
            listaProcesos.append(new ProcesoGeoTrans(this,_qMapEjecutables.value("exeGeoTransform")));
            listaProcesos.append(new ProcesoResize(this,_qMapEjecutables.value("exeResize")));
            listaProcesos.append(new ProcesoCutFiles(this,_qMapEjecutables.value("exeSubScene")));
        }
        if(dataZoPro->getFootPrintMask() && dataZoPro->getCutDtm()==false)
        {
            listaProcesos.append(new ProcesoSubScene(this,_qMapEjecutables.value("exeSubScene")));
            listaProcesos.append(new ProcesoFootPrintMask(this,_qMapEjecutables.value("exeFootPrintMask")));
            listaProcesos.append(new ProcesoGeoTrans(this,_qMapEjecutables.value("exeGeoTransform")));
            listaProcesos.append(new ProcesoResize(this,_qMapEjecutables.value("exeResize")));
        }
    }

    else //si el sistema de coordenadas es Etrs89 y Ntf
    {
        if(dataZoPro->getFootPrintMask()==false && dataZoPro->getCutDtm()==false)
        {
                listaProcesos.append(new ProcesoSubScene(this,_qMapEjecutables.value("exeSubScene")));
        }
        if(dataZoPro->getFootPrintMask() && dataZoPro->getCutDtm())
        {
            listaProcesos.append(new ProcesoSubScene(this,_qMapEjecutables.value("exeSubScene")));
            listaProcesos.append(new ProcesoResize(this,_qMapEjecutables.value("exeResize")));
            listaProcesos.append(new ProcesoFootPrintMask(this,_qMapEjecutables.value("exeFootPrintMask")));
            listaProcesos.append(new ProcesoCutFiles(this,_qMapEjecutables.value("exeSubScene")));
        }
        if(dataZoPro->getFootPrintMask()==false && dataZoPro->getCutDtm())
        {
            listaProcesos.append(new ProcesoSubScene(this,_qMapEjecutables.value("exeSubScene")));
            listaProcesos.append(new ProcesoResize(this,_qMapEjecutables.value("exeResize")));
            listaProcesos.append(new ProcesoCutFiles(this,_qMapEjecutables.value("exeSubScene")));
        }
        if(dataZoPro->getFootPrintMask() && dataZoPro->getCutDtm()==false)
        {
            listaProcesos.append(new ProcesoSubScene(this,_qMapEjecutables.value("exeSubScene")));
            listaProcesos.append(new ProcesoFootPrintMask(this,_qMapEjecutables.value("exeFootPrintMask")));
        }
    }
    return listaProcesos;
}
