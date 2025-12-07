/****************************************************************************
** Meta object code from reading C++ file 'henkilotietokanta.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../henkilotietokanta.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'henkilotietokanta.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_henkiloTietokanta_t {
    QByteArrayData data[11];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_henkiloTietokanta_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_henkiloTietokanta_t qt_meta_stringdata_henkiloTietokanta = {
    {
QT_MOC_LITERAL(0, 0, 17), // "henkiloTietokanta"
QT_MOC_LITERAL(1, 18, 17), // "lisaaTietokantaan"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 20), // "submitDataToDatabase"
QT_MOC_LITERAL(4, 58, 9), // "removeRow"
QT_MOC_LITERAL(5, 68, 6), // "search"
QT_MOC_LITERAL(6, 75, 9), // "revertAll"
QT_MOC_LITERAL(7, 85, 17), // "addDataToDatabase"
QT_MOC_LITERAL(8, 103, 5), // "aseta"
QT_MOC_LITERAL(9, 109, 8), // "QString&"
QT_MOC_LITERAL(10, 118, 5) // "bool&"

    },
    "henkiloTietokanta\0lisaaTietokantaan\0"
    "\0submitDataToDatabase\0removeRow\0search\0"
    "revertAll\0addDataToDatabase\0aseta\0"
    "QString&\0bool&"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_henkiloTietokanta[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    6,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 10,    2,    2,    2,    2,    2,    2,

       0        // eod
};

void henkiloTietokanta::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        henkiloTietokanta *_t = static_cast<henkiloTietokanta *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lisaaTietokantaan(); break;
        case 1: _t->submitDataToDatabase(); break;
        case 2: _t->removeRow(); break;
        case 3: _t->search(); break;
        case 4: _t->revertAll(); break;
        case 5: _t->addDataToDatabase(); break;
        case 6: _t->aseta((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (henkiloTietokanta::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&henkiloTietokanta::lisaaTietokantaan)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject henkiloTietokanta::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_henkiloTietokanta.data,
      qt_meta_data_henkiloTietokanta,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *henkiloTietokanta::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *henkiloTietokanta::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_henkiloTietokanta.stringdata0))
        return static_cast<void*>(const_cast< henkiloTietokanta*>(this));
    return QWidget::qt_metacast(_clname);
}

int henkiloTietokanta::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void henkiloTietokanta::lisaaTietokantaan()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
