cmake_minimum_required(VERSION 3.22)
project(Pong)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pong main.cpp Bat.cpp Bat.h Ball.cpp Ball.h)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

target_link_libraries(Pong sfml-graphics)
