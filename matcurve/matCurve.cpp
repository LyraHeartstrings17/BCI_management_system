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
}

//开始按钮
void MatCurve::StartButtonClicked()
{
    this->update();
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
        //qDebug()<<this->path;
        //QApplication app(); // 创建QApplication对象，用于管理应用程序的事件循环
        ui->widget->loadData();
        QStringList list = ui->widget->getChanlocs();
        ui->widget->setMaxPoint(1000); // 设置曲线图显示的最大点数为1000个

        ui->widget->setCurveNumGroup(4); // 设置曲线图的分组数为4组

        ui->widget->setCurveNum(list.size()); // 设置每组曲线的数量为10条

        ui->widget->setCurveLabels(list); // 设置每条曲线的标签

        ui->widget->test_chart(); // 进行曲线图的测试（根据具体实现，可能是用于生成测试数据）

        ui->widget->appendMark("123"); // 向主窗口添加标记（根据具体实现，可能是用于在曲线图中添加特定的标记）

        //app.exec(); // 运行应用程序的事件循环，等待事件的发生并响应
    }
    else if(ui->widget->getTimerId()==-1){
        ui->widget->test_chart();
    }
    else if(ui->widget->getTimerId()==-2){
        ui->widget->loadData();
        QStringList list = ui->widget->getChanlocs();

        ui->widget->setCurveNum(list.size()); // 设置每组曲线的数量为10条

        ui->widget->setCurveLabels(list); // 设置每条曲线的标签

        ui->widget->test_chart(); // 进行曲线图的测试（根据具体实现，可能是用于生成测试数据）
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
    ui->widget->previous();//该函数还有问题

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
void MatCurve::setDataPath(QString name)
{
    this->path = name;
    ui->widget->setMatPath(name);
}

MatCurve::~MatCurve()
{
    delete ui;
}
