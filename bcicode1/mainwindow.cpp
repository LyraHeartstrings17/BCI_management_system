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
#include<QWebEngineView>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    m_completer(nullptr)
{
    ui->setupUi(this);
    // 设置默认选项
    //ui->comboBox1->setPlaceholderText("按测试次数查看");
    //ui->comboBox2->setPlaceholderText("按数据类型查看");

    ui->comboBox1->setEditable(false); // 禁用编辑模式，只能选择
    ui->comboBox2->setEditable(false); // 禁用编辑模式，只能选择
    ui->radio_widget->setContextMenuPolicy(Qt::NoContextMenu);
    ui->radio_widget->load(QUrl("C:/Users/10781/Documents/qt_files/chart/Echarts/radar.html"));

    ui->line_widget->setContextMenuPolicy(Qt::NoContextMenu);
    ui->line_widget->load(QUrl("C:/Users/10781/Documents/qt_files/chart/Echarts/line1.html"));


    // 添加选项文本
    ui->comboBox1->addItem("按测试次数查看");
    ui->comboBox1->addItem("整体");
    ui->comboBox1->addItem("1");
    ui->comboBox1->addItem("2");
    ui->comboBox2->addItem("按数据类型查看");
    ui->comboBox2->addItem("脑电数据");
    ui->comboBox2->addItem("注意力指标");
    ui->comboBox2->addItem("游戏结算数据");


    //选择一项且没有全部选择时可点击开始
    //下拉框状态改变时判断是否能显示图片
    connect(ui->comboBox1, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::checkSelection);
    connect(ui->comboBox2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::checkSelection);

    //初始时显示图片btn无法点击
    ui->btn1->setEnabled(false);

    //第一行这行代码将 QTextEdit 控件设置为只读模式。也就是说，用户无法通过键盘或鼠标编辑或修改 QTextEdit 中的文本内容。
    //第二行行代码设置 QTextEdit 的垂直滚动条策略为始终显示。当 QTextEdit 的内容超过可以显示的区域时，会出现垂直滚动条，以便用户可以滚动查看文本的全部内容。

    //ui->textEdit->setReadOnly(true);
    //ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    // 创建QCompleter(QCompleter 根据用户的输入，在一个预定义的选项列表中进行匹配，并为用户提供可能的选项。它可以帮助用户快速输入和选择正确的选项。)
    QStringList options;


    options << "Option1" << "Option2" << "Option3"<< "Option1" << "Option2" << "Option3"<< "Option1" << "Option2" << "Option3";
    m_completer = new QCompleter(options, this);
    m_completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->queryEdit->setCompleter(m_completer);

    //连接文本更改信号
    connect(ui->queryEdit, &QLineEdit::textChanged, this, &MainWindow::onTextEditTextChanged);
    //静态
    ui->listWidget->setMovement(QListView::Static);
    //横向布局
    ui->listWidget->setFlow(QListWidget::TopToBottom);
    QDir dir("C:\\Users\\10781\\Desktop\\雷达数据");
    //    dir.setNameFilters(QStringList("*.bci"));
    QFileInfoList fileList = dir.entryInfoList(QDir::NoDotAndDotDot|QDir::Dirs);  // 获取目录中的子目录列表
    int dirCount = fileList.count();
    //用于保存文件名
    for(int i=0;i<dirCount;i++)
    {
        QFileInfo dirInfo = fileList.at(i);
        QDir dir2(dirInfo.canonicalFilePath());
        QFileInfoList fileList2 = dir2.entryInfoList(QDir::NoDotAndDotDot|QDir::Files);  // 获取目录中的子目录列表
        for(int j=0;j<fileList2.size();j++)
        {
            QFileInfo fileInfo = fileList2.at(j);
            this->ListWidgetItems<<fileInfo.fileName();
            this->filesPath<<fileInfo.absoluteFilePath();
            ui->listWidget->addItem(fileInfo.fileName());
            //qDebug()<<fileInfo.canonicalFilePath()<<"+"<<fileInfo.fileName();
        }
    }
    //按下搜索按钮触发搜索事件
    connect(ui->queryBtn, &QPushButton::clicked, this, &MainWindow::queryData);
    //qDebug()<<this->ListWidgetItems;
    //单击文件查看进行选择
    connect(ui->listWidget,&QListWidget::itemClicked,[=](QListWidgetItem *item){
        this->fileIndex = this->ListWidgetItems.indexOf(item->text());
    });
    //不同选项显示不同图片
    // 连接comboBox1的currentIndexChanged信号到槽函数comboBox1IndexChanged
    connect(ui->comboBox1, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::comboBox1IndexChanged);

    // 连接comboBox2的currentIndexChanged信号到槽函数comboBox2IndexChanged
    connect(ui->comboBox2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::comboBox2IndexChanged);

    // 连接button的clicked信号到槽函数on_button_clicked
    connect(ui->btn1, &QPushButton::clicked, this, &MainWindow::buttonClicked);

    // 初始状态设置 button 不可点击
    ui->btn1->setEnabled(false);
}



