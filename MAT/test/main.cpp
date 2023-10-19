#include "mat.h"
#include "QVariantMap"
#include"QDebug"
int main()
{
   MAT mat;

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
