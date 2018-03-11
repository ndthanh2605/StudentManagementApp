#ifndef JSONDATAPARSER_H
#define JSONDATAPARSER_H

#include <QJsonArray>
#include <QJsonObject>

#include "Entity/student.h"
#include "Entity/session.h"

class JsonDataParser
{
public:
    static QList<Student *> parseListStudents(const QJsonArray &arr);
    static Student* parseStudent(const QJsonObject &obj);

    static QList<Session *> parseListSessions(const QJsonArray &arr);
    static Session* parseSession(const QJsonObject &obj);

};

#endif // JSONDATAPARSER_H
