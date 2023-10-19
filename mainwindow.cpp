#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<QVBoxLayout>
#include <QCompleter>
#include <QTextEdit>
#include <QStringList>
#include <QStringListModel>
#include<QAbstractItemModel>
#include<QListView>
#include<QDir>
#include<QAbstractItemView>
#include<QMessageBox>
#include<QCoreApplication>
#include<login/logininwidget.h>
#include<QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化下拉框
    this->initComboBox();
    //初始化ListWidget
    this->initListWidget();
    //初始化分页
    this->initStackedWidget();
    //按下展示按钮展示图片
    connect(ui->showBtn, &QPushButton::clicked, this, &MainWindow::buttonClicked);
    //按下登出按钮发送登出信号
    connect(ui->logoutBtn,&QPushButton::clicked,[=](){
        emit this->LogoutSignal();
        this->close();
    });
}



//当所有下拉框都选择才能点击展示按钮
void MainWindow::checkSelection()
{
    //选择了日期，根据日期添加次数下拉框的内容
    if(ui->dateComboBox->currentIndex()!=0)
    {
        //防止重复添加下拉框内容
        if(ui->comboBox1->count() <= 1)
        {
            QString date = ui->dateComboBox->currentText();
            QString path = this->chooseFilePath;
            path.append("/").append(date);
            QDir d(path);
            QFileInfoList fileList = d.entryInfoList(QDir::NoDotAndDotDot|QDir::Dirs);
            for(int i=0;i<fileList.size();i++)
            {
                QFileInfo nameDirInfo = fileList.at(i);
                ui->comboBox1->addItem(nameDirInfo.fileName());
            }
        }
        if(ui->comboBox1->currentIndex()!=0 && ui->comboBox2->currentIndex()!=0)
        {
            ui->showBtn->setEnabled(true);
        }
        else
        {
            ui->showBtn->setEnabled(false);
        }
    }
    else
    {
        ui->showBtn->setEnabled(false);
    }
}
//展示图片
void MainWindow::buttonClicked()
{
    QString fileName = this->chooseFilePath;
    fileName.append("/").append(ui->dateComboBox->currentText()).append("/").append(ui->comboBox1->currentText());
    qDebug()<<fileName;
    if (!fileName.isEmpty())
    {
        ui->radio_widget->setGameFilePath(fileName);
        ui->radio_widget->showWidget();
    }
    else
    {
        qDebug() << "Failed to open file";
    }
}


//接受登录信号显示窗口
void MainWindow::receiveLogin()
{
    LoginInWidget l;
    l.show();
    this->show();
}
//搜索文件
void MainWindow::queryData()
{

    ui->listWidget->clear();
    ui->listWidget->addItems(this->ListWidgetItems);
    QString fileName = ui->queryEdit->text();
    QList<QListWidgetItem *> list;
    list =  ui->listWidget->findItems(fileName,Qt::MatchStartsWith);
    if(!list.empty())
    {
        QStringList filesList;
        for(int i=0;i<list.length();i++)
        {
            filesList<<list.at(i)->text();
        }
        ui->listWidget->clear();
        for(int i =0;i<filesList.length();i++)
        {
            ui->listWidget->addItem(filesList.at(i));
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("请重试！");
        msgBox.setWindowTitle("没有匹配的文件");
        msgBox.exec();
    }
}
//初始化ListWidget
void MainWindow::initListWidget()
{
    //静态
    ui->listWidget->setMovement(QListView::Static);
    //横向布局
    ui->listWidget->setFlow(QListWidget::TopToBottom);
    this->basePath = "C:/Users/10781/Desktop/雷达数据";
    QDir dir(this->basePath);
    QFileInfoList fileList = dir.entryInfoList(QDir::NoDotAndDotDot|QDir::Dirs);  // 获取目录中的子目录列表，此时获取到的都是人名;
    //用于保存文件名
    for(int i=0;i<fileList.size();i++)
    {
        QFileInfo nameDirInfo = fileList.at(i);
        ui->listWidget->addItem(nameDirInfo.fileName());
        this->ListWidgetItems<<nameDirInfo.fileName();
    }
    //按下搜索按钮触发搜索事件
    connect(ui->queryBtn, &QPushButton::clicked, this, &MainWindow::queryData);
    //qDebug()<<this->ListWidgetItems;
    //单击文件查看进行选择
    connect(ui->listWidget,&QListWidget::itemClicked,[=](QListWidgetItem *item){
        //重置下拉框防止重复添加下拉框内容
        this->resetComboBox();
        QString path = this->basePath;
        path.append("/").append(item->text());
        this->chooseFilePath = path;
        qDebug()<<this->chooseFilePath;
        //根据选择人名文件夹的内容添加下拉框内容
        QDir d(this->chooseFilePath);
        QFileInfoList fileList = d.entryInfoList(QDir::NoDotAndDotDot|QDir::Dirs);
        //qDebug()<<fileList;
        for(int i=0;i<fileList.size();i++)
        {
            QFileInfo nameDirInfo = fileList.at(i);
            ui->dateComboBox->addItem(nameDirInfo.fileName());
        }
    });
}
void MainWindow::initComboBox()
{
    ui->comboBox1->setEditable(false); // 禁用编辑模式，只能选择
    ui->comboBox2->setEditable(false); // 禁用编辑模式，只能选择
    ui->dateComboBox->setEditable(false);// 禁用编辑模式，只能选择
    // 添加选项文本
    ui->dateComboBox->addItem("被测日期");
    ui->comboBox1->addItem("被测次数");
    ui->comboBox2->addItem("数据类型");
    ui->comboBox2->addItem("脑电数据");
    ui->comboBox2->addItem("注意力指标");
    ui->comboBox2->addItem("游戏结算数据");
    //下拉框状态改变时判断是否能显示图片
    connect(ui->comboBox1, &QComboBox::activated, this, &MainWindow::checkSelection);
    connect(ui->comboBox2, &QComboBox::activated, this, &MainWindow::checkSelection);
    connect(ui->dateComboBox, &QComboBox::activated, this, &MainWindow::checkSelection);
    //初始时显示图片btn无法点击
    ui->showBtn->setEnabled(false);
}
void MainWindow::resetComboBox()
{
    ui->dateComboBox->clear();
    ui->dateComboBox->addItem("被测日期");
    ui->comboBox1->clear();
    ui->comboBox1->addItem("被测次数");
    ui->comboBox2->setCurrentIndex(0);
}
void MainWindow::initStackedWidget()
{
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->comboBox2, &QComboBox::activated,[=](){
        if(ui->comboBox2->currentIndex())//下拉框不是默认才触发
        {
            ui->stackedWidget->setCurrentIndex(ui->comboBox2->currentIndex()-1);
        }
    });
}
MainWindow::~MainWindow()
{
    delete ui;
}


