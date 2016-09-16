
include_directories(include/)

find_package(FLTK)

add_executable(ReplayGUI src/ReplayGUI.cpp)
target_link_libraries(ReplayGUI vnl vni ${FLTK_LIBRARIES})
