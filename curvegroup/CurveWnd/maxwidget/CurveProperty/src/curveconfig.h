#ifndef CURVECONFIG_H
#define CURVECONFIG_H

#include <QObject>
#include "qtpropertymanager.h"
#include "QVariant"
class CurveConfig : public QObject
{
    Q_OBJECT
public:
    explicit CurveConfig(QObject *parent = nullptr);
public slots:
    void initConfig(QString);
    void modifyProperty(QtProperty *property,const QVariant &value);
signals:
    void readFinished(QList<QVariant> data);
private:
    QString filename;
    bool isExist(QString);
    void createFile(QString);
    void createDefaultConfig(QString);
    void readConfig(QString);

};

#endif // CURVECONFIG_H
