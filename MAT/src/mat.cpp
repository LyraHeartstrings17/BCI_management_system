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
//    matvar_t **matcellvar;
    pMatFile = Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY);
    if(!pMatFile) {
        qDebug() << "Failed to Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY)";
        return;
    }
    // 遍历所有变量
//    pMatVar = Mat_VarReadInfo(pMatFile,"EEG");
//if (pMatVar->class_type == MAT_C_STRUCT) {qDebug()<<11;}
    pMatVar = Mat_VarReadNext(pMatFile);//读入mat文件中的cell变量data
//    if (pMatVar->class_type == MAT_C_STRUCT) {qDebug()<<11;}
    double* ddd;

    ddd = (double*)malloc(31*1000*sizeof(double));



    int   start[2],stride[2],edge[2];
    start[0]=0;start[1]=0;//数组起始下标；第一个数下标为0
    stride[0]=1;stride[1]=1;//读数组是跨步步距，参照Matlab中的格式——start:stride:edge
    edge[0]=31;edge[1]=1000;//数组终止下标
    matvar_t *pDataVar = Mat_VarGetStructFieldByName(pMatVar, "data",0);



//    matcellvar = Mat_VarGetCells(pMatVar,start,stride,edge);
    if (pDataVar && pDataVar->class_type == MAT_C_DOUBLE) {
        // 读取变量的数据
//        double* pData = (double*)Mat_VarReadData(pMatFile, pDataVar, ddd, start, stride, edge);
//        Mat_VarReadData(pMatFile, pDataVar, ddd, start, stride, edge);
        //                qDebug()<<pData;
//        matcellvar = Mat_VarGetCells(pMatVar,start,stride,edge);

//        Mat_VarReadData(pMatFile,*matcellvar,ddd,start,stride,edge);

        vector<double> d;
//        double* pData = (double*)Mat_VarReadData(pMatFile, pDataVar, nullptr, start, stride, edge);
        Mat_VarReadData(pMatFile, pDataVar, ddd, start, stride, edge);
        if (ddd) {
            // 输出数据
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < 10; j++) {
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
        for (const auto& value : d) {
            qDebug() << value << " ";
        }
//        if (ddd) {
//            // 输出数据
//            for (int i = 0; i < 36; i++) {
//                qDebug() << ddd[i];
//            }
//            // 释放数据内存
//            Mat_VarFree(pDataVar);
//            pDataVar = nullptr;
//        }
    }

//    start[0]=0;start[1]=0;//数组起始下标；第一个数下标为0
//    stride[0]=1;stride[1]=1;//读数组是跨步步距，参照Matlab中的格式——start:stride:edge
//    edge[0]=6;edge[1]=6;//数组终止下标
//    Mat_VarReadData(pMatFile,*matcellvar,ddd,start,stride,edge);
//    int i;
//    for(i=0;i<36;i++)
//    {
//        printf("%f/n",ddd[i]);
//    }




//        // 释放变量内存
//        Mat_VarFree(pMatVar);
//        pMatVar = nullptr;

//        // 继续遍历下一个变量
//        pMatVar = Mat_VarReadNextInfo(pMatFile);
//    }
    Mat_Close(pMatFile);
    pMatFile = 0;
}
//bool MAT::openMatFile(QString filePath)
//{
//    mat_t *pMatFile = 0;
//    matvar_t *pMatVar = 0; // 打开mat文件

//    pMatFile = Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY);
//    if(!pMatFile) {
//        qDebug() << "Failed to Mat_Open(filePath.toUtf8().data(), MAT_ACC_RDONLY)";
//        return false;
//    }
//    // 遍历所有变量
//    pMatVar = Mat_VarReadNext(pMatFile);
//    while(pMatVar) {
//        qDebug() << "read variable\n"
//                 << "pMatVar->name:" << pMatVar->name
//                 << "pMatVar->rank:" << pMatVar->rank
//                 << "pMatVar->dims:" << pMatVar->dims
//                 << "pMatVar->class_type:" << pMatVar->class_type
//                 << "pMatVar->data_type:" << pMatVar->data_type
//                 << "pMatVar->isComplex:" << pMatVar->isComplex
//                 << "pMatVar->isLogical:" << pMatVar->isLogical
//                 << "pMatVar->isGlobal:" << pMatVar->isGlobal ;

//        // 释放
//        Mat_VarFree(pMatVar);
//        pMatVar = 0;
//        // 继续遍历
//        pMatVar = Mat_VarReadNextInfo(pMatFile);
//    }


//    // 关闭mat文件
//    Mat_Close(pMatFile);
//    pMatFile = 0;
//    return true;
//}

void MAT::setFileName(QString name)
{
    mat_fp=Mat_CreateVer(name.toStdString().c_str(),NULL,MAT_FT_DEFAULT);
    start();
    saveFileName(name);

}

