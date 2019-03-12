/****************************************************************************
** Meta object code from reading C++ file 'modeluozapp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Controller-View/modeluozapp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modeluozapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Modeluozapp_t {
    QByteArrayData data[8];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Modeluozapp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Modeluozapp_t qt_meta_stringdata_Modeluozapp = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Modeluozapp"
QT_MOC_LITERAL(1, 12, 10), // "newmessage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 15), // "messagereceived"
QT_MOC_LITERAL(4, 40, 8), // "message*"
QT_MOC_LITERAL(5, 49, 11), // "messagesend"
QT_MOC_LITERAL(6, 61, 11), // "sendmessage"
QT_MOC_LITERAL(7, 73, 14) // "receivemessage"

    },
    "Modeluozapp\0newmessage\0\0messagereceived\0"
    "message*\0messagesend\0sendmessage\0"
    "receivemessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Modeluozapp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    4,   61,    2, 0x0a /* Public */,
       6,    3,   70,    2, 0x2a /* Public | MethodCloned */,
       6,    2,   77,    2, 0x2a /* Public | MethodCloned */,
       6,    1,   82,    2, 0x2a /* Public | MethodCloned */,
       7,    1,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void Modeluozapp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Modeluozapp *_t = static_cast<Modeluozapp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newmessage(); break;
        case 1: _t->messagereceived((*reinterpret_cast< message*(*)>(_a[1]))); break;
        case 2: _t->messagesend((*reinterpret_cast< message*(*)>(_a[1]))); break;
        case 3: _t->sendmessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 4: _t->sendmessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->sendmessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->sendmessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->receivemessage((*reinterpret_cast< message*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Modeluozapp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Modeluozapp::newmessage)) {
                *result = 0;
            }
        }
        {
            typedef void (Modeluozapp::*_t)(message * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Modeluozapp::messagereceived)) {
                *result = 1;
            }
        }
        {
            typedef void (Modeluozapp::*_t)(message * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Modeluozapp::messagesend)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Modeluozapp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Modeluozapp.data,
      qt_meta_data_Modeluozapp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Modeluozapp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Modeluozapp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Modeluozapp.stringdata0))
        return static_cast<void*>(const_cast< Modeluozapp*>(this));
    return QObject::qt_metacast(_clname);
}

int Modeluozapp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Modeluozapp::newmessage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Modeluozapp::messagereceived(message * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Modeluozapp::messagesend(message * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
