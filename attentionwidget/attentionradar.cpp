#pragma execution_character_set("utf-8")//防止乱码
#include "attentionradar.h"
#include "ui_attentionradar.h"

AttentionRadar::AttentionRadar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttentionRadar)
{
    ui->setupUi(this);
    QUrl source("qrc:/res/radar.qml");
    ui->quickWidget->setSource(source);
    this->setFixedWidth(300);
}

AttentionRadar::~AttentionRadar()
{
    delete ui;
}

void AttentionRadar::setRadarLabel(QStringList labels)
{
    QMetaObject::invokeMethod((QObject*)ui->quickWidget->rootObject(), /* Qml实例 */
                              "setRadarLabel",         /* 函数名字 */
                              Qt::DirectConnection, /* 连接方式*/
                              Q_ARG(QVariant, labels));/* 输入参数 */
}

void AttentionRadar::setData(QList<double> data)
{
    QVariant value=QVariant::fromValue(data);
    QMetaObject::invokeMethod((QObject*)ui->quickWidget->rootObject(), /* Qml实例 */
                              "setData",         /* 函数名字 */
                              Qt::DirectConnection, /* 连接方式*/
                              Q_ARG(QVariant,value));/* 输入参数 */
}
