/****************************************************************************
** Meta object code from reading C++ file 'siftmatch.h'
**
** Created: Thu Jul 4 19:15:34 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../siftmatch.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'siftmatch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SiftMatch[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      35,   10,   10,   10, 0x08,
      61,   10,   10,   10, 0x08,
      86,   10,   10,   10, 0x08,
     113,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SiftMatch[] = {
    "SiftMatch\0\0on_openButton_clicked()\0"
    "on_detectButton_clicked()\0"
    "on_matchButton_clicked()\0"
    "on_restartButton_clicked()\0"
    "on_mosaicButton_clicked()\0"
};

void SiftMatch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SiftMatch *_t = static_cast<SiftMatch *>(_o);
        switch (_id) {
        case 0: _t->on_openButton_clicked(); break;
        case 1: _t->on_detectButton_clicked(); break;
        case 2: _t->on_matchButton_clicked(); break;
        case 3: _t->on_restartButton_clicked(); break;
        case 4: _t->on_mosaicButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SiftMatch::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SiftMatch::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SiftMatch,
      qt_meta_data_SiftMatch, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SiftMatch::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SiftMatch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SiftMatch::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SiftMatch))
        return static_cast<void*>(const_cast< SiftMatch*>(this));
    return QDialog::qt_metacast(_clname);
}

int SiftMatch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
