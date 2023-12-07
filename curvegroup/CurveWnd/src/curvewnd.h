#ifndef CURVEWND_H
#define CURVEWND_H
#include "QWidget"
#include "QHBoxLayout"
#include "QList"
#include "seriesdata.h"
#include "qcustomplot.h"
#include "mark.h"
#include "maxwidget.h"
class CurveWnd: public QWidget
{
    Q_OBJECT
private:
    QCustomPlot *chartview;//图标
    QCPAxis  *axis_x,*axis_y;//坐标轴
    QList<SeriesData *> seriesdata;//数据
    int min_y,max_y;//y轴
    int max_point_num;//x轴的最大点
    int curve_num;//曲线数目
    QPen pen;//曲线画笔
    QStringList label;//标签
    void initChartView();//初始化图表
    QHBoxLayout *chart_layout;//图表布局
    void initLayout();//初始化布局
    void update();//数据更新
    QTimer *timer;//定时器更新数据
    void initTimer();//初始化定时器
    void timerEvent(QTimerEvent *event);//测试数据定时器

    Mark mark;//事件

    quint16 current_pos;// 当前点的位置
    Maxwidget  *maxwidget;// 曲线放大窗口
    void initMaxwidget();
    bool max_status=false; //放大状态
    quint8 max_id=0; //放大的曲线
    void Maxseries(QMouseEvent *event);//曲线最大化
public:
    explicit CurveWnd(QWidget*parent=nullptr);
    ~CurveWnd();
     void setConnect();
    //设置曲线数目
    void setCurveNum(int num);
    //更新曲线数目
    void updateCurveNum(int num);
    //设置显示的数目
    void setMaxPoint(int num);
    //设置曲线显示的标签
    void setCurveLabels(QStringList);
    //更新曲线显示的标签
    void updateCurveLabels(QStringList);

    //显示mark
    void appendMark(QString,int);
    //数据插入
    void append(QList<double> data);
//    void append(double *data,quint8 len);
    void clear();

    //测试数据
    void test_chart();

    void increaseScaleFactor();
    void reduceScaleFactor();

    int getCurveNum();

};
#endif  
