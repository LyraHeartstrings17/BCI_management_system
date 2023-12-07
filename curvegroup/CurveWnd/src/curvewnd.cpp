#include "curvewnd.h"
void CurveWnd::initChartView()
{
    chartview=new QCustomPlot(this);
    chartview->plotLayout()->setMargins(QMargins(width()*0.01,0,0,0));
    QColor color("#25262F");
    chartview->setBackground(color);
    axis_x=chartview->xAxis;
    axis_y=chartview->yAxis;
    this->min_y=-100;
    this->max_y=100;
    this->max_point_num=3000;
    axis_x->setRange(0,max_point_num);
    //设置y轴不可见
    axis_x->setVisible(false);
    axis_x->grid()->setVisible(false);
    QPen pen(QColor("#25262F"));
    axis_x->setBasePen(pen);
    axis_y->setBasePen(pen);
    axis_y->setTickLabelColor(Qt::white);
    //曲线属性
    this->pen.setColor(QColor(0,170,255,255));
    //标记
    mark.setChart(chartview);

    connect(chartview,&QCustomPlot::mouseDoubleClick,this,&CurveWnd::Maxseries);
}

void CurveWnd::initLayout()
{
    chart_layout=new QHBoxLayout;
    chart_layout->setMargin(0);
    chart_layout->addWidget(chartview);
    this->setLayout(chart_layout);
}

void CurveWnd::update()
{
    this->pen.setColor(QColor(0,170,255,255));
    for(int i=0;i<seriesdata.size();i++)
    {
        QVector<double> x=seriesdata[i]->chart_point.x;
        QVector<double> y=seriesdata[i]->chart_point.y;
        chartview->graph(i)->setData(x,y);
    }
    this->chartview->replot();

    QVector<double> x=seriesdata.at(max_id)->raw_points.x;
    QVector<double> y=seriesdata.at(max_id)->raw_points.y;
    maxwidget->setPoints(x,y);
}

void CurveWnd::initTimer()
{
    timer=new QTimer;
    connect(timer,&QTimer::timeout,this,[=](){
       update();
    });
}

void CurveWnd::timerEvent(QTimerEvent *event)
{
    QList<double> data;
    int y=rand();
//    for(int j=0;j<10;j++)
//    {
//        for (int i = 0; i < this->curve_num; i++)
//        {
//            double chart_data = 5*cos(3.14 * y)+2*cos(3.14*y*2);
//            data.append(chart_data);
//        }
//        this->append(data);
//    }
    static int i=30;
    i--;
    if(i%10==0&&i>0)
    {
        //appendMark("123");
    }

}

void CurveWnd::initMaxwidget()
{
    maxwidget=new Maxwidget();
    maxwidget->setWindowFlag(Qt::Dialog);
}

void CurveWnd::Maxseries(QMouseEvent *event)
{
    int y=event->y();
    int curve_with=this->height()/this->curve_num;
    max_id=curve_num-y/curve_with-1;
    max_status=true;
    maxwidget->setText(label[max_id]);
    maxwidget->setRangeX(0,max_point_num);
    maxwidget->show();
}
CurveWnd::CurveWnd(QWidget *parent):QWidget(parent)
{
    initChartView();
    initMaxwidget();
    initTimer();
    initLayout();
}
CurveWnd::~CurveWnd()
{
    delete chartview;
    delete chart_layout;
    delete timer;
    if(!seriesdata.isEmpty())
    {
        qDeleteAll(seriesdata.begin(),seriesdata.end());
        seriesdata.clear();
    }

}
void CurveWnd::setCurveNum(int num)
{
    for(int i=0;i<num;i++)
    {

        QCPGraph *curve=chartview->addGraph(axis_x,axis_y);
        curve->setPen(pen);

        //曲线数据
        SeriesData* data=new SeriesData;
        data->setId(i);
        data->setAxisYMinMax(min_y,max_y);
        data->setMaxPointNum(max_point_num);
        seriesdata.append(data);
    }
    this->curve_num=num;
    axis_y->setRange(min_y,num*(max_y-min_y)+min_y);
    //设置mark的属性
    mark.setMax_y(num*(max_y-min_y)+min_y);
    mark.setMin_y(min_y);
    mark.setMax_point_num(max_point_num);

    this->timer->start(50);

}

void CurveWnd::updateCurveNum(int num)
{

    chartview->clearGraphs();
    qDeleteAll(seriesdata.begin(),seriesdata.end());
    seriesdata.clear();
    setCurveNum(num);
}

void CurveWnd::setMaxPoint(int num)
{
    this->max_point_num=num;
    this->axis_x->setRange(0,num);
}

void CurveWnd::setCurveLabels(QStringList label)
{
    this->label=label;
    QVector<double> ticks;
    for(int i=0;i<curve_num;i++)
    {
        ticks.append(i*(max_y-min_y));
    }
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    QVector<QString> labels=label.toVector();
    textTicker->setTicks(ticks,label.toVector());
    axis_y->setTicker(textTicker);
}

void CurveWnd::updateCurveLabels(QStringList labels)
{
    setCurveLabels(labels);
}

void CurveWnd::appendMark(QString event,int pos)
{
    mark.append(event,pos);
}

void CurveWnd::append(QList<double> data)
{

    mark.updateMarkData();
    for(int i=0;i<seriesdata.size();i++)
    {
        seriesdata[i]->append(data[i]);
    }

    current_pos++;
    current_pos=current_pos%max_point_num;
}

void CurveWnd::clear()
{

    for(auto data:seriesdata)
    {
       data->clear();
    }

}

void CurveWnd::test_chart()
{

    this->startTimer(1);
}

void CurveWnd::increaseScaleFactor()
{
    for(auto data:seriesdata)
    {
       data->increaseScaleFactor();
    }
}
void CurveWnd::reduceScaleFactor()
{
    for(auto data:seriesdata)
    {
       data->reduceScaleFactor();
    }
}

int CurveWnd::getCurveNum()
{
    return curve_num;
}
