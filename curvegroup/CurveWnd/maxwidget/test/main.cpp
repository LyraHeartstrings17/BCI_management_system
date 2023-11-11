#include "maxwidget.h"
#include "QApplication"
int main(int args,char** argv)
{
    QApplication app(args,argv);
    Maxwidget w;
    w.setText("FP");
    w.show();
    return app.exec();
}
