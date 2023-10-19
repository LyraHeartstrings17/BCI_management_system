#include "curve.h"
#include "ui_curve.h"
#include "QUrl"
Curve::Curve(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Curve)
{
    ui->setupUi(this);
    QUrl source("qrc:/res/curve.qml");
    ui->quickWidget->setSource(source);
    this->setFixedWidth(800);
}

Curve::~Curve()
{
    delete ui;
}

void Curve::setSeriesname(QStringList labels)
{
    QMetaObject::invokeMethod((QObject*)ui->quickWidget->rootObject(), /* Qml实例 */
                              "setSeriesname",         /* 函数名字 */
                              Qt::DirectConnection, /* 连接方式*/
                              Q_ARG(QVariant, labels));/* 输入参数 */
}

void Curve::append(QList<double> data)
{
    QVariant value=QVariant::fromValue(data);
    QMetaObject::invokeMethod((QObject*)ui->quickWidget->rootObject(), /* Qml实例 */
                              "append",         /* 函数名字 */
                              Qt::DirectConnection, /* 连接方式*/
                              Q_ARG(QVariant,value));/* 输入参数 */
}
