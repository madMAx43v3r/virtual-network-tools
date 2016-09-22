cmake_minimum_required(VERSION 2.4)

set(CMAKE_CXX_FLAGS "-std=c++11 -g -O0 -pthread -Wfatal-errors")

include_directories(include/ generated/include/ lib/virtual-network-layers-cpp/include/)

add_subdirectory(generated)
add_subdirectory(lib/virtual-network-layers-cpp)

