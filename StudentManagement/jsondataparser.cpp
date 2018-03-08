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
