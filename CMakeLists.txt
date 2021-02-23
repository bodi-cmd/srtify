cmake_minimum_required(VERSION 3.17)
project(srtify C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(srtify main.c)