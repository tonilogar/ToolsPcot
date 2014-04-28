#ifndef REGISTRORAW_H
#define REGISTRORAW_H

#include <QObject>

class RegistroRaw : public QObject
{
    Q_OBJECT
public:
    explicit RegistroRaw(QObject *parent = 0);

    RegistroRaw(QObject *parent,QString name,QString path);

    //Getter
    QString getNameRaw() const
    { return _name; }

    QString getPathRaw() const
    { return _path; }

    uint getSignoPasada() const
    { return _signoPasada; }

    uint getStripNumber() const
    { return _stripNumber; }

    uint getFileNumber() const
    { return _fileNumber; }

    uint getCanalRed() const
    { return _canalRed; }

    uint getCanalGreen() const
    { return _canalGreen; }

    uint getCanalBlue() const
    { return _canalBlue; }

    //Setters
    void setNameRaw(QString name)
    { _name=name; }

    void setPathRaw(QString path)
    { _path=path; }

    void setSignoPasada(uint signoPasada)
    { _signoPasada=signoPasada; }

    void setStripNumber(uint number)
    { _stripNumber=number; }

    void setFileNumber(uint number)
    { _fileNumber=number; }

    void setCanalRed(uint canalRed)
    { _canalRed=canalRed; }

    void setCanalGreen(uint canalGreen)
    { _canalGreen=canalGreen; }

    void setCanalBlue(uint canalBlue)
    {  _canalBlue=canalBlue; }
signals:

public slots:

private:

    QString _name;
    QString _path;
    uint _signoPasada;
    uint _fileNumber;
    uint _stripNumber;
    uint _canalRed;
    uint _canalGreen;
    uint _canalBlue;

};

#endif // REGISTRORAW_H
