#ifndef REGISTROCREATEORTO_H
#define REGISTROCREATEORTO_H

#include <QObject>

class RegistroCreateOrto : public QObject
{
    Q_OBJECT
public:
    explicit RegistroCreateOrto(QObject *parent = 0);

    RegistroCreateOrto(QObject *parent,QString folderOut,QString ambitoProyecto,int tamanyoPixel,int utm,int anchoPasada,int offsetPasada, QString pathImageOrto,QString exeSubScene);

    //Getter
    QString getFolderOut();
    QString getAmbitoProyecto();
    int getTamanyPixel();
    int getUtm();
    int getAnchoPasada();
    int getOffsetPasada();
    bool getFootPrintMask();
    QString getPathImageOrto();
    QString getExeSubScene();

public slots:
//setters
    void setFolderOut(QString folderOut);
    void setAmbitoProyecto(QString ambitoProyecto);
    void setTamanyPixel(int tamanyoPixel);
    void setUtm(int utm);
    void setAnchoPasada(int anchoPasada);
    void setOffsetPasada(int offsetPasada);
    void setFootprintMask(int fprintM);
    void setPathImageOrto(QString pathImageOrto);
    void setExeSubScene(QString exeSubScene);

signals:




private:


       QString _folderOut;
       QString _ambitoProyecto;
       int _tamanyoPixel;
       int _utm;
       int _anchoPasada;
       int _offsetPasada;
       bool _fprintM;
       QString _pathImageOrto;
       QString _exeSubScene;
};

#endif // REGISTROCREATEORTO_H
