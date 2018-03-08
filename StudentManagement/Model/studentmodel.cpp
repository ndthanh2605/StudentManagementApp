#include "studentmodel.h"
#include <QDebug>

StudentModel::StudentModel(QObject *parent) : QObject(parent)
{

}

void StudentModel::clearData()
{
    for (auto itr = m_students.begin(); itr != m_students.end(); itr++) {
        delete itr.value();
        m_students.erase(itr);
    }
    m_students.clear();
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
