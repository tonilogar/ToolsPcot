//    ToolsPcot
//    Copyright (C) {2014}  {Antonio López García}
//    tologar@gmail.com

//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QActionGroup>
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButtonOptionsCnp->setIndiceButton(0);
    ui->pushButtonOptionsMet->setIndiceButton(1);
    ui->pushButtonOptionsOrto->setIndiceButton(2);

    ui->pushButtonCasi->setIndiceButton(0);
    ui->pushButtonTasi->setIndiceButton(1);
    ui->pushButtonAisa->setIndiceButton(2);


    connect(ui->widgetCoordinates,SIGNAL(filledTableView(bool)),ui->page1Cnp,SLOT(activateWidget(bool)));
    connect(ui->widgetCoordinates,SIGNAL(filledTableView(bool)),ui->page2Met,SLOT(activateWidget(bool)));
    connect(ui->widgetCoordinates,SIGNAL(filledTableView(bool)),ui->page3Orto,SLOT(activateWidget(bool)));



    connect(ui->pushButtonOptionsCnp,SIGNAL(clicked(int)),ui->stackedWidgetOpciones,SLOT(setCurrentIndex(int)));
    connect(ui->pushButtonOptionsMet,SIGNAL(clicked(int)),ui->stackedWidgetOpciones,SLOT(setCurrentIndex(int)));
    connect(ui->pushButtonOptionsOrto,SIGNAL(clicked(int)),ui->stackedWidgetOpciones,SLOT(setCurrentIndex(int)));

    connect(ui->pushButtonCasi,SIGNAL(clicked(int)),ui->stackedWidgetCasitasiAisa,SLOT(setCurrentIndex(int)));
    connect(ui->pushButtonTasi,SIGNAL(clicked(int)),ui->stackedWidgetCasitasiAisa,SLOT(setCurrentIndex(int)));
    connect(ui->pushButtonAisa,SIGNAL(clicked(int)),ui->stackedWidgetCasitasiAisa,SLOT(setCurrentIndex(int)));

    //Conectar accion de dialogo de preferencias
    connect(ui->actionPreferencias,SIGNAL(triggered()),this,SLOT(lanzarDialogoPreferencias()));

    //Agrupar las acciones de cambio de vista en un grupo de acciones

    QActionGroup *grupoVista=new QActionGroup(this);

    grupoVista->addAction(ui->actionCnps_met_orto);
    grupoVista->addAction(ui->actionCnps_combine_cnps);
    grupoVista->addAction(ui->actionCnps_rename_change_format);
    grupoVista->addAction(ui->actionCnps_correction);
    grupoVista->addAction(ui->actionCnps_view_html);
    grupoVista->addAction(ui->actionCnps_diferences);

    grupoVista->setExclusive(true); //Este flag evita que puedan estar activas dos acciones del grupo al mismo tiempo

    //Preparar el signalMapper
    mapeadorVistas=new QSignalMapper(this);


    //Establecer el mapeado
    mapeadorVistas->setMapping(ui->actionCnps_met_orto,0);
    mapeadorVistas->setMapping(ui->actionCnps_rename_change_format,1);
    mapeadorVistas->setMapping(ui->actionCnps_combine_cnps,2);
    mapeadorVistas->setMapping(ui->actionCnps_correction,3);
    mapeadorVistas->setMapping(ui->actionCnps_diferences,4);
    mapeadorVistas->setMapping(ui->actionCnps_view_html,5);

    //Conectar las señales de los objetos al mapeador
    connect(ui->actionCnps_met_orto,SIGNAL(triggered()),mapeadorVistas,SLOT(map()));
    connect(ui->actionCnps_combine_cnps,SIGNAL(triggered()),mapeadorVistas,SLOT(map()));
    connect(ui->actionCnps_correction,SIGNAL(triggered()),mapeadorVistas,SLOT(map()));
    connect(ui->actionCnps_rename_change_format,SIGNAL(triggered()),mapeadorVistas,SLOT(map()));
    connect(ui->actionCnps_view_html,SIGNAL(triggered()),mapeadorVistas,SLOT(map()));
    connect(ui->actionCnps_diferences,SIGNAL(triggered()),mapeadorVistas,SLOT(map()));

    //Conectamos la señal mapeada con el slot correspondiente
    connect(mapeadorVistas,SIGNAL(mapped(int)),ui->stackedWidgetVistas,SLOT(setCurrentIndex(int)));


    //Agrupar los botones de opciones cnps en un grupo de botones
    QButtonGroup *grupoBotones=new QButtonGroup(this);

    grupoBotones->addButton(ui->pushButtonOptionsCnp);
    grupoBotones->addButton(ui->pushButtonOptionsMet);
    grupoBotones->addButton(ui->pushButtonOptionsOrto);

    grupoBotones->setExclusive(true);

    //Agrupar los botones de Casi Tasi Aisa
    QButtonGroup *grupoBotonesCasiTasiaisa=new QButtonGroup(this);

    grupoBotonesCasiTasiaisa->addButton(ui->pushButtonCasi);
    grupoBotonesCasiTasiaisa->addButton(ui->pushButtonTasi);
    grupoBotonesCasiTasiaisa->addButton(ui->pushButtonAisa);

    grupoBotonesCasiTasiaisa->setExclusive(true);



    //Preparar botones de cambio de opciones cnp

    ui->pushButtonOptionsCnp->addEstado(0,new QIcon()); //No seleccionado
    ui->pushButtonOptionsCnp->addEstado(1,new QIcon(":/imagenes/correcto"));   //Correcto
    ui->pushButtonOptionsCnp->addEstado(2,new QIcon(":/imagenes/parcialmenteCorrecto"));       // Parcialmente correcto

    ui->pushButtonOptionsCnp->setEstadoBoton(0); //Estado inicial: No seleccionado

    //Conectar
    connect(ui->page1Cnp,SIGNAL(cambioEstadoCorreccionCnps(int)),ui->pushButtonOptionsCnp,SLOT(setEstadoBoton(int)));


    //Preparar botones de cambio de opciones orto
    ui->pushButtonOptionsOrto->addEstado(0,new QIcon()); //No seleccionado
    ui->pushButtonOptionsOrto->addEstado(1,new QIcon(":/imagenes/correcto"));   //Correcto
    ui->pushButtonOptionsOrto->addEstado(2,new QIcon(":/imagenes/parcialmenteCorrecto"));       // Parcialmente correcto

    ui->pushButtonOptionsOrto->setEstadoBoton(0); //Estado inicial: No seleccionado

    //Conectar
    connect(ui->page3Orto,SIGNAL(cambioEstadoCorreccionOrto(int)),ui->pushButtonOptionsOrto,SLOT(setEstadoBoton(int)));

    //Preparar botones de cambio de opciones Met
    ui->pushButtonOptionsMet->addEstado(0,new QIcon()); //No seleccionado
    ui->pushButtonOptionsMet->addEstado(1,new QIcon(":/imagenes/correcto"));   //Correcto
    ui->pushButtonOptionsMet->addEstado(2,new QIcon(":/imagenes/parcialmenteCorrecto"));       // Parcialmente correcto

    ui->pushButtonOptionsMet->setEstadoBoton(0); //Estado inicial: No seleccionado

    //Conectar
    connect(ui->page2Met,SIGNAL(cambioEstadoCorreccionMet(int)),ui->pushButtonOptionsMet,SLOT(setEstadoBoton(int)));
    //Inicializar lanzador de operaciones.

    _lanzadorOpe=new LanzadorOperaciones(this,ui->page1Cnp->getObjetoRegistroCreateCnps(),ui->page2Met->getObjetoRegistroCreateMet(),
                                         ui->page3Orto->getObjetoRegistroCreateOrto(),ui->widgetCoordinates);

    _dialogoProgreso= new DialogProgresoOpe(0);
    _dialogoProgreso->conectToControlCnp(_lanzadorOpe->getControlCnp());
    _dialogoProgreso->conectToControlMet(_lanzadorOpe->getControlMet());
    _dialogoProgreso->conectToControlOrto(_lanzadorOpe->getControlOrto());
    connect(_lanzadorOpe,SIGNAL(inicioOperaciones()),_dialogoProgreso,SLOT(exec()));
    connect(ui->actionNew_project,SIGNAL(triggered()),this,SLOT(nuevoProyecto()));

    //Crear el archivo de proyecto por defecto
    //ESTO ES TEMPORAL HASTA QUE CONSTRUYAMOS MEJOR EL MECANISMO DE CARGA DE PROYECTOS
    _archivoProyecto=0;
    //Resto de secciones conforme se preparen
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButtonEmpezarOperacionesMetOrto_clicked()
{

    //Creanmos 3 variables boleanas false por defect,o si el icono es correcto "1 verde " cambiaremos la variable a true
    bool iconoCnp=false;
    bool iconoMet=false;
    bool iconoOrto=false;
    //Comprobar estado de los tres botones
    //Si los tres botones estan en estado no seleccionado:
    //  - Lanzar ventana indicando que no se ha seleccionado ninguna operacion
    //Si algun boton esta seleccionado pero no esta correcto:
    //  - Lanzar ventana indicando que hay opciones que no se han rellenado de forma correcta,
    //  e indicar cuales son esas opciones
    //Si los botones estan seleccionados y correctos:
    //  - Lanzar procesos indicados.

    if((ui->pushButtonOptionsCnp->getEstadoBoton()==0)
            &&
            (ui->pushButtonOptionsMet->getEstadoBoton()==0)
            &&
            (ui->pushButtonOptionsOrto->getEstadoBoton()==0))
    {
        QMessageBox::warning(this,tr("ToolsPCot - Cnp Met Orto"),tr("No se ha seleccionado ninguna operacion CNP/MET/ORTO"));
        return;
    }
    if((ui->pushButtonOptionsCnp->getEstadoBoton()==2)
            ||
            (ui->pushButtonOptionsMet->getEstadoBoton()==2)
            ||
            (ui->pushButtonOptionsOrto->getEstadoBoton()==2))
    {
        QString mensajeWarning=tr("Las siguientes operaciones han sido seleccionadas pero no se han introducido correctamente los datos: ");

        if(ui->pushButtonOptionsCnp->getEstadoBoton()==2)
            mensajeWarning=mensajeWarning + tr("\n\t- Operacion CNP");
        if(ui->pushButtonOptionsMet->getEstadoBoton()==2)
            mensajeWarning=mensajeWarning + tr("\n\t- Operacion MET");
        if(ui->pushButtonOptionsOrto->getEstadoBoton()==2)
            mensajeWarning=mensajeWarning + tr("\n\t- Operacion ORTO");
        QMessageBox::warning(this,tr("ToolsPCot - Cnp Met Orto"),mensajeWarning);
        return;

    }
    _lanzadorOpe->setCnpActivo(false);
    _lanzadorOpe->setMetActivo(false);
    _lanzadorOpe->setOrtoActivo(false);
    //si llegamos a este linea cambiamos las variables boleanas necesarias
    qDebug()<< "Todos los datos son correctos, Comenzar operaciones cnp met orto";

    //Si el icono cnp es verde cambiamos el la variable a true y empezamos los procesos
    if((ui->pushButtonOptionsCnp->getEstadoBoton()==1))
    {
        iconoCnp==true;
        _lanzadorOpe->setCnpActivo(true);
        qDebug()<< "Creando cnps";
    }
    //Si el icono met es verde cambiamos el la variable a true y empezamos los procesos
    if((ui->pushButtonOptionsMet->getEstadoBoton()==1))
    {

        iconoMet==true;
        _lanzadorOpe->setMetActivo(true);
        qDebug()<< "Creando met";
    }
    //Si el icono orto es verde cambiamos el la variable a true y empezamos los procesos
    if((ui->pushButtonOptionsOrto->getEstadoBoton()==1))
    {
        iconoOrto==true;
        _lanzadorOpe->setOrtoActivo(true);
        qDebug()<< "Creando orto";
    }
    _dialogoProgreso->resetDialog();
    _lanzadorOpe->launch();
    _dialogoProgreso->exec();
}

