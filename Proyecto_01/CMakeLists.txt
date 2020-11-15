cmake_minimum_required(VERSION 3.17)
project(Proyecto_01)

set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5.1 COMPONENTS system window graphics audio)

add_executable(Proyecto_01 main.cpp)
target_link_libraries(Proyecto_01 sfml-system sfml-window sfml-graphics sfml-audio -static)