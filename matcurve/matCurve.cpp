#include "matCurve.h"
#include "ui_matCurve.h"
#include "QApplication"
MatCurve::MatCurve(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatCurve)
{
    ui->setupUi(this);
    // 连接五个按钮的clicked信号与槽函数
    connect(ui->pushButton, &QPushButton::clicked, this, &MatCurve::StartButtonClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MatCurve::PageUpButtonClicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MatCurve::PageDownButtonClicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MatCurve::ResetButtonClicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MatCurve::StopButtonClicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MatCurve::EndButtonClicked);
    connect(ui->pushButton_14, &QPushButton::clicked, this, &MatCurve::ShowButtonClicked);

}

//开始按钮
void MatCurve::StartButtonClicked()
{
    if(this->path.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("没有传入Mat数据路径,请先点击展示按钮");
        msgBox.setWindowTitle("请重试！");
        msgBox.exec();
        return;
    }
    //点击开始读入数据并画图
    //传入数据
    if(ui->widget->getTimerId()==0)//第一次点击开始
    {
        QMessageBox msgBox;
        msgBox.setText("要进行显示数据的切换请先点击结束按钮，随后在上方下拉框选择新的数据");
        msgBox.setWindowTitle("提示");
        msgBox.exec();
        ui->widget->loadData();
        QStringList list = ui->widget->getChanlocs();
        ui->widget->setMaxPoint(ui->widget->getPointNum()); // 设置曲线图显示的最大点数

        ui->widget->setCurveNumGroup(4); // 设置曲线图的分组数为4组

        ui->widget->setCurveNum(list.size()); // 设置每组曲线的数量

        ui->widget->setCurveLabels(list); // 设置每条曲线的标签

        ui->widget->test_chart();//进行绘图
    }
    else if(ui->widget->getTimerId()==-1){//重置时
        ui->widget->test_chart();
    }
    else if(ui->widget->getTimerId()==-2){//结束时
        ui->widget->loadData();
        QStringList list = ui->widget->getChanlocs();
        ui->widget->setMaxPoint(ui->widget->getPointNum()); // 设置曲线图显示的最大点数

        ui->widget->setCurveNum(list.size()); // 设置每组曲线的数量

        ui->widget->setCurveLabels(list); // 设置每条曲线的标签

        ui->widget->test_chart(); // 进行绘图
    }
}
//上一页按钮
void MatCurve::PageUpButtonClicked()
{
    if(this->path.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("没有传入Mat数据路径,请先点击展示按钮");
        msgBox.setWindowTitle("请重试！");
        msgBox.exec();
        return;
    }
    //点击查看上一页图
    ui->widget->previous();

}
//下一页按钮
void MatCurve::PageDownButtonClicked()
{
    if(this->path.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("没有传入Mat数据路径,请先点击展示按钮");
        msgBox.setWindowTitle("请重试！");
        msgBox.exec();
        return;
    }
    //点击查看下一页图
    ui->widget->next();

}
//重置按钮
void MatCurve::ResetButtonClicked()
{
    if(this->path.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("没有传入Mat路径,请先点击展示按钮");
        msgBox.setWindowTitle("请重试！");
        msgBox.exec();
        return;
    }
    //点击重新画图
    ui->widget->ResetData(0);
    ui->widget->test_chart();
}
//暂停按钮
void MatCurve::StopButtonClicked()
{
    if(this->path.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("没有传入Mat数据路径,请先点击展示按钮");
        msgBox.setWindowTitle("请重试！");
        msgBox.exec();
        return;
    }
    //点击暂停画图
     ui->widget->stopDraw();
}
//结束按钮
void MatCurve::EndButtonClicked()
{
     if(this->path.isEmpty())
     {
        QMessageBox msgBox;
        msgBox.setText("没有传入Mat数据路径,请先点击展示按钮");
        msgBox.setWindowTitle("请重试！");
        msgBox.exec();
        return;
     }
     ui->widget->ResetData(1);
}



void MatCurve::ShowButtonClicked()
{

     if(this->path.isEmpty())
     {
        QMessageBox msgBox;
        msgBox.setText("没有传入Mat数据路径,请先点击展示按钮");
        msgBox.setWindowTitle("请重试！");
        msgBox.exec();
        return;
     }
     //点击开始读入数据并画图
     //传入数据
     if(ui->widget->getTimerId()==0)//第一次点击开始
     {
        QMessageBox msgBox;
        msgBox.setText("要进行显示数据的切换请先点击结束按钮，随后在上方下拉框选择新的数据");
        msgBox.setWindowTitle("提示");
        msgBox.exec();
        ui->widget->loadData();
        QStringList list = ui->widget->getChanlocs();
        ui->widget->setMaxPoint(ui->widget->getPointNum()); // 设置曲线图显示的最大点数

        ui->widget->setCurveNumGroup(4); // 设置曲线图的分组数

        ui->widget->setCurveNum(list.size()); // 设置每组曲线的数量

        ui->widget->setCurveLabels(list); // 设置每条曲线的标签

        ui->widget->test_chart2(); //直接进行绘图

        ui->widget->loadEvent();//载入事件
     }
     else if(ui->widget->getTimerId()==-2){//切换要显示的脑电数据图
        ui->widget->loadData();
        QStringList list = ui->widget->getChanlocs();
        ui->widget->setMaxPoint(ui->widget->getPointNum()); // 设置曲线图显示的最大点数

        ui->widget->setCurveNum(list.size()); // 设置每组曲线的数量

        ui->widget->setCurveLabels(list); // 设置每条曲线的标签

        ui->widget->test_chart2(); // 直接进行绘图

        ui->widget->loadEvent();//载入事件
     }
}

void MatCurve::setDataPath(QString name)
{
    this->path = name;
    ui->widget->setMatPath(name);
}

MatCurve::~MatCurve()
{
    delete ui;
}