void MainWindow::on_pushButton_clicked()
{

    //prueba clase registrocreateMet
    qDebug()<< "pepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepepe";
    RegistroCreateMet *punteroRCMet;
    RegistroCreateOrto *punteroRCOrto;
    punteroRCMet=ui->page2Met->getObjetoRegistroCreateMet();
    qDebug()<< punteroRCMet->getAmbitoOperacion() <<"getAmbitoOperacion";
    qDebug()<< punteroRCMet->getAnchoPasada() <<"getAmbitoProyectoMet";
    qDebug()<< punteroRCMet->getCutDtm() <<"getAmbitoProyectoMet";
    qDebug()<< punteroRCMet->getFolderOut() <<"getAmbitoProyectoMetmetmet";
    qDebug()<< punteroRCOrto->getFolderOut() <<"getAmbitoProyectoOrto";
    qDebug()<< punteroRCMet->getFootPrintMask() <<"getAmbitoProyectoMet";
    qDebug()<< punteroRCMet->getNumeroCanales() <<"getAmbitoProyectoMet";
    qDebug()<< punteroRCMet->getOffsetPasada() <<"getAmbitoProyectoMet";

}

void MainWindow::lanzarDialogoPreferencias()
{
    DialogoPreferencias dialogo(this);
    connect(&dialogo,SIGNAL(cambiosArchivoMet()),ui->page2Met,SLOT(recargarModelosAmbito()));
    connect(&dialogo,SIGNAL(cambiosArchivoOrto()),ui->page3Orto,SLOT(recargarModelosAmbito()));
    dialogo.exec();
}
void MainWindow::mostrarDialogoProgreso()
{
    _dialogoProgreso->show();
}
void MainWindow::nuevoProyecto()
{
    NewProjectDialog welcome;
    welcome.exec();

    ArchivoProyecto *nuevoArchivo=welcome.getArchivoProyecto();
    QList<AProTPSection*> listaSecciones;
    if(_archivoProyecto)
        listaSecciones=_archivoProyecto->getListaSections();
    else {
        listaSecciones.append(ui->page1Cnp->getObjetoRegistroCreateCnps());
    }

    if(nuevoArchivo) {
        foreach(AProTPSection *section,listaSecciones) {
            section->resetSection();
            if(_archivoProyecto)
                _archivoProyecto->removeSection(section);
            nuevoArchivo->addSection(section);
        }
        if(_archivoProyecto)
        {this->disconnect(_archivoProyecto);
            delete _archivoProyecto;
            }
        _archivoProyecto=nuevoArchivo;
        _archivoProyecto->build();
        connect(_archivoProyecto,SIGNAL(cambioActualizado(bool)),this,SLOT(cambiosEnProyecto(bool)));
        this->setWindowTitle(_archivoProyecto->getnameProyect()+tr(" - ToolsPcot"));
    }
}

void MainWindow::cambiosEnProyecto(bool estado)
{
if(!estado)
{
    this->setWindowTitle(_archivoProyecto->getnameProyect()+tr("*")+tr(" - ToolsPcot"));
}
else
    this->setWindowTitle(_archivoProyecto->getnameProyect()+tr(" - ToolsPcot"));
}
