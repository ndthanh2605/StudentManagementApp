#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UI/Student/formstudentlist.h"
#include "UI/Student/formaddstudent.h"
#include "UI/Session/formsessionlist.h"
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

    void requestStudentList();
    void requestSessionList();

signals:
    void sigLogOut();

private slots:
    void on_stackedWidget_currentChanged(int idx);

    void onRecvStudentsData(const QJsonArray &arr);
    void onSubmitStudentData(bool isAdd, const QJsonObject &obj);
    void onRequestDeleteStudent(const QString &stId);

    void onRecvSessionsData(const QJsonArray &arr);

    void on_actionListSessions_triggered();

private:
    Ui::MainWindow *ui;

    QString m_baseUrl = "https://studentmanagement-ngodichat.herokuapp.com/api";
    WebserviceController m_controller;

    FormStudentList *m_formStudentList;
    FormAddStudent *m_formAddStudent;

    FormSessionList *m_formSessionList;

    void showFormAddEditStudent(const Student &st);

};

#endif // MAINWINDOW_H
