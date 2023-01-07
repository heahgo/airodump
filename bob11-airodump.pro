TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpcap
SOURCES += \
        dot11.cpp \
        main.cpp

HEADERS += \
    dot11.h
