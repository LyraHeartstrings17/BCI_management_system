#ifndef CURVEGROUP_H
#define CURVEGROUP_H
#include "QWidget"
#include "curvewnd.h"
#include "seriespoint.h"
#include "QToolButton"
#include "mat.h"
class CurveGroup:public QWidget
{
    Q_OBJECT
public:
    explicit CurveGroup(QWidget *parent=nullptr);
    ~CurveGroup();
    void loadData();
    QStringList getChanlocs();
    //设置每组显示的曲线数目
    void setCurveNumGroup(int);
    //设置显示的曲线数目
    void setCurveNum(int num);
    //设置y的范围
    void setMinMax(int,int);
    //设置显示的数目
    void setMaxPoint(int);
    //设置标签
    void setCurveLabels(QStringList);
    //设置mark
    void appendMark(QString);
    //重载mark
    void appendMark(QString mark,int latency);
    //设置当前组别
    void setCurrentGroup(int);
    //设置当前组数
    void setGroupNum(int);
    //模拟数据
    void timerEvent(QTimerEvent *event);
    //修改缩放因子
    void setScale(int value);
    void increaseScale();
    void reduceScale();
    //修改通道数
    void reduceGroupChannel();
    void increaseGroupChannel();
    //测试数据
    void test_chart();
    //设置数据传入路径
    void setMatPath(QString);
    // curvewnd访问器
    CurveWnd *getCurveWnd();
    //停止绘图
    void stopDraw();
    int getTimerId();
    void setCurveStyle();
    void alldatainput();//自己加的一次性放出脑电数据
    void test_chart2();//一次性放出脑电数据
public slots:
    void next();
    void previous();
    void last();
    void append(QList<double>);
    void ResetData(bool flag);
signals:
    void first_group();
    void end_group();
    void CurrentData(QList<double>);
private:
    CurveWnd *curvewnd;
    QHBoxLayout *widget_layout;
    int curve_num_group;
    int curve_num;
    int group_num;
    int finalGroupNum;//上一次页面切换时每组曲线数
    double scale;
    int max_point;
    int index = 0;//数据引索
    MAT mat;//读mat数据
    QString path;//数据路径
    vector<double> data;//读出来的数据
    vector<QString> chanlocs;//读出来的联导名称
    int timerId = 0;//定时器id
    QList<SeriesPoint *> seriespoint;
    QStringList labels;
    int current_group;
    void init();
    void setConnect();
    void initLayout();
};

#endif // CURVEGROUP_H
