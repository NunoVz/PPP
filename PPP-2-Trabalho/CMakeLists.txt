cmake_minimum_required(VERSION 3.17)
project(2Trabalho C)

set(CMAKE_C_STANDARD 11)
add_library(lib FuncAux.c FuncStruct.c header.h)
add_executable(2Trabalho main.c)
target_link_libraries(2Trabalho lib)
