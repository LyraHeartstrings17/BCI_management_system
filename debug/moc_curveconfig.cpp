/****************************************************************************
** Meta object code from reading C++ file 'curveconfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../curvegroup/CurveWnd/maxwidget/CurveProperty/src/curveconfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'curveconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CurveConfig_t {
    QByteArrayData data[9];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CurveConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CurveConfig_t qt_meta_stringdata_CurveConfig = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CurveConfig"
QT_MOC_LITERAL(1, 12, 12), // "readFinished"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "data"
QT_MOC_LITERAL(4, 31, 10), // "initConfig"
QT_MOC_LITERAL(5, 42, 14), // "modifyProperty"
QT_MOC_LITERAL(6, 57, 11), // "QtProperty*"
QT_MOC_LITERAL(7, 69, 8), // "property"
QT_MOC_LITERAL(8, 78, 5) // "value"

    },
    "CurveConfig\0readFinished\0\0data\0"
    "initConfig\0modifyProperty\0QtProperty*\0"
    "property\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CurveConfig[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       5,    2,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariantList,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QVariant,    7,    8,

       0        // eod
};

void CurveConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CurveConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readFinished((*reinterpret_cast< QList<QVariant>(*)>(_a[1]))); break;
        case 1: _t->initConfig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->modifyProperty((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CurveConfig::*)(QList<QVariant> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveConfig::readFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CurveConfig::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CurveConfig.data,
    qt_meta_data_CurveConfig,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CurveConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CurveConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CurveConfig.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CurveConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CurveConfig::readFinished(QList<QVariant> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
