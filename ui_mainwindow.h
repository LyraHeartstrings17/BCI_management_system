/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "attentionwidget/attentionwidget.h"
#include "gamefinfishwidget/gamefinishwidget.h"
#include "matcurve/matcurve.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *logoutBtn;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *queryEdit;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *queryBtn;
    QPushButton *selectButton;
    QListWidget *listWidget;
    QWidget *frame;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *dateComboBox;
    QComboBox *comboBox1;
    QComboBox *comboBox2;
    QStackedWidget *stackedWidget;
    MatCurve *matWidget;
    AttentionWidget *attentionWidget;
    GameFinishWidget *finishWidget;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *showBtn;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1747, 1030);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("/*background-color:rgb(246, 243, 253);*/\n"
"/*background-color: rgb(64, 162, 250);*/\n"
"	font: 25 9pt \"Alibaba PuHuiTi 2.0\";\n"
"	/*color: rgb(118, 119, 121);*/\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setStyleSheet(QString::fromUtf8("/*background-color:rgb(246, 243, 253);"));
        horizontalLayout_6 = new QHBoxLayout(centralwidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        widget_8 = new QWidget(centralwidget);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        sizePolicy.setHeightForWidth(widget_8->sizePolicy().hasHeightForWidth());
        widget_8->setSizePolicy(sizePolicy);
        widget_8->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:rgb(246, 243, 253);\n"
"        border: 0px solid black;\n"
"  border-radius: 20px; /* \350\256\276\347\275\256\345\233\233\350\247\222\347\232\204\345\234\206\346\273\221\345\215\212\345\276\204 */\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(widget_8);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(widget_8);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: rgb(246, 243, 253)\n"
"    border: 0px solid black;  /* \350\256\276\347\275\256\350\276\271\346\241\206\344\270\272\351\273\221\350\211\262\357\274\214\350\276\271\346\241\206\345\256\275\345\272\246\344\270\2721\345\203\217\347\264\240 */\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(frame_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        widget_5->setStyleSheet(QString::fromUtf8("/*background-color:rgb(246, 243, 253);*/\n"
"background-color: rgb(108, 209, 239);\n"
"border: 0px solid black;\n"
"border-radius: 0px;"));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        logoutBtn = new QPushButton(widget_5);
        logoutBtn->setObjectName(QString::fromUtf8("logoutBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logoutBtn->sizePolicy().hasHeightForWidth());
        logoutBtn->setSizePolicy(sizePolicy1);
        logoutBtn->setFocusPolicy(Qt::StrongFocus);
        logoutBtn->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"\n"
"\n"
" \n"
"            text-align: left;\n"
"            padding-left: 20px;\n"
" qproperty-icon: url(:/res/Icon/8666571_log_out_icon.png);\n"
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
        logoutBtn->setCheckable(false);

        horizontalLayout_2->addWidget(logoutBtn);

        horizontalLayout_2->setStretch(0, 20);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_4->addWidget(widget_5);

        widget_6 = new QWidget(frame_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        sizePolicy.setHeightForWidth(widget_6->sizePolicy().hasHeightForWidth());
        widget_6->setSizePolicy(sizePolicy);
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(108, 209, 239);\n"
"/*background-color:rgb(246, 243, 253);*/\n"
"border: 0px solid black;\n"
"    border-radius: 0px;\n"
"\n"
""));
        horizontalLayout_3 = new QHBoxLayout(widget_6);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_6);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("/*background-color:rgb(246, 243, 253)*/\n"
"background-color: rgb(31, 33, 45);\n"
" border-radius: 0px;\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("border: 0px solid black;"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 0, 0, 0);
        queryEdit = new QLineEdit(widget_2);
        queryEdit->setObjectName(QString::fromUtf8("queryEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(queryEdit->sizePolicy().hasHeightForWidth());
        queryEdit->setSizePolicy(sizePolicy2);
        queryEdit->setStyleSheet(QString::fromUtf8("text-align: left;          /* \346\226\207\346\234\254\346\260\264\345\271\263\345\257\271\351\275\220\346\226\271\345\274\217\344\270\272\345\267\246\345\257\271\351\275\220 */\n"
"padding-left: 20px;        /* \345\267\246\344\276\247\345\206\205\350\276\271\350\267\235\344\270\272 20 \345\203\217\347\264\240 */\n"
"qproperty-icon: url(:/res/Icon/8666670_arrow_right_circle_icon.png);   /* \350\256\276\347\275\256\345\233\276\346\240\207\344\270\272\347\273\231\345\256\232\350\267\257\345\276\204\344\270\213\347\232\204\345\233\276\345\203\217 */\n"
"       \n"
"/*border-radius: 10px;*/   /* \346\263\250\351\207\212\346\216\211\357\274\214\344\270\215\345\272\224\347\224\250\345\234\206\350\247\222\345\215\212\345\276\204\344\270\272 10 \345\203\217\347\264\240\347\232\204\346\225\210\346\236\234 */\n"
"padding: 5px;              /* \345\206\205\350\276\271\350\267\235\344\270\272 5 \345\203\217\347\264\240 */\n"
"background-color: white;   /* \350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\347\231"
                        "\275\350\211\262 */\n"
"color: black;              /* \346\226\207\346\234\254\351\242\234\350\211\262\344\270\272\351\273\221\350\211\262 */\n"
"border: 1px solid gray;    /* \350\276\271\346\241\206\346\240\267\345\274\217\344\270\272 1 \345\203\217\347\264\240\345\256\275\347\232\204\347\201\260\350\211\262\345\256\236\347\272\277\350\276\271\346\241\206 */\n"
"/* \350\256\276\347\275\256\351\230\264\345\275\261\346\225\210\346\236\234 */\n"
"\n"
"border-style: outset;      /* \350\276\271\346\241\206\346\240\267\345\274\217\344\270\272\345\207\270\345\207\272\346\225\210\346\236\234 */\n"
"border-width: 1px;         /* \350\276\271\346\241\206\345\256\275\345\272\246\344\270\272 1 \345\203\217\347\264\240 */\n"
"    \n"
"padding: 4px;        /* \346\263\250\351\207\212\346\216\211\357\274\214\344\270\215\345\272\224\347\224\250\345\206\205\350\276\271\350\267\235\344\270\272 4 \345\203\217\347\264\240\347\232\204\346\225\210\346\236\234 */\n"
"/*margin: 8px;   */            /* \345\244\226\350\276\271\350\267"
                        "\235\344\270\272 8 \345\203\217\347\264\240 */\n"
"qproperty-shadow: 5px 5px 5px rgba(0, 0, 0, 150);   /* \350\256\276\347\275\256\351\230\264\345\275\261\346\225\210\346\236\234\344\270\272 5 \345\203\217\347\264\240\347\232\204\345\201\217\347\247\273\345\222\214\346\214\207\345\256\232\347\232\204\351\242\234\350\211\262\345\200\274 */\n"
" border-radius: 20px; /* \350\256\276\347\275\256\345\233\233\350\247\222\347\232\204\345\234\206\346\273\221\345\215\212\345\276\204 */"));

        horizontalLayout->addWidget(queryEdit);

        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        queryBtn = new QPushButton(widget);
        queryBtn->setObjectName(QString::fromUtf8("queryBtn"));
        sizePolicy2.setHeightForWidth(queryBtn->sizePolicy().hasHeightForWidth());
        queryBtn->setSizePolicy(sizePolicy2);
        queryBtn->setFocusPolicy(Qt::StrongFocus);
        queryBtn->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"\n"
"\n"
" \n"
"            text-align: left;\n"
"            padding-left: 20px;\n"
" qproperty-icon: url(:/res/Icon/8666693_search_icon.png);\n"
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
        queryBtn->setCheckable(false);

        verticalLayout_2->addWidget(queryBtn);

        selectButton = new QPushButton(widget);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        sizePolicy2.setHeightForWidth(selectButton->sizePolicy().hasHeightForWidth());
        selectButton->setSizePolicy(sizePolicy2);
        selectButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"\n"
"\n"
" \n"
"            text-align: left;\n"
"            padding-left: 20px;\n"
" qproperty-icon: url(:/res/Icon/8666687_upload_cloud_icon.png);\n"
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

        verticalLayout_2->addWidget(selectButton);


        horizontalLayout->addWidget(widget);

        horizontalLayout->setStretch(0, 6);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addWidget(widget_2);

        listWidget = new QListWidget(widget_3);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"background-color: rgb(46, 48, 61);"));

        verticalLayout->addWidget(listWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 8);

        horizontalLayout_3->addWidget(widget_3);

        frame = new QWidget(widget_6);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgb(235, 239, 240);\n"
"	/*background-color: rgb(235, 239, 241);*/\n"
"    border: 0px solid black;  /* \350\256\276\347\275\256\350\276\271\346\241\206\344\270\272\351\273\221\350\211\262\357\274\214\350\276\271\346\241\206\345\256\275\345\272\246\344\270\2721\345\203\217\347\264\240 */\n"
"	/*background-color: rgb(246, 243, 253);*/\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(9, -1, 0, 9);
        widget_4 = new QWidget(frame);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        sizePolicy.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy);
        widget_4->setStyleSheet(QString::fromUtf8("border: 0 px solid black;\n"
"background-color: rgb(255, 255, 255);"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 9);
        dateComboBox = new QComboBox(widget_4);
        dateComboBox->setObjectName(QString::fromUtf8("dateComboBox"));
        sizePolicy.setHeightForWidth(dateComboBox->sizePolicy().hasHeightForWidth());
        dateComboBox->setSizePolicy(sizePolicy);
        dateComboBox->setStyleSheet(QString::fromUtf8("text-align: left;          /* \346\226\207\346\234\254\346\260\264\345\271\263\345\257\271\351\275\220\346\226\271\345\274\217\344\270\272\345\267\246\345\257\271\351\275\220 */\n"
"padding-left: 20px;        /* \345\267\246\344\276\247\345\206\205\350\276\271\350\267\235\344\270\272 20 \345\203\217\347\264\240 */\n"
"qproperty-icon: url(:/res/Icon/8666670_arrow_right_circle_icon.png);   /* \350\256\276\347\275\256\345\233\276\346\240\207\344\270\272\347\273\231\345\256\232\350\267\257\345\276\204\344\270\213\347\232\204\345\233\276\345\203\217 */\n"
"       \n"
"/*border-radius: 10px;*/   /* \346\263\250\351\207\212\346\216\211\357\274\214\344\270\215\345\272\224\347\224\250\345\234\206\350\247\222\345\215\212\345\276\204\344\270\272 10 \345\203\217\347\264\240\347\232\204\346\225\210\346\236\234 */\n"
"padding: 5px;              /* \345\206\205\350\276\271\350\267\235\344\270\272 5 \345\203\217\347\264\240 */\n"
"background-color: white;   /* \350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\347\231"
                        "\275\350\211\262 */\n"
"color: black;              /* \346\226\207\346\234\254\351\242\234\350\211\262\344\270\272\351\273\221\350\211\262 */\n"
"border: 1px solid gray;    /* \350\276\271\346\241\206\346\240\267\345\274\217\344\270\272 1 \345\203\217\347\264\240\345\256\275\347\232\204\347\201\260\350\211\262\345\256\236\347\272\277\350\276\271\346\241\206 */\n"
"/* \350\256\276\347\275\256\351\230\264\345\275\261\346\225\210\346\236\234 */\n"
"\n"
"border-style: outset;      /* \350\276\271\346\241\206\346\240\267\345\274\217\344\270\272\345\207\270\345\207\272\346\225\210\346\236\234 */\n"
"border-width: 1px;         /* \350\276\271\346\241\206\345\256\275\345\272\246\344\270\272 1 \345\203\217\347\264\240 */\n"
"    \n"
"padding: 4px;        /* \346\263\250\351\207\212\346\216\211\357\274\214\344\270\215\345\272\224\347\224\250\345\206\205\350\276\271\350\267\235\344\270\272 4 \345\203\217\347\264\240\347\232\204\346\225\210\346\236\234 */\n"
"/*margin: 8px;   */            /* \345\244\226\350\276\271\350\267"
                        "\235\344\270\272 8 \345\203\217\347\264\240 */\n"
"qproperty-shadow: 5px 5px 5px rgba(0, 0, 0, 150);   /* \350\256\276\347\275\256\351\230\264\345\275\261\346\225\210\346\236\234\344\270\272 5 \345\203\217\347\264\240\347\232\204\345\201\217\347\247\273\345\222\214\346\214\207\345\256\232\347\232\204\351\242\234\350\211\262\345\200\274 */\n"
" border-radius: 0px; /* \350\256\276\347\275\256\345\233\233\350\247\222\347\232\204\345\234\206\346\273\221\345\215\212\345\276\204 */"));
        dateComboBox->setEditable(true);

        horizontalLayout_4->addWidget(dateComboBox);

        comboBox1 = new QComboBox(widget_4);
        comboBox1->setObjectName(QString::fromUtf8("comboBox1"));
        sizePolicy.setHeightForWidth(comboBox1->sizePolicy().hasHeightForWidth());
        comboBox1->setSizePolicy(sizePolicy);
        comboBox1->setStyleSheet(QString::fromUtf8("text-align: left;          /* \346\226\207\346\234\254\346\260\264\345\271\263\345\257\271\351\275\220\346\226\271\345\274\217\344\270\272\345\267\246\345\257\271\351\275\220 */\n"
"padding-left: 20px;        /* \345\267\246\344\276\247\345\206\205\350\276\271\350\267\235\344\270\272 20 \345\203\217\347\264\240 */\n"
"qproperty-icon: url(:/res/Icon/8666670_arrow_right_circle_icon.png);   /* \350\256\276\347\275\256\345\233\276\346\240\207\344\270\272\347\273\231\345\256\232\350\267\257\345\276\204\344\270\213\347\232\204\345\233\276\345\203\217 */\n"
"       \n"
"/*border-radius: 10px;*/   /* \346\263\250\351\207\212\346\216\211\357\274\214\344\270\215\345\272\224\347\224\250\345\234\206\350\247\222\345\215\212\345\276\204\344\270\272 10 \345\203\217\347\264\240\347\232\204\346\225\210\346\236\234 */\n"
"padding: 5px;              /* \345\206\205\350\276\271\350\267\235\344\270\272 5 \345\203\217\347\264\240 */\n"
"background-color: white;   /* \350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\347\231"
                        "\275\350\211\262 */\n"
"color: black;              /* \346\226\207\346\234\254\351\242\234\350\211\262\344\270\272\351\273\221\350\211\262 */\n"
"border: 1px solid gray;    /* \350\276\271\346\241\206\346\240\267\345\274\217\344\270\272 1 \345\203\217\347\264\240\345\256\275\347\232\204\347\201\260\350\211\262\345\256\236\347\272\277\350\276\271\346\241\206 */\n"
"/* \350\256\276\347\275\256\351\230\264\345\275\261\346\225\210\346\236\234 */\n"
"\n"
"border-style: outset;      /* \350\276\271\346\241\206\346\240\267\345\274\217\344\270\272\345\207\270\345\207\272\346\225\210\346\236\234 */\n"
"border-width: 1px;         /* \350\276\271\346\241\206\345\256\275\345\272\246\344\270\272 1 \345\203\217\347\264\240 */\n"
"    \n"
"padding: 4px;        /* \346\263\250\351\207\212\346\216\211\357\274\214\344\270\215\345\272\224\347\224\250\345\206\205\350\276\271\350\267\235\344\270\272 4 \345\203\217\347\264\240\347\232\204\346\225\210\346\236\234 */\n"
"/*margin: 8px;   */            /* \345\244\226\350\276\271\350\267"
                        "\235\344\270\272 8 \345\203\217\347\264\240 */\n"
"qproperty-shadow: 5px 5px 5px rgba(0, 0, 0, 150);   /* \350\256\276\347\275\256\351\230\264\345\275\261\346\225\210\346\236\234\344\270\272 5 \345\203\217\347\264\240\347\232\204\345\201\217\347\247\273\345\222\214\346\214\207\345\256\232\347\232\204\351\242\234\350\211\262\345\200\274 */\n"
" border-radius: 0px; /* \350\256\276\347\275\256\345\233\233\350\247\222\347\232\204\345\234\206\346\273\221\345\215\212\345\276\204 */"));
        comboBox1->setEditable(true);

        horizontalLayout_4->addWidget(comboBox1);

        comboBox2 = new QComboBox(widget_4);
        comboBox2->setObjectName(QString::fromUtf8("comboBox2"));
        sizePolicy.setHeightForWidth(comboBox2->sizePolicy().hasHeightForWidth());
        comboBox2->setSizePolicy(sizePolicy);
        comboBox2->setStyleSheet(QString::fromUtf8("text-align: left;          /* \346\226\207\346\234\254\346\260\264\345\271\263\345\257\271\351\275\220\346\226\271\345\274\217\344\270\272\345\267\246\345\257\271\351\275\220 */\n"
"padding-left: 20px;        /* \345\267\246\344\276\247\345\206\205\350\276\271\350\267\235\344\270\272 20 \345\203\217\347\264\240 */\n"
"qproperty-icon: url(:/res/Icon/8666670_arrow_right_circle_icon.png);   /* \350\256\276\347\275\256\345\233\276\346\240\207\344\270\272\347\273\231\345\256\232\350\267\257\345\276\204\344\270\213\347\232\204\345\233\276\345\203\217 */\n"
"       \n"
"/*border-radius: 10px;*/   /* \346\263\250\351\207\212\346\216\211\357\274\214\344\270\215\345\272\224\347\224\250\345\234\206\350\247\222\345\215\212\345\276\204\344\270\272 10 \345\203\217\347\264\240\347\232\204\346\225\210\346\236\234 */\n"
"padding: 5px;              /* \345\206\205\350\276\271\350\267\235\344\270\272 5 \345\203\217\347\264\240 */\n"
"background-color: white;   /* \350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\347\231"
                        "\275\350\211\262 */\n"
"color: black;              /* \346\226\207\346\234\254\351\242\234\350\211\262\344\270\272\351\273\221\350\211\262 */\n"
"border: 1px solid gray;    /* \350\276\271\346\241\206\346\240\267\345\274\217\344\270\272 1 \345\203\217\347\264\240\345\256\275\347\232\204\347\201\260\350\211\262\345\256\236\347\272\277\350\276\271\346\241\206 */\n"
"/* \350\256\276\347\275\256\351\230\264\345\275\261\346\225\210\346\236\234 */\n"
"\n"
"border-style: outset;      /* \350\276\271\346\241\206\346\240\267\345\274\217\344\270\272\345\207\270\345\207\272\346\225\210\346\236\234 */\n"
"border-width: 1px;         /* \350\276\271\346\241\206\345\256\275\345\272\246\344\270\272 1 \345\203\217\347\264\240 */\n"
"    \n"
"padding: 4px;        /* \346\263\250\351\207\212\346\216\211\357\274\214\344\270\215\345\272\224\347\224\250\345\206\205\350\276\271\350\267\235\344\270\272 4 \345\203\217\347\264\240\347\232\204\346\225\210\346\236\234 */\n"
"/*margin: 8px;   */            /* \345\244\226\350\276\271\350\267"
                        "\235\344\270\272 8 \345\203\217\347\264\240 */\n"
"qproperty-shadow: 5px 5px 5px rgba(0, 0, 0, 150);   /* \350\256\276\347\275\256\351\230\264\345\275\261\346\225\210\346\236\234\344\270\272 5 \345\203\217\347\264\240\347\232\204\345\201\217\347\247\273\345\222\214\346\214\207\345\256\232\347\232\204\351\242\234\350\211\262\345\200\274 */\n"
" border-radius: 0px; /* \350\256\276\347\275\256\345\233\233\350\247\222\347\232\204\345\234\206\346\273\221\345\215\212\345\276\204 */"));
        comboBox2->setEditable(true);

        horizontalLayout_4->addWidget(comboBox2);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 2);
        horizontalLayout_4->setStretch(2, 2);

        verticalLayout_3->addWidget(widget_4);

        stackedWidget = new QStackedWidget(frame);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        matWidget = new MatCurve();
        matWidget->setObjectName(QString::fromUtf8("matWidget"));
        sizePolicy.setHeightForWidth(matWidget->sizePolicy().hasHeightForWidth());
        matWidget->setSizePolicy(sizePolicy);
        stackedWidget->addWidget(matWidget);
        attentionWidget = new AttentionWidget();
        attentionWidget->setObjectName(QString::fromUtf8("attentionWidget"));
        sizePolicy.setHeightForWidth(attentionWidget->sizePolicy().hasHeightForWidth());
        attentionWidget->setSizePolicy(sizePolicy);
        stackedWidget->addWidget(attentionWidget);
        finishWidget = new GameFinishWidget();
        finishWidget->setObjectName(QString::fromUtf8("finishWidget"));
        sizePolicy.setHeightForWidth(finishWidget->sizePolicy().hasHeightForWidth());
        finishWidget->setSizePolicy(sizePolicy);
        stackedWidget->addWidget(finishWidget);

        verticalLayout_3->addWidget(stackedWidget);

        widget_7 = new QWidget(frame);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setStyleSheet(QString::fromUtf8("border: 0px solid black;"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        showBtn = new QPushButton(widget_7);
        showBtn->setObjectName(QString::fromUtf8("showBtn"));
        sizePolicy1.setHeightForWidth(showBtn->sizePolicy().hasHeightForWidth());
        showBtn->setSizePolicy(sizePolicy1);
        showBtn->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"\n"
"\n"
" \n"
"            /*text-align: left;\n"
"            padding-left: 20px;*/\n"
" qproperty-icon: url(:/res/Icon/8666818_disc_cd_dvd_icon.png);\n"
"    min-width: 50px; max-width: 50px; min-height: 	50px; max-height: 50px; \n"
"     qproperty-iconSize: 70px; \n"
"    /*background-image: url(:/res/Icon/8666818_disc_cd_dvd_icon.png);  /* \350\256\276\347\275\256\350\203\214\346\231\257\345\233\276\345\203\217\350\267\257\345\276\204 */\n"
"    background-position: center center;  /* \345\260\206\350\203\214\346\231\257\345\233\276\345\203\217\345\261\205\344\270\255\346\230\276\347\244\272 */\n"
"    background-repeat: no-repeat;  /* \347\246\201\346\255\242\351\207\215\345\244\215\350\203\214\346\231\257\345\233\276\345\203\217 */\n"
"    padding: 0;  /* \346\270\205\351\231\244\346\214\211\351\222\256\347\232\204\345\206\205\350\276\271\350\267\235\357\274\214\347\241\256\344\277\235\345\233\276\346\240\207\345\261\205\344\270\255 */\n"
"\n"
"       \n"
"    border-radius: 30px;"
                        "\n"
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

        horizontalLayout_5->addWidget(showBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(widget_7);

        verticalLayout_3->setStretch(0, 2);
        verticalLayout_3->setStretch(1, 25);
        verticalLayout_3->setStretch(2, 1);

        horizontalLayout_3->addWidget(frame);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 4);

        verticalLayout_4->addWidget(widget_6);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 15);

        verticalLayout_5->addWidget(frame_2);


        horizontalLayout_6->addWidget(widget_8);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logoutBtn->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\207\272", nullptr));
        queryEdit->setText(QString());
        queryBtn->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        selectButton->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266\345\244\271", nullptr));
        dateComboBox->setCurrentText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\350\242\253\346\265\213\346\227\245\346\234\237", nullptr));
        comboBox1->setCurrentText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\347\254\254\345\207\240\346\254\241\346\265\213\350\257\225\347\273\223\346\236\234", nullptr));
        comboBox2->setCurrentText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\225\260\346\215\256\347\261\273\345\236\213", nullptr));
        showBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
