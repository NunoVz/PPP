cmake_minimum_required(VERSION 3.17)
project(TrabalhoFinal C)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Wall -Wextra)

add_library(lib FuncTexto.c header.h FuncStruct.c )
add_executable(1Parte main.c)
target_link_libraries(1Parte lib)

add_executable(2Parte main2.c)
target_link_libraries(2Parte lib)






