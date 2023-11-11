<<<<<<< HEAD
#ifndef RADAR_H
=======
﻿#ifndef RADAR_H
>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
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
