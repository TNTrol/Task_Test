cmake_minimum_required(VERSION 3.19)
project(Task_Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task_Test main.cpp manager/unit_manager.cpp manager/unit_manager.h manager/container.h manager/unit.cpp manager/unit.h manager/vec2.h manager/view.cpp manager/view.h)
