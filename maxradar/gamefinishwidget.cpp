#include "gamefinishwidget.h"
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
void  GameFinishWidget::readData(){
    data.readGameFinishData();

}
void GameFinishWidget::showWidget()
{
    //数据读取
//    data.readGameFinishData();
    QList<double> emotion_value=data.getEmotionValue();
    QList<double> periceive_value=data.getPericeiveValue();
    //数据输入
    setEmotionRadar(emotion_value);
    setPericeiveRadar(periceive_value);
    //clear
    data.clearValue();
    this->show();
}

void GameFinishWidget::setGameFilePath(QString path)
{
    data.setPath(path);
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
    //名
    this->setWindowTitle("训练结算");

    //雷达
    ui->emotion_radar->setRadarLabel({"应激强度","压力强度","士气水平","唤醒度","情绪属性"});
    ui->periceive_radar->setRadarLabel({"视觉能力","听觉能力","注意能力","肢体协调能力","综合认知能力"});

}

void GameFinishWidget::setLayout()
{
    this->setFixedSize(1400,800);
    //雷达图布局
    ui->radar_layout->insertStretch(0,1);
    ui->radar_layout->insertStretch(3,1);
    ui->radar_layout->setStretch(1,4);
    ui->radar_layout->setStretch(2,4);

}
