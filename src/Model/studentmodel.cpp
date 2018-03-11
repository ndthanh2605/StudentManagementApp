#include "studentmodel.h"
#include <QDebug>

StudentModel::StudentModel(QObject *parent) : QObject(parent)
{

}

void StudentModel::clearData()
{
    qDeleteAll(m_students);
    m_students.clear();
}

Student *StudentModel::getStudent(const QString &id)
{
    return m_students.value(id);
}

QList<Student *> StudentModel::getListStudents() const
{
    return m_students.values();
}

void StudentModel::setListStudents(const QList<Student *> &students)
{
    clearData();
    for (int i = 0; i < students.size(); ++i) {
        qDebug() << "add student" << students.at(i)->id();
        m_students.insert(students.at(i)->id(), students.at(i));
    }
}
