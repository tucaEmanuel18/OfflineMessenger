/****************************************************************************
** Meta object code from reading C++ file 'messenger_page.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OfflineMessangerClient/messenger_page.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messenger_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_messenger_page_t {
    QByteArrayData data[6];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_messenger_page_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_messenger_page_t qt_meta_stringdata_messenger_page = {
    {
QT_MOC_LITERAL(0, 0, 14), // "messenger_page"
QT_MOC_LITERAL(1, 15, 23), // "on_getMessagesTriggered"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 21), // "on_refreshBtn_clicked"
QT_MOC_LITERAL(4, 62, 31), // "on_sendMessageInput_textChanged"
QT_MOC_LITERAL(5, 94, 21) // "on_sendButton_clicked"

    },
    "messenger_page\0on_getMessagesTriggered\0"
    "\0on_refreshBtn_clicked\0"
    "on_sendMessageInput_textChanged\0"
    "on_sendButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_messenger_page[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void messenger_page::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<messenger_page *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_getMessagesTriggered(); break;
        case 1: _t->on_refreshBtn_clicked(); break;
        case 2: _t->on_sendMessageInput_textChanged(); break;
        case 3: _t->on_sendButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject messenger_page::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_messenger_page.data,
    qt_meta_data_messenger_page,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *messenger_page::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *messenger_page::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_messenger_page.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int messenger_page::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
