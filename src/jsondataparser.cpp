#include "jsondataparser.h"

QList<Student *> JsonDataParser::parseListStudents(const QJsonArray &arr)
{
    QList<Student *> rs;
    for (int i = 0; i < arr.size(); ++i) {
        Student *st = parseStudent(arr.at(i).toObject());
        if (st)
            rs.append(st);
    }
    return rs;
}

Student *JsonDataParser::parseStudent(const QJsonObject &obj)
{
    Student *rs = new Student;
    rs->readJson(obj);
    return rs;
}

QList<Session *> JsonDataParser::parseListSessions(const QJsonArray &arr)
{
    QList<Session *> rs;
    for (int i = 0; i < arr.size(); ++i) {
        Session *st = parseSession(arr.at(i).toObject());
        if (st)
            rs.append(st);
    }
    return rs;
}

Session *JsonDataParser::parseSession(const QJsonObject &obj)
{
    Session *rs = new Session;
    rs->readJson(obj);
    return rs;
}
