#include "maxwidget.h"

Maxwidget::Maxwidget()
{
    init();
}

Maxwidget::~Maxwidget()
{
    delete  view;
    delete  curveproperty;
    delete  widget_layout;
}

void Maxwidget::setText(QString text)
{
    this->chart->setTitle(text);
    this->curveproperty->setTitle(text);
}

void Maxwidget::setRangeX(int start, int end)
{
    this->axisx->setRange(start,end);
}

void Maxwidget::setRangeY(int start, int end)
{
    this->axisy->setRange(start,end);
}

void Maxwidget::clear()
{
    this->series->clear();
}

int Maxwidget::point_size()
{
    return this->series->points().size();
}

void Maxwidget::setPoint(QPointF data)
{
    this->series->append(data);
}

void Maxwidget::setPoint(int index, QPointF data)
{
    this->series->replace(index,data);
}

void Maxwidget::setPoints(QList<QPointF> data)
{
//    this->series->clear();
    this->series->replace(data);
}

void Maxwidget::init()
{
    this->view=new QChartView();
    this->chart=new QChart();
    this->chart->legend()->hide();
    this->axisx=new QValueAxis();
    this->axisy=new QValueAxis();
    this->series=new QLineSeries();
    this->curveproperty=new CurveProperty();

    this->view->setChart(chart);

    chart->addAxis(axisx,Qt::AlignBottom);
    chart->addAxis(axisy,Qt::AlignLeft);
    //曲线绑定坐标
    chart->addSeries(series);
    series->attachAxis(axisx);
    series->attachAxis(axisy);
    initLayaout();
    setConnect();
}

void Maxwidget::initLayaout()
{
    this->widget_layout=new QHBoxLayout();
    widget_layout->setMargin(0);
    this->widget_layout->addWidget(view,7);
    this->widget_layout->addWidget(curveproperty,3);
    this->setLayout(widget_layout);
}

void Maxwidget::setConnect()
{
    connect(curveproperty,&CurveProperty::backgroudValueChange,this,&Maxwidget::backgroudValueChange);
    connect(curveproperty,&CurveProperty::axiasXValueChange,this,&Maxwidget::axiasXValueChange);
    connect(curveproperty,&CurveProperty::axiasYValueChange,this,&Maxwidget::axiasYValueChange);
    connect(curveproperty,&CurveProperty::fontValueChange,this,&Maxwidget::fontValueChange);
    connect(curveproperty,&CurveProperty::curveColorValueChange,this,&Maxwidget::curveColorValueChange);
    connect(curveproperty,&CurveProperty::curveWidthValueChange,this,&Maxwidget::curveWidthValueChange);
    connect(curveproperty,&CurveProperty::axisYRangeChange,this,&Maxwidget::axisYRangeChange);
}
void Maxwidget::closeEvent(QCloseEvent *event)
{
    emit closed();
}
void Maxwidget::backgroudValueChange(QtProperty *property, const QVariant &value)
{
    if(property->propertyName()=="背景颜色")
    {
       this->chart->setBackgroundBrush(value.value<QColor>());
    }
}

void Maxwidget::axiasXValueChange(QtProperty *property, const QVariant &value)
{
    if(property->propertyName()=="x坐标轴颜色")
    {
        this->axisx->setLinePenColor(value.value<QColor>());
    }

}

void Maxwidget::axiasYValueChange(QtProperty *property, const QVariant &value)
{
    if(property->propertyName()=="y坐标轴颜色")
    {
        this->axisy->setLinePenColor(value.value<QColor>());
    }
}

void Maxwidget::fontValueChange(QtProperty *property, const QVariant &value)
{
    if(property->propertyName()=="字体颜色")
    {
        this->axisx->setLabelsColor(value.value<QColor>());
        this->axisy->setLabelsColor(value.value<QColor>());
    }
}

void Maxwidget::curveColorValueChange(QtProperty *property, const QVariant &value)
{
    if(property->propertyName()=="曲线颜色")
    {
        this->pen.setColor(value.value<QColor>());
        series->setPen(pen);
    }
}

void Maxwidget::curveWidthValueChange(QtProperty *property, const QVariant &value)
{
    if(property->propertyName()=="曲线宽度")
    {
        this->pen.setWidth(value.value<int>());
        series->setPen(pen);
    }
}

void Maxwidget::axisYRangeChange(QtProperty *property, const QVariant &value)
{
    if(property->propertyName()=="纵坐标")
    {
        if(value.toSize().width()>0)
        {
            this->axisy->setRange(-value.toSize().width(),value.toSize().height());
        }
        else
        {
            this->axisy->setRange(value.toSize().width(),value.toSize().height());
        }
    }


}
