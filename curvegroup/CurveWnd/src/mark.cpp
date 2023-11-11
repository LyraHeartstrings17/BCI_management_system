#include "mark.h"
#include "QGraphicsScene"
#include "QDebug"
Mark::Mark(QObject *parent) : QObject(parent)
{

}
void Mark::append(QString mark, int pos)
{
    current.append(0);
    //添加标线
    QLineSeries *series=new QLineSeries();
    QList<QAbstractAxis*> axis=chart->axes();
    chart->addSeries(series);
    series->attachAxis(axis[0]);
    series->attachAxis(axis[1]);
    markseries.append(series);
    QList<QPointF> points;
    QPointF point(pos,-1);
    points.append(point);
    point.setY(max_y);
    points.append(point);
    series->append(points);
    //添加标签
    QGraphicsTextItem *label=new QGraphicsTextItem(mark);
    label->setDefaultTextColor(Qt::white);
    label->setPos(pos*axis_scale,0);
    chart->scene()->addItem(label);
    marklabels.append(label);
}
void Mark::updateMarkData()
{
    if(current.isEmpty())
    {
        return;
    }
    int mark_num=current.size();
    for(int i=0;i<mark_num;i++)
    {
        current[i]++;
        if(current[i]==max_point_num)
        {
            current.removeAt(i);
            delete marklabels[i];
            marklabels.removeAt(i);
            chart->removeSeries(markseries[i]);
            delete  markseries[i];
            markseries.removeAt(i);
            mark_num--;

        }
    }
}

void Mark::updateMarkAxis()
{
    QList<QLineSeries *>::const_iterator begin=markseries.begin();
    QList<QGraphicsTextItem *>::const_iterator label_begin=marklabels.begin();
    int mark_num=current.size();
    for(int i=0;i<mark_num;i++)
    {
        (*label_begin)->setPos((*begin)->at(0).x()*axis_scale,0);
        begin++;
        label_begin++;
    }
}
void Mark::setChart(QChart *value)
{
     chart=value;
}

void Mark::setMax_y(int value)
{
    max_y = value;
}

void Mark::setAxisScale(double value)
{
    axis_scale = value;
}

void Mark::setMax_point_num(int value)
{
    max_point_num = value;
}

void Mark::clear()
{
    current.clear();
    qDeleteAll(marklabels);
    marklabels.clear();
    markseries.clear();
}
