#ifndef INDEXBUTTON_H
#define INDEXBUTTON_H

#include <QPushButton>
#include <QMap>
#include <QIcon>

class IndexButton : public QPushButton
{
    Q_OBJECT
public:
    explicit IndexButton(QWidget *parent = 0,int indice=0);
    int getIndiceButton();
    int getEstadoBoton() const;
    QMap<int,QIcon*> getMapaEstados() const;
    QList<int> getListaEstados() const;

signals:

    void clicked(int valor);

public slots:

    void setIndiceButton(int indice);
    void setEstadoBoton(int estado);

    /*!
      Añadir un nuevo estado y un icono
       \param numEstado
       \param iconoEstado
     */
    void addEstado(int numEstado,QIcon *iconoEstado);


    /*!
      Elimina un estado del boton
       \param numEstado
     */
    void removeEstado(int numEstado);


private:
    int index;

    int _estadoActual;          ///< Atributo de estado del boton
    QMap<int,QIcon*> mapaEstados;   ///< Mapa de estados del boton

private slots:

    void botonPulsado();
};

#endif // INDEXBUTTON_H
