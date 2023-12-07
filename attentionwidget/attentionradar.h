#ifndef ATTENTIONRADAR_H
#define ATTENTIONRADAR_H

#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class AttentionRadar;
}
QT_END_NAMESPACE
class AttentionRadar : public QWidget
{
    Q_OBJECT

public:
    explicit AttentionRadar(QWidget *parent = nullptr);
    ~AttentionRadar();
    void setRadarLabel(QStringList);
    void setData(QList<double> data);
private:
    Ui::AttentionRadar *ui;
};

#endif // ATTENTIONRADAR_H
