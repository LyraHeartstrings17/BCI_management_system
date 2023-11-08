#include "curvewnd.h"
#include "QApplication"
int main(int args,char **argv)
{
    QApplication app(args,argv);
    CurveWnd curvewnd;
    //����ͼ���С
    curvewnd.resize(640,480);
    //���ò�����
    //����������Ŀ
    curvewnd.setMinMax(-3,3);
    curvewnd.setCurveNum(5);
    //�������߱�ǩ
    curvewnd.setCurveLabels(QStringList({ "FP","AF","Pf","PF","PG"}));
    //curvewnd.setCurveLabels(QStringList({ "F","A","P","P","G"}));
    curvewnd.appendMark("123");
    curvewnd.show();
    //��������
    return app.exec();
}
