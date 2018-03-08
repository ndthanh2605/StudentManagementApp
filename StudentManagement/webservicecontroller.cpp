#include "webservicecontroller.h"
#include <QDebug>
#include <QJsonDocument>

WebserviceController::WebserviceController(QObject *parent) : QObject(parent)
{
    connect(&m_networkManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(onRecvReply(QNetworkReply*)));
}

void WebserviceController::sendRequestGET(const QString &urlStr, DataType type)
{
    m_currentType = type;

    qDebug() << "send request GET to server:\n" << urlStr;
    QUrl url(urlStr);
    QNetworkRequest request;
    request.setUrl(url);

    m_networkManager.get(request);
}

void WebserviceController::sendRequestPUT(const QString &urlStr, const QJsonObject &obj)
{
    qDebug() << "send request PUT to server:\n" << urlStr
             << "json:\n" << obj;
    QUrl url(urlStr);
    QNetworkRequest request;
    request.setUrl(url);

    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    qDebug() << "send bytes:" << bytes;
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");

    m_networkManager.put(request, bytes);
}

void WebserviceController::onRecvReply(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "reply error:" << reply->errorString();
        delete reply;
        return;
    }

    QString data = (QString) reply->readAll();
    qDebug() << "receive json data:" << data << data.size() << "\n\n";
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data.toUtf8());
    if (m_currentType == JSON_ARR) {
        QJsonArray jsonArr = jsonResponse.array();
        qDebug() << "recv json array:" << jsonArr.size() << "items";
        emit sigRecvDataArray(jsonArr);
    } else if (m_currentType == JSON_OBJ) {
        QJsonObject jsonObj = jsonResponse.object();
        qDebug() << "recv json obj:";
        for (auto itr = jsonObj.begin(); itr != jsonObj.end(); itr++) {
            qDebug() << "obj" << itr.key() << itr.value().toString();
        }
        emit sigRecvDataObject(jsonObj);
    }
}
