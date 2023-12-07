#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QComboBox>
#include <QPushButton>
#include<QTextEdit>
#include <QMainWindow>
#include<QVector>
#include<attentionwidget/attentionwidget.h>
#include<gamefinfishwidget/gamefinishwidget.h>
#include<matcurve/matCurve.h>
QT_BEGIN_NAMESPACE
using namespace std;
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
public slots:
    //接受登录信号
    void receiveLogin();
private slots:
    void queryData();//搜索文件功能
    void checkSelection(); // 检查选择的槽函数
    void buttonClicked();//展示图片
signals:
    void LogoutSignal();  //登出的信号
private:
    QString basePath;//展示ListWidget的当前路径
    QStringList ListWidgetItems;//保存原始的items
    QString chooseFilePath;//要展示图像的路径
    int currentIndex1; // comboBox1的当前选择项索引
    int currentIndex2; // comboBox2的当前选择项索引
    int flag = 1;
    void initListWidget(QString);//初始化ListWidget
    void initComboBox();//初始化ComboBox
    void resetComboBox();//重置ComboBox
    void initStackedWidget();//初始化StackedWidget
};


#endif // MAINWINDOW_H
