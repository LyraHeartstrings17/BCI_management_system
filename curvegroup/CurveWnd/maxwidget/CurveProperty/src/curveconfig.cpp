#include "curveconfig.h"
#include "QSettings"
#include "QFile"
#include "QColor"
#include "QDebug"
CurveConfig::CurveConfig(QObject *parent) : QObject(parent)
{

}

bool CurveConfig::isExist(QString filename)
{
    QFile file("./config/"+filename+"config.ini");
    return file.exists();
}

void CurveConfig::createFile(QString filename)
{
     QFile file("./config/"+filename+"config.ini");
     file.open(QIODevice::WriteOnly);
     file.close();
}

void CurveConfig::createDefaultConfig(QString filename)
{
    QString path="./config/"+filename+"config.ini";
    QSettings curveconfig(path,QSettings::IniFormat);

    curveconfig.beginGroup("背景颜色");
    curveconfig.setValue("背景颜色",QColor(255,255,255,255));
    curveconfig.endGroup();


    curveconfig.beginGroup("坐标轴设置 ");
    curveconfig.setValue("x坐标轴颜色 ",QColor(0,0,0,255));
    curveconfig.setValue("y坐标轴颜色 ",QColor(0,0,0,255));
    curveconfig.setValue("字体颜色 ",QColor(0,0,0,255));
    curveconfig.endGroup();

    curveconfig.beginGroup("曲线设置");
    curveconfig.setValue("曲线颜色",QColor(0,170,255,255));
    curveconfig.setValue("曲线宽度",2);
    curveconfig.setValue("纵坐标",QSize(200,200));
    curveconfig.endGroup();


}

void CurveConfig::readConfig(QString filename)
{
    QString path="./config/"+filename+"config.ini";
    QSettings curveconfig(path,QSettings::IniFormat);
    QList<QVariant> data;

    curveconfig.beginGroup("背景颜色");
    QVariant back_color=curveconfig.value("背景颜色");
    curveconfig.endGroup();

    curveconfig.beginGroup("坐标轴设置");
    QVariant axisx_color=curveconfig.value("x坐标轴颜色");
    QVariant axisy_color=curveconfig.value("y坐标轴颜色");
    QVariant font_color=curveconfig.value("字体颜色");
    curveconfig.endGroup();

    curveconfig.beginGroup("曲线设置");
    QVariant curve_color=curveconfig.value("曲线颜色");
    QVariant curve_width=curveconfig.value("曲线宽度");
    QVariant axis_y_range=curveconfig.value("纵坐标");
    curveconfig.endGroup();

    data.append(back_color);
    data.append(axisx_color);
    data.append(axisy_color);
    data.append(font_color);
    data.append(curve_color);
    data.append(curve_width);
    data.append(axis_y_range);
    emit readFinished(data);
}

void CurveConfig::initConfig(QString filename)
{
    this->filename=filename;
    if(isExist(filename))
    {
        readConfig(filename);
    }
    else
    {
        createFile(filename);
        createDefaultConfig(filename);
        readConfig(filename);
    }
}

void CurveConfig::modifyProperty(QtProperty *property, const QVariant &value)
{
    QString path="./config/"+filename+"config.ini";
    QSettings curveconfig(path,QSettings::IniFormat);
    if(property->propertyName()=="背景颜色")
    {
        curveconfig.beginGroup("背景颜色");
        curveconfig.setValue("背景颜色",value);
        curveconfig.endGroup();
    }
    else if(property->propertyName()=="x坐标轴颜色")
    {
        curveconfig.beginGroup("坐标轴设置");
        curveconfig.setValue("x坐标轴颜色",value);
        curveconfig.endGroup();
    }
    else if(property->propertyName()=="y坐标轴颜色")
    {
        curveconfig.beginGroup("坐标轴设置");
        curveconfig.setValue("y坐标轴颜色",value);
        curveconfig.endGroup();
    }
    else if(property->propertyName()=="字体颜色")
    {
        curveconfig.beginGroup("坐标轴设置");
        curveconfig.setValue("字体颜色",value);
        curveconfig.endGroup();
    }
    else if(property->propertyName()=="曲线颜色")
    {
        curveconfig.beginGroup("曲线设置");
        curveconfig.setValue("曲线颜色",value);
        curveconfig.endGroup();
    }
    else if(property->propertyName()=="曲线宽度")
    {
        curveconfig.beginGroup("曲线设置");
        curveconfig.setValue("曲线宽度",value);
        curveconfig.endGroup();
    }
    else if(property->propertyName()=="纵坐标")
    {
        curveconfig.beginGroup("曲线设置");
        curveconfig.setValue("纵坐标",value);
        curveconfig.endGroup();
    }
}
