#include "mark.h"
#include "QGraphicsScene"
#include "QDebug"
Mark::Mark(QObject *parent) : QObject(parent)
{
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
//    this->textTicker=textTicker;
}
void Mark::append(QString mark, int pos)
{
    current.append(0);
    //添加标线
    QCPGraph *series=chart->addGraph(chart->xAxis,chart->yAxis);
    markseries.append(series);
    series->setPen(QPen(Qt::red));
    series->addData(pos,min_y);
    series->addData(pos,max_y-60);
    //添加标签
    QCPItemText *label=new QCPItemText(chart);
    label->setPositionAlignment(Qt::AlignTop|Qt::AlignCenter);
    label->setText(mark);
    label->position->setType(QCPItemPosition::ptPlotCoords);
    if(max_y-50*flag>min_y)
    {
        label->position->setCoords(pos,max_y-50*flag);
        flag+=1;
    }
    else
    {
        flag=1;
        label->position->setCoords(pos,max_y-50*flag);
        flag+=1;
    }
    label->setFont(QFont("Arial", 12));
    label->setColor(Qt::white);
    chart->replot();
    labels.append(label);
//    tick.append(pos);
//    labels.append(mark);
//    textTicker->setTicks(tick,labels);
//    chart->xAxis->setTicker(textTicker);

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
//            tick.remove(i);
//            labels.remove(i);
//            textTicker->setTicks(tick,labels);
//            chart->xAxis2->setTicker(textTicker);

            chart->removeItem(labels[i]);
            labels.removeAt(i);
            chart->removeGraph(markseries[i]);
            markseries.removeAt(i);
            mark_num--;

        }
    }
}

//void Mark::updateMarkAxis()
//{
//    QList<QLineSeries *>::const_iterator begin=markseries.begin();
//    QList<QGraphicsTextItem *>::const_iterator label_begin=marklabels.begin();
//    int mark_num=current.size();
//    for(int i=0;i<mark_num;i++)
//    {
//        (*label_begin)->setPos((*begin)->at(0).x()*axis_scale,0);
//        begin++;
//        label_begin++;
//    }
//}
void Mark::setChart(QCustomPlot *value)
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
    int mark_num=current.size();
    for(int i=0;i<mark_num;i++)
    {
        current[i]++;
        if(current[i]==max_point_num)
        {
            current.removeAt(i);
            //            tick.remove(i);
            //            labels.remove(i);
            //            textTicker->setTicks(tick,labels);
            //            chart->xAxis2->setTicker(textTicker);

            chart->removeItem(labels[i]);
            labels.removeAt(i);
            chart->removeGraph(markseries[i]);
            markseries.removeAt(i);
            mark_num--;

        }
    }
    markseries.clear();
    current.clear();
//    labels.clear();


//    chart->replot();
}

void Mark::setMin_y(int value)
{
    min_y = value;
}
