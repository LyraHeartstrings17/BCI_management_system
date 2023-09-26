#include "login.h"
#include "ui_login.h"
#include<QPushButton>
#include<QDebug>
#include<QMessageBox>
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    //登录逻辑
    connect(ui->logBtn,&QPushButton::clicked,[=](){
        QString username = ui->userName->text();
        QString userpassword = ui->userPassword->text();
        qDebug()<<username<<userpassword;
        //是否登录成功判断
        if(username == "adm" && userpassword == "123456")
        {
            this->close();
            emit this->successLogin();
        }
        else
        {
            //登陆失败警告
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("请重试！");
            msgBox.setWindowTitle("用户名和密码不匹配");
            msgBox.exec();
        }
    });
    //取消逻辑
    connect(ui->cancelBtn,&QPushButton::clicked,[=](){
        this->close();
    });
}

login::~login()
{
    delete ui;
}
