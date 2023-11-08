#ifndef Login_H
#define Login_H

#include "register.h"
#include "register_info.h"
#include "jsonoperation.h"

#include <QWidget>
#include <QMouseEvent>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTimer>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>


namespace Ui { class Login; }


class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void show();

    int aaaa = 0;
public slots:
    void receiveLogout();//登出
private slots:
    void on_pushButton_register_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_land_clicked();

    void initParams();
    void initRegisterInfo();
    void ShowMessageBox(QString,QString);

    void autoLogin();


signals:
    void LoginSucceedSignal();  //登录成功的信号



private:

    Ui::Login *ui;

    //拖拽窗口函数
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    //register
    Register *register_1;

    //register_info
    Register_info *register_info;


    //拖拽窗口变量
    bool        m_bDrag;
    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;

    //初始化变量
    void initInfo();
    JsonOperation *jsonOperation;
    void setLoginConnect();

    QTimer *timer;

    QTimer *timer2;
    void initTimer();


    //登录状态
    bool loggingin_state;

    //登录账号
    QString account;
    //用户名
    QString name;



};
#endif // Login_H
