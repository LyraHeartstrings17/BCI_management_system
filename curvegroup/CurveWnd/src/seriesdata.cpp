#include "seriesdata.h"
#include "QPointF"
SeriesData::SeriesData(QObject *parent) : QObject(parent)
{
    this->point_index=0;
    this->max_point_num=100;
    this->max=100;
    this->min=-100;
}
void SeriesData::append(double data)
{
    QList<QPointF> series_point=chart_point;
    if (series_point.size()<max_point_num)
    {
        //原始数据
        QPointF point(series_point.size(), data);
        this->raw_points.append(point);

//         queue.append(data);
        //图标显示数据
        data=data/(max-min);
        point.setY(data+2*Id);
        this->chart_point.append(point);

        return;
    }
    if (point_index == max_point_num)
    {
        point_index = 0;

    }
//    //更新基线
//    if(queue.size()==max_point_num)
//    {
//        QList<double> queue=this->queue.mid(this->queue.size()-50);
//        base_line=std::accumulate(queue.begin(),queue.end(),0)/50;
//        queue.clear();
//    }
//    queue.append(data);

//    data=basecheck(data);
//    current_data=data;
    //原始数据
    QPointF point(point_index, data);
    this->raw_points.replace(point_index,point);

    //图标显示数据
    data=data/(max-min);
    point.setY(data+2*Id);
    this->chart_point.replace(point_index, point);

    point_index++;
}

QList<QPointF> SeriesData::getChartPoint() const
{
    return chart_point;
}

QList<QPointF> SeriesData::getRawPoint() const
{
    return raw_points;
}

void SeriesData::clear()
{
    raw_points.clear();
    chart_point.clear();
}

void SeriesData::setId(int id)
{
    this->Id=id;
}

void SeriesData::setMaxPointNum(int num)
{
    max_point_num=num;
}

void SeriesData::setMin(int value)
{
    min = value;
}

void SeriesData::setMax(int value)
{
    max = value;
}

void SeriesData::increaseScaleFactor()
{
    if(max>=50)
    {
        max/=1.5;
        min/=1.5;
    }
}

void SeriesData::reduceScaleFactor()
{
    if(max<=100)
    {
        max*=1.5;
        min*=1.5;
    }
}
double SeriesData::basecheck(double data)
{
    if(chart_point.size()==max_point_num)
    {
        data-=base_line;
    }
    return data;
}

double SeriesData::getCurrent_data() const
{
    return current_data;
}
