#include "jsonoperation.h"

#include <QFile>


JsonOperation::JsonOperation()

{

}

void JsonOperation::landID(QString account, QString password, int isAutoLand, int isSavePassword)
{

    // 1、首先完成账号密码验证是否正确。  注：没有账号的需要先完成注册
    // 2、其次如果验证成功则保存登录密码。
    QString filename = "userInfo.json";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);  //有就打开，没有就新建。
    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));
    file.close();

    QJsonObject obj= jdc.object(); //获取json数据

    if(obj.contains("user")){
        QJsonObject userAll=(obj.find("user"))->toObject();
//        qDebug()<<"userAll:"<<userAll;
        if(userAll.contains(account)){
            QJsonObject user=(userAll.find(account))->toObject();
            if(password == user.value("password").toString()){
                QJsonObject onceInfo=(user.find("info"))->toObject();
                QString name = onceInfo.value("name").toString();
                emit landSucceed(account,name);
//                qDebug()<<"登录成功:::::::::::::"<<user;
//                qDebug()<<"登录成功:::::::::::::"<<onceInfo;
//                qDebug()<<"登录成功:::::::::::::"<<name;
                JsonInsertLstLand(account,password,isAutoLand,isSavePassword);
                UpdataUser(account,isAutoLand,isSavePassword);
            }
            else {
//                qDebug()<<"登录失败";
                emit landFailed();
            }
        }
        else{
//            qDebug()<<"该用户未注册";
            emit absentUserRegister();

        }
    }
    else{
//        qDebug()<<"没有用户注册";
        emit absentAnyUser();
    }



//    QJsonDocument doc(obj);
//    QByteArray json=doc.toJson();
//    file.open(QFile::WriteOnly);
//    file.write(json);
//    file.close();
}

void JsonOperation::Register(QString account, QString password, int isAutoLand, int isSavePassword)
{
    QString filename = "userInfo.json";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));  //有就打开，没有就新建。
    file.close();

    QJsonObject obj_user= jdc.object(); //用户这个字典
    QJsonObject obj_userTemp = jdc.object();
    QJsonObject obj_userInfoTemp = jdc.object();



    QJsonObject obj_lastLand= jdc.object();  //上次登录字典
    QJsonObject obj= jdc.object();

    obj.insert("isAutoLand",isAutoLand); //0或1
    obj.insert("isSavePassword",isSavePassword);
    obj.insert("lastAccount",account);  //这次登录的账号
    if(isSavePassword){
        //保存密码到配置文件
        obj.insert(account,password);
    }
    else{
        obj.insert(account,"");
    }

    QJsonDocument doc(obj);
    QByteArray json=doc.toJson();
    file.open(QFile::WriteOnly);
    file.write(json);
    file.close();
}

void JsonOperation::initLoginInfo()
{
    // 2、其次如果验证成功则保存登录密码。
    QString filename = "userInfo.json";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);  //有就打开，没有就新建。
    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));
    file.close();

    QJsonObject obj= jdc.object(); //获取json数据

    QString account; QString password; int isAutoLand; int isSavePassword;

    if(obj.contains("lastLand")){
        QJsonObject lastLand=(obj.find("lastLand"))->toObject();
        account = lastLand.value("lastaccount").toString();
        password = lastLand.value("password").toString();
        isSavePassword = lastLand.value("isSavePassword").toInt();
        isAutoLand = lastLand.value("isAutoLand").toInt();
        emit initInfo(account,password,isAutoLand,isSavePassword);
    }
}

void JsonOperation::renewAccount(QString account)
{
    QString filename = "userInfo.json";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);  //有就打开，没有就新建。
    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));
    file.close();

    QJsonObject obj= jdc.object(); //获取json数据

    if(obj.contains("user")){
        QJsonObject userAll=(obj.find("user"))->toObject();
        if(userAll.contains(account)){
            QJsonObject user=(userAll.find(account))->toObject();

            QString password;
            if(user.value("isSavePassword").toInt()){
                password= user.value("password").toString();
            }
            else {
                password="";
            }
            int isAutoLand = user.value("isAutoLand").toInt();
            int isSavePassword = user.value("isSavePassword").toInt();
            emit renewAccountSignal(password,isAutoLand,isSavePassword);

        }
    }
}

void JsonOperation::listAllAccount()
{
    QString filename = "userInfo.json";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);  //有就打开，没有就新建。
    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));
    file.close();

    QJsonObject obj= jdc.object(); //获取json数据

    if(obj.contains("user")){
        QJsonObject userAll=(obj.find("user"))->toObject();
        QStringList accountList=userAll.keys();
        emit listAllAccountSignal(accountList);
    }
}

