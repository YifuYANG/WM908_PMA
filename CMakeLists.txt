cmake_minimum_required(VERSION 3.24)
project(PMA)

set(CMAKE_CXX_STANDARD 17)

add_executable(PMA main.cpp Component/Map.cpp Component/Map.h)
