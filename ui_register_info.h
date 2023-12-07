/********************************************************************************
** Form generated from reading UI file 'register_info.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_INFO_H
#define UI_REGISTER_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register_info
{
public:
    QFrame *line;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_age;
    QLineEdit *lineEdit_nation;
    QLineEdit *lineEdit_sex;
    QLineEdit *lineEdit_handy;
    QLineEdit *lineEdit_work;
    QLineEdit *lineEdit_education;
    QLineEdit *lineEdit_phone;
    QLineEdit *lineEdit_address;
    QLineEdit *lineEdit_health;
    QLineEdit *lineEdit_sport;
    QLineEdit *lineEdit_game;
    QLineEdit *lineEdit_entertainment;
    QPushButton *pushButton_saveInfo;

    void setupUi(QWidget *Register_info)
    {
        if (Register_info->objectName().isEmpty())
            Register_info->setObjectName(QString::fromUtf8("Register_info"));
        Register_info->resize(593, 669);
        Register_info->setStyleSheet(QString::fromUtf8("*{font: 75 14pt \"Arial\";\n"
"background-color: rgb(49, 52, 59);\n"
"color: rgb(255, 255, 255);}\n"
"\n"
""));
        line = new QFrame(Register_info);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(3, 50, 681, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        line->setFont(font);
        line->setStyleSheet(QString::fromUtf8("\n"
"border-top:1.5px solid rgb(64,64,64);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(Register_info);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 181, 51));
        layoutWidget = new QWidget(Register_info);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 70, 501, 540));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout->addWidget(label_13);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout->addWidget(label_14);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout->addWidget(label_15);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        verticalLayout_2->addWidget(lineEdit_name);

        lineEdit_age = new QLineEdit(layoutWidget);
        lineEdit_age->setObjectName(QString::fromUtf8("lineEdit_age"));

        verticalLayout_2->addWidget(lineEdit_age);

        lineEdit_nation = new QLineEdit(layoutWidget);
        lineEdit_nation->setObjectName(QString::fromUtf8("lineEdit_nation"));

        verticalLayout_2->addWidget(lineEdit_nation);

        lineEdit_sex = new QLineEdit(layoutWidget);
        lineEdit_sex->setObjectName(QString::fromUtf8("lineEdit_sex"));

        verticalLayout_2->addWidget(lineEdit_sex);

        lineEdit_handy = new QLineEdit(layoutWidget);
        lineEdit_handy->setObjectName(QString::fromUtf8("lineEdit_handy"));

        verticalLayout_2->addWidget(lineEdit_handy);

        lineEdit_work = new QLineEdit(layoutWidget);
        lineEdit_work->setObjectName(QString::fromUtf8("lineEdit_work"));

        verticalLayout_2->addWidget(lineEdit_work);

        lineEdit_education = new QLineEdit(layoutWidget);
        lineEdit_education->setObjectName(QString::fromUtf8("lineEdit_education"));

        verticalLayout_2->addWidget(lineEdit_education);

        lineEdit_phone = new QLineEdit(layoutWidget);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));

        verticalLayout_2->addWidget(lineEdit_phone);

        lineEdit_address = new QLineEdit(layoutWidget);
        lineEdit_address->setObjectName(QString::fromUtf8("lineEdit_address"));

        verticalLayout_2->addWidget(lineEdit_address);

        lineEdit_health = new QLineEdit(layoutWidget);
        lineEdit_health->setObjectName(QString::fromUtf8("lineEdit_health"));

        verticalLayout_2->addWidget(lineEdit_health);

        lineEdit_sport = new QLineEdit(layoutWidget);
        lineEdit_sport->setObjectName(QString::fromUtf8("lineEdit_sport"));

        verticalLayout_2->addWidget(lineEdit_sport);

        lineEdit_game = new QLineEdit(layoutWidget);
        lineEdit_game->setObjectName(QString::fromUtf8("lineEdit_game"));

        verticalLayout_2->addWidget(lineEdit_game);

        lineEdit_entertainment = new QLineEdit(layoutWidget);
        lineEdit_entertainment->setObjectName(QString::fromUtf8("lineEdit_entertainment"));

        verticalLayout_2->addWidget(lineEdit_entertainment);


        horizontalLayout->addLayout(verticalLayout_2);

        pushButton_saveInfo = new QPushButton(Register_info);
        pushButton_saveInfo->setObjectName(QString::fromUtf8("pushButton_saveInfo"));
        pushButton_saveInfo->setGeometry(QRect(390, 620, 151, 51));
        pushButton_saveInfo->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#pushButton_register{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  rgb(6, 191, 255), stop:1 rgb(44, 114, 255) );\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:3px;		\n"
"	font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"}\n"
"QPushButton#pushButton_register:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  rgb(20, 204, 255), stop:1 rgb(11, 141, 255) );\n"
"	border-style:none;\n"
"	border-radius:3px;\n"
"	font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"}\n"
"\n"
"QPushButton#pushButton_register:pressed{\n"
"	\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0  rgb(20, 204, 255), stop:0.5 rgb(5, 191, 255), stop:1 rgb(11, 141, 255) );\n"
"	border-style:none;\n"
"	border-radius:3px;	\n"
"	font: 12pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"}\n"
""));
        pushButton_saveInfo->setAutoDefault(false);
        pushButton_saveInfo->setFlat(false);

        retranslateUi(Register_info);

        pushButton_saveInfo->setDefault(false);


        QMetaObject::connectSlotsByName(Register_info);
    } // setupUi

    void retranslateUi(QWidget *Register_info)
    {
        Register_info->setWindowTitle(QCoreApplication::translate("Register_info", "Form", nullptr));
        label->setText(QCoreApplication::translate("Register_info", "\347\224\250\346\210\267\346\263\250\345\206\214\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        label_2->setText(QCoreApplication::translate("Register_info", "\345\247\223\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("Register_info", "\345\271\264\351\276\204", nullptr));
        label_4->setText(QCoreApplication::translate("Register_info", "\346\260\221\346\227\217", nullptr));
        label_5->setText(QCoreApplication::translate("Register_info", "\346\200\247\345\210\253 ", nullptr));
        label_6->setText(QCoreApplication::translate("Register_info", "\345\267\246\345\217\263\345\210\251\346\211\213", nullptr));
        label_7->setText(QCoreApplication::translate("Register_info", "\345\267\245\344\275\234\347\273\217\345\216\206", nullptr));
        label_8->setText(QCoreApplication::translate("Register_info", "\346\225\231\350\202\262\346\260\264\345\271\263", nullptr));
        label_9->setText(QCoreApplication::translate("Register_info", "\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        label_11->setText(QCoreApplication::translate("Register_info", "\350\201\224\347\263\273\345\234\260\345\235\200", nullptr));
        label_12->setText(QCoreApplication::translate("Register_info", "\350\272\253\344\275\223\345\201\245\345\272\267\347\212\266\345\206\265", nullptr));
        label_13->setText(QCoreApplication::translate("Register_info", "\344\275\223\350\202\262\351\224\273\347\202\274\347\261\273\345\236\213", nullptr));
        label_14->setText(QCoreApplication::translate("Register_info", "\345\270\270\347\216\251\346\270\270\346\210\217(\347\261\273\345\236\213,\345\220\215\347\247\260)", nullptr));
        label_15->setText(QCoreApplication::translate("Register_info", "\346\227\245\345\270\270\345\250\261\344\271\220\346\226\271\345\274\217", nullptr));
        lineEdit_sex->setPlaceholderText(QCoreApplication::translate("Register_info", "\342\200\230\347\224\267\342\200\231\346\210\226\342\200\230\345\245\263\342\200\231", nullptr));
        lineEdit_handy->setPlaceholderText(QCoreApplication::translate("Register_info", "\342\200\230\345\267\246\342\200\231\346\210\226\342\200\230\345\217\263\342\200\231", nullptr));
        pushButton_saveInfo->setText(QCoreApplication::translate("Register_info", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register_info: public Ui_Register_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_INFO_H
