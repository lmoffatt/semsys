TEMPLATE = app
CONFIG += console c++11
CONFIG += c++14

CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    quantities.h \
    units.h \
    variables.h \
    SI.h \
    group_algebra.h \
    Definition_system.h
