#ifndef REGISTRORAW_H
#define REGISTRORAW_H

#include <QObject>
/*!
 * @class RegistroRaw
 * @brief Classe amb les dades necessàries per fer els cavis de format.
 */
class RegistroRaw : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor explicit per defecte, necesita un punter nul.
     *
     */
    explicit RegistroRaw(QObject *parent = 0);
    /*!
     * Constructor necessita dos QStrings.
     *
     */
    RegistroRaw(QObject *parent,QString name,QString path);

    //Getter
    /*!
     * Mostrar el nom del fitxer *.raw.
     */
    QString getNameRaw() const
    { return _name; }
    /*!
     * Mostrar el path del fitxer *.raw.
     */
    QString getPathRaw() const
    { return _path; }
    /*!
     * Mostrar el valor del signe de passada.
     */
    uint getSignoPasada() const
    { return _signoPasada; }
    /*!
     * Mostrar el valor del número de passada.
     */
    uint getStripNumber() const
    { return _stripNumber; }
    /*!
     * Mostrar el valor del número de passada.
     */
    uint getFileNumber() const
    { return _fileNumber; }
    /*!
     * Mostrar el valor del Canal red.
     */
    uint getCanalRed() const
    { return _canalRed; }
    /*!
     * Mostrar el valor del Canal green.
     */
    uint getCanalGreen() const
    { return _canalGreen; }
    /*!
     * Mostrar el valor del Canal blue.
     */
    uint getCanalBlue() const
    { return _canalBlue; }

    //Setters
    /*!
     * Cambia el nom del fitxer *.raw.
     * @param identificador nou nom del fitxer raw.
     *
     */
    void setNameRaw(QString name)
    { _name=name; }
    /*!
     * Cambia el nom del path del fitxer *.raw.
     * @param identificador nou nom del path del fitxer raw.
     *
     */
    void setPathRaw(QString path)
    { _path=path; }
    /*!
     * Cambia el valor del signe de passada.
     * @param identificador nou del signe de passada.
     *
     */
    void setSignoPasada(uint signoPasada)
    { _signoPasada=signoPasada; }
    /*!
     * Cambia el valor del número de passada.
     * @param identificador nou del número de passada.
     *
     */
    void setStripNumber(uint number)
    { _stripNumber=number; }
    /*!
     * Cambia el valor del número de passada.
     * @param identificador nou del número de passada.
     *
     */
    void setFileNumber(uint number)
    { _fileNumber=number; }
    /*!
     * Cambia el valor del canal red.
     * @param identificador nou del valor del canal green.
     *
     *
     */
    void setCanalRed(uint canalRed)
    { _canalRed=canalRed; }
    /*!
     * Cambia el valor del canal red.
     * @param identificador nou del valor del canal green.
     *
     */
    void setCanalGreen(uint canalGreen)
    { _canalGreen=canalGreen; }
    /*!
     * Cambia el valor del canal blue.
     * @param identificador nou del valor del canal blue.
     *
     */
    void setCanalBlue(uint canalBlue)
    {  _canalBlue=canalBlue; }
signals:

public slots:

private:

    QString _name;      ///< Nom del fitxer raw.
    QString _path;      ///< Nom path del fitxer raw.
    uint _signoPasada;  ///< Valor del signe de passada.
    uint _fileNumber;   ///< Valor del número de fitxer.
    uint _stripNumber;  ///< Valor del número de passada de vol.
    uint _canalRed;     ///< Valor del Canal red.
    uint _canalGreen;   ///< Valor del Canal green.
    uint _canalBlue;    ///< Valor del Canal blue.

};

#endif // REGISTRORAW_H
