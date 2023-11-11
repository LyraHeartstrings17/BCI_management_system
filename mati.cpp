#include "mati.h"
#include "QDebug"
#include <QTextStream>
#include<QFile>
#include <iostream>
#include<QFileDialog>

using namespace std;
MATI::MATI(QObject *parent):QObject(parent)
{
}

MATI::~MATI()
{
}

void MATI::readEvent(QString filePath){
    mat_t *pMatFile = 0;
    matvar_t *pMatVar = 0;
    pMatFile = Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY);

    if(!pMatFile) {
        qDebug() << "Failed to Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY)";
        return;
    }
    pMatVar = Mat_VarReadNext(pMatFile);
    //读取event结构体数据
    matvar_t *pEventVar = Mat_VarGetStructFieldByName(pMatVar, "event", 0);

//    Mat_VarPrint(pEventVar,2);//查看数据与数据类型

    vector<unsigned int>latency;
    vector<unsigned int>type;

//    qDebug()<<pEventVar->dims[0];
//    qDebug()<<pEventVar->class_type;
//    matvar_t *platencyVar = Mat_VarGetStructFieldByName(pEventVar, "latency", 0);
//    qDebug()<<platencyVar->class_type;//数据类型为13-》MAT_C_UINT32

    for (int var = 0; var < pEventVar->dims[0]; ++var) {
        matvar_t *platencyVar = Mat_VarGetStructFieldByName(pEventVar, "latency", var);
        if (platencyVar && platencyVar->class_type == MAT_C_UINT32) {

            unsigned int* latencyData = static_cast<unsigned int*>(platencyVar->data);
            latency.push_back(*latencyData);
        }
    }
//    matvar_t *ptypeVar = Mat_VarGetStructFieldByName(pEventVar, "type", 0);
//    qDebug()<<ptypeVar->class_type;//数据类型也为13-MAT_C_UINT32
    for (int var = 0; var < pEventVar->dims[0]; ++var) {
        matvar_t *ptypeVar = Mat_VarGetStructFieldByName(pEventVar, "type", var);
        if (ptypeVar && ptypeVar->class_type == MAT_C_UINT32) {
            unsigned int* typeData = static_cast<unsigned int*>(ptypeVar->data);
            type.push_back(*typeData);
        }
    }
    qDebug() << type << " ";
    qDebug() << latency << " ";



}






void MATI::readChanlocs(QString filePath){

    mat_t *pMatFile = 0;
    matvar_t *pMatVar = 0;
    pMatFile = Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY);

    if(!pMatFile) {
        qDebug() << "Failed to Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY)";
        return;
    }
    pMatVar = Mat_VarReadNext(pMatFile);//读入mat文件中的cell变量data

    // 读取chanlocs结构体数据
    matvar_t *pChanlocsVar = Mat_VarGetStructFieldByName(pMatVar, "chanlocs", 0);

    vector<QString> d;

    for (int var = 0; var < 32; ++var) {
        matvar_t *pDatatypeVar = Mat_VarGetStructFieldByName(pChanlocsVar, "labels", var);
//        qDebug()<<pDatatypeVar->dims[0]<<' '<<pDatatypeVar->dims[1];
        if (pDatatypeVar && pDatatypeVar->class_type == MAT_C_CHAR) {
            char* datatypeData = static_cast<char*>(pDatatypeVar->data);
            // 保存前三个字符到需要的位置
            QString chan = QString::fromUtf8(datatypeData, pDatatypeVar->dims[1]);
            d.push_back(chan);
//            qDebug() << chan;
        }
    }
    for (const auto& value : d) {
        qDebug() << value << " ";
    }
    Mat_Close(pMatFile);
    pMatFile = 0;
}

void MATI::readData(QString filePath){
    mat_t *pMatFile = 0;
    matvar_t *pMatVar = 0; // 打开mat文件
    //读取文件
    pMatFile = Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY);
    if(!pMatFile) {
        qDebug() << "Failed to Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY)";
        return;
    }

    pMatVar = Mat_VarReadNext(pMatFile);//读入mat文件中的cell变量data
    double* ddd;
    ddd = (double*)malloc(32*20000*sizeof(double));

    //设置读取方法和读取的数据
    int   start[2],stride[2],edge[2];
    start[0]=0;start[1]=0;//数组起始下标；第一个数下标为0
    stride[0]=1;stride[1]=1;//读数组是跨步步距，参照Matlab中的格式——start:stride:edge
    edge[0]=32;edge[1]=20000;//数组终止下标
    matvar_t *pDataVar = Mat_VarGetStructFieldByName(pMatVar, "data",0);

    if (pDataVar && pDataVar->class_type == MAT_C_DOUBLE) {
        //vector保存数据
        vector<double> d;
        //读取并保存
        Mat_VarReadData(pMatFile, pDataVar, ddd, start, stride, edge);
        if (ddd) {
            // 输出数据
            for (int i = 0; i < 32; i++) {
                for (int j = 0; j < 1; j++) {
                    double value = ddd[i * 20000 + j];
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

vector<unsigned int> MATI::readEventlatency(QString filePath){
    mat_t *pMatFile = 0;
    matvar_t *pMatVar = 0;
    pMatFile = Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY);
    vector<unsigned int>latency;

    if(!pMatFile) {
        qDebug() << "Failed to Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY)";
        return latency;
    }
    pMatVar = Mat_VarReadNext(pMatFile);
    matvar_t *pEventVar = Mat_VarGetStructFieldByName(pMatVar, "event", 0);

    for (int var = 0; var < pEventVar->dims[0]; ++var) {
        matvar_t *platencyVar = Mat_VarGetStructFieldByName(pEventVar, "latency", var);
        if (platencyVar && platencyVar->class_type == MAT_C_UINT32) {

            unsigned int* latencyData = static_cast<unsigned int*>(platencyVar->data);
            latency.push_back(*latencyData);
        }
    }

//    qDebug() << type << " ";qDebug() << latency << " ";
//
    return latency;
}

vector<unsigned int> MATI::readEventtype(QString filePath){
    mat_t *pMatFile = 0;
    matvar_t *pMatVar = 0;
    pMatFile = Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY);

    vector<unsigned int>type;
    if(!pMatFile) {
        qDebug() << "Failed to Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY)";
        return type;
    }
    pMatVar = Mat_VarReadNext(pMatFile);
    matvar_t *pEventVar = Mat_VarGetStructFieldByName(pMatVar, "event", 0);

    for (int var = 0; var < pEventVar->dims[0]; ++var) {
        matvar_t *ptypeVar = Mat_VarGetStructFieldByName(pEventVar, "type", var);
        if (ptypeVar && ptypeVar->class_type == MAT_C_UINT32) {
            unsigned int* typeData = static_cast<unsigned int*>(ptypeVar->data);
            type.push_back(*typeData);
        }
    }
    //    qDebug() << type << " ";qDebug() << latency << " ";
    //
    return type;
}
