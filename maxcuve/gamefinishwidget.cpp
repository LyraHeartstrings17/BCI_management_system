﻿#include "gamefinishwidget.h"
#include "ui_gamefinishwidget.h"
GameFinishWidget::GameFinishWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameFinishWidget)
{
    ui->setupUi(this);
    init();
    setLayout();

}

GameFinishWidget::~GameFinishWidget()
{
    delete ui;

}

void GameFinishWidget::showWidget()
{

    data.readGameFinishData();
    QList<double> emotion_value=data.getEmotionValue();
    QList<double> periceive_value=data.getPericeiveValue();

    appendEmotionCurve(emotion_value);
    appendPericeiveCurve(periceive_value);
    qDebug()<<emotion_value;
    qDebug()<<data.getallEmotionValue();

    this->show();
}
void GameFinishWidget::showRadarWidget(){
    QList<double> emotion_value_all=data.getallEmotionValue();
    QList<double> periceive_value_all=data.getallPericeiveValue();

    setEmotionRadar(emotion_value_all);
    setPericeiveRadar(periceive_value_all);

    data.clearValue();
    this->show();
}
void GameFinishWidget::setGameFilePath(QString path)
{

    data.setPath(path);
}


void GameFinishWidget::appendEmotionCurve(QList<double> data)
{
    ui->emotion_curve->append(data);

}

void GameFinishWidget::appendPericeiveCurve(QList<double> data)
{
    ui->periceive_curve->append(data);

}
void GameFinishWidget::setEmotionRadar(QList<double> data)
{
    ui->emotion_radar->setData(data);
}

void GameFinishWidget::setPericeiveRadar(QList<double> data)
{
    ui->periceive_radar->setData(data);
}
void GameFinishWidget::init()

{
    //    qDebug()<<1;
    this->setWindowTitle("训练结算");
    //曲线
    ui->emotion_curve->setSeriesname({"应激强度","压力强度","士气水平","唤醒度","情绪属性"});
    ui->periceive_curve->setSeriesname({"视觉能力","听觉能力","注意能力","肢体协调能力","综合认知能力"});
    ui->emotion_radar->setRadarLabel({"应激强度","压力强度","士气水平","唤醒度","情绪属性"});
    ui->periceive_radar->setRadarLabel({"视觉能力","听觉能力","注意能力","肢体协调能力","综合认知能力"});

}

void GameFinishWidget::setLayout()
{
    //窗口大小
    this->setFixedSize(900,800);

    //曲线布局
    ui->curve_layout->setStretch(0,5);
    ui->curve_layout->setStretch(1,5);
//    ui->curve_layout->setStretch(2,5);
    ui->radar_layout->insertStretch(0,1);
    ui->radar_layout->insertStretch(3,1);
    ui->radar_layout->setStretch(1,4);
    ui->radar_layout->setStretch(2,4);

}
