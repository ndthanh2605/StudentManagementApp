#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H

#include <QObject>
#include "Entity/student.h"

class StudentModel : public QObject
{
    Q_OBJECT
public:
    explicit StudentModel(QObject *parent = nullptr);

    void clearData();

    Student *getStudent(const QString &id);

    QList<Student *> getListStudents() const;
    void setListStudents(const QList<Student *> &students);

signals:

public slots:

private:
    QHash<QString, Student *> m_students;

};

#endif // STUDENTMODEL_H