//当两个选择其中一种时才能点击开始按钮
void MainWindow::checkSelection()
{
    // 两个combobox选择其中之一且没有同时选择
    if ((ui->comboBox1->currentIndex() != 0 || ui->comboBox2->currentIndex() != 0 )&&!(ui->comboBox1->currentIndex() != 0 && ui->comboBox2->currentIndex() != 0 )) {
        // 两个combobox选择其中之一且没有同时选择，按钮可以点击
        ui->btn1->setEnabled(true);
    } else {
        // 两个都选择或两个都没有选择，按钮不可点击
        ui->btn1->setEnabled(false);
    }
}


//不同选择组合展出不同图片
void MainWindow::comboBox1IndexChanged(int index)
{
    currentIndex1 = index;
}

void MainWindow::comboBox2IndexChanged(int index)
{
    currentIndex2 = index;
}


void MainWindow::buttonClicked()
{
//    // 加载并显示第一张图片
//    QString imageName1 = QString(":/image/image_%1_%2.png").arg(currentIndex1).arg(currentIndex2);
//    QPixmap image1(imageName1);
//    ui->label1->setScaledContents(true);
//    ui->label1->setPixmap(image1);

//    // 加载并显示第二张图片
//    QString imageName2 = QString(":/image/image_%1_%2.png").arg(currentIndex1).arg(currentIndex2); // 根据需要修改文件名或路径
//    QPixmap image2(imageName2);
//    ui->label2->setScaledContents(true);
//    ui->label2->setPixmap(image2);


//    // 根据currentIndex1和currentIndex2的值加载并显示对应的图片
//    //QString imageName = QString(":/image/image_%1_%2.png").arg(currentIndex1).arg(currentIndex2);
//    QString imageName1 = QString(":/image/softewareoutline.png");
//    QPixmap image1(imageName1);
//    ui->label1->setScaledContents(true);
//    ui->label1->setPixmap(image1);

//    QString imageName2 = QString(":/image/softwareoutline.png");
//    QPixmap image2(imageName2);
//    ui->label2->setScaledContents(true);
//    ui->label2->setPixmap(image2);
    QString fileName = this->filesPath[this->fileIndex];
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            QStringList lines;
            while (!in.atEnd())
            {
                QString line = in.readLine();
                lines.append(line);
            }
            file.close();

            // 解析读取的数据
            vector<QString> name;
            vector<int> data;
            for (int i = 0; i < lines.size()/2+1; i++)
            {
                QStringList parts = lines[i].split("=");
                if (parts.size() == 2)
                {
                    QString indicatorName = parts[0].trimmed();
                    int value = parts[1].toInt();
                    name.push_back(indicatorName);
                    data.push_back(value);
                }
            }

            // 调用Updata函数
            Updata(name, data);
        }
        else
        {
            qDebug() << "Failed to open file: " << file.errorString();
        }
    }
}


//搜索框自动补全textedit
void MainWindow::onTextEditTextChanged()
{
    QString text = ui->queryEdit->text().trimmed();

    // 获取选项列表
    QStringList options = static_cast<QStringListModel*>(m_completer->model())->stringList();

    if (!text.isEmpty() && options.contains(text, Qt::CaseInsensitive)) {
        // 添加选项到 QCompleter
        QStringList matchingOptions;
        for (const QString &option : options) {
            if (option.startsWith(text, Qt::CaseInsensitive)) {
                matchingOptions.append(option);
            }
        }

        // 创建新的 QStringListModel
        QStringListModel *model = new QStringListModel(matchingOptions, m_completer);
        m_completer->setModel(model);
    } else {
        // 使用原始的 options 列表
        m_completer->setModel(new QStringListModel(options, m_completer));
    }
}
//接受登录信号显示窗口
void MainWindow::receiveLogin()
{
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
//展示图片
void MainWindow::Updata(const vector<QString> &name, const vector<int> &data)
{
    QString jscode = "onDataReceived([";
    for(int i=0;i<name.size();i++)
    {
        jscode += QString("\"%1\"").arg(name[i]);
        if(i<name.size()-1)
            jscode += ",";
    }
    jscode += "],[";

    for(int i=0;i<data.size();i++)
    {
        jscode += QString::number(data[i]);
        if(i<data.size()-1)
            jscode += ",";
    }
    jscode += "])";
    ui->radio_widget->page()->runJavaScript(jscode.toUtf8());
    ui->line_widget->page()->runJavaScript(jscode.toUtf8());
}
MainWindow::~MainWindow()
{
    delete ui;
}

