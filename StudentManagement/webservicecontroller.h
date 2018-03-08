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
        JSON_ARR
    };

    explicit WebserviceController(QObject *parent = nullptr);

    void sendRequestGET(const QString &urlStr, DataType type);
    void sendRequestPOST(const QString &urlStr, const QJsonObject &obj);

signals:
    void sigRecvDataObject(const QJsonObject &obj);
    void sigRecvDataArray(const QJsonArray &arr);

public slots:

private slots:
    void onRecvReply(QNetworkReply* reply);

private:
    QNetworkAccessManager m_networkManager;
    DataType m_currentType;

};

#endif // WEBSERVICECONTROLLER_H
