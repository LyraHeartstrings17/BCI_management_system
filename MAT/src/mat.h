#ifndef MAT_H
#define MAT_H

#include "QObject"
#include "QTemporaryFile"//临时文件
#include "QTemporaryDir"
#include "matio.h"
class  MAT:public QObject
{
    Q_OBJECT
public:
    explicit MAT(QObject *parent=nullptr);
    ~MAT();
    void setFileName(QString name);
    void start();
    void save(double *m,quint32 num);
    void stop();
    //保存脑电导联分布信息
    void  saveChanlocs(QVariantList chanlocs);
    //保存文件名字
    void  saveFileName(QString name);
    //保存脑电采样率
    void  saveSrate(quint16 rate);
    //保存事件
    void  saveEevent(QVariantList event);
    //保存原始事件
    void  saveUrevent(QVariantList event);
    //保存参考电极
    void  saveRef(QStringList ref);
    //保存年龄
    void  saveAge(quint8 age);
    //保存设备代码
    void  saveSetCode(quint8 code);
    //设置通道数目
    void setChannelNum(const quint8 &value);

private:
    //Mat文件指针
    mat_t  *mat_fp;
    //EEG Struct 指针
    matvar_t *eeg_struct;
    //通道数
    quint8   channel_num;
};

#endif // MAT_H
