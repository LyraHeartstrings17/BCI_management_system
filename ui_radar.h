/********************************************************************************
** Form generated from reading UI file 'radar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADAR_H
#define UI_RADAR_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Radar
{
public:
    QVBoxLayout *verticalLayout;
    QQuickWidget *quickWidget;

    void setupUi(QWidget *Radar)
    {
        if (Radar->objectName().isEmpty())
            Radar->setObjectName(QString::fromUtf8("Radar"));
        Radar->resize(100, 300);
        verticalLayout = new QVBoxLayout(Radar);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        quickWidget = new QQuickWidget(Radar);
        quickWidget->setObjectName(QString::fromUtf8("quickWidget"));
        quickWidget->setEnabled(false);
        quickWidget->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        quickWidget->setFont(font);
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

        verticalLayout->addWidget(quickWidget);


        retranslateUi(Radar);

        QMetaObject::connectSlotsByName(Radar);
    } // setupUi

    void retranslateUi(QWidget *Radar)
    {
        Radar->setWindowTitle(QCoreApplication::translate("Radar", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Radar: public Ui_Radar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADAR_H
