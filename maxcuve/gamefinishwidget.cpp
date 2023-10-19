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

void GameFinishWidget::showWidget()
{

    data.readGameFinishData();
    QList<double> emotion_value=data.getEmotionValue();
    QList<double> periceive_value=data.getPericeiveValue();

    appendEmotionCurve(emotion_value);
    appendPericeiveCurve(periceive_value);


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

void GameFinishWidget::init()

{
    //    qDebug()<<1;
    this->setWindowTitle("训练结算");
    //曲线
    ui->emotion_curve->setSeriesname({"应激强度","压力强度","士气水平","唤醒度","情绪属性"});
    ui->periceive_curve->setSeriesname({"视觉能力","听觉能力","注意能力","肢体协调能力","综合认知能力"});


}

void GameFinishWidget::setLayout()
{
    //窗口大小
    this->setFixedSize(800,800);

    //曲线布局
    ui->curve_layout->setStretch(0,5);
    ui->curve_layout->setStretch(1,5);
//    ui->curve_layout->setStretch(2,5);


}
