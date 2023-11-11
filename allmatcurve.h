#ifndef ALLMATCURVE_H
#define ALLMATCURVE_H

#include <QWidget>

namespace Ui {
class allmatcurve;
}

class allmatcurve : public QWidget
{
    Q_OBJECT

public:
    explicit allmatcurve(QWidget *parent = nullptr);
    ~allmatcurve();

private:
    Ui::allmatcurve *ui;
};

#endif // ALLMATCURVE_H
