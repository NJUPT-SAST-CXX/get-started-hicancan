cmake_minimum_required(VERSION 3.10)
project(PhotoAlbum)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(photoalbum main.cpp)

target_link_libraries(photoalbum Qt5::Widgets)
