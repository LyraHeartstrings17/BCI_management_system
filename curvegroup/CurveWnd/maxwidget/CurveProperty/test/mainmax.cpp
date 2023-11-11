#include "curveproperty.h"
#include "QApplication"
int main(int args,char **argv)
{
    QApplication app(args,argv);
    CurveProperty w;
    w.show();
    return app.exec();
}
