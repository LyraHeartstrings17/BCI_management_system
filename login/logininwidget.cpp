#include "logininwidget.h"
#include "qurl.h"
#include "ui_logininwidget.h"

LoginInWidget::LoginInWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginInWidget)
{
    ui->setupUi(this);
    QUrl source("qrc:/res/loggingin.qml");
    ui->quickWidget->setSource(source);
}

LoginInWidget::~LoginInWidget()
{
    delete ui;
}
