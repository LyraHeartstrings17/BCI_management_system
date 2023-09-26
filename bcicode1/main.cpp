#include "mainwindow.h"
#include<login.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login l;
    MainWindow m;
    l.show();
    //收到登录成功信号显示管理窗口
    MainWindow::connect(&l,&login::successLogin,&m,&MainWindow::receiveLogin);
    return a.exec();
}
