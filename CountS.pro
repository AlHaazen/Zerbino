TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    logic.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    logic.h

