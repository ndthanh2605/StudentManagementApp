#ifndef WEBSERVICECONTROLLER_H
#define WEBSERVICECONTROLLER_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonArray>
#include <QJsonObject>

class WebserviceController : public QObject
{
    Q_OBJECT
public:
    enum DataType {
        JSON_OBJ = 0,
        JSON_ARR,
        REPLY
    };

    explicit WebserviceController(QObject *parent = nullptr);

    void sendRequestGET(const QString &urlStr, DataType type);
    void sendRequestPUT(const QString &urlStr, const QJsonObject &obj, DataType type);
    void sendRequestDEL(const QString &urlStr);

signals:
    void sigRecvDataObject(const QJsonObject &obj);
    void sigRecvDataArray(const QJsonArray &arr);
    void sigRecvServerReply();

public slots:

private slots:
    void onRecvReply(QNetworkReply* reply);

private:
    QNetworkAccessManager m_networkManager;
    DataType m_currentType;

};

#endif // WEBSERVICECONTROLLER_H
