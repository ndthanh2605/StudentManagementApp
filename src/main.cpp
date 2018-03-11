#include "mainwindow.h"
#include <QApplication>

#include "UI/formlogin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FormLogin frmLogin;
    MainWindow w;

    frmLogin.show();

    QObject::connect(&frmLogin, &FormLogin::sigLoginSucceed, [&frmLogin, &w]() {
        frmLogin.hide();
        w.show();
    });
    QObject::connect(&w, &MainWindow::sigLogOut, [&frmLogin, &w]() {
        frmLogin.show();
        w.hide();
    });

    return a.exec();
}
