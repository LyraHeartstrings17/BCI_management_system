#ifndef GAMEFINISHWIDGET_H
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
<<<<<<< HEAD
    void setFinishFilePath(QString);
=======
>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
    void setGameFilePath(QString path);
    void setEmotionRadar(QList<double> data);
    void setPericeiveRadar(QList<double> data);
    void appendEmotionCurve(QList<double> data);
    void appendPericeiveCurve(QList<double> data);
<<<<<<< HEAD
    void showRadarWidget();
    //重置curve
    void resetEmotionCurve();
    void resetPericeiveCurve();
    void clearcurveData();
=======

>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
private:
    Ui::GameFinishWidget *ui;
    void init();
    void setLayout();
    GameFinishData data;
};

#endif // GAMEFINISHWIDGET_H
