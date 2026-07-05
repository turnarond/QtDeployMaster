/****************************************************************************
** Meta object code from reading C++ file 'DeployMaster.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../DeployMaster.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DeployMaster.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN12DeployMasterE_t {};
} // unnamed namespace

template <> constexpr inline auto DeployMaster::qt_create_metaobjectdata<qt_meta_tag_ZN12DeployMasterE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DeployMaster",
        "appendFtpLog",
        "",
        "log",
        "onAddFilesClicked",
        "onAddFolderClicked",
        "onFilesDropped",
        "filePaths",
        "onFileItemCleanClicked",
        "onDeployClicked",
        "onClearLogClicked",
        "onFtpUploadFinished",
        "deploySuccesses",
        "deployFailures",
        "shouldReboot",
        "user",
        "pass",
        "buildRemoteFileTree",
        "QList<FtpFileInfo>",
        "files"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'appendFtpLog'
        QtMocHelpers::SlotData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'onAddFilesClicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAddFolderClicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onFilesDropped'
        QtMocHelpers::SlotData<void(const QStringList &)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QStringList, 7 },
        }}),
        // Slot 'onFileItemCleanClicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onDeployClicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onClearLogClicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onFtpUploadFinished'
        QtMocHelpers::SlotData<void(const QStringList &, const QStringList &, bool, const QString &, const QString &)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QStringList, 12 }, { QMetaType::QStringList, 13 }, { QMetaType::Bool, 14 }, { QMetaType::QString, 15 },
            { QMetaType::QString, 16 },
        }}),
        // Slot 'buildRemoteFileTree'
        QtMocHelpers::SlotData<void(const QList<FtpFileInfo> &)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 18, 19 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<DeployMaster, qt_meta_tag_ZN12DeployMasterE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject DeployMaster::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12DeployMasterE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12DeployMasterE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12DeployMasterE_t>.metaTypes,
    nullptr
} };

void DeployMaster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DeployMaster *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->appendFtpLog((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->onAddFilesClicked(); break;
        case 2: _t->onAddFolderClicked(); break;
        case 3: _t->onFilesDropped((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 4: _t->onFileItemCleanClicked(); break;
        case 5: _t->onDeployClicked(); break;
        case 6: _t->onClearLogClicked(); break;
        case 7: _t->onFtpUploadFinished((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[5]))); break;
        case 8: _t->buildRemoteFileTree((*reinterpret_cast<std::add_pointer_t<QList<FtpFileInfo>>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *DeployMaster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeployMaster::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12DeployMasterE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DeployMaster::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
