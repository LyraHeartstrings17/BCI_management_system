#ifndef SERIESDATA_H
#define SERIESDATA_H

#include <QObject>

class SeriesData : public QObject
{
    Q_OBJECT
public:
    typedef   struct points
    {
        QVector<double> x;
        QVector<double> y;
        quint16 length;
    }Points;
    Points raw_points;
    Points chart_point;

    explicit SeriesData(QObject *parent = nullptr);
    void append(double data);
    void clear();
    void setId(int id);
    void setMaxPointNum(int);
    void setAxisYMinMax(int,int);
    void increaseScaleFactor();
    void reduceScaleFactor();
private:
    int max_point_num;
    int point_index;
    //曲线Id
    int Id;
    //曲线y轴
    int min_y,max_y;
    //数据的缩放
    float scale;
};

#endif // SERIESDATA_H
