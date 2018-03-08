#include "formstudentlist.h"
#include "ui_formstudentlist.h"

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
        ui->tableWidget->setItem(i, 0, itemIdx);

        QTableWidgetItem *itemSurname = new QTableWidgetItem;
        itemSurname->setText(st->surMiddleName());
        ui->tableWidget->setItem(i, 1, itemSurname);

        QTableWidgetItem *itemName = new QTableWidgetItem;
        itemName->setText(st->firstName());
        ui->tableWidget->setItem(i, 2, itemName);

        // continue

        QTableWidgetItem *itemDate = new QTableWidgetItem;
        itemDate->setText(st->startDate().toString("dd/MM/yyyy"));
        ui->tableWidget->setItem(i, 8, itemDate);

    }
}
