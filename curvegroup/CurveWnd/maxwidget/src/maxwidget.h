#ifndef MAXWIDGET_H
#define MAXWIDGET_H

#include "QWidget"
#include "qcustomplot.h"
#include "curveproperty.h"
class Maxwidget:public QWidget
{
    Q_OBJECT
public:
    explicit Maxwidget(QWidget *parent=nullptr);
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
    void setPoint(double x,double y);
    void setPoints(QVector<double>,QVector<double>);
private:
    //图表
    QCustomPlot *chart;
    //坐标轴
    QCPAxis *axis_x;
    QCPAxis *axis_y;
    //曲线
    QCPGraph *series;
    //属性表
    CurveProperty *curveproperty;
    //窗口布局
    QHBoxLayout *widget_layout;
    //
    QPen pen;
    //标题
    QCPTextElement *m_title;
    int max_point_num;
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
