#ifndef WIDGETCOORDINATES_H
#define WIDGETCOORDINATES_H

#include "widgetcoordinatestp_global.h"

#include <QWidget>

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


private:
    Ui::WidgetCoordinates *ui;

    ModeloCoordenadas *_modeloCoordenadas;
    SectionCoordinates *_sectionCoordenadas;
};

#endif // WIDGETCOORDINATES_H
