#include "formaddstudent.h"
#include "ui_formaddstudent.h"

FormAddStudent::FormAddStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAddStudent)
{
    ui->setupUi(this);
}

FormAddStudent::~FormAddStudent()
{
    delete ui;
}

void FormAddStudent::loadInfo(const Student &student)
{
    m_studentId = student.id();
}

void FormAddStudent::on_pbOk_clicked()
{
    Student st;
    st.setId(m_studentId);
    st.setSurMiddleName(ui->leSurName->text());
    st.setFirstName(ui->leFirstName->text());
    st.setClassName(ui->leClass->text());
    st.setSchool(ui->leSchool->text());
    st.setPhone(ui->lePhone->text());
    st.setReferral(ui->leReferral->text());
    st.setParentName(ui->leParentName->text());
    st.setStartDate(ui->dtStart->date());
    st.setTotalMoney(ui->spMoney->value());
    st.setNote(ui->teNote->document()->toPlainText());

    QJsonObject obj;
    st.writeJson(obj);
    bool isAdd = (m_studentId.isEmpty());
    emit sigSubmitStudentData(isAdd, obj);
}

void FormAddStudent::on_pbCancel_clicked()
{
    emit sigBack();
}
