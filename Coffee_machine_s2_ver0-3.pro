TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QT += core gui

SOURCES += \
    main.cpp \
    declares.cpp \
    statemachine.cpp \
    subsystems.cpp \
    settings.cpp \
    display.cpp

HEADERS += \
    declares.h \
    statemachine.h \
    subsystems.h \
    settings.h \
    display.h \
    appinfo.h

RESOURCES += \
    CVMresources.qrc
