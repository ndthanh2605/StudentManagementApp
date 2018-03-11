#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_formStudentList = new FormStudentList;
    ui->stackedWidget->addWidget(m_formStudentList);
    connect(m_formStudentList, &FormStudentList::sigAddStudent, this, [this]() {
        Student st;
        showFormAddEditStudent(st);
    });
    connect(m_formStudentList, &FormStudentList::sigEditStudent, this, [this](const QString &stId) {
        Student *st = m_formStudentList->getStudentInfo(stId);
        if (st) {
            showFormAddEditStudent(*st);
        }
    });
    ui->stackedWidget->setCurrentIndex(-1);

    m_formAddStudent = new FormAddStudent;
    ui->stackedWidget->addWidget(m_formAddStudent);
    connect(m_formAddStudent, &FormAddStudent::sigBack, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(m_formAddStudent, SIGNAL(sigSubmitStudentData(bool,QJsonObject)),
            this, SLOT(onSubmitStudentData(bool,QJsonObject)));
    connect(m_formStudentList, SIGNAL(sigDeleteStudent(QString)),
            this, SLOT(onRequestDeleteStudent(QString)));

    m_formSessionList = new FormSessionList;
    ui->stackedWidget->addWidget(m_formSessionList);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::requestStudentList()
{    
    QString query = QString("%1/students").arg(m_baseUrl);
    connect(&m_controller, SIGNAL(sigRecvDataArray(QJsonArray)),
            this, SLOT(onRecvStudentsData(QJsonArray)));
    m_controller.sendRequestGET(query, WebserviceController::JSON_ARR);
}

void MainWindow::requestSessionList()
{
    QString query = QString("%1/sessions").arg(m_baseUrl);
    connect(&m_controller, SIGNAL(sigRecvDataArray(QJsonArray)),
            this, SLOT(onRecvSessionsData(QJsonArray)));
    m_controller.sendRequestGET(query, WebserviceController::JSON_ARR);
}

void MainWindow::on_stackedWidget_currentChanged(int idx)
{
    switch (idx) {
    case 0: {     // form student management
        requestStudentList();
        break;
    }
    case 2: {
        requestSessionList();
        break;
    }
    default:
        break;
    }
}

void MainWindow::onRecvStudentsData(const QJsonArray &arr)
{
    QList<Student *> students = JsonDataParser::parseListStudents(arr);
    m_formStudentList->updateListStudents(students);

    disconnect(&m_controller, 0, this, 0);
}

void MainWindow::onSubmitStudentData(bool isAdd, const QJsonObject &obj)
{
    QString query = QString("%1/students/%2").arg(m_baseUrl).arg( (isAdd)? "add":"update");
    ui->stackedWidget->setCurrentIndex(0);
    connect(&m_controller, SIGNAL(sigRecvDataArray(QJsonArray)),
            this, SLOT(onRecvStudentsData(QJsonArray)));
    m_controller.sendRequestPUT(query, obj, WebserviceController::JSON_ARR);
}

void MainWindow::onRequestDeleteStudent(const QString &stId)
{
    QString query = QString("%1/students/delete/%2").arg(m_baseUrl).arg(stId);
    m_controller.sendRequestDEL(query);
    requestStudentList();
}

void MainWindow::onRecvSessionsData(const QJsonArray &arr)
{
    QList<Session *> sessions = JsonDataParser::parseListSessions(arr);
    m_formSessionList->updateListSessions(sessions);

    disconnect(&m_controller, 0, this, 0);
}

void MainWindow::showFormAddEditStudent(const Student &st)
{
    m_formAddStudent->loadInfo(st);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_actionListSessions_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
}
