cmake_minimum_required(VERSION 2.4)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_FLAGS "-std=c++11 -g -O3 -pthread -Wfatal-errors")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/installs/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/installs/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/installs/bin)

find_package(Qt4 REQUIRED QtGui)

include_directories(include/ generated/include/ lib/virtual-network-layers-cpp/include/)

include(generated/vni_input_output.cmake)
add_library(vni STATIC ${VNI_OUTPUT_FILES_SOURCE})

add_subdirectory(lib/virtual-network-layers-cpp)

add_executable(crc64 src/crc64)
target_link_libraries(crc64 vnl)

add_executable(vnlrec2json src/vnlrec2json.cpp)
target_link_libraries(vnlrec2json vnl vni)

add_executable(ReplayGUI ReplayGUI/replaygui.cpp)
target_link_libraries(ReplayGUI vnl vni Qt4::QtGui)

add_executable(AdminGUI AdminGUI/admingui.cpp)
target_link_libraries(AdminGUI vnl vni Qt4::QtGui)
