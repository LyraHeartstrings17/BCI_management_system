QT       += core gui sql quickwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gamefinishwidget/gamefinishdata.cpp \
    gamefinishwidget/gamefinishwidget.cpp \
    gamefinishwidget/radar.cpp \
    login/jsonoperation.cpp \
    login/login.cpp \
    login/register.cpp \
    login/register_info.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    gamefinishwidget/gamefinishdata.h \
    gamefinishwidget/gamefinishwidget.h \
    gamefinishwidget/radar.h \
    login/UserInfoStruct.h \
    login/jsonoperation.h \
    login/login.h \
    login/register.h \
    login/register_info.h \
    mainwindow.h \

FORMS += \
    gamefinishwidget/gamefinishwidget.ui \
    gamefinishwidget/radar.ui \
    login/login.ui \
    login/register.ui \
    login/register_info.ui \
    mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Login.qrc \
    pic.qrc \
    qml.qrc \

DISTFILES += \
    bcicode1.pro.user
