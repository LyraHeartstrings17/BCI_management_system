/****************************************************************************
** Meta object code from reading C++ file 'maxwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../curvegroup/CurveWnd/maxwidget/src/maxwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maxwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Maxwidget_t {
    QByteArrayData data[18];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Maxwidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Maxwidget_t qt_meta_stringdata_Maxwidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Maxwidget"
QT_MOC_LITERAL(1, 10, 6), // "closed"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "setPoint"
QT_MOC_LITERAL(4, 27, 1), // "x"
QT_MOC_LITERAL(5, 29, 1), // "y"
QT_MOC_LITERAL(6, 31, 9), // "setPoints"
QT_MOC_LITERAL(7, 41, 15), // "QVector<double>"
QT_MOC_LITERAL(8, 57, 20), // "backgroudValueChange"
QT_MOC_LITERAL(9, 78, 11), // "QtProperty*"
QT_MOC_LITERAL(10, 90, 8), // "property"
QT_MOC_LITERAL(11, 99, 5), // "value"
QT_MOC_LITERAL(12, 105, 17), // "axiasXValueChange"
QT_MOC_LITERAL(13, 123, 17), // "axiasYValueChange"
QT_MOC_LITERAL(14, 141, 15), // "fontValueChange"
QT_MOC_LITERAL(15, 157, 21), // "curveColorValueChange"
QT_MOC_LITERAL(16, 179, 21), // "curveWidthValueChange"
QT_MOC_LITERAL(17, 201, 16) // "axisYRangeChange"

    },
    "Maxwidget\0closed\0\0setPoint\0x\0y\0setPoints\0"
    "QVector<double>\0backgroudValueChange\0"
    "QtProperty*\0property\0value\0axiasXValueChange\0"
    "axiasYValueChange\0fontValueChange\0"
    "curveColorValueChange\0curveWidthValueChange\0"
    "axisYRangeChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Maxwidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   65,    2, 0x0a /* Public */,
       6,    2,   70,    2, 0x0a /* Public */,
       8,    2,   75,    2, 0x08 /* Private */,
      12,    2,   80,    2, 0x08 /* Private */,
      13,    2,   85,    2, 0x08 /* Private */,
      14,    2,   90,    2, 0x08 /* Private */,
      15,    2,   95,    2, 0x08 /* Private */,
      16,    2,  100,    2, 0x08 /* Private */,
      17,    2,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    4,    5,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QVariant,   10,   11,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QVariant,   10,   11,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QVariant,   10,   11,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QVariant,   10,   11,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QVariant,   10,   11,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QVariant,   10,   11,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QVariant,   10,   11,

       0        // eod
};

void Maxwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Maxwidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->setPoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->setPoints((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 3: _t->backgroudValueChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 4: _t->axiasXValueChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 5: _t->axiasYValueChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 6: _t->fontValueChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 7: _t->curveColorValueChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 8: _t->curveWidthValueChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 9: _t->axisYRangeChange((*reinterpret_cast< QtProperty*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Maxwidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Maxwidget::closed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Maxwidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Maxwidget.data,
    qt_meta_data_Maxwidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Maxwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Maxwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Maxwidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Maxwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Maxwidget::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
