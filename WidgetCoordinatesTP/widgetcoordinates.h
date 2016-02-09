#ifndef WIDGETCOORDINATES_H
#define WIDGETCOORDINATES_H

#include "widgetcoordinatestp_global.h"
#include "dialoghelpfilecoordinates.h"

#include <QWidget>
#include <QMessageBox>

#include <CoordinatesTP/modelocoordenadas.h>
#include <CoordinatesTP/sectioncoordinates.h>
#include <CoordinatesTP/readercoordinatesbasico.h>

namespace Ui {
class WidgetCoordinates;
}

class WIDGETCOORDINATESTPSHARED_EXPORT WidgetCoordinates : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetCoordinates(QWidget *parent = 0);
    ~WidgetCoordinates();

    //Getter
    ModeloCoordenadas *getModeloCoordenadas()
    { return _modeloCoordenadas; }

    SectionCoordinates *getSectionCoordinates()
    { return _sectionCoordenadas; }

signals:

    void loadedModelo(bool);

public slots:

    //Limpiar modelo de coordenadas

    void limpiarModeloCoordenadas();

    //Ayuda modelo de coordenadas

    void ayudaCoordenadas();

    //Abrir archivo de coordenadas

    void openArchivoCoordenadas(QString archivo);

private:
    Ui::WidgetCoordinates *ui;

    ModeloCoordenadas *_modeloCoordenadas;
    SectionCoordinates *_sectionCoordenadas;
};

#endif // WIDGETCOORDINATES_H
