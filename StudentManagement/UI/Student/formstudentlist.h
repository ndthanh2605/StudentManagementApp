#ifndef FORMSTUDENTLIST_H
#define FORMSTUDENTLIST_H

#include <QWidget>
#include "Model/studentmodel.h"

namespace Ui {
class FormStudentList;
}

class FormStudentList : public QWidget
{
    Q_OBJECT

public:
    explicit FormStudentList(QWidget *parent = 0);
    ~FormStudentList();

    void updateListStudents(const QList<Student *> &students);

signals:
    void sigAddStudent();
    void sigEditStudent(int studentId);
    void sigDeleteStudent(int studentId);

private slots:
    void on_tbAdd_clicked();

private:
    Ui::FormStudentList *ui;

    StudentModel m_model;

    void refreshUi();

};

#endif // FORMSTUDENTLIST_H
