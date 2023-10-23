#include "mat.h"
#include "QDebug"
#include "QFile"
MAT::MAT(QObject *parent):QObject(parent)
{
}

MAT::~MAT()
{
}

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
    //    QString filePath="E:\\ddd\\program\\data\\数据\\脑电数据";
    //    if (QFile::copy("text.mat", filePath)) {
    //        qDebug() << "File saved successfully.";
    //    } else {
    //        qDebug() << "Failed to save the file.";
    //    }

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
