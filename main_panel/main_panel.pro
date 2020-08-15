#-------------------------------------------------
#
# Project created by QtCreator 2020-08-07T11:06:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main_panel
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    formgraph.cpp \
    glib/VCGExtend.cpp \
    layerdialog.cpp \
    cloud.cpp \
    glib/transform3d.cpp

HEADERS += \
        mainwindow.h \
    formgraph.h \
    glib/VCGExtend.h \
    layerdialog.h \
    cloud.h \
    glib/V3.hpp \
    glib/transform3d.h

FORMS += \
        mainwindow.ui \
    formgraph.ui \
    layerdialog.ui

LIBS += -lopengl32\
        -lglu32




# vcg
VCGDIR = $$PWD/vcglib
INCLUDEPATH+= $$VCGDIR

INCLUDEPATH+= './glm'

HEADERS += $$VCGDIR/wrap/io_trimesh/import_ply.h \
    $$VCGDIR/wrap/io_trimesh/import_obj.h \
    $$VCGDIR/wrap/io_trimesh/import_off.h \
    $$VCGDIR/wrap/io_trimesh/import_ptx.h \
    $$VCGDIR/wrap/io_trimesh/import_stl.h \
    $$VCGDIR/wrap/io_trimesh/import_fbx.h \
    $$VCGDIR/wrap/io_trimesh/export_ply.h \
    $$VCGDIR/wrap/io_trimesh/export_obj.h \
    $$VCGDIR/wrap/io_trimesh/export_off.h \
    $$VCGDIR/wrap/ply/plylib.h \
    $$VCGDIR/wrap/io_trimesh/io_material.h
SOURCES += \
    $$VCGDIR/wrap/ply/plylib.cpp \


