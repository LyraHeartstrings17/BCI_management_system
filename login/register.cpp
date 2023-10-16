#include "register.h"
#include "ui_register.h"
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

}

Register::~Register()
{
    delete ui;
}

QString Register::SendAccount()
{
    return ui->lineEdit_phone->text();
}

void Register::ShowMessageBox(QString str)
{
    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,"error",str);
    QTimer::singleShot(2000,m_box,SLOT(accept()));
    m_box->exec();
}


void Register::closeEvent(QCloseEvent *event)
{
    //关闭注册页面，返回登录页面
    emit close_register();
    this->close();
}


void Register::on_pushButton_register_clicked()
{
    //发送注册信息
    if(ui->lineEdit_phone->text().count()==11){ //判断手机号是否未11个
        if ( (ui->lineEdit_password->text().count()>=8 && ui->lineEdit_password->text().count()<=20) ){ //判断密码是否在0到20位之间
            if ( (ui->lineEdit_password->text() == ui->lineEdit_repassword->text()) ){  //判断密码是否一样
                    emit sendRegister(ui->lineEdit_phone->text(),ui->lineEdit_password->text());
            }
            else{

                ShowMessageBox("两次密码输入不同");
            }
        }
        else{

            ShowMessageBox("密码长度错误");
        }
    }
    else{

        ShowMessageBox("手机号长度错误");
    }


}




























