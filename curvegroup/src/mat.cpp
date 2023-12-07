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
vector<QString> MAT::readChanlocs(QString filePath){

    mat_t *pMatFile = 0;
    matvar_t *pMatVar = 0;
    vector<QString> d;
    pMatFile = Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY);

    if(!pMatFile) {
        qDebug() << "Failed to Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY)";
        return d;
    }
    pMatVar = Mat_VarReadNext(pMatFile);//读入mat文件中的cell变量data

    // 读取chanlocs结构体数据
    matvar_t *pChanlocsVar = Mat_VarGetStructFieldByName(pMatVar, "chanlocs", 0);


    for (unsigned int var = 0; var < pChanlocsVar->dims[0]; ++var) {
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
//    for (const auto& value : d) {
//        qDebug() << value << " ";
//    }
    Mat_Close(pMatFile);
    pMatFile = 0;
    return d;
}

vector<double> MAT::readData(QString filePath){
    mat_t *pMatFile = 0;
    matvar_t *pMatVar = 0; // 打开mat文件
    //读取文件
    //vector保存数据
    vector<double> d;
    pMatFile = Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY);
    if(!pMatFile) {
        qDebug() << "Failed to Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY)";
        return d;
    }
    pMatVar = Mat_VarReadNext(pMatFile);//读入mat文件中的cell变量data
    matvar_t *pDataVar = Mat_VarGetStructFieldByName(pMatVar, "data",0);

    //    if (pMatVar->class_type == MAT_C_STRUCT) {qDebug()<<11;}
    double* ddd;
    //data数据为31*1000的double数据
    ddd = (double*)malloc(pDataVar->dims[0]*pDataVar->dims[1]*sizeof(double));
    //设置读取方法和读取的数据
    int   start[2],stride[2],edge[2];
    start[0]=0;start[1]=0;//数组起始下标；第一个数下标为0
    stride[0]=1;stride[1]=1;//读数组是跨步步距，参照Matlab中的格式——start:stride:edge
    edge[0]=pDataVar->dims[0];edge[1]=pDataVar->dims[1];//数组终止下标
    if (pDataVar && pDataVar->class_type == MAT_C_DOUBLE) {
        //读取并保存
        Mat_VarReadData(pMatFile, pDataVar, ddd, start, stride, edge);
        if (ddd) {
            // 输出数据
            for (unsigned int i = 0; i < pDataVar->dims[0]; i++) {
                for (unsigned int j = 0; j < pDataVar->dims[1]; j++) {
                    double value = ddd[i * pDataVar->dims[1] + j];
                    // 处理每个元素的值
                    d.push_back(value);
                }
            }
            // 释放数据内存
            Mat_VarFree(pDataVar);
            pDataVar = nullptr;
        }
        else{
            qDebug()<<123;
        }
//        if (d.empty()) {
//            qDebug() << "Vector is empty.";
//        } else {
//            qDebug() << "Vector is not empty.";
//        }
        //输出查看
//        for (const auto& value : d) {
//            qDebug() << value << " ";
//        }
    }
    Mat_Close(pMatFile);
    pMatFile = 0;
    return d;
}
vector<unsigned int> MAT::readEventlatency(QString filePath){
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

    for (unsigned int var = 0; var < pEventVar->dims[0]; ++var) {
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

vector<unsigned int> MAT::readEventtype(QString filePath){
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

    for (unsigned int var = 0; var < pEventVar->dims[0]; ++var) {
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
