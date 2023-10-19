#include <QApplication>
#include "gamefinishwidget.h"
//#include"gamefinishdata.h"

#include "QDebug"
int main(int args,char** argv)
{
    QApplication app(args,argv);

    GameFinishWidget w;
    //选择单次的数据文件夹
    w.setGameFilePath("E:\\ddd\\qtprogram\\GameFinishWidget\\result\\1");

//    w.showWidget();
    char directory[] = "E:\\ddd\\program\\radatu\\GameFinishWidget\\result\\";
    int i;
    char folder_name[10];
    char full_path[100];
    for (i = 0; i < 7; i++) {
        sprintf(folder_name, "%d", i);
        strcpy(full_path, directory);
        strcat(full_path, folder_name);
        w.setGameFilePath(full_path);
        w.showWidget();
        //        printf("访问文件夹：%s\n", full_path); // 示例：打印访问的文件夹路径
    }
    w.show();

    app.exec();
}
