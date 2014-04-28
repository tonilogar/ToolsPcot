#ifndef REGISTROFOLDEROUTCHANGEFORMAT_H
#define REGISTROFOLDEROUTCHANGEFORMAT_H

#include <QObject>

class RegistroFolderOutChangeFormat : public QObject
{
    Q_OBJECT
public:
    explicit RegistroFolderOutChangeFormat(QObject *parent = 0);
    RegistroFolderOutChangeFormat(QObject *parent,QString folderAtt,QString folderPix,QString folderAtp,QString folderRf,QString folderJpg);

    //Getter
    QString getFolderAtt() const;
    QString getFolderPix() const;
    QString getFolderAtp() const;
    QString getFolderRf() const;
    QString getFolderJpg() const;



public slots:
    //Setters
    void setFolderAtt(QString folderAtt);
    void setFolderPix(QString folderPix);
    void setFolderAtp(QString folderAtp);
    void setFolderRf(QString folderRf);
    void setFolderJpg(QString folderJpg);

signals:



private:
    QString _folderAtt;
    QString _folderPix;
    QString _folderAtp;
    QString _folderRf;
    QString _folderJpg;

};

#endif // REGISTROFOLDEROUTCHANGEFORMAT_H
