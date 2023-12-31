﻿#ifndef GAMEFINISHWIDGET_H
#define GAMEFINISHWIDGET_H

#include <QWidget>
#include "gamefinishdata.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class GameFinishWidget;
}
QT_END_NAMESPACE
class GameFinishWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameFinishWidget(QWidget *parent = nullptr);
    ~GameFinishWidget();
    void showWidget();
    void setFinishFilePath(QString);
    void setGameFilePath(QString path);
    void setEmotionRadar(QList<double> data);
    void setPericeiveRadar(QList<double> data);
    void appendEmotionCurve(QList<double> data);
    void appendPericeiveCurve(QList<double> data);
    void showRadarWidget();
    //重置curve
    void resetEmotionCurve();
    void resetPericeiveCurve();
    void clearcurveData();
private:
    Ui::GameFinishWidget *ui;
    void init();
    void setLayout();
    GameFinishData data;
};

#endif // GAMEFINISHWIDGET_H
