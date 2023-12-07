/********************************************************************************
** Form generated from reading UI file 'matCurve.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATCURVE_H
#define UI_MATCURVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "curvegroup.h"

QT_BEGIN_NAMESPACE

class Ui_MatCurve
{
public:
    QHBoxLayout *horizontalLayout_2;
    CurveGroup *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_14;

    void setupUi(QWidget *MatCurve)
    {
        if (MatCurve->objectName().isEmpty())
            MatCurve->setObjectName(QString::fromUtf8("MatCurve"));
        MatCurve->resize(778, 472);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MatCurve->sizePolicy().hasHeightForWidth());
        MatCurve->setSizePolicy(sizePolicy);
        MatCurve->setStyleSheet(QString::fromUtf8("/*background-color:rgb(246, 243, 253)*/\n"
"background-color: rgb(230, 234, 235);\n"
" border-radius: 20px;"));
        horizontalLayout_2 = new QHBoxLayout(MatCurve);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new CurveGroup(MatCurve);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        horizontalLayout_2->addWidget(widget);

        widget_3 = new QWidget(MatCurve);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 234, 235);"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"\n"
"\n"
" \n"
"            text-align: left;\n"
"            padding-left: 20px;\n"
"            qproperty-icon: url(:/res/Icon/8666551_play_circle_icon.png);\n"
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
"    background-color: #aaa;\n"
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
""));

        verticalLayout->addWidget(pushButton);

        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy2.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy2);
        pushButton_5->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"\n"
"\n"
" \n"
"            text-align: left;\n"
"            padding-left: 20px;\n"
"          qproperty-icon: url(:/res/Icon/8666549_pause_circle_icon.png);\n"
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
"    background-color: #aaa;\n"
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
""));

        verticalLayout->addWidget(pushButton_5);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        pushButton_2->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"\n"
"\n"
" \n"
"            text-align: left;\n"
"            padding-left: 20px;\n"
"            qproperty-icon: url(:/res/Icon/8666655_arrow_left_circle_icon.png);\n"
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
"    background-color: #aaa;\n"
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
""));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        pushButton_3->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"\n"
"\n"
" \n"
"            text-align: left;\n"
"            padding-left: 20px;\n"
" qproperty-icon: url(:/res/Icon/8666670_arrow_right_circle_icon.png);\n"
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
"    background-color: #aaa;\n"
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
""));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);
        pushButton_4->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"\n"
"\n"
" \n"
"            text-align: left;\n"
"            padding-left: 20px;\n"
"            qproperty-icon: url(:/res/Icon/8666721_rotate_ccw_icon.png);\n"
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
"    background-color: #aaa;\n"
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
""));

        verticalLayout->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(widget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy2.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy2);
        pushButton_6->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"\n"
"\n"
" \n"
"            text-align: left;\n"
"            padding-left: 20px;\n"
"            qproperty-icon: url(:/res/Icon/8666692_power_icon.png);\n"
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
"    background-color: #aaa;\n"
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
""));

        verticalLayout->addWidget(pushButton_6);

        pushButton_14 = new QPushButton(widget_2);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        sizePolicy2.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy2);
        pushButton_14->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"\n"
"\n"
" \n"
"            text-align: left;\n"
"            padding-left: 20px;\n"
"            qproperty-icon: url(:/res/Icon/8666634_play_icon.png);\n"
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
"    background-color: #aaa;\n"
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
""));

        verticalLayout->addWidget(pushButton_14);


        verticalLayout_2->addWidget(widget_2);


        horizontalLayout_2->addWidget(widget_3);

        horizontalLayout_2->setStretch(0, 12);
        horizontalLayout_2->setStretch(1, 1);

        retranslateUi(MatCurve);

        QMetaObject::connectSlotsByName(MatCurve);
    } // setupUi

    void retranslateUi(QWidget *MatCurve)
    {
        MatCurve->setWindowTitle(QCoreApplication::translate("MatCurve", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("MatCurve", "\345\274\200\345\247\213", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MatCurve", "\346\232\202\345\201\234", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MatCurve", "\344\270\212\344\270\200\351\241\265", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MatCurve", "\344\270\213\344\270\200\351\241\265", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MatCurve", "\351\207\215\347\275\256", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MatCurve", "\347\273\223\346\235\237", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MatCurve", "\347\233\264\346\216\245\345\261\225\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MatCurve: public Ui_MatCurve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCURVE_H
