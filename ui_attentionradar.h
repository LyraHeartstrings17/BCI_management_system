/********************************************************************************
** Form generated from reading UI file 'attentionradar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENTIONRADAR_H
#define UI_ATTENTIONRADAR_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttentionRadar
{
public:
    QHBoxLayout *horizontalLayout;
    QQuickWidget *quickWidget;

    void setupUi(QWidget *AttentionRadar)
    {
        if (AttentionRadar->objectName().isEmpty())
            AttentionRadar->setObjectName(QString::fromUtf8("AttentionRadar"));
        AttentionRadar->resize(100, 300);
        horizontalLayout = new QHBoxLayout(AttentionRadar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        quickWidget = new QQuickWidget(AttentionRadar);
        quickWidget->setObjectName(QString::fromUtf8("quickWidget"));
        quickWidget->setEnabled(false);
        quickWidget->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        quickWidget->setFont(font);
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

        horizontalLayout->addWidget(quickWidget);


        retranslateUi(AttentionRadar);

        QMetaObject::connectSlotsByName(AttentionRadar);
    } // setupUi

    void retranslateUi(QWidget *AttentionRadar)
    {
        AttentionRadar->setWindowTitle(QCoreApplication::translate("AttentionRadar", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AttentionRadar: public Ui_AttentionRadar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENTIONRADAR_H
