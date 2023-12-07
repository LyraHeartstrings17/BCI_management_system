#ifndef MARK_H
#define MARK_H

#include <QObject>
#include "qcustomplot.h"
class Mark : public QObject
{
    Q_OBJECT
public:
    explicit Mark(QObject *parent = nullptr);
    void append(QString,int pos);
    void updateMarkData();
//    void updateMarkAxis();

    void setChart(QCustomPlot *value);
    void setMax_y(int value);
    void setAxisScale(double value);
    void setMax_point_num(int value);
    void clear();
    void setMin_y(int value);

signals:

private:
//    QVector<double> tick;
//    QVector<QString> labels;
//    QSharedPointer<QCPAxisTickerText> textTicker;
    QList<QCPItemText*> labels;
    QCustomPlot *chart;
    QList<QCPGraph *> markseries;
    QList<int> current;
    int max_y,min_y;
    double axis_scale;
    int max_point_num;
    int flag = 1;
};

#endif // MARK_H
