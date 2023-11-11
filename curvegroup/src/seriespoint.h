#ifndef SERIESPOINT_H
#define SERIESPOINT_H
#include "QPointF"
#include "QObject"
class SeriesPoint:public QObject
{
public:
	SeriesPoint();
	~SeriesPoint();
    void append(double);
	QList<QPointF> points();
	void setMaxPointNum(int);
private:
	int max_point_num=50;
	int point_index = 0;
	QList<QPointF> series_point;
};
#endif // !SERIESPOINT_H
