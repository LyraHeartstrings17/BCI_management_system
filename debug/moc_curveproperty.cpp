/****************************************************************************
** Meta object code from reading C++ file 'curveproperty.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../curvegroup/CurveWnd/maxwidget/CurveProperty/src/curveproperty.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'curveproperty.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CurveProperty_t {
    QByteArrayData data[16];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CurveProperty_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CurveProperty_t qt_meta_stringdata_CurveProperty = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CurveProperty"
QT_MOC_LITERAL(1, 14, 20), // "backgroudValueChange"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "QtProperty*"
QT_MOC_LITERAL(4, 48, 8), // "property"
QT_MOC_LITERAL(5, 57, 5), // "value"
QT_MOC_LITERAL(6, 63, 17), // "axiasXValueChange"
QT_MOC_LITERAL(7, 81, 17), // "axiasYValueChange"
QT_MOC_LITERAL(8, 99, 15), // "fontValueChange"
QT_MOC_LITERAL(9, 115, 21), // "curveColorValueChange"
QT_MOC_LITERAL(10, 137, 21), // "curveWidthValueChange"
QT_MOC_LITERAL(11, 159, 16), // "axisYRangeChange"
QT_MOC_LITERAL(12, 176, 14), // "getCurveConfig"
QT_MOC_LITERAL(13, 191, 11), // "valueChange"
QT_MOC_LITERAL(14, 203, 15), // "readCurveConfig"
QT_MOC_LITERAL(15, 219, 6) // "config"

    },
    "CurveProperty\0backgroudValueChange\0\0"
    "QtProperty*\0property\0value\0axiasXValueChange\0"
    "axiasYValueChange\0fontValueChange\0"
    "curveColorValueChange\0curveWidthValueChange\0"
    "axisYRangeChange\0getCurveConfig\0"
    "valueChange\0readCurveConfig\0config"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CurveProperty[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       6,    2,   69,    2, 0x06 /* Public */,
       7,    2,   74,    2, 0x06 /* Public */,
       8,    2,   79,    2, 0x06 /* Public */,
       9,    2,   84,    2, 0x06 /* Public */,
      10,    2,   89,    2, 0x06 /* Public */,
      11,    2,   94,    2, 0x06 /* Public */,
      12,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    2,  102,    2, 0x08 /* Private */,
      14,    1,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QVariant,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QVariant,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QVariant,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QVariant,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QVariant,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QVariant,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QVariant,    4,    5,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QVariant,    4,    5,
    QMetaType::Void, QMetaType::QVariantList,   15,

       0        // eod
};

void CurveProperty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CurveProperty *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backgroudValueChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 1: _t->axiasXValueChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 2: _t->axiasYValueChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 3: _t->fontValueChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 4: _t->curveColorValueChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 5: _t->curveWidthValueChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 6: _t->axisYRangeChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 7: _t->getCurveConfig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->valueChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 9: _t->readCurveConfig((*reinterpret_cast< QList<QVariant>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CurveProperty::*)(QtProperty * , const QVariant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveProperty::backgroudValueChange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CurveProperty::*)(QtProperty * , const QVariant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveProperty::axiasXValueChange)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CurveProperty::*)(QtProperty * , const QVariant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveProperty::axiasYValueChange)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CurveProperty::*)(QtProperty * , const QVariant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveProperty::fontValueChange)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CurveProperty::*)(QtProperty * , const QVariant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveProperty::curveColorValueChange)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CurveProperty::*)(QtProperty * , const QVariant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveProperty::curveWidthValueChange)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CurveProperty::*)(QtProperty * , const QVariant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveProperty::axisYRangeChange)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CurveProperty::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveProperty::getCurveConfig)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CurveProperty::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CurveProperty.data,
    qt_meta_data_CurveProperty,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CurveProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CurveProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CurveProperty.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CurveProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void CurveProperty::backgroudValueChange(QtProperty * _t1, const QVariant & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CurveProperty::axiasXValueChange(QtProperty * _t1, const QVariant & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CurveProperty::axiasYValueChange(QtProperty * _t1, const QVariant & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CurveProperty::fontValueChange(QtProperty * _t1, const QVariant & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CurveProperty::curveColorValueChange(QtProperty * _t1, const QVariant & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CurveProperty::curveWidthValueChange(QtProperty * _t1, const QVariant & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CurveProperty::axisYRangeChange(QtProperty * _t1, const QVariant & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CurveProperty::getCurveConfig(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
