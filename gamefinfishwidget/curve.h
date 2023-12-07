#ifndef CURVE_H
#define CURVE_H

#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class Curve;
}
QT_END_NAMESPACE
class Curve : public QWidget
{
    Q_OBJECT

public:
    explicit Curve(QWidget *parent = nullptr);
    ~Curve();
    void setSeriesname(QStringList);
    void append(QList<double> data);
    void clearData();

private:
    Ui::Curve *ui;
};

#endif // CURVE_H
