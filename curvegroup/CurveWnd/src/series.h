#ifndef SERIES_H
#define SERIES_H

#include <QObject>
#include "QLineSeries"
#include "seriesdata.h"
#include "maxwidget.h"
#include "QPointF"
using namespace QtCharts;
class Series : public QObject
{
    Q_OBJECT
public:
    explicit Series(QObject *parent = nullptr);
    ~Series();
    void append(QList<double>);
    void setSeries(const QList<QAbstractSeries *> &value);
    QList<QPointF> getRawPoints(int Id);
    void setPen(QPen pen);
    void clear();
    void MaxSeries(int id,QString labels);
    void setMaxPointNum(int num);
    int  getCurrentPoint();
    void updateData();
    void increaseScaleFactor();
    void reduceScaleFactor();
    void getCurrentData();
signals:
    void CurrentData(QList<double>);
public slots:

private:
    QList<QAbstractSeries *> series;
    QList<SeriesData *> seriesdata;
    Maxwidget curvemax;
    int max_point_num;
    void setSeriesData();
    bool max_falg=false;
    int max_curve_id;
    //当前的采样点
    int current_point=0;
};

#endif // SERIES_H
