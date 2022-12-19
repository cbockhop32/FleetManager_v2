cmake_minimum_required(VERSION 3.19)

project(fleet_manager)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp Display/display.cpp Helper/helper.cpp Car/car.cpp Fleet/fleet.cpp)

