#include "seriespoint.h"
SeriesPoint::SeriesPoint()
{
}

SeriesPoint::~SeriesPoint()
{
}
void SeriesPoint::append(double data)
{

	if (this->series_point.size() < max_point_num)
	{
		QPointF point(this->series_point.size(), data);
		this->series_point.append(point);
		return;
	}
	if (point_index == max_point_num)
	{
		point_index = 0;
	}
	QPointF point(point_index, data);
	this->series_point.replace(point_index, point);
	point_index++;
}

QList<QPointF> SeriesPoint::points()
{
	return this->series_point;
}

void SeriesPoint::setMaxPointNum(int num)
{
	this->max_point_num = num;
}
