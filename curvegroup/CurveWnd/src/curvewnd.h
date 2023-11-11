#ifndef CURVEWND_H
#define CURVEWND_H
#include "QChart"
#include "QWidget"
#include "QChartView"
#include "QHBoxLayout"
#include "QList"
#include "QCategoryAxis"
#include "series.h"
#include "maxwidget.h"
#include "mark.h"
using namespace QtCharts;
class CurveWnd: public QWidget
{
    Q_OBJECT
private:
    /* data */
    //曲线数目
    int series_num;
    //
    int max_point_num;
    //曲线标签
    QStringList labels;
    //曲线数据
    Series series;
    //markxx
    Mark mark;
    //图表UI
    QChart *chart;
    //图表视图
    QChartView *view;
    //图标布局
    QHBoxLayout *layout;
    //x坐标
    QCategoryAxis *axisx;
    //y坐标
    QCategoryAxis *axisy;
    //定时器id
    int timerId = 0;
    //数据的最大值最小值
    int min,max;

    //画笔
    QPen  pen;

    void initParam();
    void mouseDoubleClickEvent(QMouseEvent *event);
    //设置x坐标范围
    void setAxisXRange(int start,int end);
    //设置y坐标范围
    void setAxisYRange(int start,int end);
    void timerEvent(QTimerEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
signals:
     void CurrentData(QList<double>);
public:
    explicit CurveWnd(QWidget*parent=nullptr);
    ~CurveWnd();
     void setConnect();
    //设置曲线数目
    void setCurveNum(int num);
    int  getCurveNum();
    //更新曲线数目
    void updateCurveNum(int num);
    //设置显示的数目
    void setMaxPoint(int num);
    //设置曲线显示的标签
    void setCurveLabels(QStringList);
    //更新曲线显示的标签
    void updateCurveLabels(QStringList);

    //显示mark
    void appendMark(QString);
    //重载传入event时间点
    void appendMark(QString mark,int latency);
    //数据插入
    void append(QList<double> data);
    void clear();
    //更新图表
    void updateChart();
    //测试数据
    void test_chart();

    void setMinMax(int,int);
    //设置放大因子
    void setScale(double value);

    void increaseScaleFactor();
    void reduceScaleFactor();

    // pen访问器
    QPen getPen();

    // chart访问器
    QChart* getChart();
};
#endif  
