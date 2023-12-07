#ifndef RADAR_H
#define RADAR_H

#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class Radar;
}
QT_END_NAMESPACE
class Radar : public QWidget
{
    Q_OBJECT

public:
    explicit Radar(QWidget *parent = nullptr);
    ~Radar();
    void setRadarLabel(QStringList);
    void setData(QList<double> data);
private:
    Ui::Radar *ui;
};

#endif // RADAR_H
