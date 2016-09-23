#!/bin/bash

mkdir -p installs/bin
mkdir -p installs/lib

mkdir -p tmp
cd tmp
cmake ..
make -j `nproc`
cd ..

mkdir -p tmp-ReplayGUI
cd tmp-ReplayGUI
qmake-qt4 CONFIG+=release -o Makefile ../ReplayGUI/ReplayGUI.pro
make -j `nproc`
cp ReplayGUI ../installs/bin/
cd ..

