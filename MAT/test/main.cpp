#include "mat.h"
#include "QVariantMap"
#include"QDebug"
int main()
{
    MAT mat;

    mat_t *matfp = Mat_Open("E:/ddd/program/data/数据/脑电数据/lx_20230908170117_123_2.mat", MAT_ACC_RDONLY);
    if (matfp == NULL) {
        // 处理打开MAT文件失败的情况
        qDebug()<<'4';
    }

    matvar_t *matvar = Mat_VarRead(matfp, "data");
    if (matvar == NULL) {
        // 处理读取变量失败的情况
        qDebug()<<'3';
    }

    int status = Mat_VarReadDataAll(matfp, matvar);
    if (status != 0) {
        // 处理读取数据失败的情况
        qDebug()<<'2';
    }

    // 打印读取到的数据
    double *d = (double *)matvar->data;
    int numElements = matvar->nbytes / sizeof(double);
    for (int i = 0; i < numElements; i++) {
        printf("%f ", d[i]);
    }
    printf("\n");

    Mat_VarFree(matvar);
    Mat_Close(matfp);



    mat.setFileName("text.mat");
    mat.setChannelNum(2);
    mat.saveSrate(1000);
    mat.saveAge(18);
    mat.saveSetCode(0);
    mat.saveRef({"FP","PF"});
    QVariantMap map;
    map["labels"]=QString("FP3");
    map["x"]=double(0.0555);
    map["urchan"]=int(1);
    QVariantList list={map,map};
    mat.saveChanlocs(list);
    QVariantMap map2;
    map2["latency"]=int(134);
    map2["type"]=QString("stimulus");
    map2["channel"]=int(1);
    QVariantList list2={map2,map2};
    mat.saveEevent(list2);
    mat.saveUrevent(list2);
    int i=1000;
    qDebug()<<1;
    double *data=(double*)malloc(sizeof (double)*2);
    while (i) {
        data[0]=0.40;
        data[1]=0.05;
        mat.save(data,sizeof (double)*2);
        i--;
    }

    free(data);
    mat.stop();

}
