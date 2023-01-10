TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpcap

DESTDIR=./

SOURCES += \
        dot11.cpp \
        airodump.cpp

HEADERS += \
    dot11.h

