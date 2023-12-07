/****************************************************************************
** Meta object code from reading C++ file 'jsonoperation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../login/jsonoperation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jsonoperation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JsonOperation_t {
    QByteArrayData data[16];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JsonOperation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JsonOperation_t qt_meta_stringdata_JsonOperation = {
    {
QT_MOC_LITERAL(0, 0, 13), // "JsonOperation"
QT_MOC_LITERAL(1, 14, 11), // "landSucceed"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "landFailed"
QT_MOC_LITERAL(4, 38, 18), // "absentUserRegister"
QT_MOC_LITERAL(5, 57, 13), // "absentAnyUser"
QT_MOC_LITERAL(6, 71, 8), // "initInfo"
QT_MOC_LITERAL(7, 80, 7), // "account"
QT_MOC_LITERAL(8, 88, 8), // "password"
QT_MOC_LITERAL(9, 97, 10), // "isAutoLand"
QT_MOC_LITERAL(10, 108, 14), // "isSavePassword"
QT_MOC_LITERAL(11, 123, 18), // "renewAccountSignal"
QT_MOC_LITERAL(12, 142, 20), // "listAllAccountSignal"
QT_MOC_LITERAL(13, 163, 14), // "registerFailed"
QT_MOC_LITERAL(14, 178, 15), // "registerSucceed"
QT_MOC_LITERAL(15, 194, 19) // "UserInfoSaveSucceed"

    },
    "JsonOperation\0landSucceed\0\0landFailed\0"
    "absentUserRegister\0absentAnyUser\0"
    "initInfo\0account\0password\0isAutoLand\0"
    "isSavePassword\0renewAccountSignal\0"
    "listAllAccountSignal\0registerFailed\0"
    "registerSucceed\0UserInfoSaveSucceed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JsonOperation[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       3,    0,   69,    2, 0x06 /* Public */,
       4,    0,   70,    2, 0x06 /* Public */,
       5,    0,   71,    2, 0x06 /* Public */,
       6,    4,   72,    2, 0x06 /* Public */,
      11,    3,   81,    2, 0x06 /* Public */,
      12,    1,   88,    2, 0x06 /* Public */,
      13,    0,   91,    2, 0x06 /* Public */,
      14,    1,   92,    2, 0x06 /* Public */,
      15,    0,   95,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void JsonOperation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JsonOperation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->landSucceed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->landFailed(); break;
        case 2: _t->absentUserRegister(); break;
        case 3: _t->absentAnyUser(); break;
        case 4: _t->initInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->renewAccountSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->listAllAccountSignal((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 7: _t->registerFailed(); break;
        case 8: _t->registerSucceed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->UserInfoSaveSucceed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JsonOperation::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JsonOperation::landSucceed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (JsonOperation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JsonOperation::landFailed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (JsonOperation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JsonOperation::absentUserRegister)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (JsonOperation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JsonOperation::absentAnyUser)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (JsonOperation::*)(QString , QString , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JsonOperation::initInfo)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (JsonOperation::*)(QString , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JsonOperation::renewAccountSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (JsonOperation::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JsonOperation::listAllAccountSignal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (JsonOperation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JsonOperation::registerFailed)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (JsonOperation::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JsonOperation::registerSucceed)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (JsonOperation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JsonOperation::UserInfoSaveSucceed)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject JsonOperation::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_JsonOperation.data,
    qt_meta_data_JsonOperation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *JsonOperation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JsonOperation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JsonOperation.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int JsonOperation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void JsonOperation::landSucceed(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JsonOperation::landFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void JsonOperation::absentUserRegister()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void JsonOperation::absentAnyUser()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void JsonOperation::initInfo(QString _t1, QString _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void JsonOperation::renewAccountSignal(QString _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void JsonOperation::listAllAccountSignal(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void JsonOperation::registerFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void JsonOperation::registerSucceed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void JsonOperation::UserInfoSaveSucceed()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
