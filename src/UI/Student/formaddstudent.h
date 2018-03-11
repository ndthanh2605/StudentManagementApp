#ifndef FORMADDSTUDENT_H
#define FORMADDSTUDENT_H

#include <QWidget>
#include "Entity/student.h"

namespace Ui {
class FormAddStudent;
}

class FormAddStudent : public QWidget
{
    Q_OBJECT

public:
    explicit FormAddStudent(QWidget *parent = 0);
    ~FormAddStudent();

    void loadInfo(const Student &student);

signals:
    void sigBack();
    void sigSubmitStudentData(bool isAdd, const QJsonObject &obj);

private slots:
    void on_pbOk_clicked();

    void on_pbCancel_clicked();

private:
    Ui::FormAddStudent *ui;

    QString m_studentId;

};

#endif // FORMADDSTUDENT_H
