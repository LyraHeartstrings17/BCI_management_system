/********************************************************************************
** Form generated from reading UI file 'curve.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVE_H
#define UI_CURVE_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Curve
{
public:
    QHBoxLayout *horizontalLayout;
    QQuickWidget *quickWidget;

    void setupUi(QWidget *Curve)
    {
        if (Curve->objectName().isEmpty())
            Curve->setObjectName(QString::fromUtf8("Curve"));
        Curve->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Curve);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        quickWidget = new QQuickWidget(Curve);
        quickWidget->setObjectName(QString::fromUtf8("quickWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(quickWidget->sizePolicy().hasHeightForWidth());
        quickWidget->setSizePolicy(sizePolicy);
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

        horizontalLayout->addWidget(quickWidget);


        retranslateUi(Curve);

        QMetaObject::connectSlotsByName(Curve);
    } // setupUi

    void retranslateUi(QWidget *Curve)
    {
        Curve->setWindowTitle(QCoreApplication::translate("Curve", "maxcurve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Curve: public Ui_Curve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVE_H
