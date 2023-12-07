/********************************************************************************
** Form generated from reading UI file 'gamefinishwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEFINISHWIDGET_H
#define UI_GAMEFINISHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "curve.h"
#include "radar.h"

QT_BEGIN_NAMESPACE

class Ui_GameFinishWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout;
    Radar *emotion_radar;
    Radar *periceive_radar;
    QWidget *page_2;
    QVBoxLayout *verticalLayout;
    Curve *emotion_curve;
    Curve *periceive_curve;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *switchButton;

    void setupUi(QWidget *GameFinishWidget)
    {
        if (GameFinishWidget->objectName().isEmpty())
            GameFinishWidget->setObjectName(QString::fromUtf8("GameFinishWidget"));
        GameFinishWidget->resize(1425, 571);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameFinishWidget->sizePolicy().hasHeightForWidth());
        GameFinishWidget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(GameFinishWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        stackedWidget = new QStackedWidget(GameFinishWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout = new QHBoxLayout(page);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        emotion_radar = new Radar(page);
        emotion_radar->setObjectName(QString::fromUtf8("emotion_radar"));
        emotion_radar->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(emotion_radar);

        periceive_radar = new Radar(page);
        periceive_radar->setObjectName(QString::fromUtf8("periceive_radar"));
        periceive_radar->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(periceive_radar);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout = new QVBoxLayout(page_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        emotion_curve = new Curve(page_2);
        emotion_curve->setObjectName(QString::fromUtf8("emotion_curve"));
        emotion_curve->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(emotion_curve);

        periceive_curve = new Curve(page_2);
        periceive_curve->setObjectName(QString::fromUtf8("periceive_curve"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(periceive_curve->sizePolicy().hasHeightForWidth());
        periceive_curve->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(periceive_curve);

        stackedWidget->addWidget(page_2);

        horizontalLayout_2->addWidget(stackedWidget);

        widget = new QWidget(GameFinishWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        switchButton = new QPushButton(widget);
        switchButton->setObjectName(QString::fromUtf8("switchButton"));
        sizePolicy.setHeightForWidth(switchButton->sizePolicy().hasHeightForWidth());
        switchButton->setSizePolicy(sizePolicy);
        switchButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"\n"
"\n"
" 	writing-mode: vertical-rl; /* \350\256\276\347\275\256\346\226\207\345\255\227\347\253\226\346\216\222 */\n"
"    text-align: left; /* \346\226\207\345\255\227\345\261\205\344\270\255\345\257\271\351\275\220 */\n"
"    height: 100px; /* \350\256\276\347\275\256\346\214\211\351\222\256\351\253\230\345\272\246 */\n"
"    min-width: 20px; max-width: 20px; min-height: 	100px; max-height: 100px; \n"
"\n"
"			\n"
"            \n"
"\n"
"            \n"
" qproperty-icon: url(:/res/Icon/9068701_change_icon.png);\n"
"       \n"
"\n"
"       \n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background-color: white;\n"
"	color: black;\n"
"	border: 1px solid gray;\n"
"	/* \350\256\276\347\275\256\351\230\264\345\275\261\346\225\210\346\236\234 */\n"
"   \n"
"    border-style: outset;\n"
"    border-width: 1px;\n"
"    \n"
"    /*padding: 4px;*/\n"
"    margin: 8px;\n"
"    qproperty-shadow: 5px 5px 5px rgba(0, 0, 0, 150);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-col"
                        "or: #aaa;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #888;\n"
"}\n"
"\n"
" QPushButton::icon {\n"
"            width: 16px;\n"
"            height: 16px;\n"
"            margin-right: 8px;\n"
"        }\n"
"\n"
"\n"
"\n"
""));

        verticalLayout_2->addWidget(switchButton);


        horizontalLayout_2->addWidget(widget);

        horizontalLayout_2->setStretch(0, 15);

        retranslateUi(GameFinishWidget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(GameFinishWidget);
    } // setupUi

    void retranslateUi(QWidget *GameFinishWidget)
    {
        GameFinishWidget->setWindowTitle(QCoreApplication::translate("GameFinishWidget", "Form", nullptr));
        switchButton->setText(QCoreApplication::translate("GameFinishWidget", "\345\210\207\n"
"\346\215\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameFinishWidget: public Ui_GameFinishWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEFINISHWIDGET_H
