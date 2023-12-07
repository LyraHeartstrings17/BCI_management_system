/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QLineEdit *lineEdit_phone;
    QPushButton *pushButton_register;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_repassword;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(765, 504);
        Register->setStyleSheet(QString::fromUtf8("*{\n"
"	background-color: rgb(33, 36, 41);\n"
"color:rgb(255, 255, 255);\n"
"font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLineEdit{\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	padding:10px;\n"
"	background-color: rgb(50, 53, 60);\n"
"	border: 0px;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: rgb(118, 119, 121);\n"
"}"));
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 40, 201, 61));
        label->setStyleSheet(QString::fromUtf8("font: 75 28pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_phone = new QLineEdit(Register);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(90, 150, 382, 48));
        pushButton_register = new QPushButton(Register);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        pushButton_register->setGeometry(QRect(90, 430, 151, 51));
        pushButton_register->setStyleSheet(QString::fromUtf8("\n"
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
        lineEdit_password = new QLineEdit(Register);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(90, 240, 381, 48));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        lineEdit_repassword = new QLineEdit(Register);
        lineEdit_repassword->setObjectName(QString::fromUtf8("lineEdit_repassword"));
        lineEdit_repassword->setGeometry(QRect(90, 330, 381, 48));
        lineEdit_repassword->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(Register);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 130, 61, 16));
        label_5 = new QLabel(Register);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 220, 61, 16));
        label_6 = new QLabel(Register);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 306, 61, 20));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "\345\210\233\345\273\272\346\202\250\347\232\204\350\264\246\346\210\267", nullptr));
        label->setText(QCoreApplication::translate("Register", "<html><head/><body><p>\346\254\242\350\277\216\346\263\250\345\206\214</p></body></html>", nullptr));
        lineEdit_phone->setPlaceholderText(QCoreApplication::translate("Register", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267", nullptr));
        pushButton_register->setText(QCoreApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("Register", "\345\257\206\347\240\2018-20\344\275\215\357\274\214\345\214\205\346\213\254\346\225\260\345\255\227/\345\255\227\346\257\215", nullptr));
        lineEdit_repassword->setPlaceholderText(QCoreApplication::translate("Register", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("Register", "\346\211\213\346\234\272\345\217\267\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("Register", "\350\256\276\347\275\256\345\257\206\347\240\201", nullptr));
        label_6->setText(QCoreApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