void JsonOperation::insertNewAccount(QString account,QString password)
{
    QString filename = "userInfo.json";
    QFile file(filename);
//    file.open(QIODevice::ReadOnly); //不会创建
    file.open(QIODevice::ReadWrite);

    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));  //有就打开，没有就新建。
    file.close();

    QJsonObject obj= jdc.object(); //用户这个字典
    QJsonObject newOnes; //新的用户载体

//    newOnes.insert("account",account);  //字典名就是账号了，所以不需要添加account
    newOnes.insert("password",password);
    newOnes.insert("isAutoLand",0);
    newOnes.insert("isSavePassword",0);

    if(obj.contains("user")){
        QJsonObject userAll=(obj.find("user"))->toObject();
        if(userAll.contains(account)){
           emit registerFailed();
        }
        else {

           userAll.insert(account,newOnes);

           obj.insert("user",userAll);
           QJsonDocument doc(obj);
           QByteArray json=doc.toJson();
           file.open(QFile::WriteOnly);
           file.write(json);
           file.close();
           emit registerSucceed(account);

        }
    }
    else{
        QJsonObject userAll ;
        userAll.insert(account,newOnes);
        obj.insert("user",userAll);
        QJsonDocument doc(obj);
        QByteArray json=doc.toJson();
        file.open(QFile::WriteOnly);
        file.write(json);
        file.close();
        emit registerSucceed(account);

    }


}

void JsonOperation::insertUserInfo(QVariant _info)
{
    Info info = _info.value<Info>();

    QString filename = "userInfo.json";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));  //有就打开，没有就新建。
    file.close();

    QJsonObject obj= jdc.object(); //用户这个字典
    QJsonObject jsonInfo;
    jsonInfo.insert("name",info.name);
    jsonInfo.insert("age",info.age);
    jsonInfo.insert("nation",info.nation);
    jsonInfo.insert("sex",info.sex);
    jsonInfo.insert("handy",info.handy);
    jsonInfo.insert("work",info.work);
    jsonInfo.insert("education",info.education);
    jsonInfo.insert("phone",info.phone);
    jsonInfo.insert("address",info.address);
    jsonInfo.insert("health",info.health);
    jsonInfo.insert("sport",info.sport);
    jsonInfo.insert("game",info.game);
    jsonInfo.insert("entertainment",info.entertainment);
    jsonInfo.insert("other",info.other);

    if(obj.contains("user")){
        QJsonObject userAll=(obj.find("user"))->toObject();
        if(userAll.contains(info.account)){
            QJsonObject user=(userAll.find(info.account))->toObject();

            user.insert("info",jsonInfo);
            userAll.insert(info.account,user);
            obj.insert("user",userAll);

            QJsonDocument doc(obj);
            QByteArray json=doc.toJson();
            file.open(QFile::WriteOnly);
            file.write(json);
            file.close();

            emit UserInfoSaveSucceed();
        }
    }

}

bool JsonOperation::checkPhoneRepeat(QString account)
{
    QString filename = "userInfo.json";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);  //有就打开，没有就新建。
    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));
    file.close();

    QJsonObject obj= jdc.object(); //获取json数据

    if(obj.contains("user")){
        QJsonObject userAll=(obj.find("user"))->toObject();
//        qDebug()<<"userAll:"<<userAll;
        return userAll.contains(account);
        }
    return false;
}

void JsonOperation::JsonInsertLstLand(QString account, QString password, int isAutoLand, int isSavePassword)
{
    QString filename = "userInfo.json";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));  //有就打开，没有就新建。
    file.close();

    QJsonObject obj= jdc.object(); //用户这个字典
    QJsonObject newOnes;

    newOnes.insert("lastaccount",account);
    if(isSavePassword){
        newOnes.insert("password",password);
    }
    else {
        newOnes.insert("password","");
    }
    newOnes.insert("isAutoLand",isAutoLand);
    newOnes.insert("isSavePassword",isSavePassword);

    obj.insert("lastLand",newOnes);

    QJsonDocument doc(obj);
    QByteArray json=doc.toJson();
    file.open(QFile::WriteOnly);
    file.write(json);
    file.close();

}

void JsonOperation::UpdataUser(QString account, int isAutoLand, int isSavePassword)
{
    QString filename = "userInfo.json";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));  //有就打开，没有就新建。
    file.close();

    QJsonObject obj= jdc.object();

    if(obj.contains("user")){
        QJsonObject userAll=(obj.find("user"))->toObject();
        if(userAll.contains(account)){
            QJsonObject user=(userAll.find(account))->toObject();
            user.insert("isAutoLand",isAutoLand);
            user.insert("isSavePassword",isSavePassword);

            userAll.insert(account,user);
            obj.insert("user",userAll);

        }
    }

    QJsonDocument doc(obj);
    QByteArray json=doc.toJson();
    file.open(QFile::WriteOnly);
    file.write(json);
    file.close();
}
