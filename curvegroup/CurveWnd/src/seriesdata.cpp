#include "seriesdata.h"

SeriesData::SeriesData(QObject *parent) : QObject(parent)
{
    this->point_index=0;
    this->max_point_num=100;
    this->scale=1;
    this->raw_points.length=0;
    this->chart_point.length=0;
}
void SeriesData::append(double data)
{
    int data_length=chart_point.length;
    if (data_length<max_point_num)
    {
        this->raw_points.x.append(data_length);
        this->raw_points.y.append(data);
        this->raw_points.length++;
        this->chart_point.x.append(data_length);
        this->chart_point.y.append(data*scale+(max_y-min_y)*Id);
        this->chart_point.length++;
        return;
    }
    this->raw_points.y.replace(point_index,data);
    this->chart_point.y.replace(point_index,data*scale+(max_y-min_y)*Id);
    point_index++;
    point_index%=max_point_num;
}
void SeriesData::clear()
{
    raw_points.x.clear();
    raw_points.y.clear();
    raw_points.length=0;
    chart_point.x.clear();
    chart_point.y.clear();
    chart_point.length=0;
}

void SeriesData::setId(int id)
{
    this->Id=id;
}

void SeriesData::setMaxPointNum(int num)
{
    max_point_num=num;
}

void SeriesData::setAxisYMinMax(int min, int max)
{
    min_y=min;
    max_y=max;
}
void SeriesData::increaseScaleFactor()
{
    clear();
    if(scale<=10)
    {
        scale++;
    }

}
void SeriesData::reduceScaleFactor()
{
    clear();
    if(scale>1)
    {
         scale--;
    }
    else
    {
        if(scale>=0.5)
        {
           scale-=0.1;
        }
    }
}
