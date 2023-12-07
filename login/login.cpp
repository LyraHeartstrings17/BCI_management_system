//#pragma execution_character_set("utf-8")//防止乱码
#include "login.h"
#include "ui_login.h"

#include <QComboBox>
#include <QDebug>
#include "QThread"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);


//    qRegisterMetaType<Info>("Info&");

    //设置窗口不显示标题、不显示边框
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);

    initParams();

    initInfo();

    initRegisterInfo();

    initTimer();

    setLoginConnect();


}

Login::~Login()
{
    delete ui;
    delete timer;
    delete timer2;
}

void Login::show()
{
    QWidget::show();
    timer2->start();
}

void Login::initParams(){
    jsonOperation= new JsonOperation;
    register_1 = new Register;
    register_info =  new Register_info;
}

void Login::initRegisterInfo()
{
    connect(register_info,&Register_info::sendRegisterInfo,jsonOperation,&JsonOperation::insertUserInfo);
    connect(jsonOperation,&JsonOperation::UserInfoSaveSucceed,this,[=](){
        ShowMessageBox("注册成功","注册成功");
        register_info->close();
        this->show();
    });
}


//拖拽操作
void Login::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event->globalPos();
        //mouseStartPoint = event->pos();
        //获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

void Login::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag)
    {
        //获得鼠标移动的距离
        QPoint distance = event->globalPos() - mouseStartPoint;
        //QPoint distance = event->pos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
}

void Login::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}



void Login::initInfo()
{
    //初始化时的账号设置
    connect(jsonOperation,&JsonOperation::initInfo,this,[=](QString account, QString password, int isAutoLand, int isSavePassword){
        ui->lineEdit_account->setText(account);
        ui->lineEdit_password->setText(password);
        ui->checkBox_autoLand->setChecked(isAutoLand);
        ui->checkBox_savePassword->setChecked(isSavePassword);
        this->account=account;
    });

    //更换账号时的出发函数
    connect(ui->comboBox_account,&QComboBox::currentTextChanged,this,[=](){
        ui->lineEdit_account->setText(ui->comboBox_account->currentText());
        jsonOperation->renewAccount(ui->comboBox_account->currentText());
    });

    //更改账号后的密码和设置更改
    connect(jsonOperation,&JsonOperation::renewAccountSignal,this,[=](QString password, int isAutoLand, int isSavePassword){
        ui->lineEdit_password->setText(password);
        ui->checkBox_autoLand->setChecked(isAutoLand);
        ui->checkBox_savePassword->setChecked(isSavePassword);
    });

    //将所有登录过的账号添加到combox_account中
    connect(jsonOperation,&JsonOperation::listAllAccountSignal,this,[=](QStringList accountList){
        for(int i=0 ;i<accountList.size();i++){
            ui->comboBox_account->addItem(accountList[i]);
        }
    });

    jsonOperation->listAllAccount();

    jsonOperation->initLoginInfo();

}

void Login::setLoginConnect()
{
    connect(jsonOperation,&JsonOperation::absentAnyUser,this,[=](){
        ShowMessageBox("登录失败","还没有任何用户注册");
    });
    connect(jsonOperation,&JsonOperation::absentUserRegister,this,[=](){
        ShowMessageBox("登录失败","该用户未注册");
    });
    connect(jsonOperation,&JsonOperation::landFailed,this,[=](){
        ShowMessageBox("登录失败","密码错误");
    });
    connect(jsonOperation,&JsonOperation::landSucceed,this,[=](){
        emit LoginSucceedSignal();
        this->close();
    });
}

void Login::initTimer()
{
    timer=new QTimer();
    timer->setInterval(3000);
    timer->setSingleShot(true);
    connect(timer,&QTimer::timeout,this,[=](){
//         qDebug()<<loggingin_state;
         if(loggingin_state)
         {
             emit LoginSucceedSignal();
         }
    });
    timer2=new QTimer();
    timer2->setInterval(1000);
    timer2->setSingleShot(true);
    connect(timer2,&QTimer::timeout,this,[=](){
            autoLogin();
    });
}

void Login::ShowMessageBox(QString str1,QString str)
{
    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,str1,str);
    QTimer::singleShot(1500,m_box,SLOT(accept()));
    m_box->exec();
    delete m_box;
}

void Login::autoLogin()
{
    if(ui->checkBox_autoLand->isChecked())
    {
        //emit this->LoginSucceedSignal();
        //this->close();
    }
}



void Login::on_pushButton_register_clicked()
{
    connect(jsonOperation,&JsonOperation::registerFailed,this,[=](){
        //注册失败
        register_1->ShowMessageBox("该号码已被注册");
    });
    connect(jsonOperation,&JsonOperation::registerSucceed,this,[=](QString account){
        //注册成功，进入用户编辑信息界面
        register_info->getAccount(account);
        register_info->show();
        register_1->close();
        this->hide();
    });


    //点击注册槽

    register_1->show();
    this->hide();
    connect(register_1,&Register::close_register,this,[=](){
        this->show();
    });
    connect(register_1,&Register::sendRegister,jsonOperation,&JsonOperation::insertNewAccount);  //验证正确的密

}

void Login::on_pushButton_close_clicked()
{
    //点击关闭窗口
    this->close();
}

void Login::on_pushButton_min_clicked()
{
    //点击最小化窗口
    this->showMinimized();
}

void Login::on_pushButton_land_clicked()
{

    QString account = ui->lineEdit_account->text();
    QString password= ui->lineEdit_password->text();
    int isAutoLand = ui->checkBox_autoLand->isChecked();
    int isSavePassword = ui->checkBox_savePassword->isChecked();

    jsonOperation->landID(account,password,isAutoLand,isSavePassword);
}
void Login::receiveLogout()
{
    this->show();
}
