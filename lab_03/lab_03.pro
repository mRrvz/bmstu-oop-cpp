QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    commands/command.cpp \
    gui/drawer.cpp \
    gui/mainwindow.cpp \
    objects/camera.cpp \
    facade/facade.cpp \
    load/builder.cpp \
    load/loader.cpp \
    main.cpp \
    objects/composite.cpp \
    objects/link.cpp \
    objects/model.cpp \
    objects/point.cpp \
    managers/draw_manager.cpp \
    managers/load_manager.cpp \
    managers/reform_manager.cpp \
    managers/scene_manager.cpp \
    scene/scene.cpp

HEADERS += \
    commands/command.h \
    gui/factory.h \
    managers/base_manager.h \
    objects/camera.h \
    errors/base_error.h \
    errors/camera_error.h \
    errors/file_error.h \
    errors/model_error.h \
    facade/facade.h \
    gui/drawer.h \
    gui/mainwindow.h \
    load/builder.h \
    load/loader.h \
    objects/component.h \
    objects/composite.h \
    objects/link.h \
    objects/model.h \
    objects/point.h \
    managers/draw_manager.h \
    managers/load_manager.h \
    managers/reform_manager.h \
    managers/scene_manager.h \
    scene/scene.h \
    vector/vector.h \
    vector/vector.hpp \
    vector/iterator.h \
    vector/iterator.hpp \
    visitor/visitor.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
