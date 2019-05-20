cmake_minimum_required(VERSION 3.14)
project(demo2 C)

set(CMAKE_C_STANDARD 11)

add_executable(demo main.c)

target_link_libraries(
        demo
        avutil
        avformat
)