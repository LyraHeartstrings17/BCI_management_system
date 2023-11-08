#ifndef JSONOPERATION_H
#define JSONOPERATION_H

#include <QObject>
#include <QJsonArray>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include "UserInfoStruct.h"

class JsonOperation :public QObject
{
    Q_OBJECT
public:
    JsonOperation();



    //登录
    void landID(QString account,QString password,int isAutoLand,int isSavePassword);

    //注册
    void Register(QString account, QString password, int isAutoLand, int isSavePassword);

    void initLoginInfo(); //初始化界面账号信息

    //更换账号后更新有无保存密码
    void renewAccount(QString account);  //combox更换账号时更换账号的相关信息

    //将登录过的用户添加到combox_account
    void listAllAccount();

    //注册插入新的用户
    void insertNewAccount(QString,QString);

    //注册成功后，保存用户的详细信息
    void insertUserInfo(QVariant);

    bool checkPhoneRepeat(QString);

signals:
    void landSucceed(QString,QString); //登录成功
    void landFailed();  //登录失败
    void absentUserRegister(); //该用户没有注册
    void absentAnyUser();   //没有任何用户
    void initInfo(QString account, QString password,int isAutoLand, int isSavePassword);
    void renewAccountSignal(QString password, int isAutoLand, int isSavePassword);
    void listAllAccountSignal(QStringList);
    void registerFailed();  //注册失败，该用户已经存在
    void registerSucceed(QString);  //注册成功，该用户已经存入
    void UserInfoSaveSucceed();

private:
    QJsonArray *json;
    void JsonInsertLstLand(QString account, QString password, int isAutoLand, int isSavePassword);  //更新上一次登录LstLand信息
    void UpdataUser(QString account,int isAutoLand, int isSavePassword);  //更新用户user登录选择信息
};

#endif // JSONOPERATION_H
