#ifndef USERINFOSTRUCT_H
#define USERINFOSTRUCT_H
#include<QString>
typedef struct Info //定义作图的结构体
{
    QString account;
    QString name;
    QString age;
    QString nation ;
    QString sex ;
    QString handy ;
    QString work;
    QString education;
    QString phone;
    QString address;
    QString health;
    QString sport;
    QString game;
    QString entertainment;
    QString other;
} Info;
Q_DECLARE_METATYPE(Info)

#endif // USERINFOSTRUCT_H
