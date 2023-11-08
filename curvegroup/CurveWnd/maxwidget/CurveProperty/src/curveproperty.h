#ifndef CURVEPROPERTY_H
#define CURVEPROPERTY_H

#include "QWidget"
#include "qtvariantproperty.h"
#include "qttreepropertybrowser.h"
#include "qtpropertymanager.h"
#include "QHBoxLayout"
#include "curveconfig.h"
#include "QVariant"
class CurveProperty:public QWidget
{
    Q_OBJECT
public:
    CurveProperty(QWidget *parent=nullptr);
    ~CurveProperty();
    void setTitle(QString title);
signals:
    void backgroudValueChange(QtProperty *property,const QVariant &value);
    void axiasXValueChange(QtProperty *property,const QVariant &value);
    void axiasYValueChange(QtProperty *property,const QVariant &value);
    void fontValueChange(QtProperty *property,const QVariant &value);
    void curveColorValueChange(QtProperty *property,const QVariant &value);
    void curveWidthValueChange(QtProperty *property,const QVariant &value);
    void axisYRangeChange(QtProperty *property,const QVariant &value);
    void getCurveConfig(QString);
private:
    QtVariantPropertyManager *var_manager;
    QtVariantEditorFactory   *editfactory;
    QtTreePropertyBrowser    *treeproperty;
    QHBoxLayout              *widget_layout;
    QThread   *thread;
    CurveConfig *curveconfig;
    void init();
    void initTree();
    void setConnect();
private slots:
    void valueChange(QtProperty *property,const QVariant &value);
    void readCurveConfig(QList<QVariant> config);
};

#endif // CURVEPROPERTY_H
