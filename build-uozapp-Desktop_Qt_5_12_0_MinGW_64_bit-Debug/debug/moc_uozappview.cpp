/****************************************************************************
** Meta object code from reading C++ file 'uozappview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../uozapp/Controller-View/uozappview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uozappview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UozAppview_t {
    QByteArrayData data[8];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UozAppview_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UozAppview_t qt_meta_stringdata_UozAppview = {
    {
QT_MOC_LITERAL(0, 0, 10), // "UozAppview"
QT_MOC_LITERAL(1, 11, 10), // "pressSendT"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "pressSendI"
QT_MOC_LITERAL(4, 34, 10), // "pressSendC"
QT_MOC_LITERAL(5, 45, 15), // "showmessagesent"
QT_MOC_LITERAL(6, 61, 8), // "message*"
QT_MOC_LITERAL(7, 70, 19) // "showmessagereceived"

    },
    "UozAppview\0pressSendT\0\0pressSendI\0"
    "pressSendC\0showmessagesent\0message*\0"
    "showmessagereceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UozAppview[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void UozAppview::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UozAppview *_t = static_cast<UozAppview *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pressSendT(); break;
        case 1: _t->pressSendI(); break;
        case 2: _t->pressSendC(); break;
        case 3: _t->showmessagesent((*reinterpret_cast< message*(*)>(_a[1]))); break;
        case 4: _t->showmessagereceived((*reinterpret_cast< message*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UozAppview::staticMetaObject = { {
    &QDockWidget::staticMetaObject,
    qt_meta_stringdata_UozAppview.data,
    qt_meta_data_UozAppview,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UozAppview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UozAppview::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UozAppview.stringdata0))
        return static_cast<void*>(this);
    return QDockWidget::qt_metacast(_clname);
}

int UozAppview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
