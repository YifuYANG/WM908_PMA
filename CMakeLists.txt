cmake_minimum_required(VERSION 3.24)
project(PMA)

set(CMAKE_CXX_STANDARD 17)

add_executable(PMA main.cpp Components/Map.cpp Components/Map.h "Settings/Settings.cpp" "Settings/Settings.h" Components/GameStart.cpp Components/GameStart.h)