void MAT::start()
{
    size_t dim[2]={1,1};
    const char *field[9]={"chanlocs","data","srate","filename","event","urevent","ref","age","set"};
    eeg_struct=Mat_VarCreateStruct("EEG",2,dim,field,9);

}
void MAT::save(double *data,quint32 size)
{
    double* Matdata=data;
    uint row=channel_num;
    uint col=size;
    size_t dims[2];
    dims[0]=row;
    dims[1]=col;
    matvar_t *data_field=Mat_VarCreate(NULL,MAT_C_DOUBLE,MAT_T_DOUBLE,2,dims,Matdata,0);
    Mat_VarSetStructFieldByName(eeg_struct,"data",0,data_field);
}
void MAT::stop()
{
    //数据写入mat文件
    Mat_VarWrite(mat_fp,eeg_struct,MAT_COMPRESSION_NONE);
    //释放mat数据的空间
    Mat_VarFree(eeg_struct);
    eeg_struct=NULL;
    //关闭mat文件指针
    Mat_Close(mat_fp);
    mat_fp=NULL;
}
void MAT::saveChanlocs(QVariantList chanlocs)
{

    const char *chanlocs_item_field[12]={
        "labels","type","theta","radius",
        "x","y","z","sph_theta","sph_phi",
        "sph_radius","urchan","ref"
    };
    size_t dim[2]={1,1};
    dim[0]=channel_num;
    matvar_t *chanlocs_field=Mat_VarCreateStruct("chanlocs",2,dim,chanlocs_item_field,12);
    int index=0;
    for(QVariantList::const_iterator begin=chanlocs.begin();begin!=chanlocs.end();begin++)
    {
        QVariantMap map=(*begin).value<QVariantMap>();
        quint8 map_size=map.size();
        QStringList keys=map.keys();
        for(int i=0;i<map_size;i++)
        {
            QString key=keys[i];
            QVariant value=map[key];
            if(value.type()==QVariant::String)
            {
                QString data=value.value<QString>();
                int len=data.size();
                size_t dim[2];
                dim[0]=1;
                dim[1]=len;
                matvar_t *filename_field=Mat_VarCreate(NULL,MAT_C_CHAR,MAT_T_UTF8,2,dim,data.toUtf8().data(),0);
                Mat_VarSetStructFieldByName(chanlocs_field,key.toUtf8().data(),index,filename_field);
            }
            else if(value.type()==QVariant::Double)
            {
                size_t dim[2]={1,1};
                double data=value.value<double>();
                matvar_t *field = Mat_VarCreate(NULL,MAT_C_DOUBLE,MAT_T_DOUBLE,2,dim,&data,0);
                Mat_VarSetStructFieldByName(chanlocs_field,key.toUtf8().data(),index,field);
            }
            else if(value.type()==QVariant::Int)
            {
                size_t dim[2]={1,1};
                int data=value.value<int>();
                matvar_t *field = Mat_VarCreate(NULL,MAT_C_UINT32,MAT_T_UINT32,2,dim,&data,0);
                Mat_VarSetStructFieldByName(chanlocs_field,key.toUtf8().data(),index,field);
            }


        }
        index++;
    }
    Mat_VarSetStructFieldByName(eeg_struct,"chanlocs",0,chanlocs_field);
}
void MAT::saveFileName(QString name)
{
    QFileInfo info(name);
    name=info.fileName();
    int len=name.size();
    size_t dim[2];
    dim[0]=1;
    dim[1]=len;
    matvar_t *filename_field=Mat_VarCreate(NULL,MAT_C_CHAR,MAT_T_UTF8,2,dim,name.toUtf8().data(),0);
    Mat_VarSetStructFieldByName(eeg_struct,"filename",0,filename_field);
}

void MAT::saveSrate(quint16 rate)
{
    size_t value=rate;
    size_t dim[2]={1,1};
    matvar_t *srate_field=Mat_VarCreate(NULL,MAT_C_UINT16,MAT_T_UINT16,2,dim,&value,0);
    Mat_VarSetStructFieldByName(eeg_struct,"srate",0,srate_field);
}

