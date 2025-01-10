cmake_minimum_required(VERSION 3.30)
project(Chapter11_FileFinder C)

set(CMAKE_C_STANDARD 23)

add_executable(Chapter11_FileFinder main.c)
add_executable(FindFile01 findfile01.c)
add_executable(Glob01 glob01.c)
add_executable(Glob02 glob02.c)
add_executable(FindFile02 findfile02.c)
add_executable(FindDupe01 finddupe01.c)
add_executable(FindDupe02 finddupe02.c)
