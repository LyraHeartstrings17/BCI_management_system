<<<<<<< HEAD
﻿//#pragma execution_character_set("utf-8")//防止乱码
#include "gamefinishwidget.h"
#include "ui_gamefinishwidget.h"
#include<QDebug>
=======
﻿#include "gamefinishwidget.h"
#include "ui_gamefinishwidget.h"
>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
GameFinishWidget::GameFinishWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameFinishWidget)
{
    ui->setupUi(this);
<<<<<<< HEAD
//    connect(ui->curveButton,&QPushButton::clicked,[=](){
//        ui->stackedWidget->setCurrentIndex(1);
//    });
//    connect(ui->radarButton,&QPushButton::clicked,[=](){
//        ui->stackedWidget->setCurrentIndex(0);
//    });
    connect(ui->switchButton,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(!ui->stackedWidget->currentIndex());
    });
    init();
    //setLayout();
=======
    init();
    //setLayout();

>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
}

GameFinishWidget::~GameFinishWidget()
{
    delete ui;
}

void GameFinishWidget::showWidget()
{
<<<<<<< HEAD

    data.readGameFinishData();
    QList<double> emotion_value=data.getEmotionValue();
    QList<double> periceive_value=data.getPericeiveValue();

    appendEmotionCurve(emotion_value);
    appendPericeiveCurve(periceive_value);
}
void GameFinishWidget::showRadarWidget(){
    QList<double> emotion_value_all=data.getallEmotionValue();
    QList<double> periceive_value_all=data.getallPericeiveValue();

    setEmotionRadar(emotion_value_all);
    setPericeiveRadar(periceive_value_all);
    this->data.clearValue();
}
void GameFinishWidget::setFinishFilePath(QString path)
{
    data.setBCIPath(path);
}
=======
    //数据读取
    data.readGameFinishData();
    QList<double> emotion_value=data.getEmotionValue();
    QList<double> periceive_value=data.getPericeiveValue();
    //数据输入
    setEmotionRadar(emotion_value);
    setPericeiveRadar(periceive_value);
    this->init();
    this->show();
}

>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
void GameFinishWidget::setGameFilePath(QString path)
{
    data.setPath(path);
}
<<<<<<< HEAD
//curve重置
void GameFinishWidget::resetEmotionCurve()
{
    ui->emotion_curve->clearData();
}

void GameFinishWidget::resetPericeiveCurve()
{
    ui->periceive_curve->clearData();
}
void GameFinishWidget::clearcurveData(){
    resetEmotionCurve();
    resetPericeiveCurve();
}


void GameFinishWidget::appendEmotionCurve(QList<double> data)
{
    ui->emotion_curve->append(data);
}

void GameFinishWidget::appendPericeiveCurve(QList<double> data)
{
    ui->periceive_curve->append(data);
}
=======
>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
void GameFinishWidget::setEmotionRadar(QList<double> data)
{
    ui->emotion_radar->setData(data);
}

void GameFinishWidget::setPericeiveRadar(QList<double> data)
{
    ui->periceive_radar->setData(data);
}
<<<<<<< HEAD
void GameFinishWidget::init()

{
    //    qDebug()<<1;
    this->setWindowTitle("训练结算");
    //曲线
    ui->emotion_curve->setSeriesname({"应激强度","压力强度","士气水平","唤醒度","情绪属性"});
    ui->periceive_curve->setSeriesname({"视觉能力","听觉能力","注意能力","肢体协调能力","综合认知能力"});
    ui->emotion_radar->setRadarLabel({"应激强度","压力强度","士气水平","唤醒度","情绪属性"});
    ui->periceive_radar->setRadarLabel({"视觉能力","听觉能力","注意能力","肢体协调能力","综合认知能力"});
=======

void GameFinishWidget::init()

{
    //名
    this->setWindowTitle("训练结算");

    //雷达
    ui->emotion_radar->setRadarLabel({"应激强度","压力强度","士气水平","唤醒度","情绪属性"});
    ui->periceive_radar->setRadarLabel({"视觉能力","听觉能力","注意能力","肢体协调能力","综合认知能力"});

>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
}

void GameFinishWidget::setLayout()
{
<<<<<<< HEAD
    //曲线布局
//    ui->curve_layout->setStretch(0,5);
//    ui->curve_layout->setStretch(1,5);
//    ui->radar_layout->insertStretch(0,1);
//    ui->radar_layout->insertStretch(3,1);
//    ui->radar_layout->setStretch(0,4);
//    ui->radar_layout->setStretch(1,4);
=======
    this->setFixedSize(1400,800);
//    //雷达图布局
//    ui->radar_layout->insertStretch(0,1);
//    ui->radar_layout->insertStretch(3,1);
//    ui->radar_layout->setStretch(1,4);
//    ui->radar_layout->setStretch(2,4);

>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
}
