/********************************************************************************
** Form generated from reading UI file 'attentionwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENTIONWIDGET_H
#define UI_ATTENTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "attentionradar.h"

QT_BEGIN_NAMESPACE

class Ui_AttentionWidget
{
public:
    QHBoxLayout *horizontalLayout;
    AttentionRadar *emotion_radar;
    AttentionRadar *periceive_radar;

    void setupUi(QWidget *AttentionWidget)
    {
        if (AttentionWidget->objectName().isEmpty())
            AttentionWidget->setObjectName(QString::fromUtf8("AttentionWidget"));
        AttentionWidget->resize(504, 410);
        horizontalLayout = new QHBoxLayout(AttentionWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        emotion_radar = new AttentionRadar(AttentionWidget);
        emotion_radar->setObjectName(QString::fromUtf8("emotion_radar"));
        emotion_radar->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(emotion_radar);

        periceive_radar = new AttentionRadar(AttentionWidget);
        periceive_radar->setObjectName(QString::fromUtf8("periceive_radar"));
        periceive_radar->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(periceive_radar);


        retranslateUi(AttentionWidget);

        QMetaObject::connectSlotsByName(AttentionWidget);
    } // setupUi

    void retranslateUi(QWidget *AttentionWidget)
    {
        AttentionWidget->setWindowTitle(QCoreApplication::translate("AttentionWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AttentionWidget: public Ui_AttentionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENTIONWIDGET_H
