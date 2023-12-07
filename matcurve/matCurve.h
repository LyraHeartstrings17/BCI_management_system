#ifndef MATCURVE_H
#define MATCURVE_H

#include <QWidget>

namespace Ui {
class MatCurve;
}

class MatCurve : public QWidget
{
    Q_OBJECT

public:
    void setDataPath(QString);
    QString path;
    explicit MatCurve(QWidget *parent = nullptr);
    ~MatCurve();

private:
    Ui::MatCurve *ui;

private slots:
    void StartButtonClicked();
    void StopButtonClicked();
    void EndButtonClicked();
    void PageDownButtonClicked();
    void PageUpButtonClicked();
    void ResetButtonClicked();
    void ShowButtonClicked();
};

#endif // MATCURVE_H
