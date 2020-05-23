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
    component/camera.cpp \
    drawer.cpp \
    errors/base_error.cpp \
    facade/facade.cpp \
    load/builder.cpp \
    load/loader.cpp \
    main.cpp \
    mainwindow.cpp \
    component/component.cpp \
    component/composite.cpp \
    component/link.cpp \
    component/model.cpp \
    component/point.cpp \
    managers/draw_manager.cpp \
    managers/load_manager.cpp \
    managers/scene_manager.cpp \
    mediator/mediator.cpp \
    scene.cpp

HEADERS += \
    commands/command.h \
    component/camera.h \
    drawer.h \
    errors/base_error.h \
    facade/facade.h \
    load/builder.h \
    load/loader.h \
    mainwindow.h \
    component/component.h \
    component/composite.h \
    component/link.h \
    component/model.h \
    component/point.h \
    managers/draw_manager.h \
    managers/load_manager.h \
    managers/scene_manager.h \
    mediator/mediator.h \
    scene.h \
    vector/vector.h \
    vector/vector.hpp \
    vector/iterator.h \
    vector/iterator.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
