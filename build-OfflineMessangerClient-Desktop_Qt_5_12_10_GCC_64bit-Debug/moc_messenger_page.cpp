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
    QByteArrayData data[10];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_messenger_page_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_messenger_page_t qt_meta_stringdata_messenger_page = {
    {
QT_MOC_LITERAL(0, 0, 14), // "messenger_page"
QT_MOC_LITERAL(1, 15, 13), // "replySelected"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "Message"
QT_MOC_LITERAL(4, 38, 7), // "message"
QT_MOC_LITERAL(5, 46, 23), // "on_getMessagesTriggered"
QT_MOC_LITERAL(6, 70, 31), // "on_sendMessageInput_textChanged"
QT_MOC_LITERAL(7, 102, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(8, 124, 21), // "on_newConvBtn_clicked"
QT_MOC_LITERAL(9, 146, 20) // "on_logOutBtn_clicked"

    },
    "messenger_page\0replySelected\0\0Message\0"
    "message\0on_getMessagesTriggered\0"
    "on_sendMessageInput_textChanged\0"
    "on_sendButton_clicked\0on_newConvBtn_clicked\0"
    "on_logOutBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_messenger_page[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
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
        case 0: _t->replySelected((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 1: _t->on_getMessagesTriggered(); break;
        case 2: _t->on_sendMessageInput_textChanged(); break;
        case 3: _t->on_sendButton_clicked(); break;
        case 4: _t->on_newConvBtn_clicked(); break;
        case 5: _t->on_logOutBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (messenger_page::*)(Message );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&messenger_page::replySelected)) {
                *result = 0;
                return;
            }
        }
    }
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void messenger_page::replySelected(Message _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
