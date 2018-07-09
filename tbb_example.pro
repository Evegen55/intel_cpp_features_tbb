TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    md5calculate.cpp

HEADERS += \
    md5calculate.h


unix:INCLUDEPATH += /usr/include
unix:LIBS += -ltbb
