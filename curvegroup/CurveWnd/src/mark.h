#ifndef MARK_H
#define MARK_H

#include <QObject>
#include "QAbstractAxis"
#include "QLineSeries"
#include "QScatterSeries"
#include "QtCharts/QChart"
using namespace QtCharts;
class Mark : public QObject
{
    Q_OBJECT
public:
    explicit Mark(QObject *parent = nullptr);
    void append(QString,int pos);
    void updateMarkData();
    void updateMarkAxis();

    void setChart(QChart *value);
    void setMax_y(int value);
    void setAxisScale(double value);

    void setMax_point_num(int value);

    void clear();

signals:

private:
    QChart *chart;
    QList<QLineSeries *> markseries;
    QList<QGraphicsTextItem*> marklabels;
    QList<int> current;
    int max_y;
    double axis_scale;
    int max_point_num;
};

#endif // MARK_H
