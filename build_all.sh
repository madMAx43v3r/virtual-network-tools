#!/bin/bash

mkdir -p build
cd build
cmake ../
make -j8
cd ..

mkdir -p build-ReplayGUI
cd build-ReplayGUI
qmake CONFIG+=release -o Makefile ../ReplayGUI/ReplayGUI.pro
make -j8
cd ..

