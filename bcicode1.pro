<<<<<<< HEAD
QT       += core gui sql quickwidgets charts
=======
QT       += core gui sql quickwidgets
>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
<<<<<<< HEAD
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
    allmatcurve.cpp \
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
    curvegroup/CurveWnd/src/curvewnd.cpp \
    curvegroup/CurveWnd/src/mark.cpp \
    curvegroup/CurveWnd/src/series.cpp \
    curvegroup/CurveWnd/src/seriesdata.cpp \
    curvegroup/src/curvegroup.cpp \
    curvegroup/src/dialog.cpp \
    curvegroup/src/mat.cpp \
    curvegroup/src/seriespoint.cpp \
    gamefinishwidget/curve.cpp \
=======

SOURCES += \
>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
    gamefinishwidget/gamefinishdata.cpp \
    gamefinishwidget/gamefinishwidget.cpp \
    gamefinishwidget/radar.cpp \
    login/jsonoperation.cpp \
    login/login.cpp \
    login/register.cpp \
    login/register_info.cpp \
    main.cpp \
    mainwindow.cpp \
<<<<<<< HEAD
    matcurve/matCurve.cpp \
    mati.cpp

HEADERS += \
    allmatcurve.h \
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
    curvegroup/CurveWnd/src/curvewnd.h \
    curvegroup/CurveWnd/src/mark.h \
    curvegroup/CurveWnd/src/series.h \
    curvegroup/CurveWnd/src/seriesdata.h \
    curvegroup/src/curvegroup.h \
    curvegroup/src/dialog.h \
    curvegroup/src/mat.h \
    curvegroup/src/seriespoint.h \
    gamefinishwidget/curve.h \
=======

HEADERS += \
>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
    gamefinishwidget/gamefinishdata.h \
    gamefinishwidget/gamefinishwidget.h \
    gamefinishwidget/radar.h \
    login/UserInfoStruct.h \
    login/jsonoperation.h \
    login/login.h \
    login/register.h \
    login/register_info.h \
    mainwindow.h \
<<<<<<< HEAD
    matcurve/matCurve.h \ \
    mati.h

FORMS += \
    allmatcurve.ui \
    attentionwidget/attentionradar.ui \
    attentionwidget/attentionwidget.ui \
    curvegroup/src/dialog.ui \
    gamefinishwidget/curve.ui \
=======

FORMS += \
>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
    gamefinishwidget/gamefinishwidget.ui \
    gamefinishwidget/radar.ui \
    login/login.ui \
    login/register.ui \
    login/register_info.ui \
<<<<<<< HEAD
    mainwindow.ui \
    matcurve/matCurve.ui
include(curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtpropertybrowserutils.pri)
=======
    mainwindow.ui \  

>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
<<<<<<< HEAD
    Icon.qrc \
    Login.qrc \
    curvegroup/CurveWnd/maxwidget/CurveProperty/qtpropertybrowser/qtpropertybrowser.qrc \
=======
    Login.qrc \
>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
    pic.qrc \
    qml.qrc \

DISTFILES += \
<<<<<<< HEAD
    bcicode1.pro.user \
=======
    bcicode1.pro.user
>>>>>>> 6618c4e4f0412b5ffa1e5ebebc39a0de6cfef416
