#include "curvegroup.h"
#define defalut_curve_num 4
#define defalut_max_point 1000
CurveGroup::CurveGroup(QWidget *parent):QWidget(parent)
{
    init();
    initLayout();
}

CurveGroup::~CurveGroup()
{
    delete  curvewnd;
}

void CurveGroup::init()
{
    curvewnd=new CurveWnd(this);
    widget_layout=new QHBoxLayout;
    this->curvewnd->lower();
    this->curve_num_group=defalut_curve_num;
    this->curve_num=defalut_curve_num;
    this->group_num=0;
    this->max_point=defalut_max_point;
    this->current_group=1;
    this->scale=1;
}
void CurveGroup::initLayout()
{
    this->widget_layout->addWidget(curvewnd);
    this->setLayout(widget_layout);
}
void CurveGroup::setCurveNumGroup(int num)
{
    this->curve_num_group=num;
    this->curvewnd->setCurveNum(num);
}

void CurveGroup::setCurveNum(int num)
{
    this->curve_num=num;
    if(this->curve_num>0)
    {
        if(curve_num%curve_num_group==0)
        {
            this->group_num=curve_num/curve_num_group;
            this->finalGroupNum = curve_num_group;
        }
        else
        {
            this->group_num=curve_num/curve_num_group+1;
            this->finalGroupNum = curve_num%curve_num_group;
        }
        //qDebug()<<this->group_num;
        //qDebug()<<this->finalGroupNum;
    }
}
void CurveGroup::setMaxPoint(int num)
{
    this->max_point=num;
    this->curvewnd->setMaxPoint(num);
}

void CurveGroup::setCurveLabels(QStringList labels)
{
    this->labels=labels;
    QStringList show_labels;
    for(int i=0;i<curve_num_group;i++)
    {
        show_labels.append(labels[i+(current_group-1)*curve_num_group]);
    }
    //qDebug()<<show_labels;
    this->curvewnd->updateCurveNum(show_labels.size());//在切换页面时切换标签
    this->curvewnd->setCurveLabels(show_labels);
}

void CurveGroup::setCurrentGroup(int num)
{
    this->current_group=num;
}

void CurveGroup::setGroupNum(int num)
{
    this->group_num=num;

}

void CurveGroup::appendMark(QString mark,int latency)
{
    curvewnd->appendMark(mark,latency);
}
void CurveGroup::append(QList<double> data)
{
    if(data.isEmpty())
    {
        return;
    }
    QList<double> show_data;
    QList<double>::const_iterator begin=data.begin();
    QList<double>::const_iterator::difference_type n=(current_group-1)*curve_num_group;
    int num=curve_num-(current_group-1)*curve_num_group;
    for(int i=0;(i<curve_num_group)&&(i<num);i++)
    {
        show_data.append(*(begin+n));
        begin++;
    }
    curvewnd->append(show_data);
}
void CurveGroup::next()
{
    if(current_group==group_num)
    {
        QMessageBox msgBox;
        msgBox.setText("这是最后一页");
        msgBox.setWindowTitle("切换页面失败");
        msgBox.exec();
        return;
    }
    else
    {
        this->index = 0;//重置引索
        this->curvewnd->clear();
        this->current_group++;
        QStringList show_labels;
        for(int i=0;i<curve_num_group;i++)
        {
            if(i+(current_group-1)*curve_num_group>=this->curve_num)
            {
                break;
            }
            show_labels.append(labels[i+(current_group-1)*curve_num_group]);
        }
        //qDebug()<<show_labels<<this->current_group<<group_num;
        if(current_group==group_num)//如果翻到了最后一页
        {
            //更新通道数
            curvewnd->updateCurveNum(show_labels.size());
            //更新通道名字
            curvewnd->setCurveLabels(show_labels);
        }
        else
        {
            //qDebug()<<current_group;
            this->curvewnd->updateCurveLabels(show_labels);
        }
    }
}
//查看上一页
void CurveGroup::previous()
{
    if(current_group == 1)
    {
        QMessageBox msgBox;
        msgBox.setText("这是第一页");
        msgBox.setWindowTitle("切换页面失败");
        msgBox.exec();
        return; // 如果当前组已经是第一组，直接返回，无法查看上一页
    }
    else
    {
        this->index = 0;//重置引索
        this->curvewnd->clear(); // 清空曲线窗口中的内容
        this->current_group--; // 减少当前组编号
        QStringList show_labels; // 创建一个字符串列表用于存储要显示的通道名称
        for(int i = 0; i < curve_num_group; i++)
        {
            int index = i + (current_group - 1) * curve_num_group;
            if (index >= labels.size()||index<0)
            {
                break; // 避免越界访问
            }
            show_labels.append(labels[index]); // 将上一页的通道名称添加到列表中
            //show_labels.append(labels[i+(current_group-1) * curve_num_group]); // 将上一页的通道名称添加到列表中
        }
        //qDebug()<<show_labels.size();
        if(current_group+1 == group_num)//最后一页的上一页
        {
            // 更新曲线窗口中的通道数为实际显示的通道数量
            curvewnd->updateCurveNum(show_labels.size());
            // 更新曲线窗口中的通道名称
            curvewnd->setCurveLabels(show_labels);
        }
        else
        {
            this->curvewnd->updateCurveLabels(show_labels); // 更新曲线窗口中的通道名称
        }
    }
}
//重置数据
void CurveGroup::ResetData(bool flag)
{
    this->curvewnd->clear();

    //this->seriespoint.clear();
    if(timerId>=0){
        this->killTimer(timerId);
        if(!flag)
        {
            timerId=-1;//重置或者暂停
        }
        else
        {
            this->current_group = 1;//将组设为1
            timerId=-2;//结束
            qDebug()<<timerId;
        }
    }
    this->index = 0;
}
//停止画图
void CurveGroup::stopDraw(){
    if(timerId!=-1){
        this->killTimer(timerId);
        timerId=-1;//重置或者暂停
    }
}
//模拟数据传入
void CurveGroup::timerEvent(QTimerEvent *event)
{
    QList<double> inputData;
    for (int i = 0; i < this->curve_num; i++)
    {
        if(this->index>=this->max_point)
        {
            this->stopDraw();
            QMessageBox msgBox;
            msgBox.setText("请点击重置按钮重新绘图");
            msgBox.setWindowTitle("折线图绘制结束");
            msgBox.exec();
            break;
        }
        inputData.append(this->data[index*this->curve_num+i]);
    }
    this->index++;
    this->append(inputData);
}

