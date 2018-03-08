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
        m_formAddStudent->loadInfo(st);
        ui->stackedWidget->setCurrentIndex(1);
    });
    ui->stackedWidget->setCurrentIndex(-1);

    m_formAddStudent = new FormAddStudent;
    ui->stackedWidget->addWidget(m_formAddStudent);
    connect(m_formAddStudent, &FormAddStudent::sigBack, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(m_formAddStudent, SIGNAL(sigSubmitStudentData(bool,QJsonObject)),
            this, SLOT(onSubmitStudentData(bool,QJsonObject)));

    requestData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::requestData()
{
    QString query = QString("%1/students").arg(m_baseUrl);
    connect(&m_controller, SIGNAL(sigRecvDataArray(QJsonArray)),
            this, SLOT(onRecvStudentsData(QJsonArray)));
    m_controller.sendRequestGET(query, WebserviceController::JSON_ARR);
}

void MainWindow::on_stackedWidget_currentChanged(int idx)
{
    switch (idx) {
    case 0: {     // form student management

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
    QString postQuery = QString("%1/students/%2").arg(m_baseUrl).arg( (isAdd)? "add":"update");
    m_controller.sendRequestPOST(postQuery, obj);
}
