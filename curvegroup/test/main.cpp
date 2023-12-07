#include "QApplication"
#include "curvegroup.h"
int main(int args,char **argv)
{
    QApplication app(args,argv);
    CurveGroup w;
    w.resize(640,480);
    w.setMaxPoint(1000);
    w.setCurveNumGroup(4);
    w.setCurveNum(10);//31
    w.setCurveLabels(QStringList({ "Fp1","F3","F7","FT9","FC5","FC1","C3","T7","TP9","CP5","CP1","Pz","P3","p7","O1","Oz","O2","P4","P8","TP10","CP6","CP2","Cz","C4","T8","FT10","FC6","FC2","F4","F8","FP2"}));
//    w.increaseGroupChannel();
//    w.increaseGroupChannel();
//    w.next();O
    w.test_chart();
    w.show();
    w.appendMark("123");

    return app.exec();
}
