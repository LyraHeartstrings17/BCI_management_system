#include "series.h"
#include "QPointF"
Series::Series(QObject *parent) : QObject(parent)
{
}

Series::~Series()
{
    qDeleteAll(seriesdata);
    seriesdata.clear();
}
void Series::append(QList<double> data)
{
    if(current_point==max_point_num)
    {
        current_point=0;
    }
    else
    {
       current_point++;
    }

    if(series.isEmpty())
    {
        QT_THROW(QString("series don't init"));
    }
    else
    {
        QList<double>::const_iterator begin=data.begin();
        for(auto data:seriesdata)
        {
            data->append(*begin);
            begin++;
        }
        getCurrentData();
    }
}

void Series::setSeries(const QList<QAbstractSeries *> &value)
{
    series = value;
    setSeriesData();
}

QList<QPointF> Series::getRawPoints(int Id)
{
    return seriesdata[Id]->getRawPoint();
}

void Series::setPen(QPen pen)
{
    for(auto curve:series)
    {
        QLineSeries *serie=(QLineSeries *)curve;
        serie->setPen(pen);
    }
}

void Series::clear()
{
    //采样点置零
    current_point=0;
    QList<QAbstractSeries*>::const_iterator begin=series.begin();
    for(auto data:seriesdata)
    {
        QLineSeries *curve=(QLineSeries *)(*begin);
        curve->clear();
        data->clear();
        begin++;
    }
}

void Series::MaxSeries(int id, QString labels)
{
    max_falg=true;
    max_curve_id=id;
    curvemax.setRangeX(0,max_point_num);
    curvemax.setText(labels);
    curvemax.clear();
    curvemax.setPoints(seriesdata[id]->getRawPoint());
    curvemax.show();
}

void Series::setMaxPointNum(int num)
{
    this->max_point_num=num;
}

int Series::getCurrentPoint()
{
    return current_point;
}

void Series::updateData()
{
    QList<QAbstractSeries*>::const_iterator begin=series.begin();
    for(auto data:seriesdata)
    {
        QLineSeries *curve=(QLineSeries *)(*begin);
        curve->replace(data->getChartPoint());
        begin++;
    }
    if(max_falg)
    {
        curvemax.setPoints(seriesdata[max_curve_id]->getRawPoint());
    }
}

void Series::increaseScaleFactor()
{
    int series_num=seriesdata.size();
    for(int i=0;i<series_num;i++)
    {
        seriesdata[i]->increaseScaleFactor();
    }
}

void Series::reduceScaleFactor()
{
    int series_num=seriesdata.size();
    for(int i=0;i<series_num;i++)
    {
        seriesdata[i]->reduceScaleFactor();
    }
}

void Series::getCurrentData()
{
    QList<double> data;
    int series_num=seriesdata.size();
    for(int i=0;i<series_num;i++)
    {
        data.append(seriesdata[i]->getCurrent_data());
    }
    emit CurrentData(data);

}

void Series::setSeriesData()
{
    if(!seriesdata.isEmpty())
    {
        qDeleteAll(seriesdata);
        seriesdata.clear();
    }
    int curve_num=series.size();
    for(int i=0;i<curve_num;i++)
    {
        SeriesData *data=new SeriesData;
        data->setMaxPointNum(max_point_num);
        data->setId(i);
        seriesdata.append(data);
    }
}