void CurveGroup::alldatainput(){

    QList<double> inputData;

    for (int j = 0; j < this->max_point; j++){
        for (int i = 0; i < this->curve_num; i++)
        {
            inputData.append(this->data[j * this->curve_num + i]);

        }
        this->append(inputData);
        inputData.clear();
    }

}
void CurveGroup::setScale(int value)
{
    //curvewnd->setScale(value);
}

void CurveGroup::increaseScale()
{
    curvewnd->increaseScaleFactor();
}

void CurveGroup::reduceScale()
{
    curvewnd->reduceScaleFactor();
}

void CurveGroup::reduceGroupChannel()
{
    if(curve_num_group>1)
    {
        curve_num_group--;
        //组页重置0
        current_group=0;
        //更新通道数
        curvewnd->updateCurveNum(curve_num_group);
        //更新通道名字
        setCurveLabels(this->labels);
        //更新组数
        group_num=(curve_num-1)/curve_num_group;

    }
}
void CurveGroup::increaseGroupChannel()
{
    if(curve_num_group<8)
    {
        curve_num_group++;
        //组页重置0
        current_group=0;
        //更新通道数
        curvewnd->updateCurveNum(curve_num_group);
        //更新通道名字
        setCurveLabels(this->labels);
        //更新组数
        group_num=(curve_num-1)/curve_num_group;
    }

}
void CurveGroup::test_chart()
{

    timerId = startTimer(1);
}

void CurveGroup::test_chart2()
{
    alldatainput();
}

int CurveGroup::getTimerId(){
    return timerId;
}

int CurveGroup::getPointNum(){
    qDebug()<<this->data.size()/this->chanlocs.size();
    return this->data.size()/this->chanlocs.size();
}

void CurveGroup::setMatPath(QString name)
{
    this->path = name;
}

CurveWnd *CurveGroup::getCurveWnd(){
    return this->curvewnd;
}

void CurveGroup::loadData()
{
    this->data=this->mat.readData(this->path);

}

void CurveGroup::loadEvent()
{
    vector<unsigned int> eventtype=this->mat.readEventtype(this->path);
    vector<unsigned int> lantency=this->mat.readEventlatency(this->path);
    QString type;
    int length = eventtype.size();
    qDebug()<<length;
    for(int i=0;i<length;i++)
    {
        switch(eventtype[i]){
        case 0:
            type="EnemyBorn";break;
        case 1:
            type="EnemyDie";break;
        case 2:
            type="FireHitErr";break;
        case 3:
            type="FireMiss";break;
        case 4:
            type="CutHit";break;
        case 5:
            type="CutHitErr";break;
        default:
            type="000";break;
        }
        this->appendMark(type,lantency[i]);
    }
}
//获取通道list
QStringList CurveGroup::getChanlocs()
{
    this->chanlocs=this->mat.readChanlocs(this->path);
    QStringList chanlocList;
    for(unsigned int i=0;i<chanlocs.size();i++)
    {
        chanlocList.append(chanlocs[i]);
    }
    return chanlocList;
}

