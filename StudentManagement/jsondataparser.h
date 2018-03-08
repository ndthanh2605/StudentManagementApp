#ifndef JSONDATAPARSER_H
#define JSONDATAPARSER_H

#include <QJsonArray>
#include <QJsonObject>

#include "Entity/student.h"

class JsonDataParser
{
public:
    static QList<Student *> parseListStudents(const QJsonArray &arr);
    static Student* parseStudent(const QJsonObject &obj);

};

#endif // JSONDATAPARSER_H
