
CONFIG += warn_off

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += ../include/ ../generated/include/ ../lib/virtual-network-layers-cpp/include/

LIBS += -L../installs/lib/ -lvnl -lvni

HEADERS += \
    replaygui.h

SOURCES += \
    replaygui.cpp
