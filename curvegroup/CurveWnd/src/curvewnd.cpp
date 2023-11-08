#include "curvewnd.h"
#include "math.h"
#include "QDebug"
void CurveWnd::setScale(double value)
{
}

void CurveWnd::increaseScaleFactor()
{
    series.clear();
    series.increaseScaleFactor();
}

void CurveWnd::reduceScaleFactor()
{
    series.clear();
    series.reduceScaleFactor();
}

void CurveWnd::initParam()
{
    //初始化控件
    //初始化图表
    this->chart=new QChart();
    this->chart->legend()->hide();
    this->chart->setMargins(QMargins(0,0,0,0));
    this->chart->setTheme(QChart::ChartThemeLight);
    //初始化图表视图
    this->view=new QChartView(this->chart);
    //初始化坐标
    this->axisx=new QCategoryAxis;
    this->axisx->setLabelsVisible(true);
    this->axisx->setLineVisible(true);
    this->chart->addAxis(axisx,Qt::AlignBottom);
    this->axisy=new QCategoryAxis;
    this->axisy->setLabelsVisible(true);
    this->chart->addAxis(axisy,Qt::AlignLeft);
    //初始化标记
    this->mark.setChart(chart);
    //初始化画笔
    this->pen.setColor(Qt::black);
    this->pen.setWidth(1);
    //初始化布局
    this->layout=new QHBoxLayout();
    this->layout->setMargin(0);
    this->layout->addWidget(view);
    this->setLayout(this->layout);
    //初始化参数
    this->max_point_num=50;
    this->max=0;
    this->min=0;
}
void CurveWnd::mouseDoubleClickEvent(QMouseEvent *event)
{
    int y=event->y();
    int curve_with=this->height()/this->series_num;
    int index=series_num-y/curve_with-1;
    series.MaxSeries(index,labels[index]);

}
CurveWnd::CurveWnd(QWidget*parent):QWidget(parent)
{
    initParam();
    setConnect();
}
CurveWnd::~CurveWnd()
{
    delete view;
    delete layout;
}

void CurveWnd::setConnect()
{
    connect(&series,&Series::CurrentData,this,&CurveWnd::CurrentData);
}
void CurveWnd::setAxisXRange(int start,int end)
{
    //设置x坐标的范围
    this->axisx->setRange(start,end);
    //设置最大显示数目
    this->max_point_num=end;
}
void CurveWnd::setAxisYRange(int start,int end)
{
    //设置y坐标的范围
    this->axisy->setRange(start,end);
}

void CurveWnd::timerEvent(QTimerEvent *event)
{
//    mark.updateMarkAxis();
    series.updateData();
}

void CurveWnd::resizeEvent(QResizeEvent *event)
{
    mark.setAxisScale(width()*1.0/max_point_num);
    mark.updateMarkAxis();
}

void CurveWnd::setMaxPoint(int num)
{
    this->max_point_num=num;
    this->axisx->setRange(0,num);
    series.setMaxPointNum(num);
    mark.setMax_point_num(num);
}
void CurveWnd::setCurveLabels(QStringList labels)
{
    //判定标签数目和曲线数目是否一致
    if (labels.size() != this->series_num)
    {
        throw QString("labels of size != curve of size");
    }
    //设置坐标标签
    for (int i = 0; i < this->series_num; i++)
    {
        this->axisy->append(labels[this->series_num-i-1], i * 2);
    }
    //使标签与坐标对齐
    this->axisy->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    this->labels=labels;
}

void CurveWnd::updateCurveLabels(QStringList labels)
{
    for (int i = 0; i < labels.size(); i++)
    {
        this->axisy->replaceLabel(this->labels[i],labels[i]);
    }

    this->labels=labels;
}
void CurveWnd::appendMark(QString mark)
{
    this->mark.append(mark,series.getCurrentPoint());
}
void CurveWnd::setCurveNum(int num)
{
    //设置y坐标大小
    this->setAxisYRange(-1, (num * 2) - 1);
    //设置曲线数目
    this->series_num=num;
    //初始化曲线数据
    for(int i=0;i<num;i++)
    {
        QLineSeries *curve=new QLineSeries();
        //设置曲线数据最大数目
        QPen pen;
        pen.setColor(QColor(22,184,243));
        curve->setPen(pen);
        chart->addSeries(curve);
        curve->attachAxis(axisx);
        curve->attachAxis(axisy);
    }
    series.setSeries(chart->series());
    mark.setMax_y(num*2);
    timerId = startTimer(100);
}

int CurveWnd::getCurveNum()
{
    return series_num;
}

void CurveWnd::updateCurveNum(int num)
{
    chart->removeAllSeries();
    mark.clear();
    for(QStringList::const_iterator begin=labels.begin();begin!=labels.end();begin++)
    {
        this->axisy->remove((*begin));
    }
    setCurveNum(num);
}

void CurveWnd::append(QList<double> data)
{
    mark.updateMarkData();
    series.append(data);
}

void CurveWnd::clear()
{
    series.clear();
}

void CurveWnd::setMinMax(int min, int max)
{
    this->min=min;
    this->max=max;
}

// pen访问器
QPen CurveWnd::getPen()
{
    return this->pen;
}

QChart *CurveWnd::getChart()
{
    return this->chart;
}

