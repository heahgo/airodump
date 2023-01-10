TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpcap

DESTDIR=../bin

SOURCES += \
        dot11.cpp \
        airodump.cpp

HEADERS += \
    dot11.h

