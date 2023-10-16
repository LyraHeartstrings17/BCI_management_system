#include "register_info.h"
#include "ui_register_info.h"

Register_info::Register_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register_info)
{
    ui->setupUi(this);
}

Register_info::~Register_info()
{
    delete ui;
}

void Register_info::getAccount(QString _account)
{

    account=_account;
}

void Register_info::on_pushButton_saveInfo_clicked()
{
    Info info;
    //点击保存按钮。
    info.account=account;
    info.name=ui->lineEdit_name->text();
    info.age=ui->lineEdit_age->text();
    info.nation=ui->lineEdit_nation->text();
    info.sex=ui->lineEdit_sex->text();
    info.handy=ui->lineEdit_handy->text();
    info.work = ui->lineEdit_work->text();
    info.education=ui->lineEdit_education->text();
    info.phone=ui->lineEdit_phone->text();
    info.address=ui->lineEdit_address->text();
    info.health=ui->lineEdit_health->text();
    info.sport=ui->lineEdit_sport->text();
    info.game=ui->lineEdit_game->text();
    info.entertainment=ui->lineEdit_entertainment->text();
    QVariant DataVar;
    DataVar.setValue(info);

    emit sendRegisterInfo(DataVar);
}
