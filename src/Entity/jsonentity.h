#ifndef JSONENTITY_H
#define JSONENTITY_H

#include <QJsonObject>

class JsonEntity
{
public:
    JsonEntity();

    virtual void readJson(const QJsonObject &obj);
    virtual void writeJson(QJsonObject &obj);

};

#endif // JSONENTITY_H
