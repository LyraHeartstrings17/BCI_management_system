#ifndef MAXWIDGET_H
#define MAXWIDGET_H

#include "QWidget"
#include "QtCharts"
#include "QChartView"
#include "QHBoxLayout"
#include "QValueAxis"
#include "curveproperty.h"
#include "QPointF"
#include "QVariant"
using namespace QtCharts;
class Maxwidget:public QWidget
{
    Q_OBJECT
public:
    Maxwidget();
     ~Maxwidget();
    //设置图表标题
    void setText(QString);
    //设置X,Y坐标范围
    void setRangeX(int start,int end);
    void setRangeY(int start,int end);
    void clear();
    int  point_size();
signals:
    void closed();
public slots:
    //设置曲线数据
    void setPoint(QPointF data);
    void setPoint(int index,QPointF data);
    void setPoints(QList<QPointF> data);
private:
    //图标
    QChartView *view;
    QChart *chart;
    QValueAxis *axisx;
    QValueAxis *axisy;

    QLineSeries *series;
     //画笔
    QPen  pen;
    //属性表
    CurveProperty *curveproperty;
    //窗口布局
    QHBoxLayout *widget_layout;

    void init();
    void initLayaout();
    void setConnect();
    void closeEvent(QCloseEvent *event);
private slots:
    //处理背景颜色修改
    void backgroudValueChange(QtProperty *property,const QVariant &value);
    //处理X坐标发生改变
    void axiasXValueChange(QtProperty *property,const QVariant &value);
    //处理X坐标发生改变
    void axiasYValueChange(QtProperty *property,const QVariant &value);
    //坐标标签颜色发生改变
    void fontValueChange(QtProperty *property,const QVariant &value);
    //曲线颜色发生改变
    void curveColorValueChange(QtProperty *property,const QVariant &value);
    //曲线宽度发生改变
    void curveWidthValueChange(QtProperty *property,const QVariant &value);
    //曲线纵坐标发生改变
    void axisYRangeChange(QtProperty *property,const QVariant &value);
};

#endif // MAXWIDGET_H
