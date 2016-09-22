
CONFIG += warn_off

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += ../include/ ../generated/include/ ../lib/virtual-network-layers-cpp/include/

LIBS += -L../build/lib/virtual-network-layers-cpp/ -lvnl -L../build/generated/ -lvni

HEADERS += \
    replaygui.h

SOURCES += \
    replaygui.cpp
