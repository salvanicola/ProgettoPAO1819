/****************************************************************************
** Meta object code from reading C++ file 'modeluozapp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../uozapp/Controller-View/modeluozapp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modeluozapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Modeluozapp_t {
    QByteArrayData data[9];
    char stringdata0[99];
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
QT_MOC_LITERAL(3, 24, 14), // "messagereceive"
QT_MOC_LITERAL(4, 39, 8), // "message*"
QT_MOC_LITERAL(5, 48, 11), // "messagesend"
QT_MOC_LITERAL(6, 60, 11), // "answeringto"
QT_MOC_LITERAL(7, 72, 11), // "sendmessage"
QT_MOC_LITERAL(8, 84, 14) // "receivemessage"

    },
    "Modeluozapp\0newmessage\0\0messagereceive\0"
    "message*\0messagesend\0answeringto\0"
    "sendmessage\0receivemessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Modeluozapp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       5,    1,   63,    2, 0x06 /* Public */,
       6,    1,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    4,   69,    2, 0x0a /* Public */,
       7,    3,   78,    2, 0x2a /* Public | MethodCloned */,
       7,    2,   85,    2, 0x2a /* Public | MethodCloned */,
       7,    1,   90,    2, 0x2a /* Public | MethodCloned */,
       8,    1,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    0x80000000 | 4, 0x80000000 | 4,    2,

 // slots: parameters
    0x80000000 | 4, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    0x80000000 | 4, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    0x80000000 | 4, QMetaType::QString, QMetaType::QString,    2,    2,
    0x80000000 | 4, QMetaType::QString,    2,
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
        case 1: _t->messagereceive((*reinterpret_cast< message*(*)>(_a[1]))); break;
        case 2: _t->messagesend((*reinterpret_cast< message*(*)>(_a[1]))); break;
        case 3: { message* _r = _t->answeringto((*reinterpret_cast< message*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< message**>(_a[0]) = std::move(_r); }  break;
        case 4: { message* _r = _t->sendmessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< message**>(_a[0]) = std::move(_r); }  break;
        case 5: { message* _r = _t->sendmessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< message**>(_a[0]) = std::move(_r); }  break;
        case 6: { message* _r = _t->sendmessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< message**>(_a[0]) = std::move(_r); }  break;
        case 7: { message* _r = _t->sendmessage((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< message**>(_a[0]) = std::move(_r); }  break;
        case 8: _t->receivemessage((*reinterpret_cast< message*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Modeluozapp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modeluozapp::newmessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Modeluozapp::*)(message * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modeluozapp::messagereceive)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Modeluozapp::*)(message * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modeluozapp::messagesend)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = message * (Modeluozapp::*)(message * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Modeluozapp::answeringto)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Modeluozapp::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Modeluozapp.data,
    qt_meta_data_Modeluozapp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Modeluozapp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Modeluozapp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Modeluozapp.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Modeluozapp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Modeluozapp::newmessage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Modeluozapp::messagereceive(message * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Modeluozapp::messagesend(message * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
message * Modeluozapp::answeringto(message * _t1)
{
    message* _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
