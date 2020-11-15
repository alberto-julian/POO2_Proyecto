cmake_minimum_required(VERSION 3.17)
project(Proyecto_02)

set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5.1 COMPONENTS system window graphics audio)


add_executable(Proyecto_02 main.cpp Macro.h Particula.cpp Particula.h MyWindow.cpp MyWindow.h)
target_link_libraries(Proyecto_02 sfml-system sfml-window sfml-graphics sfml-audio -static)