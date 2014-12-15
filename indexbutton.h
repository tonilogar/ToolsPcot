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
      Afegeix un nou estat al boto
       \param numEstado
       \param iconoEstado
     */
    void addEstado(int numEstado,QIcon *iconoEstado);


    /*!
      Borra un estat del boto
       \param numEstado
     */
    void removeEstado(int numEstado);


private:
    int index;

    int _estadoActual;          ///< Atribut del estat del boto.
    QMap<int,QIcon*> mapaEstados;   ///< Mapa del estat del boto.

private slots:

    void botonPulsado();///< Atribut boolea del estat del boto.
};

#endif // INDEXBUTTON_H
