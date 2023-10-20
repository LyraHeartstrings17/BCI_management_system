#include <QApplication>
#include "gamefinishwidget.h"
#include"gamefinishdata.h"

#include "QDebug"
int main(int args,char** argv)
{
    QApplication app(args,argv);

    GameFinishWidget w;
    //选择每次的的数据文件夹中的max
    char directory[] = "E:\\ddd\\program\\radatu\\GameFinishWidget\\result\\";
    int i;
    char folder_name[10];
    char full_path[100];
    for (i = 0; i < 7; i++) {
        sprintf(folder_name, "%d", i);
        strcpy(full_path, directory);
        strcat(full_path, folder_name);
        w.setGameFilePath(full_path);

        //读取文件并存储在maxvalue里面
        w.readData();
    }
    w.showWidget();

    w.show();

    app.exec();
}
