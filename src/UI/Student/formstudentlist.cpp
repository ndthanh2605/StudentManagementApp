#include "formstudentlist.h"
#include "ui_formstudentlist.h"

#include <QPushButton>

FormStudentList::FormStudentList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormStudentList)
{
    ui->setupUi(this);
}

FormStudentList::~FormStudentList()
{
    delete ui;
}

void FormStudentList::updateListStudents(const QList<Student *> &students)
{
    m_model.setListStudents(students);
    refreshUi();
}

Student *FormStudentList::getStudentInfo(const QString &id)
{
    return m_model.getStudent(id);
}

void FormStudentList::on_tbAdd_clicked()
{
    emit sigAddStudent();
}

void FormStudentList::refreshUi()
{
    ui->tableWidget->setRowCount(0);
    QList<Student *> students = m_model.getListStudents();
    for (int i = 0; i < students.size(); ++i) {
        ui->tableWidget->insertRow(i);

        Student * const st = students.at(i);
        QTableWidgetItem *itemIdx = new QTableWidgetItem;
        itemIdx->setText(QString::number(i+1));
        itemIdx->setData(Qt::UserRole, st->id());
        ui->tableWidget->setItem(i, 0, itemIdx);

        QTableWidgetItem *itemSurname = new QTableWidgetItem;
        itemSurname->setText(st->surMiddleName());
        ui->tableWidget->setItem(i, 1, itemSurname);

        QTableWidgetItem *itemName = new QTableWidgetItem;
        itemName->setText(st->firstName());
        ui->tableWidget->setItem(i, 2, itemName);

        // continue with other attributes

        QTableWidgetItem *itemDate = new QTableWidgetItem;
        itemDate->setText(st->startDate().toString("dd/MM/yyyy"));
        ui->tableWidget->setItem(i, 8, itemDate);

        QPushButton *pbEdit = new QPushButton("Sửa");
        connect(pbEdit, &QPushButton::clicked, this, [this, st]() {
            emit sigEditStudent(st->id());
        });
        ui->tableWidget->setCellWidget(i, 9, pbEdit);

        QPushButton *pbDel = new QPushButton("Xóa");
        connect(pbDel, &QPushButton::clicked, this, [this, st]() {
            emit sigDeleteStudent(st->id());
        });
        ui->tableWidget->setCellWidget(i, 10, pbDel);
    }
}
