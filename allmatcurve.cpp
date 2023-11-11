#include "allmatcurve.h"
#include "ui_allmatcurve.h"

allmatcurve::allmatcurve(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::allmatcurve)
{
    ui->setupUi(this);
}

allmatcurve::~allmatcurve()
{
    delete ui;
}
