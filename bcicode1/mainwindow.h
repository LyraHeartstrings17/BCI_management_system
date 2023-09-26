#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QComboBox>
#include <QPushButton>
#include<QTextEdit>
#include <QMainWindow>
#include<QWebEngineView>
#include<QVector>
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
    void receiveLogin();
private slots:
    void queryData();//搜索文件
    void checkSelection(); // 检查选择的槽函数

    //不同选择展现不同图片
    void comboBox1IndexChanged(int index);
    void comboBox2IndexChanged(int index);
    void buttonClicked();

    //搜索栏设置
    //void onLineEditTextChanged(const QString& text);
    void onTextEditTextChanged();
    //接受登录信号

private:
    QComboBox *comboBox1;
    QComboBox *comboBox2;
    QPushButton *btn1;
    QStringList ListWidgetItems;//保存原始的items
    QStringList filesPath;//保存各个文件路径
    int fileIndex;
    int currentIndex1; // comboBox1的当前选择项索引
    int currentIndex2; // comboBox2的当前选择项索引
    void Updata(const vector<QString> &name,const vector<int> &data);
   //搜索栏操作

    QLineEdit* m_lineEdit;
    QTextEdit* m_scrollArea;
    QCompleter* m_completer;
    //QStringList options;

    //QCompleter *m_completer;

};


#endif // MAINWINDOW_H
