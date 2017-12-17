cmake_minimum_required(VERSION 3.5)
project(desktop)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_CURRENT_INCLUDE ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Core REQUIRED)


set(Qt_lib Qt5::Core Qt5::Widgets Qt5::Gui)

file(GLOB SRC src/*.cc)
file(GLOB HDR src/*.h)


add_executable(desktop WIN32 ${HDR} ${SRC})
target_link_libraries(desktop ${Qt_lib})