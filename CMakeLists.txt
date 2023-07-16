cmake_minimum_required(VERSION 3.25)
project(miniDataBaseCpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(miniDataBaseCpp main.cpp)

find_package(Curses REQUIRED)
target_link_libraries(miniDataBaseCpp PRIVATE ${CURSES_LIBRARIES})
