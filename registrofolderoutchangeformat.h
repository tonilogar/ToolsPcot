#ifndef REGISTROFOLDEROUTCHANGEFORMAT_H
#define REGISTROFOLDEROUTCHANGEFORMAT_H

#include <QObject>
/*!
 * @class  RegistroFolderOutChangeFormat
 * @brief Classe per mostrar o canvia els path de directoris de sortida.
 */
class RegistroFolderOutChangeFormat : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     *
     */
    explicit RegistroFolderOutChangeFormat(QObject *parent = 0);
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     *
     */
    RegistroFolderOutChangeFormat(QObject *parent,QString folderAtt,QString folderPix,QString folderAtp,QString folderRf,QString folderJpg);

    //Getter
    /*!
     * Mostrar el directori de sortida dels fitxers att.
     */
    QString getFolderAtt() const;
    /*!
     * Mostrar el directori de sortida dels fitxers pix.
     */
    QString getFolderPix() const;
    /*!
     * Mostrar el directori de sortida dels fitxers atp.
     */
    QString getFolderAtp() const;
    /*!
     * Mostrar el directori de sortida dels fitxers rf.
     */
    QString getFolderRf() const;
    /*!
     * Mostrar el directori de sortida dels fitxers jpg.
     */
    QString getFolderJpg() const;



public slots:
    //Setters
    /*!
     * Canvia el directori de sortida dels fitxers att.
     * @param Nou valor del directori de sotida dels fitxers att.
     *
     */
    void setFolderAtt(QString folderAtt);
    /*!
     * Canvia el directori de sortida dels fitxers pix.
     * @param Nou valor del directori de sotida dels fitxers pix.
     *
     */
    void setFolderPix(QString folderPix);
    /*!
     * Canvia el directori de sortida dels fitxers atp.
     * @param Nou valor del directori de sotida dels fitxers atp.
     *
     */
    void setFolderAtp(QString folderAtp);
    /*!
     * Canvia el directori de sortida dels fitxers rf.
     * @param Nou valor del directori de sotida dels fitxers rf.
     *
     */
    void setFolderRf(QString folderRf);
    /*!
     * Canvia el directori de sortida dels fitxers jpg.
     * @param Nou valor del directori de sotida dels fitxers jpg.
     *
     */
    void setFolderJpg(QString folderJpg);

signals:



private:
    QString _folderAtt;   ///< Nom del directori de sortida att.
    QString _folderPix;   ///< Nom del directori de sortida pix.
    QString _folderAtp;   ///< Nom del directori de sortida atp.
    QString _folderRf;    ///< Nom del directori de sortida rf.
    QString _folderJpg;   ///< Nom del directori de sortida jpg.

};

#endif // REGISTROFOLDEROUTCHANGEFORMAT_H
