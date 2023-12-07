QT       += core gui sql quickwidgets charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH+=$$PWD\matcurve\matio\x86\debug\include
LIBS += -L$$PWD\matcurve\matio\x86\debug\lib -llibmatio
LIBS += -L$$PWD\matcurve\matio\x86\debug\lib -llibhdf5_D
LIBS += -L$$PWD\matcurve\matio\x86\debug\lib -llibhdf5_hl_D
LIBS += -L$$PWD\matcurve\matio\x86\debug\lib -llibhdf5_tools_D
LIBS += -L$$PWD\matcurve\matio\x86\debug\lib -lzlibd
LIBS += -L$$PWD\matcurve\matio\x86\debug\lib -lzlibstaticd
INCLUDEPATH += curvegroup/src \
               curvegroup/CurveWnd/src \
               curvegroup/CurveWnd/maxwidget/src \
               curvegroup/CurveWnd/maxwidget/CurveProperty/src

msvc:QMAKE_CXXFLAGS += -execution-charset:utf-8
msvc:QMAKE_CXXFLAGS += -source-charset:utf-8
SOURCES += \
    attentionwidget/attentiondata.cpp \
    attentionwidget/attentionradar.cpp \
    attentionwidget/attentionwidget.cpp \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtbuttonpropertybrowser.cpp \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qteditorfactory.cpp \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtgroupboxpropertybrowser.cpp \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtpropertybrowser.cpp \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtpropertymanager.cpp \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qttreepropertybrowser.cpp \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtvariantproperty.cpp \
    curvegroup/CurveWnd/maxwidget/CurveProperty/src/curveconfig.cpp \
    curvegroup/CurveWnd/maxwidget/CurveProperty/src/curveproperty.cpp \
    curvegroup/CurveWnd/maxwidget/src/maxwidget.cpp \
    curvegroup/CurveWnd/maxwidget/src/qcustomplot.cpp \
    curvegroup/CurveWnd/src/curvewnd.cpp \
    curvegroup/CurveWnd/src/mark.cpp \
    curvegroup/CurveWnd/src/seriesdata.cpp \
    curvegroup/src/curvegroup.cpp \
    curvegroup/src/mat.cpp \
    gamefinfishwidget/curve.cpp \
    gamefinfishwidget/gamefinishdata.cpp \
    gamefinfishwidget/gamefinishwidget.cpp \
    gamefinfishwidget/radar.cpp \
    login/jsonoperation.cpp \
    login/login.cpp \
    login/register.cpp \
    login/register_info.cpp \
    main.cpp \
    mainwindow.cpp \
    matcurve/matCurve.cpp

HEADERS += \
    attentionwidget/attentiondata.h \
    attentionwidget/attentionradar.h \
    attentionwidget/attentionwidget.h \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtbuttonpropertybrowser.h \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qteditorfactory.h \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtgroupboxpropertybrowser.h \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtpropertybrowser.h \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtpropertymanager.h \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qttreepropertybrowser.h \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtvariantproperty.h \
    curvegroup/CurveWnd/maxwidget/CurveProperty/src/curveconfig.h \
    curvegroup/CurveWnd/maxwidget/CurveProperty/src/curveproperty.h \
    curvegroup/CurveWnd/maxwidget/src/maxwidget.h \
    curvegroup/CurveWnd/maxwidget/src/qcustomplot.h \
    curvegroup/CurveWnd/src/curvewnd.h \
    curvegroup/CurveWnd/src/mark.h \
    curvegroup/CurveWnd/src/seriesdata.h \
    curvegroup/src/curvegroup.h \
    curvegroup/src/mat.h \
    gamefinfishwidget/curve.h \
    gamefinfishwidget/gamefinishdata.h \
    gamefinfishwidget/gamefinishwidget.h \
    gamefinfishwidget/radar.h \
    login/UserInfoStruct.h \
    login/jsonoperation.h \
    login/login.h \
    login/register.h \
    login/register_info.h \
    mainwindow.h \
    matcurve/matCurve.h \

FORMS += \
    attentionwidget/attentionradar.ui \
    attentionwidget/attentionwidget.ui \
    gamefinfishwidget/curve.ui \
    gamefinfishwidget/gamefinishwidget.ui \
    gamefinfishwidget/radar.ui \
    login/login.ui \
    login/register.ui \
    login/register_info.ui \
    mainwindow.ui \
    matcurve/matCurve.ui
include(curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtpropertybrowserutils.pri)
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icon.qrc \
    Login.qrc \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtpropertybrowser.qrc \
    pic.qrc \
    qml.qrc \

DISTFILES += \
    bcicode1.pro.user \