void MAT::saveEevent(QVariantList event)
{
    const char *event_item_field[8]={
        "latency","duration","channel","bvtime","bvmknum",
        "type","code","urevent"
    };
    size_t dim[2]={1,1};
    dim[0]=event.size();
    matvar_t *event_field=Mat_VarCreateStruct("event",2,dim,event_item_field,8);
    int index=0;
    for(QVariantList::const_iterator begin=event.begin();begin!=event.end();begin++)
    {
        QVariantMap map=(*begin).value<QVariantMap>();
        quint8 map_size=map.size();
        QStringList keys=map.keys();
        for(int i=0;i<map_size;i++)
        {
            QString key=keys[i];
            QVariant value=map[key];
            if(value.type()==QVariant::String)
            {
                QString data=value.value<QString>();
                int len=data.size();
                size_t dim[2];
                dim[0]=1;
                dim[1]=len;
                matvar_t *filename_field=Mat_VarCreate(NULL,MAT_C_CHAR,MAT_T_UTF8,2,dim,data.toUtf8().data(),0);
                Mat_VarSetStructFieldByName(event_field,key.toUtf8().data(),index,filename_field);
            }
            else if(value.type()==QVariant::Double)
            {
                size_t dim[2]={1,1};
                double data=value.value<double>();
                matvar_t *field = Mat_VarCreate(NULL,MAT_C_DOUBLE,MAT_T_DOUBLE,2,dim,&data,0);
                Mat_VarSetStructFieldByName(event_field,key.toUtf8().data(),index,field);
            }
            else if(value.type()==QVariant::Int)
            {
                size_t dim[2]={1,1};
                int data=value.value<int>();
                matvar_t *field = Mat_VarCreate(NULL,MAT_C_UINT32,MAT_T_UINT32,2,dim,&data,0);
                Mat_VarSetStructFieldByName(event_field,key.toUtf8().data(),index,field);
            }
        }
        index++;
    }
    Mat_VarSetStructFieldByName(eeg_struct,"event",0,event_field);
}
void MAT::saveUrevent(QVariantList event)
{
    const char *urevent_item_field[7]={
        "latency","duration","channel","bvtime","bvmknum",
        "type","code"
    };
    size_t dim[2]={1,1};
    dim[0]=event.size();
    matvar_t *urevent_field=Mat_VarCreateStruct("event",2,dim,urevent_item_field,7);
    int index=0;
    for(QVariantList::const_iterator begin=event.begin();begin!=event.end();begin++)
    {
        QVariantMap map=(*begin).value<QVariantMap>();
        quint8 map_size=map.size();
        QStringList keys=map.keys();
        for(int i=0;i<map_size;i++)
        {
            QString key=keys[i];
            QVariant value=map[key];
            if(value.type()==QVariant::String)
            {
                QString data=value.value<QString>();
                int len=data.size();
                size_t dim[2];
                dim[0]=1;
                dim[1]=len;
                matvar_t *filename_field=Mat_VarCreate(NULL,MAT_C_CHAR,MAT_T_UTF8,2,dim,data.toUtf8().data(),0);
                Mat_VarSetStructFieldByName(urevent_field,key.toUtf8().data(),index,filename_field);
            }
            else if(value.type()==QVariant::Double)
            {
                size_t dim[2]={1,1};
                double data=value.value<double>();
                matvar_t *field = Mat_VarCreate(NULL,MAT_C_DOUBLE,MAT_T_DOUBLE,2,dim,&data,0);
                Mat_VarSetStructFieldByName(urevent_field,key.toUtf8().data(),index,field);
            }
            else if(value.type()==QVariant::Int)
            {
                size_t dim[2]={1,1};
                int data=value.value<int>();
                matvar_t *field = Mat_VarCreate(NULL,MAT_C_UINT32,MAT_T_UINT32,2,dim,&data,0);
                Mat_VarSetStructFieldByName(urevent_field,key.toUtf8().data(),index,field);
            }


        }
        index++;
    }
    Mat_VarSetStructFieldByName(eeg_struct,"urevent",0,urevent_field);
}

void MAT::saveRef(QStringList ref)
{
    size_t dim[2]={0,1};
    int ref_size=ref.size();
    dim[0]=ref_size;
    matvar_t *ref_field=Mat_VarCreate(NULL,MAT_C_CELL,MAT_T_UTF8,2,dim,NULL,0);
    for(int i=0;i<ref_size;i++)
    {
        size_t cell_dim[2];
        cell_dim[0]=1;
        cell_dim[1]=ref[i].size();
        matvar_t *cell=Mat_VarCreate(NULL,MAT_C_CHAR,MAT_T_UTF8,2,cell_dim,ref[i].toUtf8().data(),0);
        Mat_VarSetCell(ref_field,i,cell);
    }
    Mat_VarSetStructFieldByName(eeg_struct,"ref",0,ref_field);
}

void MAT::saveAge(quint8 age)
{
    size_t value=age;
    size_t dim[2]={1,1};
    matvar_t *age_field=Mat_VarCreate(NULL,MAT_C_UINT16,MAT_T_UINT16,2,dim,&value,0);
    Mat_VarSetStructFieldByName(eeg_struct,"age",0,age_field);
}

void MAT::saveSetCode(quint8 code)
{
    size_t value=code;
    size_t dim[2]={1,1};
    matvar_t *set_field=Mat_VarCreate(NULL,MAT_C_UINT16,MAT_T_UINT16,2,dim,&value,0);
    Mat_VarSetStructFieldByName(eeg_struct,"set",0,set_field);
}
void MAT::setChannelNum(const quint8 &value)
{
    channel_num = value;
}
