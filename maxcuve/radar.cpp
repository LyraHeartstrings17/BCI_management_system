#include "radar.h"
#include "ui_radar.h"

Radar::Radar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Radar)
{
    ui->setupUi(this);
    QUrl source("qrc:/res/radar.qml");
    ui->quickWidget->setSource(source);
    this->setFixedWidth(300);
}

Radar::~Radar()
{
    delete ui;
}

void Radar::setRadarLabel(QStringList labels)
{
    QMetaObject::invokeMethod((QObject*)ui->quickWidget->rootObject(), /* Qml实例 */
                              "setRadarLabel",         /* 函数名字 */
                              Qt::DirectConnection, /* 连接方式*/
                              Q_ARG(QVariant, labels));/* 输入参数 */
}

void Radar::setData(QList<double> data)
{
    QVariant value=QVariant::fromValue(data);
    QMetaObject::invokeMethod((QObject*)ui->quickWidget->rootObject(), /* Qml实例 */
                              "setData",         /* 函数名字 */
                              Qt::DirectConnection, /* 连接方式*/
                              Q_ARG(QVariant,value));/* 输入参数 */
}
