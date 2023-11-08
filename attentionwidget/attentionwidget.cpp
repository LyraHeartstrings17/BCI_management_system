#pragma execution_character_set("utf-8")//防止乱码
#include "attentionwidget.h"
#include "ui_attentionwidget.h"
AttentionWidget::AttentionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttentionWidget)
{
    ui->setupUi(this);
    init();
    //setLayout();

}

AttentionWidget::~AttentionWidget()
{
    delete ui;
}

void AttentionWidget::showWidget()
{
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
void AttentionWidget::setFinishFilePath(QString path)
{
    data.setBCIPath(path);
}
void AttentionWidget::setGameFilePath(QString path)
{
    data.setPath(path);
}
void AttentionWidget::setEmotionRadar(QList<double> data)
{
    ui->emotion_radar->setData(data);
}

void AttentionWidget::setPericeiveRadar(QList<double> data)
{
    ui->periceive_radar->setData(data);
}

void AttentionWidget::init()

{
    //名
    this->setWindowTitle("训练结算");

    //雷达
    ui->emotion_radar->setRadarLabel({"应激强度","压力强度","士气水平","唤醒度","情绪属性"});
    ui->periceive_radar->setRadarLabel({"视觉能力","听觉能力","注意能力","肢体协调能力","综合认知能力"});

}

void AttentionWidget::setLayout()
{
    this->setFixedSize(1400,800);
//    //雷达图布局
//    ui->radar_layout->insertStretch(0,1);
//    ui->radar_layout->insertStretch(3,1);
//    ui->radar_layout->setStretch(1,4);
//    ui->radar_layout->setStretch(2,4);

}
