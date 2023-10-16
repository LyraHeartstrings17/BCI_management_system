#ifndef REGISTER_INFO_H
#define REGISTER_INFO_H

#include <QWidget>
#include <QVariant>
#include "UserInfoStruct.h"

namespace Ui {
class Register_info;
}

class Register_info : public QWidget
{
    Q_OBJECT

public:
    explicit Register_info(QWidget *parent = nullptr);
    ~Register_info();

    void getAccount(QString);




signals:
    void sendRegisterInfo(QVariant);

private slots:
    void on_pushButton_saveInfo_clicked();

private:
    Ui::Register_info *ui;

    QString account;



};

#endif // REGISTER_INFO_H
