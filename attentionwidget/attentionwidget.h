#ifndef ATTENTIONWIDGET_H
#define ATTENTIONWIDGET_H

#include <QWidget>
#include "attentiondata.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class AttentionWidget;
}
QT_END_NAMESPACE
class AttentionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AttentionWidget(QWidget *parent = nullptr);
    ~AttentionWidget();
    void showWidget();
    //存放结算数据
    void setFinishFilePath(QString);
    void setGameFilePath(QString path);
    void setEmotionRadar(QList<double> data);
    void setPericeiveRadar(QList<double> data);
    void appendEmotionCurve(QList<double> data);
    void appendPericeiveCurve(QList<double> data);

private:
    Ui::AttentionWidget *ui;
    void init();
    void setLayout();
    AttentionData data;
};

#endif // ATTENTIONWIDGET_H
