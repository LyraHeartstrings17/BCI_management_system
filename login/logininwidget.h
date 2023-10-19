#ifndef LOGININWIDGET_H
#define LOGININWIDGET_H

#include <QWidget>

namespace Ui {
class LoginInWidget;
}

class LoginInWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginInWidget(QWidget *parent = nullptr);
    ~LoginInWidget();

private:
    Ui::LoginInWidget *ui;
};

#endif // LOGININWIDGET_H
