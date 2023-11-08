#ifndef SERIESDATA_H
#define SERIESDATA_H

#include <QObject>
#include "QPointF"
class SeriesData : public QObject
{
    Q_OBJECT
public:
    explicit SeriesData(QObject *parent = nullptr);
    void append(double data);
    QList<QPointF> getChartPoint()const;
    QList<QPointF> getRawPoint()const;
    void clear();
    void setId(int id);
    void setMaxPointNum(int);
    void setMin(int value);
    void setMax(int value);
    void increaseScaleFactor();
    void reduceScaleFactor();

    double getCurrent_data() const;

signals:
private:
    int max_point_num;
    int point_index;
    //曲线Id
    int Id;
    //曲线的最大值和最小值
    int max,min;
    QList<QPointF> raw_points;
    QList<QPointF> chart_point;
    //基准校验
    double base_sum=0;
    double base_line=0;
    double basecheck(double data);
    QList<double> queue;
    double current_data;//当前数据
};

#endif // SERIESDATA_H
