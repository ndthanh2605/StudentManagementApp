#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UI/Student/formstudentlist.h"
#include "UI/Student/formaddstudent.h"
#include "webservicecontroller.h"
#include "jsondataparser.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void requestData();

signals:
    void sigLogOut();

private slots:
    void on_stackedWidget_currentChanged(int idx);

    void onRecvStudentsData(const QJsonArray &arr);
    void onSubmitStudentData(bool isAdd, const QJsonObject &obj);

private:
    Ui::MainWindow *ui;

    QString m_baseUrl = "https://studentmanagement-ngodichat.herokuapp.com/api";
    WebserviceController m_controller;

    FormStudentList *m_formStudentList;
    FormAddStudent *m_formAddStudent;

};

#endif // MAINWINDOW_H
