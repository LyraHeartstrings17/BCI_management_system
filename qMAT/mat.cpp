#include "mat.h"
#include "QDebug"
#include "QFile"
using namespace std;
MAT::MAT(QObject *parent):QObject(parent)
{
}

MAT::~MAT()
{
}



void MAT::readData(QString filePath){
    mat_t *pMatFile = 0;
    matvar_t *pMatVar = 0; // 打开mat文件
    //读取文件
    pMatFile = Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY);
    if(!pMatFile) {
        qDebug() << "Failed to Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY)";
        return;
    }

    pMatVar = Mat_VarReadNext(pMatFile);//读入mat文件中的cell变量data
    //    if (pMatVar->class_type == MAT_C_STRUCT) {qDebug()<<11;}
    double* ddd;
    //data数据为31*1000的double数据
    ddd = (double*)malloc(31*1000*sizeof(double));


    //设置读取方法和读取的数据
    int   start[2],stride[2],edge[2];
    start[0]=0;start[1]=0;//数组起始下标；第一个数下标为0
    stride[0]=1;stride[1]=1;//读数组是跨步步距，参照Matlab中的格式——start:stride:edge
    edge[0]=31;edge[1]=1000;//数组终止下标
    matvar_t *pDataVar = Mat_VarGetStructFieldByName(pMatVar, "data",0);

    if (pDataVar && pDataVar->class_type == MAT_C_DOUBLE) {
        //vector保存数据
        vector<double> d;
        //读取并保存
        Mat_VarReadData(pMatFile, pDataVar, ddd, start, stride, edge);
        if (ddd) {
            // 输出数据
            for (int i = 0; i < 31; i++) {
                for (int j = 0; j < 1000; j++) {
                    double value = ddd[i * 1000 + j];
                    // 处理每个元素的值

                    d.push_back(value);
                    //                    qDebug()<<1;
                }
            }
            // 释放数据内存
            Mat_VarFree(pDataVar);
            pDataVar = nullptr;
        }
        else{
            qDebug()<<123;
        }
        if (d.empty()) {
            qDebug() << "Vector is empty.";
        } else {
            qDebug() << "Vector is not empty.";
        }
        //输出查看
        for (const auto& value : d) {
            qDebug() << value << " ";
        }

    }


    Mat_Close(pMatFile);
    pMatFile = 0;
}
