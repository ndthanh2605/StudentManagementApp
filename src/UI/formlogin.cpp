#include "formlogin.h"
#include "ui_formlogin.h"

FormLogin::FormLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormLogin)
{
    ui->setupUi(this);
}

FormLogin::~FormLogin()
{
    delete ui;
}

void FormLogin::on_tbLogin_clicked()
{
    if (ui->leEmail->text() == "admin@gmail.com"
            && ui->lePassword->text() == "admin123") {
        emit sigLoginSucceed();
    }
}
