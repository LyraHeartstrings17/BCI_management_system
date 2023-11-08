#include "curveproperty.h"
#include "QDebug"
#include "QThread"
CurveProperty::CurveProperty(QWidget *parent):QWidget(parent)
{
    init();
    initTree();
    setConnect();
}

CurveProperty::~CurveProperty()
{
    thread->exit();
    delete  var_manager;
    delete  editfactory;
    delete  treeproperty;
    delete  widget_layout;
    delete  thread;
    delete  curveconfig;
}

void CurveProperty::setTitle(QString title)
{
    QList<QtProperty *> properties=this->treeproperty->properties();
    QtVariantProperty *titleproperty=(QtVariantProperty *)properties[0];
    titleproperty->setValue(title);
    emit getCurveConfig(title);
}

void CurveProperty::init()
{
    this->resize(640,480);
    this->treeproperty=new QtTreePropertyBrowser();
    this->var_manager=new QtVariantPropertyManager(treeproperty);
    this->editfactory=new QtVariantEditorFactory();
    //多线程读取配置
    this->thread=new QThread(this);
    this->curveconfig=new CurveConfig();
    this->curveconfig->moveToThread(thread);
    thread->start();

    this->treeproperty->setFactoryForManager(var_manager,editfactory);
    this->widget_layout=new QHBoxLayout();
    this->widget_layout->addWidget(treeproperty);
    widget_layout->setMargin(0);
    this->setLayout(widget_layout);
}

void CurveProperty::initTree()
{
      //背景设置
      QtProperty *group0=this->var_manager->addProperty(QVariant::String,"窗口标题");
      group0->setEnabled(false);
      QtProperty *group1=var_manager->addProperty(QVariant::Color,"背景颜色");
      QtVariantProperty *item=(QtVariantProperty *)group1;
      item->setValue(QColor(255,255,255,255));

      //坐标轴设置
      QtProperty *group2=var_manager->addProperty(QtVariantPropertyManager::groupTypeId(),"坐标轴设置");
      item=var_manager->addProperty(QVariant::Color,"x坐标轴颜色");
      group2->addSubProperty(item);
      item=var_manager->addProperty(QVariant::Color,"y坐标轴颜色");
      group2->addSubProperty(item);
      item=var_manager->addProperty(QVariant::Color,"字体颜色");
      group2->addSubProperty(item);

      //曲线设置
      QtProperty *group3=var_manager->addProperty(QtVariantPropertyManager::groupTypeId(),"曲线设置");
      item=var_manager->addProperty(QVariant::Color,"曲线颜色");
      group3->addSubProperty(item);
      item=var_manager->addProperty(QVariant::Int,"曲线宽度");
      group3->addSubProperty(item);
      item=var_manager->addProperty(QVariant::Size,"纵坐标");
      item->subProperties()[0]->setPropertyName("Min");
      item->subProperties()[1]->setPropertyName("Max");
      group3->addSubProperty(item);


      this->treeproperty->addProperty(group0);
      this->treeproperty->addProperty(group1);
      this->treeproperty->addProperty(group2);
      this->treeproperty->addProperty(group3);
}

void CurveProperty::setConnect()
{
    connect(var_manager,&QtVariantPropertyManager::valueChanged,this,&CurveProperty::valueChange);
    connect(this,&CurveProperty::getCurveConfig,curveconfig,&CurveConfig::initConfig);
    connect(curveconfig,&CurveConfig::readFinished,this,&CurveProperty::readCurveConfig);
     connect(var_manager,&QtVariantPropertyManager::valueChanged,curveconfig,&CurveConfig::modifyProperty);
}
void CurveProperty::valueChange(QtProperty *property,const QVariant &value)
{
    if(property->propertyName()=="背景颜色")
    {
        emit backgroudValueChange(property,value);
    }
    else if(property->propertyName()=="x坐标轴颜色")
    {
        emit axiasXValueChange(property,value);
    }
    else if(property->propertyName()=="y坐标轴颜色")
    {
        emit axiasYValueChange(property,value);
    }
    else if(property->propertyName()=="字体颜色")
    {
        emit fontValueChange(property,value);
    }
    else if(property->propertyName()=="曲线颜色")
    {
        emit curveColorValueChange(property,value);
    }
    else if(property->propertyName()=="曲线宽度")
    {
        emit curveWidthValueChange(property,value);
    }
    else if (property->propertyName()=="纵坐标") {
        emit axisYRangeChange(property,value);
    }
}

void CurveProperty::readCurveConfig(QList<QVariant> config)
{
    QList<QtProperty *> properties=this->treeproperty->properties();
    //背景颜色
    QtVariantProperty *property=(QtVariantProperty *)properties[1];
    property->setValue(config[0]);
    //坐标轴
    property=(QtVariantProperty *)properties[2];
    QList<QtProperty*> subProperties=property->subProperties();
    for(int i=0;i<3;i++)
    {
        QtVariantProperty *subproperty=(QtVariantProperty *)subProperties[i];
        subproperty->setValue(config[i+1]);
    }
    //曲线设置
    property=(QtVariantProperty *)properties[3];
    subProperties=property->subProperties();
    for(int i=0;i<3;i++)
    {
        QtVariantProperty *subproperty=(QtVariantProperty *)subProperties[i];
        subproperty->setValue(config[i+4]);
    }
}
