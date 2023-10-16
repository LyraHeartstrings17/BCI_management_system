#include "mainwindow.h"
#include <QApplication>
#include <login.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login l;
    MainWindow m;
    l.show();
    //收到登录成功信号显示管理窗口
    MainWindow::connect(&l,&Login::LoginSucceedSignal,&m,&MainWindow::receiveLogin);
    //收到登出信号显示登录窗口
    MainWindow::connect(&m,&MainWindow::LogoutSignal,&l,&Login::receiveLogout);
    return a.exec();
}
